#include <arpa/inet.h>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <portaudio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/socket.h>

#define CHECK(x) { if(!(x)) { \
	fprintf(stderr, "%s:%i: failure at: %s\n", __FILE__, __LINE__, #x); \
	_exit(1); } }

using namespace std;

#define DIVISOR 4 

int streamCallback(
    const void *input, void *output,
    unsigned long frameCount,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *userData );


std::string freadStr(FILE* f, size_t len) {
    std::string s(len, '\0');
    CHECK(fread(&s[0], 1, len, f) == len);
    return s;
}

template<typename T>
T freadNum(FILE* f) {
    T value;
    CHECK(fread(&value, sizeof(value), 1, f) == 1);
    return value; // no endian-swap for now... WAV is LE anyway...
}


class AudioReader {
public:
    int numChannels;
    int sampleRate;
    int bytesPerSample, bitsPerSample;
    void* audioData;
    void* audioDataEnd;

private:
    FILE* wavfile;


public:

    AudioReader(char* filename) {
        wavfile = fopen(filename, "r");

        CHECK(freadStr(wavfile, 4) == "RIFF");
        uint32_t wavechunksize = freadNum<uint32_t>(wavfile);
        CHECK(freadStr(wavfile, 4) == "WAVE");
        uint32_t dataLength;
        while(true) {
            std::string chunkName = freadStr(wavfile, 4);
            uint32_t chunkLen = freadNum<uint32_t>(wavfile);
            if(chunkName == "fmt ")
                readFmtChunk(chunkLen);
            else if(chunkName == "data") {
                CHECK(sampleRate != 0);
                CHECK(numChannels > 0);
                CHECK(bytesPerSample > 0);
                dataLength = chunkLen;
                printf("len: %.0f secs\n", double(chunkLen) / sampleRate / numChannels / bytesPerSample);
                break; // start playing now
            } else {
                // skip chunk
                CHECK(fseek(wavfile, chunkLen, SEEK_CUR) == 0);
            }
        }

        audioData = malloc(dataLength);
	audioDataEnd = audioData + dataLength;

        // We got the audio format, let's read the rest of the file.
        cout << "reading " << dataLength << " bytes of data." << endl;
        fread(audioData, 1, dataLength, wavfile);

        cout << "Read the audio file! Yay" << endl;
        fclose(wavfile);
    }

    ~AudioReader() {
    	free(audioData);
    }

    PaSampleFormat getSampleFormat() {
        switch(bitsPerSample) {
        case 8:
	    cout << "sample format int8" << endl;
            return paInt8;
        case 16:
	    cout << "sample format int16" << endl;
            return  paInt16;
        case 32:
 	    cout << "sample format int32" << endl;
            return paInt32;
        default:
            return -1;
        }
    }


	void readFmtChunk(uint32_t chunkLen) {
	    CHECK(chunkLen >= 16);
	    uint16_t fmttag = freadNum<uint16_t>(wavfile); // 1: PCM (int). 3: IEEE float
	    CHECK(fmttag == 1 || fmttag == 3);
	    numChannels = freadNum<uint16_t>(wavfile);
	    CHECK(numChannels > 0);
	    printf("%i channels\n", numChannels);
	    sampleRate = freadNum<uint32_t>(wavfile);
	    printf("%i Hz\n", sampleRate);
	    uint32_t byteRate = freadNum<uint32_t>(wavfile);
	    uint16_t blockAlign = freadNum<uint16_t>(wavfile);
	    bitsPerSample = freadNum<uint16_t>(wavfile);
	    bytesPerSample = bitsPerSample / 8;
	    cout << bytesPerSample << " bytes per sample" << endl;
	    CHECK(byteRate == sampleRate * numChannels * bytesPerSample);
	    CHECK(blockAlign == numChannels * bytesPerSample);
	    if(chunkLen > 16) {
		uint16_t extendedSize = freadNum<uint16_t>(wavfile);
		CHECK(chunkLen == 18 + extendedSize);
		fseek(wavfile, extendedSize, SEEK_CUR);
	    }
	}
};

class AudioReference {
public:
	AudioReader* reader;
	int currentPos;

	AudioReference(AudioReader* r) {
		reader = r;
		currentPos = 0;
	}	

	bool dataLeft() {
		return reader->audioData + currentPos < reader->audioDataEnd;
	}

	void addFrameTo(void* output, bool overwrite) {
		size_t bytes = reader->numChannels*reader->bytesPerSample;
		uint16_t* target = (uint16_t*)output;
		for(uint16_t* pos = (uint16_t*)(reader->audioData+currentPos); pos < (uint16_t*)(reader->audioData+currentPos+bytes); pos++) {
			if(!overwrite) {
				int16_t value = ((*pos)&0x00FF) | ((*pos)&0xFF00);
				value /= DIVISOR;
				value = ((value)&0x00FF) | ((value)&0xFF00);
				*target += value;
			} else {
				*target = (*pos/10);
			}
		}
		//memcpy(output, reader->audioData+currentPos, reader->numChannels * reader->bytesPerSample);
		currentPos += reader->numChannels*reader->bytesPerSample;
	}
};

std::mutex mmutex;
vector<AudioReference*> refs;

int streamCallback(
    const void *input, void *output,
    unsigned long frameCount,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *userData )
{
    uint16_t result = 0;

    mmutex.lock();
    vector<int> deadRefs;
    for(int i = 0; i < refs.size(); i++) {
	AudioReference* currentRef = refs[i];
    // check, if the reference does have data left
    bool first = true;
    if(currentRef->dataLeft()) {
	currentRef->addFrameTo(&result, false);
        first = false;	
    } else {
	deadRefs.push_back(i);
	//cout << "Playback done" << endl;
    }
    }
    // remove the dead ones

    for(int i = 0; i < deadRefs.size(); i++) {
	AudioReference* r = refs[deadRefs[i]-i];
	delete r;
	refs.erase(refs.begin() + deadRefs[i]-i);
    }
    mmutex.unlock();

    *((uint16_t*)output) = result;

//    memcpy(output, reader->nextSample, reader->numChannels * frameCount * reader->bytesPerSample);
//    reader->nextSample += reader->bytesPerSample * frameCount * reader->numChannels;

//    cout << "Frame Count: " << frameCount << ", statusFlags: " << statusFlags << endl;

    /*size_t numRead = fread(output, reader->bytesPerSample * numChannels, frameCount, wavfile);
    output = (uint8_t*)output + numRead * reader->numChannels * reader->bytesPerSample;
    frameCount -= numRead;

    if(frameCount > 0) {
        memset(output, 0, frameCount * reader->numChannels * reader->bytesPerSample);
        return paComplete;
    }*/
  //  cout << "Stream callback called.." << endl;

    return paContinue;
}



class StreamPlayer {
private:
    PaStream* stream;

public:
    StreamPlayer(AudioReader* reader) {
        PaError err;
        /* Open an audio I/O stream. */
        /* Open an audio I/O stream. */
        err = Pa_OpenDefaultStream( &stream,
                                      0,          /* no input channels */
                                      reader->numChannels,          /* stereo output */
                                      reader->getSampleFormat(),  /* 32 bit floating point output */
                                      reader->sampleRate,
                                      1,
                                      streamCallback,
                                      NULL);
        if( err != paNoError ) {
		cerr << "There was some error.. " << strerror(err) << endl;	
	}


        cout << "Opened the stream!" << endl;
	Pa_StartStream(stream);
    }
};

#define BUFSIZE 1024

struct __attribute__((packed)) soundStruct {
  uint32_t id;
  uint8_t playerID;
  uint8_t soundID;
};

int main(int argc, char** argv) {
	Pa_Initialize();

	// Read sound files
	AudioReader sndShoot("shoot.wav");
	AudioReader sndReload("reload.wav");
	AudioReader sndDie("die.wav");
	AudioReader sndNoammo("noammo.wav");
	AudioReader sndRespawn("respawn.wav");
	cout << "Finished reading sounds" << endl;

	// Create a stream, use shoot sound as reference
	StreamPlayer sp(&sndShoot);

	struct sockaddr_in myaddr;
 	struct sockaddr_in remaddr; /* remote address */ 
	socklen_t addrlen = sizeof(remaddr); /* length of addresses */

	memset((char *)&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(12345);

	int sockfd = socket(AF_INET, SOCK_DGRAM,0);
	
	if(bind(sockfd, (struct sockaddr*)&myaddr, sizeof(myaddr)) < 0) {
		cerr << "Error binding socket." << endl;
		return 1;
	}

	cout << "Binding Done. Waiting for packets!" << endl;

	int recvlen;
	unsigned char buf[BUFSIZE];
	while(1) {
		recvlen = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
		cout << "Got packet! Size: " << recvlen << endl;
		if(recvlen != 6) {
			continue;
		}

		struct soundStruct* s = (struct soundStruct*)buf;
		cout << s->id << ", " << s->playerID << ", " << (int)s->soundID << endl;
		AudioReader* toUse = NULL;
		switch(s->soundID) {
		case 1:
			toUse = &sndShoot;
			break;
		case 2:
			toUse = &sndReload;
			break;
		case 3:
			toUse = &sndDie;
			break;
                case 4:
                        toUse = &sndRespawn;
			break;
		case 5:
			toUse = &sndNoammo;
			break;
		default:
			continue;
		}
		if(toUse != NULL) {
		cout << "Playing sound!" << endl;
		mmutex.lock();
		refs.push_back(new AudioReference(toUse));
		mmutex.unlock();
		}
	}
}


/*
int main(int argc, char** argv) {
    Pa_Initialize();

    AudioReader sound1("blast.wav");
    //cout << "finished!" << endl;
    AudioReader sound2("blast2.wav");
    //cout << "and another one" << endl;

    StreamPlayer player(&sound1);

    mmutex.lock();
    refs.push_back(new AudioReference(&sound1));
    mmutex.unlock();

    for(int i = 0; i < 3; i++) {
    usleep(100000);
    mmutex.lock();
    refs.push_back(new AudioReference(&sound2));
    mmutex.unlock();
}
    

    while(1);
    cout << "beginning sleep" << endl;
    usleep(1000000);
    cout << "done" << endl;
    StreamPlayer player2(&sound1);

    while(1);
}*/


/*
PaStream* stream;


PaSampleFormat sampleFormat;

int paStreamCallback(
    const void *input, void *output,
    unsigned long frameCount,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *userData )
{
    size_t numRead = fread(output, bytesPerSample * numChannels, frameCount, wavfile);
    output = (uint8_t*)output + numRead * numChannels * bytesPerSample;
    frameCount -= numRead;

    if(frameCount > 0) {
        memset(output, 0, frameCount * numChannels * bytesPerSample);
        return paComplete;
    }

    return paContinue;
}


bool portAudioOpen() {

    CHECK(Pa_Initialize() == paNoError);

    PaStreamParameters outputParameters;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    CHECK(outputParameters.device != paNoDevice);

    outputParameters.channelCount = numChannels;
    outputParameters.sampleFormat = sampleFormat;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

	cout << "got here2" << endl;

    PaError ret = Pa_OpenStream(
        &stream,
        NULL, // no input
        &outputParameters,
        sampleRate,
        4096, // framesPerBuffer
        0, // flags
        &paStreamCallback,
        NULL //void *userData
        );



    if(ret != paNoError) {
	cout << "error was: " << strerror(ret) << endl;
        if(stream)
            Pa_CloseStream(stream);
        return false;
    }
	cout << "got here3" << endl;

    CHECK(Pa_StartStream(stream) == paNoError);
    	cout << "got here4" << endl;

return true;
}





int main(int argc, char** argv) {
    CHECK(argc > 1);
    wavfile = fopen(argv[1], "r");
    CHECK(wavfile != NULL);

    CHECK(freadStr(wavfile, 4) == "RIFF");
    uint32_t wavechunksize = freadNum<uint32_t>(wavfile);
    CHECK(freadStr(wavfile, 4) == "WAVE");
    while(true) {
        std::string chunkName = freadStr(wavfile, 4);
        uint32_t chunkLen = freadNum<uint32_t>(wavfile);
        if(chunkName == "fmt ")
            readFmtChunk(chunkLen);
        else if(chunkName == "data") {
            CHECK(sampleRate != 0);
            CHECK(numChannels > 0);
            CHECK(bytesPerSample > 0);
            printf("len: %.0f secs\n", double(chunkLen) / sampleRate / numChannels / bytesPerSample);
            break; // start playing now
        } else {
            // skip chunk
            CHECK(fseek(wavfile, chunkLen, SEEK_CUR) == 0);
        }
    }

    printf("start playing...\n");
    CHECK(portAudioOpen());

    // wait until stream has finished playing
    while(Pa_IsStreamActive(stream) > 0)
        usleep(1000);

    printf("finished\n");
    fclose(wavfile);
    Pa_CloseStream(stream);
    Pa_Terminate();
}
*/

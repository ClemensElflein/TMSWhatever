#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <portaudio.h>
// #include <boost/filesystem.hpp>
// #include "play_audio.cpp"

using namespace std;
// namespace fs = boost::filesystem;

// #define CHECK(x) { if(!(x)) { \
// fprintf(stderr, "%s:%i: failure at: %s\n", __FILE__, __LINE__, #x); \
// _exit(1); } }


// PaStream* blastStream;
// PaStream* reviveStream;
enum sound{
    SHOOT,
    EMPTYSHOOT,
    DIE,
    REVIVE,
    RELOAD
};

void error( char *msg)
{
 perror(msg);
 exit(EXIT_FAILURE);
}

struct packet{
    uint32_t id;
    uint8_t player;
    uint8_t sound;
};

static void playSound(int sound)
{
    switch(sound)
    {
        case SHOOT:
            // std::stringstream stream;
            // stream <<"audio/blast.wav "<<cusip;
            // system(stream.str().c_str());
            system("./Play audio/blast.wav");
            break;

        case REVIVE:
            // std::stringstream stream;
            // stream <<"audio/revive.wav "<<cusip;
            // system(stream.str().c_str());
            system("./Play audio/revive.wav");
            break;

        default: break;
    }
}

#if 0
bool portAudioOpen(PaStream* stream) {
    CHECK(Pa_Initialize() == paNoError);

    PaStreamParameters outputParameters;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    CHECK(outputParameters.device != paNoDevice);

    outputParameters.channelCount = numChannels;
    outputParameters.sampleFormat = sampleFormat;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultHighOutputLatency;

    PaError ret = Pa_OpenStream(
        &stream,
        NULL, // no input
        &outputParameters,
        sampleRate,
        paFramesPerBufferUnspecified, // framesPerBuffer
        0, // flags
        NULL,
        NULL //void *userData
        );

    if(ret != paNoError) {
        fprintf(stderr, "Pa_OpenStream failed: (err %i) %s\n", ret, Pa_GetErrorText(ret));
        if(stream)
            Pa_CloseStream(stream);
        return false;
    }

    // CHECK(Pa_StartStream(stream) == paNoError);
    return true;
}

void readAudioFiles(FILE* blast)
{
    // FILE* blast, revive;
    CHECK(blast != NULL);
    // fseek(blast, 44,0);

    CHECK(freadStr(blast, 4) == "RIFF");
    uint32_t wavechunksize = freadNum<uint32_t>(blast);
    CHECK(freadStr(blast, 4) == "WAVE");
    while(true) {
        std::string chunkName = freadStr(blast, 4);
        uint32_t chunkLen = freadNum<uint32_t>(blast);
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
            CHECK(fseek(blast, chunkLen, SEEK_CUR) == 0);
        }
    }

    CHECK(portAudioOpen(blastStream));


}
#endif

int main()
{
    int sockfd, n;
    uint32_t curId, prevId;
    uint8_t player, sound;
    unsigned int length, cl_length;
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in server,client;
    // struct packet buf;
    struct packet udp_packet;
    char buf[1024];

    length = sizeof(server);
    bzero(&server,length);

    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("10.25.12.120");

    if (bind(sockfd, (struct sockaddr *)&server,length) < 0)
    {
        error("Binding\n");
    }
    cl_length = sizeof(client);

    // fs::path p("audio/blast.wav");

    // fs::ifstream ifs(p);
    // FILE* blast;
    // blast = fopen("audio/blast.wav", "r");
    // readAudioFiles(blast);
    // fclose(blast);

    // FILE* revive;
    // revive = fopen("audio/revive.wav", "r");
    // readAudioFiles(revive);
    // fclose(revive);
    prevId = 0;
    while(1)
    {
        n = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&client,&cl_length);
        if(n < 0)
        {
            error("Receive From\n");
        }
        write(1, "Received Datagram: ", 19);
        write(1,buf,n);

        curId = buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
        // curId = 10;
        // cout << "I am here\n";
        if (curId > prevId)
        {
            player = buf[4];
            sound = buf[5];

            playSound(sound);

        }
        prevId = curId;
    }
    // Pa_Terminate();

}

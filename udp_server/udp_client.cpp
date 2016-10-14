#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


enum sound{
    SHOT,
    REVIVE
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
        case SHOT:
            break;

        case REVIVE:
            break;

        default: break;
    }
}

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
    char buf[2] = {'H', 'I'};

    length = sizeof(server);
    bzero(&server,length);

    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("10.25.12.120");
    // server.sin_addr.s_addr = inet_addr("10.177.255.146");

    n = sendto(sockfd, buf, 2, 0, (struct sockaddr *)&server, length);
 // char buffer[256];
 // socklen_t l = sizeof(serv);
 // //socklen_t m = client;
 // cout<<"\ngoing to recv\n";
 // if(rc<0)
 // {
 // cout<<"ERROR READING FROM SOCKET";
 // }
 // cout<<"\n the message received is : "<<buffer<<endl;
 // int rp= sendto(sockfd,"hi",2,0,(struct sockaddr *)&client,l);

 // if(rp<0)
 // {
 // cout<<"ERROR writing to SOCKET";
 // }
}

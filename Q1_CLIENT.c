#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg) { perror(msg); exit(0); }

int main(int argc, char *argv[])
{
    int socketFD, portNumber, charsRead;
    struct sockaddr_in serverAddress;
    struct hostent* serverHostInfo;
    int randomNumber;

    if (argc < 3) 
    {
        fprintf(stderr,"USAGE: %s hostname port\n", argv[0]); 
        exit(0);
    } 
  
    memset((char*)&serverAddress, '\0', sizeof(serverAddress)); 
    portNumber = atoi(argv[2]); 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(portNumber); 
    serverHostInfo = gethostbyname(argv[1]); 
    if (serverHostInfo == NULL)
    { 
        fprintf(stderr, "CLIENT: ERROR NO SUCH H\n"); 
        exit(0); 
    }
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length);

    
    socketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
    if (socketFD < 0) 
    error("CLIENT: ERROR OPENING SOCKET");

  
    if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
        error("CLIENT: ERROR CONNECTING");

   
    charsRead = recv(socketFD, &randomNum, sizeof(int), 0); 
    if (charsRead < 0) 
    error("CLIENT: ERROR READING FROM SOCKET");
    printf("Random Number from Server: %d\n", randomNumber);

    close(socketFD); 
    return 0;
}
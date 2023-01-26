#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) { perror(msg); exit(1); } 

int main(int argc, char *argv[]) {
    int listenSocketFD, establishedConnectionFD, portNumber, charsRead;
    socklen_t sizeOfClientInfo;
    struct sockaddr_in serverAddress, clientAddress;
    int randomNum;

    if (argc < 2) 
    {
         fprintf(stderr,"USAGE: %s port\n", argv[0]); 
         exit(1); 
    } 


    memset((char *)&serverAddress, '\0', sizeof(serverAddress))
    portNumber = atoi(argv[1]); 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(portNumber);
    serverAddress.sin_addr.s_addr = INADDR_ANY; 


    listenSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSocketFD < 0) 
    error("ERROR OPENING SOCKET");

    
    if (bind(listenSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    error("ERROR ON BINDING");
    listen(listenSocketFD, 5); 

    sizeOfClientInfo = sizeof(clientAddress);
    establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo);
    if (establishedConnectionFD < 0) 
    error("ERROR ON ACCEPT");

    srand(time(NULL));
    randomNum = rand() % 900 + 100;

    charsRead = send(establishedConnectionFD, &randomNumber, sizeof(int), 0); 
    if (charsRead < 0) 
    error("ERROR WRITING TO SOCKET");

    
    close(establishedConnectionFD); 
    close(listenSocketFD);
    return 0; 
}
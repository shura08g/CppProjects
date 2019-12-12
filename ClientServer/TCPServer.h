#ifndef TCPSERVER_H_INCLUDED
#define TCPSERVER_H_INCLUDED

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
//#include <Winsock2.h>
#include <sys/socket.h> //for Linux
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

using namespace std;

class TCPServer{
private:
    static void * Tasck(void * argv);
public:
    int sockfd, newsockfd, n, pid;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    pthread_t serverThread;
    char msg[MAXPACKETSIZE];
    static string Message;

    void setup(int port);
    string receive();
    string getMessage();
    void Send(string msg);
    void detach();
    void clean();
};

#endif // TCPSERVER_H_INCLUDED

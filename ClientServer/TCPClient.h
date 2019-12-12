#ifndef TCPCLIENT_H_INCLUDED
#define TCPCLIENT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
//#include <Winsock2.h>
#include <sys/socket.h> //for Linux
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <vector>

using namespace std;

class TCPClient{
private:
    int sock;
    string address;
    int port;
    struct sockaddr_in server;

public:
    TCPClient();
    bool setup(string address, int port);
    bool Send(string data);
    string receive(int size = 4096);
    string read();
    void exit();
};

#endif // TCPCLIENT_H_INCLUDED

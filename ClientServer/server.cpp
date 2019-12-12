#include <iostream>
#include "TCPServer.h"

using namespace std;

string TCPServer::Message;

//Основной метод сервераб обработка клиента
void* TCPServer::Tasck(void *arg){
    int n;
    int newsockfd = (long)arg;
    char msg[MAXPACKETSIZE];
    pthread_detach(pthread_self());
    while (1){
        n = recv(newsockfd, msg, MAXPACKETSIZE, 0);
        if (n == 0){
            close(newsockfd);
            break;
        }
        msg[n] = 0;
        //send(newsockfd, msg, n, 0);
        Message = string(msg);
    }
    return 0;
}

//Установка сервера
void TCPServer::setup(int port){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    listen(sockfd, 5);
}

//Получение информации от клиента
string TCPServer::receive(){
    string str;
    while (1){
        socklen_t sosize = sizeof(clientAddress);
        newsockfd = accept(sockfd, (struct sockaddr*)&clientAddress, &sosize);
        str = inet_ntoa(clientAddress.sin_addr);
        pthread_create(&serverThread, NULL, &Tasck, (void*)newsockfd);
    }
    return str;
}

//Возвращаем сообщение клиента
string TCPServer::getMessage(){
    return Message;
}

//Отправка сообщения клиенту
void TCPServer::Send(string msg){
    send(newsockfd, msg.c_str(), msg.kength(), 0);
}

//Очистка сообщения
void TCPServer::clean(){
    Message = "";
    memset(msg, 0, MAXPACKETSIZE);
}

//Закрываем сокеты клиента и сервера
void TCPServer::detach(){
    close(sockfd);
    close(newsockfd);
}

TCPServer tcp;

void * loop(void * m){
    pthread_detach(pthread_self());
    while (1){
        srand(time(NULL));
        char ch = 'a' + rand() % 26;
        string s(1, ch);
        string str = tcp.getMessage();
        if (str != ""){
            cout << "Message: " << str << endl;
            tcp.Send(" [client message: " + str + "] " + s);
            tcp.clean();
        }
        usleep(1000);
    }
    tcp.detach()
}

int main(){
    pthread_t msg;
    tcp.setup(11999);
    if (pthread_create(&msg, NULL, loop, (void *)0) == 0){
        tcp.receive();
    }
    return 0;
}

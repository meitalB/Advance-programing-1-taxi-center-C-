

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#define CORRECT 0
#define ERROR_SOCKET -1
#define ERROR_BIND -2
#define ERROR_LISTEN -3
#define ERROR_CONNECT -4
#define ERROR_SEND -5
#define ERROR_RECIVE -6
#define ERROR_ACCEPT -7
#define CONNECTION_CLOSED -8
#define ERROR_CAPACITY -9
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <pthread.h>
#include <list>

using namespace std;

class TcpServer {
public:
    TcpServer(int port);
	int start();
    int connectClient();
    long receiveData(char *buffer, unsigned long size, int client) ;
    int sendData(string data, int client);
    void sendDataToAllClients(string data);
    virtual ~TcpServer();

private:
    struct ClientData {
		struct sockaddr_in client_socket;
        int client;
        unsigned int client_size;
        bool online;
    };

	int port;
	int capacity;
	int num_of_connections;
	int server_socket;
	bool online;
	struct sockaddr_in server_details;
    list<ClientData*>* clients;

    pthread_mutex_t connection_locker;
	pthread_mutex_t map_locker;
};

#endif /* SERVER_SERVER_H_ */



#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#define CORRECT 0
#define ERROR_SOCKET -1
#define ERROR_BIND -2
#define ERROR_LISTEN -3
#define ERROR_CONNECT -4
#define ERROR_SEND -5
#define ERROR_RECIVE -6
#define ERROR_ACCEPT -7
#define CONNECTION_CLOSED -8
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class TcpClient {
public:
	TcpClient(string ip, int port);
	int Connect();
	virtual ~TcpClient();
    int sendData(string data);
	long receiveData(char *buffer, unsigned long size);
private:
	string ip;
	int port;
	int client_socket;
	struct sockaddr_in connection_details;
	bool connected;
};

#endif /* CLIENT_CLIENT_H_ */

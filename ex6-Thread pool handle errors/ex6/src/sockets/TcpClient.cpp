

#include "TcpClient.h"

TcpClient::TcpClient(string ip, int port) {
	this->ip = ip;
	this->port = port;
	this->client_socket = -1;
	this->connected = false;
}

int TcpClient::Connect() {
	// Init socket
	this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(this->client_socket >= 0){
		// Memset the connection details
		memset(&this->connection_details, 0, sizeof(this->connection_details));
		this->connection_details.sin_family = AF_INET;
		this->connection_details.sin_addr.s_addr = inet_addr(this->ip.c_str());
		this->connection_details.sin_port = htons(port);
		// Connect to a server
		if (connect(this->client_socket, (struct sockaddr*)&this->connection_details, 
                    sizeof(this->connection_details)) >= 0) {
            this->connected = true;
            cout<<"connect successfully"<< endl;
            return CORRECT;
        }
        cout<<"connection error" << endl;
        return ERROR_CONNECT;
    }
    return ERROR_SOCKET;
}

/***********************************************************************
* function name: sendData											   *
* The Input: string data to send									   *
* The output: int number representing the return status		           *
* The Function operation: sending the required data, using his length  *
* and the socket descroptor											   *
***********************************************************************/
int TcpClient::sendData(string data) {
    if (this->connected) {
        unsigned long data_len = data.size() + 1;
        const char *datas = data.c_str();
        try {
            // Send the message to the server
            int bytes = (int) send(this->client_socket, datas, (size_t) data_len, 0);
            if (bytes < 0) {
                //return an error represent error at this method
                return ERROR_SEND;
            } else {
                cout<<"send data successfully \n";
                //return correct if there were no problem
                return CORRECT;
            }
        } catch (...) {
            cout << ">> Error." << endl;
        }
    }
    return CONNECTION_CLOSED;
}

/***********************************************************************
* function name: recive												   *
* The Input: none										               *
* The output: int number representing the return status	               *
* The Function operation: getting data from the other socket to,	   *
* enter it to the buffer and print the data							   *
***********************************************************************/
long TcpClient::receiveData(char *buffer, unsigned long size) {
    if (this->connected) {
        long read_bytes = 0;
        try {
            read_bytes = recv(this->client_socket, buffer, (size_t) size, 0);
            //checking the errors
            if (read_bytes == 0) {
                return CONNECTION_CLOSED;
            } else if (read_bytes < 0) {
                //return an error represent error at this method
                return ERROR_RECIVE;
            }
        } catch (...) {
            cout << ">> Error." << endl;
        }

        //return correct if there were no problem
        return (unsigned long) read_bytes;
    }
    return CONNECTION_CLOSED;
}

TcpClient::~TcpClient() {
    cout << "close CLIENT" << endl;
	close(this->client_socket);
}


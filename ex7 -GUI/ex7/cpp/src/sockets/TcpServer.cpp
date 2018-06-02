
#include <map>
#include "TcpServer.h"
/*#include "../logging/easylogging++.h"*/

TcpServer::TcpServer(int port) {
	this->port = port;
	this->clients = new  list<ClientData*>;
	this->server_socket = -1;
	this->capacity = 50;
	this->num_of_connections = 0;
	this->online = false;
}

int TcpServer::start() {
	// Socketing TCP
	this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->server_socket == -1) {
/*        LOG(ERROR) << ">> Failure: opening socket.";*/
        return ERROR_SOCKET;
    } else {
      /*  LOG(DEBUG) << ">> Successfully opened socket.";*/
    }
	// Server details
	memset(&this->server_details, 0, sizeof(this->server_details));
	this->server_details.sin_family = AF_INET;
	this->server_details.sin_addr.s_addr = INADDR_ANY;
	this->server_details.sin_port = htons((uint16_t) this->port);
	bzero(&(this->server_details.sin_zero), 8);

	// Binding
	if (bind(this->server_socket, (struct sockaddr*)&this->server_details, sizeof(struct sockaddr)) < 0) {
    /*    LOG(ERROR) << " Failure: binding.";*/
        return ERROR_BIND;
	} else {
    /*    LOG(DEBUG) << " Successfully binded.";*/
    }

	// Listening
	if(listen(this->server_socket, this->capacity) < 0) {
    /*   LOG(ERROR) << ">> Failure: listening.";*/
        return ERROR_LISTEN;
    }
  /*  LOG(DEBUG) << ">> Server is listening on port: " << this->port << ".";*/
    this->online = true;
    return CORRECT;
}

TcpServer::~TcpServer() {
	close(this->server_socket);

	ClientData* data = NULL;

    for (list<ClientData*>::iterator it = clients->begin(); it != clients->end(); ++it) {
        data = *it;
        delete data;
    }

	delete this->clients;
  /*  LOG(DEBUG) << "close SERVER";*/
}


int TcpServer::connectClient() {
    int client;
    struct sockaddr_in client_socket;
    unsigned int client_size = sizeof(client_socket);
    ClientData* data;

    // If there's some remaining capacity on server
    if (this->num_of_connections < this->capacity) {
        // Accepted a client
        client = accept(this->server_socket, (struct sockaddr*) &client_socket, &client_size);
        if (client >= 0) {
            // Create the clients data
            data = new ClientData();
            data->client_socket = client_socket;
            data->client = client;
            data->client_size = client_size;
            data->online = true;


            // Push the client to the list
            this->clients->push_back(data);
      /*      LOG(DEBUG) << ">> accepting new client.";*/
            return data->client;
        } else {
      /*      LOG(ERROR) << ">> Failure: accepting client.";*/
            return ERROR_ACCEPT;
        }
    }
   /*LOG(ERROR) << ">> Failure: accepting client - out of capacity.";*/
    return ERROR_CAPACITY;
}

/***********************************************************************
* function name: sendData											   *
* The Input: string data to send									   *
* The output: int number representing the return status		           *
* The Function operation: sending the required data, using his length  *
* and the socket descroptor											   *
***********************************************************************/
int TcpServer::sendData(string data, int client) {
    if (this->online) {
        unsigned long data_len = data.size() + 1;
        const char *datas = data.c_str();
        try {
            // Send the message to the server
            int bytes = (int) send(client, datas, (size_t) data_len, 0);
            if (bytes < 0) {
                //return an error represent error at this method
                return ERROR_SEND;
            } else {
                //return correct if there were no problem
                return CORRECT;
            }
        } catch (...) {
            cout << ">> Error.";
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
long TcpServer::receiveData(char *buffer, unsigned long size, int client) {
    if (this->online) {
        long read_bytes = 0;
        try {
            read_bytes = recv(client, buffer, (size_t) size, 0);
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
        return read_bytes;
    }
    return CONNECTION_CLOSED;
}

void TcpServer::sendDataToAllClients(string data) {
    for (list<ClientData*>::iterator it = clients->begin(); it != clients->end(); ++it) {
        this->sendData(data, (*it)->client);
    }
}

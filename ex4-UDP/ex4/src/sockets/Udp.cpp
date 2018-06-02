/************************************************************
* File description: UDP implementation.						*
* the class inherit from socket. 							*
* methods of udp socket type								*
************************************************************/


#include "Udp.h"

/***********************************************************************
* function name: Udp												   *
* The Input: Boolean, true - if server, false if client and port number*
* The output: none										               *
* The Function operation: creating new Udp socket					   *
***********************************************************************/
Udp::Udp(bool isServers, int port_num) {
    this->port_number = port_num;
    this->isServer = isServers;
}

/***********************************************************************
* function name: ~Udp												   *
* The Input: none													   *
* The output: none										               *
* The Function operation: default destructor					       *
***********************************************************************/
Udp::~Udp() {
    // TODO Auto-generated destructor stub
}

/***********************************************************************
* function name: initialize											   *
* The Input: none              										   *
* The output: int number representing the return status		           *
* The Function operation: initialize the Socket object by using 	   *
* socket(), and bind() if server					   				   *
***********************************************************************/
int Udp::initialize() {
    //creating new socket and getting his descriptor
    this->socketDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->socketDescriptor < 0) {
        return ERROR_SOCKET;
    }
    //if server
    if (this->isServer) {
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = htons((uint16_t) this->port_number);
        //bind
        if (bind(this->socketDescriptor,
                 (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            return ERROR_BIND;
        }
    }
    //return correct if there were no problems
    return CORRECT;
}

/***********************************************************************
* function name: sendData											   *
* The Input: string representing the data to send		               *
* The output: int number representing the return status		           *
* The Function operation: sending the input data to the socket         *
* who connect to this socket. check if send successfully			   *
***********************************************************************/
int Udp::sendData(string data) {
    //initialize the struct
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(this->ip_address.c_str());
    sin.sin_port = htons((uint16_t) this->port_number);
    const char *datas = data.c_str();
    unsigned long data_size = data.size() + 1;
    //send
    ssize_t sent_bytes = sendto(this->socketDescriptor,
                                datas, data_size, 0, (struct sockaddr *) &sin, sizeof(sin));
    //check if send successfully
    if (sent_bytes < 0) {
        return ERROR_SEND;
    }
    //return correct if there were no problems
    return CORRECT;
}

/***********************************************************************
* function name: receive         									   *
* The Input: none										               *
* The output: int number representing the return status	               *
* The Function operation: getting data from the other socket check if  *
*  there were no error receiving and print							   *
***********************************************************************/
unsigned long Udp::receiveData(char *buffer, unsigned long size) {
    struct sockaddr_in to;
    unsigned int to_len = sizeof(struct sockaddr_in);
    //receive
    ssize_t bytes = recvfrom(this->socketDescriptor,
                             buffer, (size_t) size, 0, (struct sockaddr *) &to, &to_len);
    //set the port number to the new one which we get with the data
    this->port_number = ntohs(to.sin_port);
    //check if receive successfully

    if (bytes < 0) {
        return ERROR_RECIVE;
    }
    //return correct if there were no error
    return (unsigned long) bytes;
}

Udp::Udp(bool isServers, string ip, int port_num) {
    this->port_number = port_num;
    this->ip_address = ip;
    this->isServer = isServers;
}

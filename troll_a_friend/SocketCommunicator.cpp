
#include "SocketCommunicator.h"


#define DEFAULT_PORT "2001"



SocketCommunicator::SocketCommunicator(string ip, unsigned int port)
{
	
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		this->~SocketCommunicator();
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(ip.c_str(), DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		this->~SocketCommunicator();
	}
}

void SocketCommunicator::connect()
{
	for (this->ptr = this->result; this->ptr != NULL; this->ptr = this->ptr->ai_next) {

		// Create a SOCKET for connecting to server
		this->ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			this->~SocketCommunicator();
		}

		// Connect to server.
		this->iResult = ::connect(this->ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (this->iResult == SOCKET_ERROR) {
			closesocket(this->ConnectSocket);
			this->ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		this->~SocketCommunicator();
	}

}

string SocketCommunicator::read()
{
	this->iResult = recv(this->ConnectSocket, this->recvbuf, this->recvbuflen, 0);
	
	if (this->iResult == 0)
		printf("Connection closed\n");
	else
		printf("recv failed with error: %d\n", WSAGetLastError());
	return string(this->recvbuf);
}

void SocketCommunicator::write(string source)
{
	this->iResult = send(this->ConnectSocket, source.c_str(), source.size(), 0);
	if (this->iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
	}
}

void SocketCommunicator::disconnect()
{
	this->iResult = shutdown(this->ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
	}

}
SocketCommunicator::~SocketCommunicator()
{
	std::cout << "----------------- WARNING -----------------" << std::endl;
	std::cout << "Socket Is Closed" << std::endl;
}

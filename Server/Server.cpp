#include <windows.networking.sockets.h>
#include <iostream>
#include <string>
#pragma comment(lib, "Ws2_32.lib")
#include <fstream>
#include <direct.h>
#define GetCurrentDir _getcwd
#define MAX_LINES 1000
using namespace std;
string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}
int main()
{
	string filename = "Data.txt";
	ifstream file;
	string array[MAX_LINES];
	file.open(filename);
	if (file.fail())
	{
		cout << "File failed to open." << endl;
		return 1;
	}

	int lines = 0;
	while (!file.eof())
	{
		getline(file, array[lines]);
		lines++;
		if (lines == MAX_LINES)
		{
			cout << "Max storage reached" << endl;
			break;
		}
	}
	file.close();

again:
	//starts Winsock DLLs		
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	//create server socket
	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	//binds socket to address
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(27000);
	if (bind(ServerSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
	{
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	//listen on a socket
	if (listen(ServerSocket, 1) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}
	cout << "Waiting for client connection\n" << endl;

	//accepts a connection from a client
	SOCKET ConnectionSocket;
	ConnectionSocket = SOCKET_ERROR;
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	cout << "Connection Established" << endl;
	while (1) {

		//receives RxBuffer

		char RxBuffer[128] = {};

		recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0);
		if (RxBuffer[0] == '*')
		{
			closesocket(ConnectionSocket);	//closes incoming socket
			closesocket(ServerSocket);	    //closes server socket	
			WSACleanup();					//frees Winsock resources
			goto again;
		}
		if (strcmp(RxBuffer, "Exit") == 0)
		{
			closesocket(ConnectionSocket);	//closes incoming socket
			closesocket(ServerSocket);	    //closes server socket	
			WSACleanup();					//frees Winsock resources
			break;
		}
		cout << "Msg Rx: " << RxBuffer << endl;
		array[lines] = RxBuffer;
		lines++;
		char TxBUffer[128] = "Received";

		send(ConnectionSocket, TxBUffer, strlen(TxBUffer), 0);
	}
	ofstream outFile;
	outFile.open("Data.txt", ofstream::out);
	if (outFile.fail())
	{
		cout << "Error opening file." << endl;
		return 1;
	}
	for (int i = 0; i < lines; i++)
	{
		if (!array[i].empty()) {
			outFile << array[i] << endl;
		}
	}
	outFile.close();

	string path = get_current_dir();
	int len = path.length();
	string str2 = path.substr(0, len - 6);
	str2 += "C++ network winform\\Data.txt";

	ofstream outFile_Client;
	outFile_Client.open(str2, ofstream::out);
	if (outFile_Client.fail())
	{
		cout << "Error opening file." << endl;
		return 1;
	}
	for (int i = 0; i < lines; i++)
	{
		if (!array[i].empty()) {
			outFile_Client << array[i] << endl;
		}
	}
	outFile_Client.close();

	return 1;
}
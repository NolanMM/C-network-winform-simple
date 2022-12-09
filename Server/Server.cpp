// Include all the library that needed for the program
//
//  Server Program Created by Minh Le Nguyen - Conestoga College
// 
#include <windows.networking.sockets.h>
#include <iostream>
#include <string>
#pragma comment(lib, "Ws2_32.lib")
#include <fstream>
#include <direct.h>
#define GetCurrentDir _getcwd
#define MAX_LINES 1000
using namespace std;
// Function to return the current directory inorder to save the file later
string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}
int main()
{
	// Open and read all the lines from text file name Data and store it into the string array that maximum 1000 lines
	string filename = "Data.txt";
	ifstream file;
	string array[MAX_LINES];
	file.open(filename);

	// Check if the fille opened fail
	if (file.fail())
	{
		cout << "File failed to open." << endl;
		return 1;
	}

	// Create a counter for the string array that store each lines in the file
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
	// Close the files
	file.close();
// Set the mark to set the return point to generate new connect again when user want to reconnect from client
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
	// While loop to wait for the message from the client
	while (1) {

		//receives RxBuffer
		char RxBuffer[128] = {};

		recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0);
		// Check if the user want to reconnect the server again, the server will return to the mark point
		if (RxBuffer[0] == '*')
		{
			closesocket(ConnectionSocket);	//closes incoming socket
			closesocket(ServerSocket);	    //closes server socket	
			WSACleanup();					//frees Winsock resources
			goto again;
		}
		// Check if the Exit signal the server will close it and store all the current data and exit the program
		if (strcmp(RxBuffer, "Exit") == 0)
		{
			closesocket(ConnectionSocket);	//closes incoming socket
			closesocket(ServerSocket);	    //closes server socket	
			WSACleanup();					//frees Winsock resources
			break;
		}
		// Print the message to the command promt to check the message
		cout << "Msg Rx: " << RxBuffer << endl;
		// Continue stoore each successfully received message from user into the string array
		array[lines] = RxBuffer;
		lines++;
		// Create a respond message to send back to the client
		char TxBUffer[128] = "Received";
		send(ConnectionSocket, TxBUffer, strlen(TxBUffer), 0);
	}
	// Open The Data file and store all the messages successfully received into Server Directory
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

	// Open The Data file and store all the messages successfully received into Client Directory
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
#include "stdafx.h"
#include <Windows.h>
#include <fstream>
#pragma once
//#include <bits/stdc++.h>
#include <windows.networking.sockets.h>
#include <string>
#include <string.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
//using namespace msclr::interop;
#define MAX_LINES 1000

using namespace std;
namespace Cnetworkwinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Client_Form
	/// </summary>
	public ref class Client_Form : public System::Windows::Forms::Form
	{
	public:
		Client_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Client_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Welcome_Label;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ Send_To_Server_btn;
	public: System::Windows::Forms::TextBox^ Author_Name_box;
	public: System::Windows::Forms::TextBox^ Topic_box;
	private: System::Windows::Forms::ListView^ Listview_topic;
	public:

	public:
	private: System::Windows::Forms::ColumnHeader^ Author_name;
	private: System::Windows::Forms::ColumnHeader^ Topic;
	private: System::Windows::Forms::Button^ Exit_btn;
	public: System::Windows::Forms::Button^ Disconnect_btn;
	private: System::Windows::Forms::Label^ Error_mess;
	public: System::Windows::Forms::Button^ Reconnect_btn;
	private: System::Windows::Forms::Button^ End;
	private: System::Windows::Forms::ColumnHeader^ Post;
	private: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::TextBox^ Post_Content_box;



	private: System::Windows::Forms::ColumnHeader^ Respond;
	private: System::Windows::Forms::Label^ label4;
	public:
	private:

	private:
	public:
	private:
	public:
	private:

	private:

	private:



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Client_Form::typeid));
			this->Welcome_Label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Send_To_Server_btn = (gcnew System::Windows::Forms::Button());
			this->Author_Name_box = (gcnew System::Windows::Forms::TextBox());
			this->Topic_box = (gcnew System::Windows::Forms::TextBox());
			this->Listview_topic = (gcnew System::Windows::Forms::ListView());
			this->Author_name = (gcnew System::Windows::Forms::ColumnHeader());
			this->Topic = (gcnew System::Windows::Forms::ColumnHeader());
			this->Post = (gcnew System::Windows::Forms::ColumnHeader());
			this->Respond = (gcnew System::Windows::Forms::ColumnHeader());
			this->Exit_btn = (gcnew System::Windows::Forms::Button());
			this->Disconnect_btn = (gcnew System::Windows::Forms::Button());
			this->Error_mess = (gcnew System::Windows::Forms::Label());
			this->Reconnect_btn = (gcnew System::Windows::Forms::Button());
			this->End = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Post_Content_box = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Welcome_Label
			// 
			this->Welcome_Label->AutoSize = true;
			this->Welcome_Label->BackColor = System::Drawing::Color::Transparent;
			this->Welcome_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->Welcome_Label->ForeColor = System::Drawing::Color::White;
			this->Welcome_Label->Location = System::Drawing::Point(355, 38);
			this->Welcome_Label->Name = L"Welcome_Label";
			this->Welcome_Label->Size = System::Drawing::Size(835, 86);
			this->Welcome_Label->TabIndex = 0;
			this->Welcome_Label->Text = L"Welcome to Client Program";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(61, 488);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(267, 54);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Author Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(61, 605);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 54);
			this->label1->TabIndex = 2;
			this->label1->Text = L"The Topic";
			// 
			// Send_To_Server_btn
			// 
			this->Send_To_Server_btn->BackColor = System::Drawing::Color::Black;
			this->Send_To_Server_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Send_To_Server_btn->ForeColor = System::Drawing::Color::Red;
			this->Send_To_Server_btn->Location = System::Drawing::Point(408, 544);
			this->Send_To_Server_btn->Name = L"Send_To_Server_btn";
			this->Send_To_Server_btn->Size = System::Drawing::Size(202, 45);
			this->Send_To_Server_btn->TabIndex = 7;
			this->Send_To_Server_btn->Text = L"Send To Server";
			this->Send_To_Server_btn->UseVisualStyleBackColor = false;
			this->Send_To_Server_btn->Click += gcnew System::EventHandler(this, &Client_Form::Send_To_Server_btn_Click);
			// 
			// Author_Name_box
			// 
			this->Author_Name_box->BackColor = System::Drawing::SystemColors::InfoText;
			this->Author_Name_box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Author_Name_box->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->Author_Name_box->ForeColor = System::Drawing::Color::White;
			this->Author_Name_box->Location = System::Drawing::Point(70, 555);
			this->Author_Name_box->Name = L"Author_Name_box";
			this->Author_Name_box->Size = System::Drawing::Size(309, 47);
			this->Author_Name_box->TabIndex = 8;
			// 
			// Topic_box
			// 
			this->Topic_box->BackColor = System::Drawing::SystemColors::InfoText;
			this->Topic_box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Topic_box->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->Topic_box->ForeColor = System::Drawing::Color::White;
			this->Topic_box->Location = System::Drawing::Point(70, 672);
			this->Topic_box->Name = L"Topic_box";
			this->Topic_box->Size = System::Drawing::Size(309, 47);
			this->Topic_box->TabIndex = 9;
			// 
			// Listview_topic
			// 
			this->Listview_topic->BackColor = System::Drawing::Color::Black;
			this->Listview_topic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Listview_topic.BackgroundImage")));
			this->Listview_topic->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Listview_topic->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Author_name,
					this->Topic, this->Post, this->Respond
			});
			this->Listview_topic->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->Listview_topic->ForeColor = System::Drawing::Color::White;
			this->Listview_topic->GridLines = true;
			this->Listview_topic->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->Listview_topic->HideSelection = false;
			this->Listview_topic->Location = System::Drawing::Point(408, 283);
			this->Listview_topic->MultiSelect = false;
			this->Listview_topic->Name = L"Listview_topic";
			this->Listview_topic->Size = System::Drawing::Size(941, 226);
			this->Listview_topic->TabIndex = 10;
			this->Listview_topic->UseCompatibleStateImageBehavior = false;
			this->Listview_topic->View = System::Windows::Forms::View::Details;
			// 
			// Author_name
			// 
			this->Author_name->Text = L"Author Name";
			this->Author_name->Width = 180;
			// 
			// Topic
			// 
			this->Topic->Text = L"Topic";
			this->Topic->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Topic->Width = 120;
			// 
			// Post
			// 
			this->Post->Text = L"Post Content";
			this->Post->Width = 360;
			// 
			// Respond
			// 
			this->Respond->Text = L"Respond From Server";
			this->Respond->Width = 262;
			// 
			// Exit_btn
			// 
			this->Exit_btn->BackColor = System::Drawing::Color::Black;
			this->Exit_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exit_btn->ForeColor = System::Drawing::Color::Red;
			this->Exit_btn->Location = System::Drawing::Point(720, 545);
			this->Exit_btn->Name = L"Exit_btn";
			this->Exit_btn->Size = System::Drawing::Size(274, 45);
			this->Exit_btn->TabIndex = 11;
			this->Exit_btn->Text = L"Close Server and Client";
			this->Exit_btn->UseVisualStyleBackColor = false;
			this->Exit_btn->Click += gcnew System::EventHandler(this, &Client_Form::Exit_btn_Click);
			// 
			// Disconnect_btn
			// 
			this->Disconnect_btn->BackColor = System::Drawing::Color::Black;
			this->Disconnect_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Disconnect_btn->ForeColor = System::Drawing::Color::Red;
			this->Disconnect_btn->Location = System::Drawing::Point(1075, 544);
			this->Disconnect_btn->Name = L"Disconnect_btn";
			this->Disconnect_btn->Size = System::Drawing::Size(274, 45);
			this->Disconnect_btn->TabIndex = 12;
			this->Disconnect_btn->Text = L"Disconnect To Server";
			this->Disconnect_btn->UseVisualStyleBackColor = false;
			this->Disconnect_btn->Click += gcnew System::EventHandler(this, &Client_Form::Disconnect_btn_Click);
			// 
			// Error_mess
			// 
			this->Error_mess->AutoSize = true;
			this->Error_mess->BackColor = System::Drawing::Color::Black;
			this->Error_mess->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->Error_mess->ForeColor = System::Drawing::Color::Red;
			this->Error_mess->Location = System::Drawing::Point(352, 135);
			this->Error_mess->Name = L"Error_mess";
			this->Error_mess->Size = System::Drawing::Size(838, 54);
			this->Error_mess->TabIndex = 13;
			this->Error_mess->Text = L"Error! Empty Input! Please Enter Post Content";
			this->Error_mess->Visible = false;
			// 
			// Reconnect_btn
			// 
			this->Reconnect_btn->BackColor = System::Drawing::Color::Black;
			this->Reconnect_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Reconnect_btn->ForeColor = System::Drawing::Color::Red;
			this->Reconnect_btn->Location = System::Drawing::Point(1075, 544);
			this->Reconnect_btn->Name = L"Reconnect_btn";
			this->Reconnect_btn->Size = System::Drawing::Size(274, 45);
			this->Reconnect_btn->TabIndex = 14;
			this->Reconnect_btn->Text = L"Re-Connect To Server";
			this->Reconnect_btn->UseVisualStyleBackColor = false;
			this->Reconnect_btn->Visible = false;
			this->Reconnect_btn->Click += gcnew System::EventHandler(this, &Client_Form::Reconnect_btn_Click);
			// 
			// End
			// 
			this->End->BackColor = System::Drawing::Color::Black;
			this->End->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->End->ForeColor = System::Drawing::Color::Red;
			this->End->Location = System::Drawing::Point(1324, 24);
			this->End->Name = L"End";
			this->End->Size = System::Drawing::Size(41, 45);
			this->End->TabIndex = 15;
			this->End->Text = L"x";
			this->End->UseVisualStyleBackColor = false;
			this->End->Click += gcnew System::EventHandler(this, &Client_Form::End_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(76, 283);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(252, 54);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Post Content";
			// 
			// Post_Content_box
			// 
			this->Post_Content_box->BackColor = System::Drawing::SystemColors::InfoText;
			this->Post_Content_box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Post_Content_box->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->Post_Content_box->ForeColor = System::Drawing::Color::White;
			this->Post_Content_box->Location = System::Drawing::Point(70, 340);
			this->Post_Content_box->Multiline = true;
			this->Post_Content_box->Name = L"Post_Content_box";
			this->Post_Content_box->Size = System::Drawing::Size(309, 153);
			this->Post_Content_box->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(623, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(499, 54);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Post History In System File";
			this->label4->Visible = false;
			// 
			// Client_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1394, 768);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Post_Content_box);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->End);
			this->Controls->Add(this->Reconnect_btn);
			this->Controls->Add(this->Error_mess);
			this->Controls->Add(this->Disconnect_btn);
			this->Controls->Add(this->Exit_btn);
			this->Controls->Add(this->Listview_topic);
			this->Controls->Add(this->Topic_box);
			this->Controls->Add(this->Author_Name_box);
			this->Controls->Add(this->Send_To_Server_btn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Welcome_Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Client_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Client_Form";
			this->Load += gcnew System::EventHandler(this, &Client_Form::Client_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Exit_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			string TxBuffer = "Exit";
			const char* test = TxBuffer.c_str();
			send(ClientSocket_2, test, strlen(test), 0);
			//closes connection and socket
			closesocket(ClientSocket_2);

			//frees Winsock DLL resources
			WSACleanup();
			exit(0);
		}
		string convertToString(char* a)
		{
			string s = a;
			return s;
		}


		private: System::Void Send_To_Server_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (Post_Content_box->Text->Length == 0)
			{
				Error_mess->Visible = true;
				return;
			}
			if (Post_Content_box->Text->Length != 0) {
				Error_mess->Visible = false;
			}
			if (Author_Name_box->Text->Length == 0)
			{
				Error_mess->Visible = false;
				Author_Name_box->Text = "Unknow";
			}
			if (Topic_box->Text->Length == 0)
			{
				Error_mess->Visible = false;
				Topic_box->Text = "Unknow";
			}
			//Item[0] = marshal_as<string>(Author_Name_box->Text);
			//Item[1] = marshal_as<string>(Topic_box->Text);
			
			
			
			System::String^ test_System_string = "Author Name: " + Author_Name_box->Text + " --- " +"Topic: " + Topic_box->Text + " --- " + "Post Content: " + Post_Content_box->Text;

			string Total = marshal_as<string>(test_System_string);
			const char* Send_message = Total.c_str();

			//char TxBuffer[128] = {};
			//string TxBuffer;
			//cout << "Enter a String to transmit" << endl;
			//TxBuffer = Author_name + " " + Topic;
			//getline(cin, TxBuffer);

			send(ClientSocket_2, Send_message, strlen(Send_message), 0);
			

			char RxBuffer[128] = {};

			recv(ClientSocket_2, RxBuffer, sizeof(RxBuffer), 0);
			string rev = convertToString(RxBuffer);
			String^ Respond = gcnew String(rev.data());
			ListViewItem^ items = gcnew ListViewItem(Author_Name_box->Text);
			items->SubItems->Add(Topic_box->Text);
			items->SubItems->Add(Post_Content_box->Text);
			items->SubItems->Add(Respond);
			//
			Listview_topic->Items->Insert(0, items);
			//
			Post_Content_box->Clear();
			Author_Name_box->Clear();
			Topic_box->Clear();
			Total.erase();
		}
		SOCKET ClientSocket_2;
private: System::Void Client_Form_Load(System::Object^ sender, System::EventArgs^ e) {

	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return;
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return;
	}
	//Connect socket to specified server
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;						//Address family type itnernet
	SvrAddr.sin_port = htons(27000);					//port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//IP address
	if ((connect(ClientSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr))) == SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		return;
	}
	else {
		ClientSocket_2 = ClientSocket;
	}

	string filename = "Data.txt";
	ifstream file;

	
	file.open(filename);
	if (file.fail())
	{
		cout << "File failed to open." << endl;
	}
	string array[MAX_LINES];
	int lines = 0;
	while (!file.eof())
	{
		string delimiter = " --- ";
		getline(file, array[lines]);
		
		if (lines == MAX_LINES)
		{
			cout << "Max storage reached" << endl;
			break;
		}
		size_t pos = 0;
		string token;
		int count = 0;
		string Items[3];

		while ((pos = array[lines].find(delimiter)) != string::npos) {
			token = array[lines].substr(0, pos);
			Items[count] = token;
			count++;
			Items[2] = array[lines].erase(0, pos + delimiter.length());
		}

		string delimiter_author = "Author Name: ";
		string author_name_;
		while ((pos = Items[0].find(delimiter_author)) != string::npos) {
			token = Items[0].substr(0, pos);
			author_name_ = token;
			author_name_ = Items[0].erase(0, pos + delimiter_author.length());
		}
		String^ author_name = gcnew String(author_name_.c_str());
		

		string delimiter_topic = "Topic: ";
		string topic_name_;
		while ((pos = Items[1].find(delimiter_topic)) != string::npos) {
			token = Items[1].substr(0, pos);
			topic_name_ = token;
			topic_name_ = Items[1].erase(0, pos + delimiter_topic.length());
		}
		String^ topic = gcnew String(topic_name_.c_str());

		string delimiter_Content = "Post Content: ";
		string Description_;
		while ((pos = Items[2].find(delimiter_Content)) != string::npos) {
			token = Items[2].substr(0, pos);
			Description_ = token;
			Description_ = Items[2].erase(0, pos + delimiter_Content.length());
		}
		String^ Desctiption = gcnew String(Description_.c_str());

		String^ Respond = gcnew String("Received");
		if (author_name->Length != 0)
		{
			ListViewItem^ items = gcnew ListViewItem(author_name);
			items->SubItems->Add(topic);
			items->SubItems->Add(Desctiption);
			items->SubItems->Add(Respond);
			Listview_topic->Items->Insert(0, items);
		}
		lines++;
	}

	file.close();
	
}

private: System::Void Disconnect_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	string TxBuffer = "*";
	const char* test = TxBuffer.c_str();
	send(ClientSocket_2, test, strlen(test), 0);
	//closes connection and socket
	closesocket(ClientSocket_2);

	//frees Winsock DLL resources
	WSACleanup();
	Reconnect_btn->Visible = true;
	Disconnect_btn->Visible = false;
}
private: System::Void Reconnect_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return;
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return;
	}

	//Connect socket to specified server
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;						//Address family type itnernet
	SvrAddr.sin_port = htons(27000);					//port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//IP address
	if ((connect(ClientSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr))) == SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		return;
	}
	else {
		ClientSocket_2 = ClientSocket;
	}
	Disconnect_btn->Visible = true;
	Reconnect_btn->Visible = false;
}
private: System::Void End_Click(System::Object^ sender, System::EventArgs^ e) {
	string TxBuffer = "Exit";
	const char* test = TxBuffer.c_str();
	send(ClientSocket_2, test, strlen(test), 0);
	//closes connection and socket
	closesocket(ClientSocket_2);

	//frees Winsock DLL resources
	WSACleanup();
	exit(0);
}
};
}

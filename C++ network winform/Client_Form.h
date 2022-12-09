#pragma once
// Includes all the library needed for the program
#include "stdafx.h"
#include <Windows.h>
#include <fstream>
#include <windows.networking.sockets.h>
#include <string>
#include <string.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
using namespace std;

#define MAX_LINES 1000

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
	private: System::Windows::Forms::ListView^ Items_Send_Server_ListView;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	public: System::Windows::Forms::Button^ History_post_btn;
	private:
	public: System::Windows::Forms::Button^ Post_Send_Currently_Session_btn;
	private: System::Windows::Forms::Label^ label5;
	public:
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
			this->Items_Send_Server_ListView = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->History_post_btn = (gcnew System::Windows::Forms::Button());
			this->Post_Send_Currently_Session_btn = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
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
			// Items_Send_Server_ListView
			// 
			this->Items_Send_Server_ListView->BackColor = System::Drawing::Color::Black;
			this->Items_Send_Server_ListView->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Items_Send_Server_ListView.BackgroundImage")));
			this->Items_Send_Server_ListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Items_Send_Server_ListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader1,
					this->columnHeader2, this->columnHeader3, this->columnHeader4
			});
			this->Items_Send_Server_ListView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->Items_Send_Server_ListView->ForeColor = System::Drawing::Color::White;
			this->Items_Send_Server_ListView->GridLines = true;
			this->Items_Send_Server_ListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->Items_Send_Server_ListView->HideSelection = false;
			this->Items_Send_Server_ListView->Location = System::Drawing::Point(408, 283);
			this->Items_Send_Server_ListView->MultiSelect = false;
			this->Items_Send_Server_ListView->Name = L"Items_Send_Server_ListView";
			this->Items_Send_Server_ListView->Size = System::Drawing::Size(941, 226);
			this->Items_Send_Server_ListView->TabIndex = 19;
			this->Items_Send_Server_ListView->UseCompatibleStateImageBehavior = false;
			this->Items_Send_Server_ListView->View = System::Windows::Forms::View::Details;
			this->Items_Send_Server_ListView->Visible = false;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Author Name";
			this->columnHeader1->Width = 180;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Topic";
			this->columnHeader2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->columnHeader2->Width = 120;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Post Content";
			this->columnHeader3->Width = 360;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Respond From Server";
			this->columnHeader4->Width = 262;
			// 
			// History_post_btn
			// 
			this->History_post_btn->BackColor = System::Drawing::Color::Black;
			this->History_post_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->History_post_btn->ForeColor = System::Drawing::Color::Red;
			this->History_post_btn->Location = System::Drawing::Point(408, 672);
			this->History_post_btn->Name = L"History_post_btn";
			this->History_post_btn->Size = System::Drawing::Size(299, 45);
			this->History_post_btn->TabIndex = 20;
			this->History_post_btn->Text = L"History Post In System";
			this->History_post_btn->UseVisualStyleBackColor = false;
			this->History_post_btn->Click += gcnew System::EventHandler(this, &Client_Form::History_post_btn_Click);
			// 
			// Post_Send_Currently_Session_btn
			// 
			this->Post_Send_Currently_Session_btn->BackColor = System::Drawing::Color::Black;
			this->Post_Send_Currently_Session_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Post_Send_Currently_Session_btn->ForeColor = System::Drawing::Color::Red;
			this->Post_Send_Currently_Session_btn->Location = System::Drawing::Point(1066, 674);
			this->Post_Send_Currently_Session_btn->Name = L"Post_Send_Currently_Session_btn";
			this->Post_Send_Currently_Session_btn->Size = System::Drawing::Size(299, 45);
			this->Post_Send_Currently_Session_btn->TabIndex = 21;
			this->Post_Send_Currently_Session_btn->Text = L"Post Sent This Session";
			this->Post_Send_Currently_Session_btn->UseVisualStyleBackColor = false;
			this->Post_Send_Currently_Session_btn->Click += gcnew System::EventHandler(this, &Client_Form::Post_Send_Currently_Session_btn_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Black;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 30, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(613, 226);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(523, 54);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Posts sent Currently Session";
			// 
			// Client_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1394, 768);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Post_Send_Currently_Session_btn);
			this->Controls->Add(this->History_post_btn);
			this->Controls->Add(this->Items_Send_Server_ListView);
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
			/*
			//	Create string to send the message to exit the program to the server
			//	The signal is "Exit";
			*/
			string TxBuffer = "Exit";
			// Convert string to const char[] and store inside const char*
			const char* test = TxBuffer.c_str();

			// Send the message to socket that store inside the program when the form be loaded at the beginning
			send(ClientSocket_2, test, strlen(test), 0);
			//closes connection and socket
			closesocket(ClientSocket_2);

			//frees Winsock DLL resources
			WSACleanup();
			exit(0);
		}
		/*
		* // Function to convert char * to string and return string s
		*/
		string convertToString(char* a)
		{
			string s = a;
			return s;
		}

		/* ********
		// Use case: When user want to send the message to the server
		// ********

		/*************
		// Requirement
		// Post_content_box must be not null
		// Author_Name_box and Topic_box can be null
		// ***********

		// Description:
		//
		// Function that take the input System::String^ from each box and convert to std::string and convert 
		// to const char* and send it to the server by its string length()
		// Function also allow to check for the input from post_box which must be != null and accept the null
		// input from Author name box and Topic box and change it into unknown and send to server
		*/
		private: System::Void Send_To_Server_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			/* Check if The post box be null will send the warning message and return
			// Error mess visible change from false (at the beginning form load) to true
			*/
			if (Post_Content_box->Text->Length == 0)
			{
				Error_mess->Visible = true;
				return;
			}
			/* Check if the Post box =! null hide the warning message
			//
			// Error mess visible change from true (if the post content box be 
			// null last time) to false
			*/
			if (Post_Content_box->Text->Length != 0) {
				Error_mess->Visible = false;
			}
			/* Check if the author name box == null then change to unknown for friendly interface
			//
			*/
			if (Author_Name_box->Text->Length == 0)
			{
				Author_Name_box->Text = "Unknow";
			}
			/* Check if the topic name box == null then change to unknown for friendly interface
			//
			*/
			if (Topic_box->Text->Length == 0)
			{
				Topic_box->Text = "Unknow";
			}

			// In the case want to store inside a string array
			// string Item[2];
			//Item[0] = marshal_as<string>(Author_Name_box->Text);
			//Item[1] = marshal_as<string>(Topic_box->Text);
			
			// System::String^ combine to a single line by the default format
			// [Author Name: ][Author_Name_box->Text][ --- ][Topic: ][Topic_box->Text][ --- ][Post Content: ][Post_Content_box->Text]
			System::String^ test_System_string = "Author Name: " + Author_Name_box->Text + " --- " +"Topic: " + Topic_box->Text + " --- " + "Post Content: " + Post_Content_box->Text;

			// Convert System::String^ to std::string name Total
			string Total = marshal_as<string>(test_System_string);
			// Convert std:: string to const char[] and store the address in side const char* name Send_message
			const char* Send_message = Total.c_str();

			// In case want to take input from user in the ASS3 REPO
			//char TxBuffer[128] = {};
			//string TxBuffer;
			//cout << "Enter a String to transmit" << endl;
			//TxBuffer = Author_name + " " + Topic;
			//getline(cin, TxBuffer);

			// Send the message to Server
			send(ClientSocket_2, Send_message, strlen(Send_message), 0);
			
			// Create a variable to store the receive message
			char RxBuffer[128] = {};

			// Received the message and store inside a char array name RxBuffer
			recv(ClientSocket_2, RxBuffer, sizeof(RxBuffer), 0);

			// Convert char array to std::string by using function convertToString
			string rev = convertToString(RxBuffer);

			// Create a new System::String^ inorder to show to the interface for the user
			// Using listview to displayed all the information sent to the server and responded from server
			String^ Respond = gcnew String(rev.data());

			// Create new listview items and assign all the elements
			ListViewItem^ items = gcnew ListViewItem(Author_Name_box->Text);
			items->SubItems->Add(Topic_box->Text);
			items->SubItems->Add(Post_Content_box->Text);
			items->SubItems->Add(Respond);
			// Insert Items at the top of the listview
			Listview_topic->Items->Insert(0, items);
			//
			// Clear all the Text_box and prepare for the next input from user
			Post_Content_box->Clear();
			Author_Name_box->Clear();
			Topic_box->Clear();
			//  Erase the data from this time free the memory
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
	}
	//
	// ??
	// Show the history of the file  at the beginning codes
	// ??
	//
	/*string filename = "Data.txt";
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
			Items_Send_Server_ListView->Items->Insert(0, items);
		}
		lines++;
	}

	file.close();
	
}*/

		// Functions when the user want to disconnect to server but dont want to exit the program yet to check for the history of the posts

		private: System::Void Disconnect_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create and send the signal disconnect to the server
		string TxBuffer = "*";
		const char* test = TxBuffer.c_str();
		send(ClientSocket_2, test, strlen(test), 0);
		//closes connection and socket
		closesocket(ClientSocket_2);

		//frees Winsock DLL resources
		WSACleanup();
		
		// Show the button reconnect in case user want to reconnect to the server again
		Reconnect_btn->Visible = true;
		// Hide the disconnect from the form when the disconnect progress be successful
		Disconnect_btn->Visible = false;

		}
// Funtions when the user want to reconnect to the server
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
	// The button disconnect visible be set to true when the reconnection be successful
	Disconnect_btn->Visible = true;
	// set the visible of the reconnect button to false and hide it from the user 
	Reconnect_btn->Visible = false;
}
	// Function Exit when the user want to exit by X button 
	// Create a signal "Exit" send to the server to exit the server
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

// Function that take the data from the file that be saved by the server from last sessions and show it to the user
private: System::Void History_post_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	
	// Open and read from file name Data 
	string filename = "Data.txt";
	ifstream file;
	file.open(filename);

	// Check if the file was open fail it will Sent a message
	if (file.fail())
	{
		cout << "File failed to open." << endl;
	}
	// Create a string array can store 1000 lines in the text files that content 1000 posts
	string array[MAX_LINES];
	// Set the counter and the index for each lines in the text files
	int lines = 0;
	// While loop to loop until the end of the files
	while (!file.eof())
	{
		// Create a string delimiter to using string split from the file default format for messages
		// and store all the element are author name:"(Data), " Topic: "(Data)", "Post Content: "(Data)" into each elements Items[3]
		//"Author Name: " + Author_Name_box->Text + " --- " +"Topic: " + Topic_box->Text + " --- " + "Post Content: " + Post_Content_box->Text;
		string delimiter = " --- ";

		// Take every single lines inside the file and store it into the array of string
		// Each items inside array is a string format
		// "Author Name: " + Author_Name_box->Text + " --- " +"Topic: " + Topic_box->Text + " --- " + "Post Content: " + Post_Content_box->Text;
		getline(file, array[lines]);

		// Check if Reach the limits of the lines or not
		if (lines == MAX_LINES)
		{
			cout << "Max storage reached" << endl;
			break;
		}

		// Set the pos to store the count of length want to substring 
		size_t pos = 0;
		string token;
		// Counter for Items string array
		int count = 0;
		string Items[3];

		// Substring first fine all the address of delimiter inside each lines string
		while ((pos = array[lines].find(delimiter)) != string::npos) {
			// Substring and store the item string inside the token
			// token = array[0].substr(0, pos);      ===   "Author Name: (Data)"
			// token = array[1].substr(0, pos);      ===   "Topic: (Data)"
			// token = array[2].substr(0, pos);      ===   "Post Content: (Data)"
			token = array[lines].substr(0, pos);
			Items[count] = token;
			count++;
			// Take the last elemtent and store it inside the last items of string array
			Items[2] = array[lines].erase(0, pos + delimiter.length());
		}
		// Substring to take the Data from "Author Name: (Data)" <------- Items[0]
		// Using the same technique above but change the delimiter to "Author Name: " and take the items
		string delimiter_author = "Author Name: ";
		string author_name_;
		while ((pos = Items[0].find(delimiter_author)) != string::npos) {
			token = Items[0].substr(0, pos);
			author_name_ = token;
			author_name_ = Items[0].erase(0, pos + delimiter_author.length());
		}
		// Convert the author name std::string to System::String^ and store inside variable author_name
		String^ author_name = gcnew String(author_name_.c_str());

		// Substring to take the Data from "Topic: (Data)" <------- Items[1]
		// Using the same technique above but change the delimiter to "Topic: " and take the items
		string delimiter_topic = "Topic: ";
		string topic_name_;
		while ((pos = Items[1].find(delimiter_topic)) != string::npos) {
			token = Items[1].substr(0, pos);
			topic_name_ = token;
			topic_name_ = Items[1].erase(0, pos + delimiter_topic.length());
		}
		// Convert the topic_name std::string to System::String^ and store inside variable topic
		String^ topic = gcnew String(topic_name_.c_str());

		// Substring to take the Data from "Post Content: (Data)" <-------- Items[2]
		// Using the same technique above but change the delimiter to "Post Content: " and take the items
		string delimiter_Content = "Post Content: ";
		string Description_;
		while ((pos = Items[2].find(delimiter_Content)) != string::npos) {
			token = Items[2].substr(0, pos);
			Description_ = token;
			Description_ = Items[2].erase(0, pos + delimiter_Content.length());
		}
		// Convert the  std::string to System::String^ and store inside variable author_name
		// Convert the Description std::string to System::String^ and store inside variable Description
		String^ Desctiption = gcnew String(Description_.c_str());

		// Create the string Received to announce to the user that the lines are already inside the 
		//file so it already received and saved by the server
		String^ Respond = gcnew String("Received");

		// Check if the author_name Length != to avoid string array Items[] be null in the first elemtent that store the author name
		if (author_name->Length != 0)
		{
			ListViewItem^ items = gcnew ListViewItem(author_name);
			items->SubItems->Add(topic);
			items->SubItems->Add(Desctiption);
			items->SubItems->Add(Respond);
			Items_Send_Server_ListView->Items->Insert(0, items);
		}
		// Increment the counter of the lines to store the nexts lines into program and process
		lines++;
	}
	// Close the files
	file.close();
	// The list view containts all the post just sent hide from users and also the lable for it
	Listview_topic->Visible = false;
	label5->Visible = false;
	// Show the list view of history post that be stored in the files by the server to track
	label4->Visible = true;
	Items_Send_Server_ListView->Visible = true;
}
private: System::Void Post_Send_Currently_Session_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Hide the History listview of the post that be store in the file and also its label
	Items_Send_Server_ListView->Visible = false;
	label4->Visible = false;
	// Show the Content of the listview that store the items that be sent in currently session
	label5->Visible = true;
	Listview_topic->Visible = true;

}
};
}

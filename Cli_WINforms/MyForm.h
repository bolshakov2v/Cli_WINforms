#pragma once
#define WIN32_LEAN_AND_MEAN
#include<string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "7770"


namespace Cli_WINforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	


	SOCKET ConnectSocket = INVALID_SOCKET;
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			richTextBox1->Enabled = 0;
			richTextBox2->Enabled = 1;
			button1->Enabled = 0;
			
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::Label^  label5;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 551);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите сообщение";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(18, 575);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(754, 104);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(18, 172);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(952, 356);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(786, 591);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(186, 91);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Отправить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(18, 117);
			this->richTextBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(316, 33);
			this->richTextBox3->TabIndex = 4;
			this->richTextBox3->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(688, 98);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 65);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Войти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 88);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введите ник";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(22, 20);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(261, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Добро пожаловать в онлайн чат!";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(640, 60);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 20);
			this->label4->TabIndex = 8;
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(345, 117);
			this->richTextBox4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(316, 33);
			this->richTextBox4->TabIndex = 9;
			this->richTextBox4->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(340, 88);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(119, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Введите ключ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 700);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"Bolshakov\'s сообщения";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}		 
		 
		 String^ name = "5";


		 void recvmes() {
			 char buffer[1024];
			 for (int i = 0; i < 1024; i++) {
				 buffer[i] = 0;
			 }
			 for (int k = 0; k < 1; k++) {
				 recv(ConnectSocket, buffer, 1024, 0);
				 String^ recvm = "";
				 for (int i = 0; i < 1024; i++) {
					 if (buffer[i] != Convert::ToChar(3)) recvm += Convert::ToChar(buffer[i]);
					 else break;
				 }
				 if (recvm != "") richTextBox2->AppendText(recvm);
			 }
		 }
public: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		WSADATA wsaData;
		//SOCKET ConnectSocket = INVALID_SOCKET;
		struct addrinfo *result = NULL, *ptr = NULL, hints;
		char *sendbuf = "123456";
		char recvbuf[DEFAULT_BUFLEN];
		int iResult;
		int recvbuflen = DEFAULT_BUFLEN;

		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);

		for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
			ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

			iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ConnectSocket);
				ConnectSocket = INVALID_SOCKET;
				continue;
			}
			break;
		}
		
		freeaddrinfo(result);
		name = richTextBox3->Text;
		richTextBox3->Text = "";
		richTextBox3->Enabled = 0;
		char buffer[10];
		for (int i = 0; i < 11; i++) {
			buffer[i] = 0;
		}
		recv(ConnectSocket, buffer, 10, 0);
		String^ s = "";
		for (int i = 0; i < 10; i++) {
			s += Convert::ToChar(buffer[i]);
		}
		richTextBox2->AppendText(s);
		richTextBox2->AppendText("\n");
		button2->Enabled = 0;
		button1->Enabled = 1;
		richTextBox1->Enabled = 1;
		char b[1024];
		String^ key = "";
		key += richTextBox4->Text;
		richTextBox4->Text = "";
		richTextBox4->Enabled = 0;
		
		for (int i = 0; i < 1024; i++) {
			b[i] = 0;
		}
		for (int i = 0; i < key->Length; i++) {
			b[i] = key[i];
		}
		send(ConnectSocket, b, 1024, 0);
		richTextBox2->AppendText("key check...\n");
		for (int i = 0; i < 1024; i++) b[i] = 0;
		recv(ConnectSocket, b, 1024, 0);
		s = "";
		for (int i = 0; i < 11; i++) {
			s += Convert::ToChar(b[i]);
		}
		richTextBox2->AppendText(s);	
}

public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ mes = name+": ";
	mes += richTextBox1->Text;
	mes += Convert::ToChar('\n');
	richTextBox1->Text = "";
	char buf[1024];
	for (int i = 0; i < 1024; i++) {
		buf[i] = 0;
	}
	for (int i = 0; i < mes->Length; i++) {
		buf[i] = mes[i];
	}
	send(ConnectSocket, buf, 1024, 0);
	recvmes();
	
}
public: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
	
}

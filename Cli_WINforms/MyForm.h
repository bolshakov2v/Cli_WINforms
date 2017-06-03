#pragma once
#define WIN32_LEAN_AND_MEAN
#include<string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <WinBase.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 1024




namespace Cli_WINforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	

	SOCKET ConnectSocket = INVALID_SOCKET;

	char port[] = "631";

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
		String^ name = "";
			
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
	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::Label^  label6;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
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
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 358);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите сообщение";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 374);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(384, 69);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(12, 112);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(504, 233);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(413, 384);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 59);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Отправить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(12, 76);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(127, 23);
			this->richTextBox3->TabIndex = 4;
			this->richTextBox3->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(413, 64);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 42);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Войти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введите ник";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(15, 13);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(174, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Добро пожаловать в онлайн чат!";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(427, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 8;
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(143, 76);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(125, 23);
			this->richTextBox4->TabIndex = 9;
			this->richTextBox4->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(140, 57);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Введите ключ";
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(272, 76);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(125, 23);
			this->richTextBox5->TabIndex = 11;
			this->richTextBox5->Text = L"";
			this->richTextBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox5_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(269, 57);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(127, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Введите адрес сервера";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 455);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->richTextBox5);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bolshakov\'s сообщения";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}		 
System::Void rss() {
			 for (;; Sleep(75)) {
				 checkDebug();
				 char buffer[1024];
				 for (int i = 0; i < 1024; i++) buffer[i] = 0;

				 recv(ConnectSocket, buffer, 1024, 0);
				 String^ recvm = "";
				 for (int i = 0; i < 1024; i++) recvm += Convert::ToChar(buffer[i]);
				 richTextBox2->Invoke(gcnew Action<String^>(this, &MyForm::recvmes), recvm);
			 }
		 }
System::Void recvmes(String^ recvm) {

			 richTextBox2->AppendText(recvm);
		 }
ThreadStart^ threadDelegate = gcnew ThreadStart(this, &MyForm::rss);
Thread^ newThread = gcnew Thread(threadDelegate);

System::Void checkDebug() {
	if (IsDebuggerPresent()) {
		Application::Exit();
	}
}
public: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	checkDebug();
	if (richTextBox3->Text == "" || richTextBox4->Text == "" || richTextBox5->Text == "") {
		richTextBox2->AppendText("Введенные данные не верны!\n");
	}
	else {
		String^ ip = richTextBox5->Text;
		char dd[100];
		for (int i = 0; i < 100; i++) dd[i] = 0;
		for (int i = 0; i < ip->Length; i++) dd[i] = ip[i];
		richTextBox5->Text = "";
		richTextBox5->Enabled = 0;

		WSADATA wsaData;
		struct addrinfo *result = NULL, *ptr = NULL, hints;
		int iResult;

		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		iResult = getaddrinfo(dd, port, &hints, &result);

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


		name = richTextBox3->Text;//получение ника
		richTextBox3->Text = "";
		richTextBox3->Enabled = 0;


		char buffer[1024];
		for (int i = 0; i < 11; i++) buffer[i] = 0;

		recv(ConnectSocket, buffer, 10, 0);

		String^ s = "";
		for (int i = 0; i < 10; i++) s += Convert::ToChar(buffer[i]);
		richTextBox2->AppendText(s + "\n"); //message connecting...

		button2->Enabled = 0;
		button1->Enabled = 1;
		richTextBox1->Enabled = 1;

		String^ key = "";
		key += richTextBox4->Text;
		richTextBox4->Text = "";
		richTextBox4->Enabled = 0; //get key

		for (int i = 0; i < 1024; i++) buffer[i] = 0;

		for (int i = 0; i < key->Length; i++) buffer[i] = key[i];
		send(ConnectSocket, buffer, 1024, 0); //send key to check

		for (int i = 0; i < 1024; i++) buffer[i] = 0;
		recv(ConnectSocket, buffer, 1024, 0);
		s = "";
		for (int i = 0; i < 11; i++) s += Convert::ToChar(buffer[i]);//get result check key

		if (s == "wrong  key ") {
			richTextBox1->Enabled = 0;
			button1->Enabled = 0;
			richTextBox2->AppendText(s + Convert::ToChar("\n"));
			richTextBox2->AppendText("Please restart chat");
		}
		else richTextBox2->AppendText(s + Convert::ToChar("\n"));


		newThread->Start();
	}
}
		DateTime tdnow = DateTime::Now;
public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ time = Convert::ToString(tdnow.Now.Hour + ":" + tdnow.Now.Minute + ":" + tdnow.Now.Second + "  ");
	String^ send_mes = time + name + ": ";

	if ((richTextBox1->Text) != "") {
		send_mes += richTextBox1->Text;
		send_mes += "\n";
		richTextBox1->Text = "";

		char buffer[1024];
		for (int i = 0; i < 1024; i++) buffer[i] = 0;

		for (int i = 0; i < send_mes->Length; i++) buffer[i] = send_mes[i];
		send(ConnectSocket, buffer, 1024, 0);
	
	}
	else richTextBox2->AppendText("You can't send blank message\n");
	
}
public: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void richTextBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}

};
	
}

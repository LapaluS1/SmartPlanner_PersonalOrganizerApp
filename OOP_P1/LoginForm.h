#pragma once
#include"DatabaseHelper.h"
#include"SignupForm.h"
#include"Dashboard.h"

namespace OOPP1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btlogin;
	private: System::Windows::Forms::Button^ btcancel;

	private: System::Windows::Forms::TextBox^ tbname;
	private: System::Windows::Forms::TextBox^ tbpwd;
	private: System::Windows::Forms::LinkLabel^ linksignup;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btlogin = (gcnew System::Windows::Forms::Button());
			this->btcancel = (gcnew System::Windows::Forms::Button());
			this->tbname = (gcnew System::Windows::Forms::TextBox());
			this->tbpwd = (gcnew System::Windows::Forms::TextBox());
			this->linksignup = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(657, -94);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(867, 904);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(117, 245);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(409, 108);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// btlogin
			// 
			this->btlogin->Location = System::Drawing::Point(147, 401);
			this->btlogin->Name = L"btlogin";
			this->btlogin->Size = System::Drawing::Size(115, 40);
			this->btlogin->TabIndex = 2;
			this->btlogin->Text = L"LOGIN";
			this->btlogin->UseVisualStyleBackColor = true;
			this->btlogin->Click += gcnew System::EventHandler(this, &LoginForm::btlogin_Click);
			// 
			// btcancel
			// 
			this->btcancel->Location = System::Drawing::Point(333, 401);
			this->btcancel->Name = L"btcancel";
			this->btcancel->Size = System::Drawing::Size(121, 40);
			this->btcancel->TabIndex = 3;
			this->btcancel->Text = L"CANCEL";
			this->btcancel->UseVisualStyleBackColor = true;
			this->btcancel->Click += gcnew System::EventHandler(this, &LoginForm::btcancel_Click);
			// 
			// tbname
			// 
			this->tbname->Location = System::Drawing::Point(182, 255);
			this->tbname->Name = L"tbname";
			this->tbname->Size = System::Drawing::Size(297, 22);
			this->tbname->TabIndex = 5;
			// 
			// tbpwd
			// 
			this->tbpwd->Location = System::Drawing::Point(182, 323);
			this->tbpwd->Name = L"tbpwd";
			this->tbpwd->PasswordChar = '*';
			this->tbpwd->Size = System::Drawing::Size(297, 22);
			this->tbpwd->TabIndex = 6;
			// 
			// linksignup
			// 
			this->linksignup->AutoSize = true;
			this->linksignup->Location = System::Drawing::Point(144, 491);
			this->linksignup->Name = L"linksignup";
			this->linksignup->Size = System::Drawing::Size(47, 16);
			this->linksignup->TabIndex = 7;
			this->linksignup->TabStop = true;
			this->linksignup->Text = L"signup";
			this->linksignup->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linksignup_LinkClicked_1);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->linksignup);
			this->Controls->Add(this->tbpwd);
			this->Controls->Add(this->tbname);
			this->Controls->Add(this->btcancel);
			this->Controls->Add(this->btlogin);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->Text = L"SmartPlanner";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btcancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btlogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->tbname->Text;
		String^ password = this->tbpwd->Text;

		if (String::IsNullOrWhiteSpace(username) || String::IsNullOrWhiteSpace(password))
		{
			MessageBox::Show("Please enter both username and password.");
			return;
		}

		// Call CheckLogin to verify credentials
		if (CheckLogin(username, password))
		{
			
			// Code to open the main form or next form goes here
			Dashboard^ dashboard = gcnew Dashboard();
			this->Hide();
			dashboard->ShowDialog(); // Show signup form
			this->Show();
		}
		else
		{
			MessageBox::Show("Invalid Username or Password.");
		}
	}

		   bool CheckLogin(String^ username, String^ password)
		   {
			   // Use DatabaseHelper to check credentials
			   return DatabaseHelper::CheckCredentials(username, password);
		   }
	

private: System::Void linksignup_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	SignupForm^ signupForm = gcnew SignupForm();
	this->Hide();
	signupForm->ShowDialog(); // Show signup form
	this->Show();
}
private: System::Void linksignup_LinkClicked_1(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	SignupForm^ signupForm = gcnew SignupForm();
	this->Hide();
	signupForm->ShowDialog(); // Show signup form
	this->Show();
}
};
}

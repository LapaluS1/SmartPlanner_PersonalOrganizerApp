#pragma once
#include"DatabaseHelper.h"
#include"SignupForm.h"
#include"Dashboard.h"
#include"termsForm.h"

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
			this->richTextBox2->SelectionAlignment = System::Windows::Forms::HorizontalAlignment::Center;
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


	private: System::Windows::Forms::TextBox^ tbname;
	private: System::Windows::Forms::TextBox^ tbpwd;
	private: System::Windows::Forms::LinkLabel^ linksignup;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ chkAgreeTerms;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;

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
			this->tbname = (gcnew System::Windows::Forms::TextBox());
			this->tbpwd = (gcnew System::Windows::Forms::TextBox());
			this->linksignup = (gcnew System::Windows::Forms::LinkLabel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chkAgreeTerms = (gcnew System::Windows::Forms::CheckBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(793, -19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(631, 741);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(172, 313);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(431, 139);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// btlogin
			// 
			this->btlogin->BackColor = System::Drawing::Color::DodgerBlue;
			this->btlogin->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btlogin->ForeColor = System::Drawing::Color::White;
			this->btlogin->Location = System::Drawing::Point(172, 539);
			this->btlogin->Name = L"btlogin";
			this->btlogin->Size = System::Drawing::Size(431, 40);
			this->btlogin->TabIndex = 2;
			this->btlogin->Text = L"LOGIN";
			this->btlogin->UseVisualStyleBackColor = false;
			this->btlogin->Click += gcnew System::EventHandler(this, &LoginForm::btlogin_Click);
			// 
			// tbname
			// 
			this->tbname->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbname->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbname->ForeColor = System::Drawing::Color::Black;
			this->tbname->Location = System::Drawing::Point(212, 329);
			this->tbname->Name = L"tbname";
			this->tbname->Size = System::Drawing::Size(372, 22);
			this->tbname->TabIndex = 5;
			// 
			// tbpwd
			// 
			this->tbpwd->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbpwd->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbpwd->Location = System::Drawing::Point(213, 411);
			this->tbpwd->Name = L"tbpwd";
			this->tbpwd->PasswordChar = '*';
			this->tbpwd->Size = System::Drawing::Size(372, 22);
			this->tbpwd->TabIndex = 6;
			// 
			// linksignup
			// 
			this->linksignup->AutoSize = true;
			this->linksignup->Font = (gcnew System::Drawing::Font(L"PT Sans", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linksignup->Location = System::Drawing::Point(439, 642);
			this->linksignup->Name = L"linksignup";
			this->linksignup->Size = System::Drawing::Size(51, 19);
			this->linksignup->TabIndex = 7;
			this->linksignup->TabStop = true;
			this->linksignup->Text = L"signup";
			this->linksignup->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linksignup_LinkClicked_1);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(260, 70);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(232, 43);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(190, 163);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(388, 43);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Welcome to SmartPlanner";
			// 
			// chkAgreeTerms
			// 
			this->chkAgreeTerms->AutoSize = true;
			this->chkAgreeTerms->Location = System::Drawing::Point(174, 484);
			this->chkAgreeTerms->Name = L"chkAgreeTerms";
			this->chkAgreeTerms->Size = System::Drawing::Size(18, 17);
			this->chkAgreeTerms->TabIndex = 10;
			this->chkAgreeTerms->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(200, 483);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(372, 37);
			this->richTextBox1->TabIndex = 11;
			this->richTextBox1->Text = L"You must agree to the Terms and Conditions to log in. Please check the box to pro"
				L"ceed.";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(197, 209);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(372, 37);
			this->richTextBox2->TabIndex = 12;
			this->richTextBox2->Text = L"Please log in to access your personal organizer, manage finances, academic schedu"
				L"le, and more.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"PT Sans Caption", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(172, 291);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 19);
			this->label2->TabIndex = 13;
			this->label2->Text = L"User Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"PT Sans Caption", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(172, 381);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 19);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"PT Sans", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(276, 642);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(157, 19);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Are you new member \?";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(282, 500);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(121, 17);
			this->linkLabel1->TabIndex = 16;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Terms and Conditions";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel1_LinkClicked);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->chkAgreeTerms);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->linksignup);
			this->Controls->Add(this->tbpwd);
			this->Controls->Add(this->tbname);
			this->Controls->Add(this->btlogin);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->Text = L"SmartPlanner";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btcancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btlogin_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!chkAgreeTerms->Checked) {
			MessageBox::Show("You must agree to the Terms and Conditions to log in. Please check the box to proceed.");
			return; // Prevent login if checkbox is unchecked
		}

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
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	termsForm^ TermsForm = gcnew termsForm();
	this->Hide();
	TermsForm->ShowDialog(); // Show signup form
	this->Show();
}
};
}

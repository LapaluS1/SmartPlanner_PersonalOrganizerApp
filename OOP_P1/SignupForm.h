#pragma once
#include"DatabaseHelper.h"
namespace OOPP1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SignupForm
	/// </summary>
	public ref class SignupForm : public System::Windows::Forms::Form
	{
	public:
		SignupForm(void)
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
		~SignupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ tbname;
	private: System::Windows::Forms::TextBox^ tbmail;
	private: System::Windows::Forms::TextBox^ tbpwd;
	private: System::Windows::Forms::Button^ btsignup;

	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::LinkLabel^ linksignup;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignupForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->tbname = (gcnew System::Windows::Forms::TextBox());
			this->tbmail = (gcnew System::Windows::Forms::TextBox());
			this->tbpwd = (gcnew System::Windows::Forms::TextBox());
			this->btsignup = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->linksignup = (gcnew System::Windows::Forms::LinkLabel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(37, -19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(631, 741);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(890, 293);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(431, 219);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// tbname
			// 
			this->tbname->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbname->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F));
			this->tbname->Location = System::Drawing::Point(931, 311);
			this->tbname->Name = L"tbname";
			this->tbname->Size = System::Drawing::Size(349, 22);
			this->tbname->TabIndex = 2;
			// 
			// tbmail
			// 
			this->tbmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbmail->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F));
			this->tbmail->Location = System::Drawing::Point(931, 394);
			this->tbmail->Name = L"tbmail";
			this->tbmail->Size = System::Drawing::Size(371, 22);
			this->tbmail->TabIndex = 3;
			// 
			// tbpwd
			// 
			this->tbpwd->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbpwd->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F));
			this->tbpwd->Location = System::Drawing::Point(931, 470);
			this->tbpwd->Name = L"tbpwd";
			this->tbpwd->PasswordChar = '*';
			this->tbpwd->Size = System::Drawing::Size(372, 22);
			this->tbpwd->TabIndex = 4;
			// 
			// btsignup
			// 
			this->btsignup->BackColor = System::Drawing::Color::DodgerBlue;
			this->btsignup->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->btsignup->ForeColor = System::Drawing::Color::White;
			this->btsignup->Location = System::Drawing::Point(890, 578);
			this->btsignup->Name = L"btsignup";
			this->btsignup->Size = System::Drawing::Size(431, 39);
			this->btsignup->TabIndex = 5;
			this->btsignup->Text = L"SIGNUP";
			this->btsignup->UseVisualStyleBackColor = false;
			this->btsignup->Click += gcnew System::EventHandler(this, &SignupForm::btsignup_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(913, 207);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(372, 37);
			this->richTextBox2->TabIndex = 15;
			this->richTextBox2->Text = L"Please log in to access your personal organizer, manage finances, academic schedu"
				L"le, and more.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(906, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(388, 43);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Welcome to SmartPlanner";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(970, 66);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(232, 43);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 13;
			this->pictureBox3->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"PT Sans", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(985, 659);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(186, 19);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Are you already a member \?";
			// 
			// linksignup
			// 
			this->linksignup->AutoSize = true;
			this->linksignup->Font = (gcnew System::Drawing::Font(L"PT Sans", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linksignup->Location = System::Drawing::Point(1172, 659);
			this->linksignup->Name = L"linksignup";
			this->linksignup->Size = System::Drawing::Size(45, 19);
			this->linksignup->TabIndex = 16;
			this->linksignup->TabStop = true;
			this->linksignup->Text = L"Login";
			this->linksignup->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignupForm::linksignup_LinkClicked);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"PT Sans Caption", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(886, 442);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 19);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"PT Sans Caption", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(886, 272);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 19);
			this->label3->TabIndex = 19;
			this->label3->Text = L"User Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"PT Sans Caption", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(886, 358);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 19);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Email";
			// 
			// SignupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->linksignup);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->btsignup);
			this->Controls->Add(this->tbpwd);
			this->Controls->Add(this->tbmail);
			this->Controls->Add(this->tbname);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SignupForm";
			this->Text = L"SmartPlanner";
			this->Load += gcnew System::EventHandler(this, &SignupForm::SignupForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btclose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void SignupForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btsignup_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ username = this->tbname->Text->Trim();
	String^ password = this->tbpwd->Text->Trim();
	String^ email = this->tbmail->Text->Trim();

	if (String::IsNullOrWhiteSpace(username) || String::IsNullOrWhiteSpace(email) || String::IsNullOrWhiteSpace(password))
	{
		MessageBox::Show("Please enter username, email, and password.");
		return;
	}

	// Assuming DatabaseHelper::AddUser has been updated to include the email parameter
	if (DatabaseHelper::AddUser(username, email, password)) {
		MessageBox::Show("Sign up successful!");
		this->Close();
	}
	else {
		MessageBox::Show("Sign up failed. Please try again.");
	}
}

private: System::Void linksignup_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->Close();
}
};
}

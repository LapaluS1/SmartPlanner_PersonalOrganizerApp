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
	private: System::Windows::Forms::Button^ btclose;

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
			this->btclose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-27, -45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(664, 752);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(943, 213);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(352, 186);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// tbname
			// 
			this->tbname->Location = System::Drawing::Point(973, 227);
			this->tbname->Name = L"tbname";
			this->tbname->Size = System::Drawing::Size(306, 22);
			this->tbname->TabIndex = 2;
			// 
			// tbmail
			// 
			this->tbmail->Location = System::Drawing::Point(973, 299);
			this->tbmail->Name = L"tbmail";
			this->tbmail->Size = System::Drawing::Size(306, 22);
			this->tbmail->TabIndex = 3;
			// 
			// tbpwd
			// 
			this->tbpwd->Location = System::Drawing::Point(973, 365);
			this->tbpwd->Name = L"tbpwd";
			this->tbpwd->PasswordChar = '*';
			this->tbpwd->Size = System::Drawing::Size(306, 22);
			this->tbpwd->TabIndex = 4;
			// 
			// btsignup
			// 
			this->btsignup->Location = System::Drawing::Point(943, 471);
			this->btsignup->Name = L"btsignup";
			this->btsignup->Size = System::Drawing::Size(131, 40);
			this->btsignup->TabIndex = 5;
			this->btsignup->Text = L"SIGNUP";
			this->btsignup->UseVisualStyleBackColor = true;
			this->btsignup->Click += gcnew System::EventHandler(this, &SignupForm::btsignup_Click);
			// 
			// btclose
			// 
			this->btclose->Location = System::Drawing::Point(1167, 471);
			this->btclose->Name = L"btclose";
			this->btclose->Size = System::Drawing::Size(100, 31);
			this->btclose->TabIndex = 6;
			this->btclose->Text = L"LOGIN";
			this->btclose->UseVisualStyleBackColor = true;
			this->btclose->Click += gcnew System::EventHandler(this, &SignupForm::btclose_Click);
			// 
			// SignupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->btclose);
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

};
}

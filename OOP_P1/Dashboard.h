#pragma once
#include"IncomeExpensesForm.h"
#include"FinancialReportForm.h"
#include"AcadamicScheduler.h"
#include"BudgetingForm.h"
namespace OOPP1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			this->StartPosition = FormStartPosition::CenterScreen;

			this->notificationTimer = gcnew System::Windows::Forms::Timer();
			this->notificationTimer->Interval = 1000; // 1 second interval for fading effect
			//this->notificationTimer->Tick += gcnew System::EventHandler(this, &Dashboard::notificationTimer_Tick);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ notificationTimer;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ d1;
	private: System::Windows::Forms::Button^ d3;
	protected:


	private: System::Windows::Forms::Button^ d2;
	private: System::Windows::Forms::Button^ d4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->d1 = (gcnew System::Windows::Forms::Button());
			this->d3 = (gcnew System::Windows::Forms::Button());
			this->d2 = (gcnew System::Windows::Forms::Button());
			this->d4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Location = System::Drawing::Point(457, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(547, 43);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to SmartPlanner Dashboard";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// d1
			// 
			this->d1->BackColor = System::Drawing::Color::Black;
			this->d1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d1.BackgroundImage")));
			this->d1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->d1->Location = System::Drawing::Point(82, 161);
			this->d1->Name = L"d1";
			this->d1->Size = System::Drawing::Size(323, 181);
			this->d1->TabIndex = 1;
			this->d1->UseVisualStyleBackColor = false;
			this->d1->Click += gcnew System::EventHandler(this, &Dashboard::d1_Click);
			// 
			// d3
			// 
			this->d3->BackColor = System::Drawing::Color::Black;
			this->d3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d3.BackgroundImage")));
			this->d3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->d3->Location = System::Drawing::Point(761, 161);
			this->d3->Name = L"d3";
			this->d3->Size = System::Drawing::Size(323, 181);
			this->d3->TabIndex = 2;
			this->d3->UseVisualStyleBackColor = false;
			this->d3->Click += gcnew System::EventHandler(this, &Dashboard::d3_Click);
			// 
			// d2
			// 
			this->d2->BackColor = System::Drawing::Color::Black;
			this->d2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d2.BackgroundImage")));
			this->d2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->d2->Location = System::Drawing::Point(427, 161);
			this->d2->Name = L"d2";
			this->d2->Size = System::Drawing::Size(323, 181);
			this->d2->TabIndex = 3;
			this->d2->UseVisualStyleBackColor = false;
			this->d2->Click += gcnew System::EventHandler(this, &Dashboard::d2_Click);
			// 
			// d4
			// 
			this->d4->BackColor = System::Drawing::Color::Black;
			this->d4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d4.BackgroundImage")));
			this->d4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->d4->Location = System::Drawing::Point(1093, 161);
			this->d4->Name = L"d4";
			this->d4->Size = System::Drawing::Size(323, 181);
			this->d4->TabIndex = 4;
			this->d4->UseVisualStyleBackColor = false;
			this->d4->Click += gcnew System::EventHandler(this, &Dashboard::d4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(152, 459);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1189, 151);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(654, 681);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(181, 50);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(158, 355);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Income and Expense Tracker";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(508, 355);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(157, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Category-Based Budgeting";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(877, 355);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Financial Reports";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(1199, 355);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Academic schedule";
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->d4);
			this->Controls->Add(this->d2);
			this->Controls->Add(this->d3);
			this->Controls->Add(this->d1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Dashboard";
			this->Text = L"SmartPlanner Dashboard";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	ShowAssignmentAlerts();
}

private: System::Void ShowAssignmentAlerts() {
	List<String^>^ assignments = DatabaseHelper::GetUpcomingAssignments();

	if (assignments->Count > 0) {
		
		String^ message = "Upcoming Assignment Deadlines (Next 3 Days):\n";
		for each (String ^ assignment in assignments) {
			message += assignment + "\n";
		}

		MessageBox::Show(message, "Assignment Deadline Alert", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else {
		MessageBox::Show("No assignments are due in the next 3 days.", "Assignment Deadline Alert", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void d1_Click(System::Object^ sender, System::EventArgs^ e) {
	IncomeExpensesForm^ incomeexpensesForm = gcnew IncomeExpensesForm();
	this->Hide();
	incomeexpensesForm->ShowDialog();
	this->Show();
}
private: System::Void d2_Click(System::Object^ sender, System::EventArgs^ e) {
	BudgetingForm^ budgetingForm = gcnew BudgetingForm();
	this->Hide();
	budgetingForm->ShowDialog();
	this->Show();
}
private: System::Void d3_Click(System::Object^ sender, System::EventArgs^ e) {
	FinancialReportForm^ financialReportForm = gcnew FinancialReportForm();
	this->Hide();
	financialReportForm->ShowDialog();
	this->Show();
}
private: System::Void d4_Click(System::Object^ sender, System::EventArgs^ e) {
	AcadamicScheduler^ acadamicScheduler = gcnew AcadamicScheduler();
	this->Hide();
	acadamicScheduler->ShowDialog();
	this->Show();
}
};
}

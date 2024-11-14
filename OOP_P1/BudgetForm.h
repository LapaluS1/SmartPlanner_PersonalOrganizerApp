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
	/// Summary for BudgetForm
	/// </summary>
	public ref class BudgetForm : public System::Windows::Forms::Form
	{
	public:
		BudgetForm(void)
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
		~BudgetForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ txtcategory;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ txtamount;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnSetBudget;
	private: System::Windows::Forms::Button^ btnclose;

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
			this->txtcategory = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtamount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnSetBudget = (gcnew System::Windows::Forms::Button());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtamount))->BeginInit();
			this->SuspendLayout();
			// 
			// txtcategory
			// 
			this->txtcategory->FormattingEnabled = true;
			this->txtcategory->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"food", L"entertainment", L"traveling", L"clothing",
					L"education equipment", L"university fee"
			});
			this->txtcategory->Location = System::Drawing::Point(361, 100);
			this->txtcategory->Name = L"txtcategory";
			this->txtcategory->Size = System::Drawing::Size(276, 24);
			this->txtcategory->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Category";
			// 
			// txtamount
			// 
			this->txtamount->Location = System::Drawing::Point(370, 184);
			this->txtamount->Name = L"txtamount";
			this->txtamount->Size = System::Drawing::Size(120, 22);
			this->txtamount->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(277, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"amount";
			// 
			// btnSetBudget
			// 
			this->btnSetBudget->Location = System::Drawing::Point(277, 275);
			this->btnSetBudget->Name = L"btnSetBudget";
			this->btnSetBudget->Size = System::Drawing::Size(75, 23);
			this->btnSetBudget->TabIndex = 4;
			this->btnSetBudget->Text = L"SetBudget";
			this->btnSetBudget->UseVisualStyleBackColor = true;
			this->btnSetBudget->Click += gcnew System::EventHandler(this, &BudgetForm::btnSetBudget_Click);
			// 
			// btnclose
			// 
			this->btnclose->Location = System::Drawing::Point(414, 274);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(75, 23);
			this->btnclose->TabIndex = 5;
			this->btnclose->Text = L"Exit";
			this->btnclose->UseVisualStyleBackColor = true;
			this->btnclose->Click += gcnew System::EventHandler(this, &BudgetForm::btnclose_Click);
			// 
			// BudgetForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->btnclose);
			this->Controls->Add(this->btnSetBudget);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtamount);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtcategory);
			this->Name = L"BudgetForm";
			this->Text = L"BudgetForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtamount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSetBudget_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Get the user input from the textboxes
			String^ category = txtcategory->Text; // Assuming a TextBox for category input
			double budgetAmount = Convert::ToDouble(txtamount->Text); // Assuming a TextBox for budget amount input

			// Validate the inputs
			if (budgetAmount <= 0) {
				MessageBox::Show("Please enter valid category, budget amount, and month-year.");
				return;
			}

			// Get the logged-in user's ID (from static variable or wherever you store it)
			int userID = DatabaseHelper::LoggedInUserID; // Replace with how you store the logged-in user ID

			if (userID == -1) {
				MessageBox::Show("User not logged in!");
				return;
			}

			// Create an instance of DatabaseHelper to call the non-static method
			DatabaseHelper^ dbHelper = gcnew DatabaseHelper();

			// Call the function to save the budget in the database
			dbHelper->setCategoryBudget(userID, category, budgetAmount);

			// Notify the user that the budget was set successfully
			MessageBox::Show("Budget set successfully!");
		}
		catch (Exception^ ex) {
			// Handle any errors (e.g., invalid input, database issues)
			MessageBox::Show("Error: " + ex->Message);
		}
	}
private: System::Void btnclose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

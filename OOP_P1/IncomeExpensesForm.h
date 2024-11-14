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
	/// Summary for IncomeExpensesForm
	/// </summary>
	public ref class IncomeExpensesForm : public System::Windows::Forms::Form
	{
	public:
		IncomeExpensesForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			this->StartPosition = FormStartPosition::CenterScreen;
			dbHelper = gcnew DatabaseHelper();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IncomeExpensesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		DatabaseHelper^ dbHelper;
	private: System::Windows::Forms::ComboBox^ selectIE;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ category;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ source;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ description;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ amount;

	private: System::Windows::Forms::Button^ back;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ reset;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(IncomeExpensesForm::typeid));
			this->selectIE = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->category = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->source = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->description = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->amount = (gcnew System::Windows::Forms::NumericUpDown());
			this->back = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->reset = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount))->BeginInit();
			this->SuspendLayout();
			// 
			// selectIE
			// 
			this->selectIE->FormattingEnabled = true;
			this->selectIE->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Income", L"Expenses" });
			this->selectIE->Location = System::Drawing::Point(352, 77);
			this->selectIE->Name = L"selectIE";
			this->selectIE->Size = System::Drawing::Size(121, 24);
			this->selectIE->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(205, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"income/expenses";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(352, 141);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(208, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"date";
			// 
			// category
			// 
			this->category->FormattingEnabled = true;
			this->category->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"food", L"entertainment", L"traveling", L"clothing",
					L"educationEquipment", L"universityFees", L"others"
			});
			this->category->Location = System::Drawing::Point(352, 203);
			this->category->Name = L"category";
			this->category->Size = System::Drawing::Size(171, 24);
			this->category->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(208, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"category";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(208, 267);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"source";
			// 
			// source
			// 
			this->source->FormattingEnabled = true;
			this->source->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"job", L"allowance from parents", L"scholarships",
					L"student aid"
			});
			this->source->Location = System::Drawing::Point(352, 260);
			this->source->Name = L"source";
			this->source->Size = System::Drawing::Size(171, 24);
			this->source->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(211, 324);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Description";
			// 
			// description
			// 
			this->description->Location = System::Drawing::Point(352, 324);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(334, 22);
			this->description->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(208, 382);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 16);
			this->label6->TabIndex = 10;
			this->label6->Text = L"amount";
			// 
			// amount
			// 
			this->amount->Location = System::Drawing::Point(352, 382);
			this->amount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->amount->Name = L"amount";
			this->amount->Size = System::Drawing::Size(120, 22);
			this->amount->TabIndex = 11;
			// 
			// back
			// 
			this->back->Location = System::Drawing::Point(339, 447);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(75, 23);
			this->back->TabIndex = 13;
			this->back->Text = L"Back";
			this->back->UseVisualStyleBackColor = true;
			this->back->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::back_Click);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(183, 447);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(75, 23);
			this->Add->TabIndex = 14;
			this->Add->Text = L"Add";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::Add_Click);
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(519, 446);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(133, 23);
			this->reset->TabIndex = 15;
			this->reset->Text = L"NewMonth";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::reset_Click);
			// 
			// IncomeExpensesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->back);
			this->Controls->Add(this->amount);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->description);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->source);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->category);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selectIE);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"IncomeExpensesForm";
			this->Text = L"SmartPlanner Income-Expenses Tracker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void ResetDatabase() {
			try {
				// Call the method to delete all data from the relevant tables in the database
				dbHelper->DeleteAllData();  // No need to check for return value, as DeleteAllData already handles this

				// The success message is shown in DeleteAllData, so we don't need to display it here.
			}
			catch (Exception^ ex) {
				// Handle any unexpected exceptions
				MessageBox::Show("An unexpected error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}


	
private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {
	// Retrieve data from the form controls
	String^ incomeExpense = selectIE->Text;  // Income or Expenses
	DateTime selectedDate = dateTimePicker1->Value;  // Selected date
	String^ selectedCategory = category->Text;  // Selected category
	String^ selectedSource = source->Text;  // Selected source
	String^ descriptionText = description->Text;  // Description
	Decimal amountValue = amount->Value;  // Amount

	// Create a new instance of DatabaseHelper
	DatabaseHelper^ dbHelper = gcnew DatabaseHelper();

	// Check if all necessary fields are filled
	if (incomeExpense == "" || amountValue <= 0) {
		MessageBox::Show("Please fill in all fields correctly.");
		return;
	}

	// For "Income", allow category to be null
	if (incomeExpense == "Income" && selectedCategory == "") {
		selectedCategory = nullptr;  // Allow category to be null for income
	}

	// Convert the DateTime to a string for SQL insertion (if needed)
	String^ dateString = selectedDate.ToString("yyyy-MM-dd");

	// Call the addIncomeExpense method from DatabaseHelper class
	bool success = dbHelper->addIncomeExpense(incomeExpense, dateString, selectedCategory, selectedSource, descriptionText, amountValue);

	// Provide feedback to the user based on success/failure
	if (success) {
		MessageBox::Show("Income/Expense added successfully!");
	}
	else {
		MessageBox::Show("Failed to add Income/Expense.");
	}
}
private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
	ResetDatabase();
}
};
}

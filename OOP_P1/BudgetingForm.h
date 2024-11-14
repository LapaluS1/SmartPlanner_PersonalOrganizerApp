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
	/// Summary for BudgetingForm
	/// </summary>
	
	public ref class BudgetingForm : public System::Windows::Forms::Form
	{
	public:
		BudgetingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			dbHelper = gcnew DatabaseHelper();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BudgetingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		DatabaseHelper^ dbHelper;
	private: System::Windows::Forms::ComboBox^ category;
	protected:
	private: System::Windows::Forms::NumericUpDown^ budgetamount;
	private: System::Windows::Forms::Button^ setbudget;
	private: System::Windows::Forms::Button^ back;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ spentAmountLabel;
	private: System::Windows::Forms::Label^ remainingAmountLabel;

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
			this->category = (gcnew System::Windows::Forms::ComboBox());
			this->budgetamount = (gcnew System::Windows::Forms::NumericUpDown());
			this->setbudget = (gcnew System::Windows::Forms::Button());
			this->back = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->spentAmountLabel = (gcnew System::Windows::Forms::Label());
			this->remainingAmountLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->budgetamount))->BeginInit();
			this->SuspendLayout();
			// 
			// category
			// 
			this->category->FormattingEnabled = true;
			this->category->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"food", L"entertainment", L"traveling", L"clothing",
					L"educationEquipment", L"universityFees"
			});
			this->category->Location = System::Drawing::Point(440, 73);
			this->category->Name = L"category";
			this->category->Size = System::Drawing::Size(259, 24);
			this->category->TabIndex = 0;
			// 
			// budgetamount
			// 
			this->budgetamount->Location = System::Drawing::Point(440, 130);
			this->budgetamount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			this->budgetamount->Name = L"budgetamount";
			this->budgetamount->Size = System::Drawing::Size(227, 22);
			this->budgetamount->TabIndex = 1;
			// 
			// setbudget
			// 
			this->setbudget->Location = System::Drawing::Point(337, 237);
			this->setbudget->Name = L"setbudget";
			this->setbudget->Size = System::Drawing::Size(106, 41);
			this->setbudget->TabIndex = 2;
			this->setbudget->Text = L"SetBudget";
			this->setbudget->UseVisualStyleBackColor = true;
			this->setbudget->Click += gcnew System::EventHandler(this, &BudgetingForm::setbudget_Click);
			// 
			// back
			// 
			this->back->Location = System::Drawing::Point(848, 237);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(75, 23);
			this->back->TabIndex = 3;
			this->back->Text = L"Back";
			this->back->UseVisualStyleBackColor = true;
			this->back->Click += gcnew System::EventHandler(this, &BudgetingForm::back_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(304, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"category";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(307, 144);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"amount";
			// 
			// spentAmountLabel
			// 
			this->spentAmountLabel->AutoSize = true;
			this->spentAmountLabel->Location = System::Drawing::Point(285, 367);
			this->spentAmountLabel->Name = L"spentAmountLabel";
			this->spentAmountLabel->Size = System::Drawing::Size(0, 16);
			this->spentAmountLabel->TabIndex = 6;
			// 
			// remainingAmountLabel
			// 
			this->remainingAmountLabel->AutoSize = true;
			this->remainingAmountLabel->Location = System::Drawing::Point(524, 367);
			this->remainingAmountLabel->Name = L"remainingAmountLabel";
			this->remainingAmountLabel->Size = System::Drawing::Size(0, 16);
			this->remainingAmountLabel->TabIndex = 7;
			// 
			// BudgetingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->remainingAmountLabel);
			this->Controls->Add(this->spentAmountLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->back);
			this->Controls->Add(this->setbudget);
			this->Controls->Add(this->budgetamount);
			this->Controls->Add(this->category);
			this->Name = L"BudgetingForm";
			this->Text = L"BudgetingForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->budgetamount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void setbudget_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ selectedCategory = category->Text;
	Decimal budgetLimit = budgetamount->Value;

	if (dbHelper->setCategoryBudget(selectedCategory, budgetLimit)) {
		MessageBox::Show("Budget set successfully!");
	}
	else {
		MessageBox::Show("Failed to set budget.");
	}
}

private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
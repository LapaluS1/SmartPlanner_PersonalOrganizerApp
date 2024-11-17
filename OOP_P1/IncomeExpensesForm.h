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
		void LoadIncomeExpenseData()
		{
			// Fetch income and expense data from the database
			DataTable^ incomeData = dbHelper->GetIncomeData();
			DataTable^ expenseData = dbHelper->GetExpenseData();

			// Bind data to the DataGridViews
			dgvIncome->DataSource = incomeData;
			dgvexpenses->DataSource = expenseData;
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


	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ reset;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ dgvIncome;
	private: System::Windows::Forms::DataGridView^ dgvexpenses;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ ViewData;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;


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
			this->Add = (gcnew System::Windows::Forms::Button());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dgvIncome = (gcnew System::Windows::Forms::DataGridView());
			this->dgvexpenses = (gcnew System::Windows::Forms::DataGridView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->ViewData = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvIncome))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvexpenses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// selectIE
			// 
			this->selectIE->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selectIE->FormattingEnabled = true;
			this->selectIE->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Income", L"Expenses" });
			this->selectIE->Location = System::Drawing::Point(49, 187);
			this->selectIE->Name = L"selectIE";
			this->selectIE->Size = System::Drawing::Size(121, 30);
			this->selectIE->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::DodgerBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(45, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Income/expenses";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Location = System::Drawing::Point(201, 187);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(262, 29);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DodgerBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(197, 156);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Date";
			// 
			// category
			// 
			this->category->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->category->FormattingEnabled = true;
			this->category->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"food", L"entertainment", L"traveling", L"clothing",
					L"educationEquipment", L"universityFees", L"others"
			});
			this->category->Location = System::Drawing::Point(491, 188);
			this->category->Name = L"category";
			this->category->Size = System::Drawing::Size(171, 30);
			this->category->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DodgerBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(487, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 22);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Category";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::DodgerBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(705, 156);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 22);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Source";
			// 
			// source
			// 
			this->source->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->source->FormattingEnabled = true;
			this->source->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"job", L"allowance from parents", L"scholarships",
					L"student aid"
			});
			this->source->Location = System::Drawing::Point(709, 187);
			this->source->Name = L"source";
			this->source->Size = System::Drawing::Size(171, 30);
			this->source->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::DodgerBlue;
			this->label5->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(922, 156);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 22);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Description";
			// 
			// description
			// 
			this->description->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->description->Location = System::Drawing::Point(926, 187);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(214, 29);
			this->description->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::DodgerBlue;
			this->label6->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(1184, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 22);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Amount";
			// 
			// amount
			// 
			this->amount->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->amount->Location = System::Drawing::Point(1188, 187);
			this->amount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->amount->Name = L"amount";
			this->amount->Size = System::Drawing::Size(120, 29);
			this->amount->TabIndex = 11;
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::Black;
			this->Add->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Add->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add->ForeColor = System::Drawing::Color::White;
			this->Add->Location = System::Drawing::Point(1355, 178);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(102, 37);
			this->Add->TabIndex = 14;
			this->Add->Text = L"Add";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::Add_Click);
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(1291, 22);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(154, 23);
			this->reset->TabIndex = 15;
			this->reset->Text = L"Clean All Data";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::reset_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(520, 42);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(392, 43);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Income / Expenses Tracker";
			// 
			// dgvIncome
			// 
			this->dgvIncome->BackgroundColor = System::Drawing::Color::White;
			this->dgvIncome->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvIncome->GridColor = System::Drawing::Color::Black;
			this->dgvIncome->Location = System::Drawing::Point(80, 279);
			this->dgvIncome->Name = L"dgvIncome";
			this->dgvIncome->RowHeadersWidth = 51;
			this->dgvIncome->RowTemplate->Height = 24;
			this->dgvIncome->Size = System::Drawing::Size(1303, 166);
			this->dgvIncome->TabIndex = 17;
			// 
			// dgvexpenses
			// 
			this->dgvexpenses->BackgroundColor = System::Drawing::Color::White;
			this->dgvexpenses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvexpenses->GridColor = System::Drawing::Color::Black;
			this->dgvexpenses->Location = System::Drawing::Point(80, 492);
			this->dgvexpenses->Name = L"dgvexpenses";
			this->dgvexpenses->RowHeadersWidth = 51;
			this->dgvexpenses->RowTemplate->Height = 24;
			this->dgvexpenses->Size = System::Drawing::Size(1303, 166);
			this->dgvexpenses->TabIndex = 18;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"PT Sans", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(75, 247);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(94, 29);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Incomes";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"PT Sans", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(75, 460);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(105, 29);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Expenses";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(659, 709);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(158, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::Black;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(1296, 676);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(120, 39);
			this->btnUpdate->TabIndex = 22;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::btnUpdate_Click);
			// 
			// ViewData
			// 
			this->ViewData->BackColor = System::Drawing::Color::Red;
			this->ViewData->Font = (gcnew System::Drawing::Font(L"PT Sans", 7.799999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ViewData->ForeColor = System::Drawing::Color::White;
			this->ViewData->Location = System::Drawing::Point(1170, 677);
			this->ViewData->Name = L"ViewData";
			this->ViewData->Size = System::Drawing::Size(120, 37);
			this->ViewData->TabIndex = 23;
			this->ViewData->Text = L"View Data";
			this->ViewData->UseVisualStyleBackColor = false;
			this->ViewData->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::ViewData_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-11, 126);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1500, 118);
			this->pictureBox2->TabIndex = 24;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(26, 22);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(45, 32);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 25;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &IncomeExpensesForm::pictureBox3_Click);
			// 
			// IncomeExpensesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->ViewData);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dgvexpenses);
			this->Controls->Add(this->dgvIncome);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->reset);
			this->Controls->Add(this->Add);
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
			this->Controls->Add(this->pictureBox2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"IncomeExpensesForm";
			this->Text = L"SmartPlanner Income-Expenses Tracker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvIncome))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvexpenses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
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
	dgvIncome->DataSource = dbHelper->GetIncomeData();
	dgvexpenses->DataSource = dbHelper->GetExpenseData();
}
private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {
	ResetDatabase();
}

private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	// Loop through each row in the income grid and update the data in the database
	for (int i = 0; i < dgvIncome->Rows->Count; i++) {
		// Skip the new row (empty row at the bottom of the grid)
		if (dgvIncome->Rows[i]->IsNewRow) {
			continue;
		}

		// Get the values from the current row for income
		int entryID = Convert::ToInt32(dgvIncome->Rows[i]->Cells["EntryID"]->Value);
		String^ incomeExpense = dgvIncome->Rows[i]->Cells["IncomeExpense"]->Value->ToString();
		String^ date = dgvIncome->Rows[i]->Cells["Date"]->Value->ToString();
		String^ category = dgvIncome->Rows[i]->Cells["Category"]->Value->ToString();
		String^ description = dgvIncome->Rows[i]->Cells["Description"]->Value->ToString();
		String^ source = dgvIncome->Rows[i]->Cells["Source"]->Value->ToString();
		Decimal amount = Convert::ToDecimal(dgvIncome->Rows[i]->Cells["Amount"]->Value);

		// Call the method to update the database with the new values for income
		dbHelper->UpdateIncomeExpense(entryID, incomeExpense, date, category, description, source, amount);
	}
	// Loop through each row in the grid and update the data in the database
	for (int i = 0; i < dgvexpenses->Rows->Count; i++) {
		// Skip the new row (empty row at the bottom of the grid)
		if (dgvexpenses->Rows[i]->IsNewRow) {
			continue;
		}

		// Get the values from the current row
		int entryID = Convert::ToInt32(dgvexpenses->Rows[i]->Cells["EntryID"]->Value);
		String^ incomeExpense = dgvexpenses->Rows[i]->Cells["IncomeExpense"]->Value->ToString();
		String^ date = dgvexpenses->Rows[i]->Cells["Date"]->Value->ToString();
		String^ category = dgvexpenses->Rows[i]->Cells["Category"]->Value->ToString();
		String^ description = dgvexpenses->Rows[i]->Cells["Description"]->Value->ToString();
		String^ source = dgvexpenses->Rows[i]->Cells["Source"]->Value->ToString();
		Decimal amount = Convert::ToDecimal(dgvexpenses->Rows[i]->Cells["Amount"]->Value);

		// Call the method to update the database with the new values
		dbHelper->UpdateIncomeExpense(entryID, incomeExpense, date, category, description, source, amount);
	}

	// Optionally, show a success message
	MessageBox::Show("Data updated successfully!");
	dgvIncome->DataSource = dbHelper->GetIncomeData();
	dgvexpenses->DataSource = dbHelper->GetExpenseData();
}
private: System::Void ViewData_Click(System::Object^ sender, System::EventArgs^ e) {
	dgvIncome->DataSource = dbHelper->GetIncomeData();
	dgvexpenses->DataSource = dbHelper->GetExpenseData();
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

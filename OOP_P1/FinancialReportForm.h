#pragma once
#include"DatabaseHelper.h"
namespace OOPP1 {
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for FinancialReportForm
	/// </summary>
	public ref class FinancialReportForm : public System::Windows::Forms::Form
	{
	public:
		FinancialReportForm(void)
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
		~FinancialReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private:
		DatabaseHelper^ dbHelper;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblTotalIncome;
	private: System::Windows::Forms::Label^ lblTotalExpenses;
	private: System::Windows::Forms::Label^ lblSavings;
	private: System::Windows::Forms::Button^ btnGenerateReport;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartExpenses;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblTotalIncome = (gcnew System::Windows::Forms::Label());
			this->lblTotalExpenses = (gcnew System::Windows::Forms::Label());
			this->lblSavings = (gcnew System::Windows::Forms::Label());
			this->btnGenerateReport = (gcnew System::Windows::Forms::Button());
			this->chartExpenses = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartExpenses))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(43, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Income";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Expense";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"saving";
			// 
			// lblTotalIncome
			// 
			this->lblTotalIncome->AutoSize = true;
			this->lblTotalIncome->Location = System::Drawing::Point(163, 35);
			this->lblTotalIncome->Name = L"lblTotalIncome";
			this->lblTotalIncome->Size = System::Drawing::Size(0, 16);
			this->lblTotalIncome->TabIndex = 6;
			// 
			// lblTotalExpenses
			// 
			this->lblTotalExpenses->AutoSize = true;
			this->lblTotalExpenses->Location = System::Drawing::Point(163, 81);
			this->lblTotalExpenses->Name = L"lblTotalExpenses";
			this->lblTotalExpenses->Size = System::Drawing::Size(0, 16);
			this->lblTotalExpenses->TabIndex = 7;
			// 
			// lblSavings
			// 
			this->lblSavings->AutoSize = true;
			this->lblSavings->Location = System::Drawing::Point(163, 136);
			this->lblSavings->Name = L"lblSavings";
			this->lblSavings->Size = System::Drawing::Size(0, 16);
			this->lblSavings->TabIndex = 8;
			// 
			// btnGenerateReport
			// 
			this->btnGenerateReport->Location = System::Drawing::Point(46, 191);
			this->btnGenerateReport->Name = L"btnGenerateReport";
			this->btnGenerateReport->Size = System::Drawing::Size(75, 23);
			this->btnGenerateReport->TabIndex = 9;
			this->btnGenerateReport->Text = L"Genarate";
			this->btnGenerateReport->UseVisualStyleBackColor = true;
			this->btnGenerateReport->Click += gcnew System::EventHandler(this, &FinancialReportForm::btnGenerateReport_Click);
			// 
			// chartExpenses
			// 
			chartArea1->Name = L"ChartArea1";
			this->chartExpenses->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chartExpenses->Legends->Add(legend1);
			this->chartExpenses->Location = System::Drawing::Point(339, 35);
			this->chartExpenses->Name = L"chartExpenses";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Spent";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Remaining";
			this->chartExpenses->Series->Add(series1);
			this->chartExpenses->Series->Add(series2);
			this->chartExpenses->Size = System::Drawing::Size(1098, 665);
			this->chartExpenses->TabIndex = 10;
			this->chartExpenses->Text = L"chart1";
			// 
			// FinancialReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->chartExpenses);
			this->Controls->Add(this->btnGenerateReport);
			this->Controls->Add(this->lblSavings);
			this->Controls->Add(this->lblTotalExpenses);
			this->Controls->Add(this->lblTotalIncome);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"FinancialReportForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartExpenses))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Method to display the financial report
		void DisplayFinancialReport() {
			// Get total income from the database
			Decimal totalIncome = dbHelper->getTotalIncome();

			// Get total expenses from the database
			Decimal totalExpenses = dbHelper->getTotalExpenses();

			// Calculate savings (Income - Expenses) using Decimal::Subtract
			Decimal savings = Decimal::Subtract(totalIncome, totalExpenses);

			// Display the results
			lblTotalIncome->Text = "Total Income: " + totalIncome.ToString("C");
			lblTotalExpenses->Text = "Total Expenses: " + totalExpenses.ToString("C");
			lblSavings->Text = "Savings: " + savings.ToString("C");
		}

		
			


	private: System::Void btnGenerateReport_Click(System::Object^ sender, System::EventArgs^ e) {
		DisplayFinancialReport();
	}
};
}

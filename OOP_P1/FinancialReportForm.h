#pragma once
#include"DatabaseHelper.h"
namespace OOPP1 {
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;



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
			this->StartPosition = FormStartPosition::CenterScreen;
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ lineChartArea = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ lineLegend = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ expenseSeries = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ incomeSeries = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());

			// Initialize the chart
			this->chartIncomeExpenseLine = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			lineChartArea->Name = L"LineChartArea";
			this->chartIncomeExpenseLine->ChartAreas->Add(lineChartArea);

			lineLegend->Name = L"LineLegend";
			this->chartIncomeExpenseLine->Legends->Add(lineLegend);

			// Configure the Expense series
			expenseSeries->ChartArea = L"LineChartArea";
			expenseSeries->Legend = L"LineLegend";
			expenseSeries->Name = L"Expenses";
			expenseSeries->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			expenseSeries->Color = System::Drawing::Color::Red;

			// Configure the Income series
			incomeSeries->ChartArea = L"LineChartArea";
			incomeSeries->Legend = L"LineLegend";
			incomeSeries->Name = L"Income";
			incomeSeries->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			incomeSeries->Color = System::Drawing::Color::Green;

			this->chartIncomeExpenseLine->Series->Add(expenseSeries);
			this->chartIncomeExpenseLine->Series->Add(incomeSeries);

			// Set chart properties
			this->chartIncomeExpenseLine->Location = System::Drawing::Point(20, 240); // Adjust location as needed
			this->chartIncomeExpenseLine->Size = System::Drawing::Size(550, 250); // Adjust size as needed
			this->chartIncomeExpenseLine->TabIndex = 10;
			this->chartIncomeExpenseLine->Text = L"Income vs. Expense Line Chart";

			// Add the chart to the form
			this->Controls->Add(this->chartIncomeExpenseLine);

			
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




	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartIncomeExpenseLine;
	private: System::Windows::Forms::Label^ lblTotalIncome;
	private: System::Windows::Forms::Label^ lblTotalExpenses;
	private: System::Windows::Forms::Label^ lblSavings;
	private: System::Windows::Forms::Button^ btnGenerateReport;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartExpenses;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FinancialReportForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->lblTotalIncome = (gcnew System::Windows::Forms::Label());
			this->lblTotalExpenses = (gcnew System::Windows::Forms::Label());
			this->lblSavings = (gcnew System::Windows::Forms::Label());
			this->btnGenerateReport = (gcnew System::Windows::Forms::Button());
			this->chartExpenses = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartExpenses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// lblTotalIncome
			// 
			this->lblTotalIncome->AutoSize = true;
			this->lblTotalIncome->BackColor = System::Drawing::Color::White;
			this->lblTotalIncome->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalIncome->Location = System::Drawing::Point(408, 188);
			this->lblTotalIncome->Name = L"lblTotalIncome";
			this->lblTotalIncome->Size = System::Drawing::Size(0, 43);
			this->lblTotalIncome->TabIndex = 6;
			// 
			// lblTotalExpenses
			// 
			this->lblTotalExpenses->AutoSize = true;
			this->lblTotalExpenses->BackColor = System::Drawing::Color::White;
			this->lblTotalExpenses->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold));
			this->lblTotalExpenses->Location = System::Drawing::Point(779, 188);
			this->lblTotalExpenses->Name = L"lblTotalExpenses";
			this->lblTotalExpenses->Size = System::Drawing::Size(0, 43);
			this->lblTotalExpenses->TabIndex = 7;
			// 
			// lblSavings
			// 
			this->lblSavings->AutoSize = true;
			this->lblSavings->BackColor = System::Drawing::Color::White;
			this->lblSavings->Font = (gcnew System::Drawing::Font(L"PT Sans", 19.8F, System::Drawing::FontStyle::Bold));
			this->lblSavings->Location = System::Drawing::Point(1138, 188);
			this->lblSavings->Name = L"lblSavings";
			this->lblSavings->Size = System::Drawing::Size(0, 43);
			this->lblSavings->TabIndex = 8;
			// 
			// btnGenerateReport
			// 
			this->btnGenerateReport->BackColor = System::Drawing::Color::White;
			this->btnGenerateReport->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGenerateReport.BackgroundImage")));
			this->btnGenerateReport->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnGenerateReport->Font = (gcnew System::Drawing::Font(L"PT Sans", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGenerateReport->ForeColor = System::Drawing::Color::Transparent;
			this->btnGenerateReport->Location = System::Drawing::Point(32, 187);
			this->btnGenerateReport->Name = L"btnGenerateReport";
			this->btnGenerateReport->Size = System::Drawing::Size(280, 45);
			this->btnGenerateReport->TabIndex = 9;
			this->btnGenerateReport->Text = L"Genarate";
			this->btnGenerateReport->UseVisualStyleBackColor = false;
			this->btnGenerateReport->Click += gcnew System::EventHandler(this, &FinancialReportForm::btnGenerateReport_Click);
			// 
			// chartExpenses
			// 
			chartArea1->Name = L"ChartArea1";
			this->chartExpenses->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chartExpenses->Legends->Add(legend1);
			this->chartExpenses->Location = System::Drawing::Point(787, 279);
			this->chartExpenses->Name = L"chartExpenses";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Spent";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Remaining";
			this->chartExpenses->Series->Add(series1);
			this->chartExpenses->Series->Add(series2);
			this->chartExpenses->Size = System::Drawing::Size(714, 366);
			this->chartExpenses->TabIndex = 10;
			this->chartExpenses->Text = L"chart1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(20, -7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1446, 312);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(32, 636);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(674, 96);
			this->richTextBox1->TabIndex = 12;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(732, 636);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(674, 86);
			this->richTextBox2->TabIndex = 13;
			this->richTextBox2->Text = L"The chartExpenses visualizes the spent and remaining amounts for each budget cate"
				L"gory, helping track financial progress and budget adherence. It updates dynamica"
				L"lly based on the latest category data.";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1424, 703);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(46, 40);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &FinancialReportForm::pictureBox2_Click);
			// 
			// FinancialReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->chartExpenses);
			this->Controls->Add(this->btnGenerateReport);
			this->Controls->Add(this->lblSavings);
			this->Controls->Add(this->lblTotalExpenses);
			this->Controls->Add(this->lblTotalIncome);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FinancialReportForm";
			this->Text = L"SmartPlanner Financial_Report";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartExpenses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void LoadIncomeExpenseLineChart() {
			// Clear previous data
			chartIncomeExpenseLine->Series["Expenses"]->Points->Clear();
			chartIncomeExpenseLine->Series["Income"]->Points->Clear();

			// Get daily expense and income data from the database
			DataTable^ dailyExpenseData = dbHelper->GetDailyExpenses(); // Retrieve daily expenses
			DataTable^ dailyIncomeData = dbHelper->GetDailyIncome();   // Retrieve daily income

			// Populate the Expenses series
			for (int i = 0; i < dailyExpenseData->Rows->Count; i++) {
				DataRow^ row = dailyExpenseData->Rows[i];
				DateTime date = Convert::ToDateTime(row["Date"]);
				Decimal amount = Convert::ToDecimal(row["Amount"]);

				// Add data points to the Expenses line
				chartIncomeExpenseLine->Series["Expenses"]->Points->AddXY(date.ToShortDateString(), amount);
			}

			// Populate the Income series
			for (int i = 0; i < dailyIncomeData->Rows->Count; i++) {
				DataRow^ row = dailyIncomeData->Rows[i];
				DateTime date = Convert::ToDateTime(row["Date"]);
				Decimal amount = Convert::ToDecimal(row["Amount"]);

				// Add data points to the Income line
				chartIncomeExpenseLine->Series["Income"]->Points->AddXY(date.ToShortDateString(), amount);
			}
		}

		// Method to display the financial report
		void DisplayFinancialReport() {
			// Get total income from the database
			Decimal totalIncome = dbHelper->getTotalIncome();

			// Get total expenses from the database
			Decimal totalExpenses = dbHelper->getTotalExpenses();

			// Calculate savings (Income - Expenses) using Decimal::Subtract
			Decimal savings = Decimal::Subtract(totalIncome, totalExpenses);

			// Display the results
			lblTotalIncome->Text = "Rs. " + totalIncome.ToString("");
			lblTotalExpenses->Text = "Rs. " + totalExpenses.ToString("");
			// Check if savings are negative, and update the label accordingly
			if (savings < 0) {
				lblSavings->Text = "Deficit: Rs." + savings.ToString("");
			}
			else {
				lblSavings->Text = "Rs. " + savings.ToString("");
			}
		}
		
		void LoadCategoryBudgetData() {
			// Retrieve the category budget data from the database
			DataTable^ categoryBudgetData = dbHelper->GetCategoryBudgetData();

			// Clear the existing series in the chart
			chartExpenses->Series["Spent"]->Points->Clear();
			chartExpenses->Series["Remaining"]->Points->Clear();

			// Iterate over the rows of the retrieved data
			for (int i = 0; i < categoryBudgetData->Rows->Count; i++) {
				DataRow^ row = categoryBudgetData->Rows[i];
				String^ category = row["Category"]->ToString();
				Decimal budgetLimit = Convert::ToDecimal(row["BudgetLimit"]);
				Decimal spentAmount = Convert::ToDecimal(row["SpentAmount"]);

				// Correct calculation for remaining amount (budgetLimit - spentAmount)
				Decimal remainingAmount = Decimal::Subtract(budgetLimit, spentAmount);

				// Ensure the remaining amount is not negative
				if (remainingAmount < 0) {
					remainingAmount = 0;
				}

				// Add the spent amount to the "Spent" series
				chartExpenses->Series["Spent"]->Points->AddXY(category, spentAmount);

				// Add the remaining amount to the "Remaining" series
				chartExpenses->Series["Remaining"]->Points->AddXY(category, remainingAmount);
			}

			// Optionally, adjust the Y-axis range to ensure it accommodates the data
			// Check that the ChartArea exists
			if (chartExpenses->ChartAreas->Count == 0) {
				chartExpenses->ChartAreas->Add(gcnew ChartArea("ChartArea1"));
			}

			// Set the Y-axis minimum to 0
			chartExpenses->ChartAreas[0]->AxisY->Minimum = 0;

			// Adjust the maximum Y-axis value based on the data
			Decimal maxAmount = 0;
			for (int i = 0; i < categoryBudgetData->Rows->Count; i++) {
				DataRow^ row = categoryBudgetData->Rows[i];
				Decimal budgetLimit = Convert::ToDecimal(row["BudgetLimit"]);
				if (budgetLimit > maxAmount) {
					maxAmount = budgetLimit;
				}
			}

			// Convert 1.1 to Decimal explicitly
			Decimal multiplier = Decimal::Parse("1.1");

			// Multiply maxAmount with the Decimal multiplier
			
		}
	private: System::Void btnGenerateReport_Click(System::Object^ sender, System::EventArgs^ e) {
		DisplayFinancialReport();
		LoadCategoryBudgetData();
		LoadIncomeExpenseLineChart();
		
	}



private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

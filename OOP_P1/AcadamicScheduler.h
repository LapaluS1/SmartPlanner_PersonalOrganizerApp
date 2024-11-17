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
	/// Summary for AcadamicScheduler
	/// </summary>
	public ref class AcadamicScheduler : public System::Windows::Forms::Form
	{
	public:
		AcadamicScheduler(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			this->monthCalendar->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &AcadamicScheduler::monthCalendar_DateChanged);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AcadamicScheduler()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ AcaSubject;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ AcaSC;

	private: System::Windows::Forms::DateTimePicker^ AcaDate;
	private: System::Windows::Forms::Button^ AcaAdd;
	private: System::Windows::Forms::Button^ AssAdd;

	private: System::Windows::Forms::DateTimePicker^ AssStartDate;
	private: System::Windows::Forms::TextBox^ AssSubjectCode;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ AssName;
	private: System::Windows::Forms::DateTimePicker^ AssEndDate;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::DataGridView^ gridAcademicSchedule;
	private: System::Windows::Forms::DataGridView^ gridAssignments;
	private: System::Windows::Forms::DateTimePicker^ Time;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::MonthCalendar^ monthCalendar;
	private: System::Void monthCalendar_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		DateTime selectedDate = monthCalendar->SelectionStart;

		// Get academic schedules for the selected date
		DatabaseHelper^ dbHelper = gcnew DatabaseHelper();
		DataTable^ academicData = dbHelper->GetAcademicSchedule(selectedDate);
		gridAcademicSchedule->DataSource = academicData;

		// Get assignments for the selected date
		DataTable^ assignmentData = dbHelper->GetAssignments(selectedDate);
		gridAssignments->DataSource = assignmentData;
	}


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->AcaSubject = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->AcaSC = (gcnew System::Windows::Forms::TextBox());
			this->AcaDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->AcaAdd = (gcnew System::Windows::Forms::Button());
			this->AssAdd = (gcnew System::Windows::Forms::Button());
			this->AssStartDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->AssSubjectCode = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->AssName = (gcnew System::Windows::Forms::TextBox());
			this->AssEndDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->gridAcademicSchedule = (gcnew System::Windows::Forms::DataGridView());
			this->gridAssignments = (gcnew System::Windows::Forms::DataGridView());
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->Time = (gcnew System::Windows::Forms::DateTimePicker());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAcademicSchedule))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAssignments))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Acadamic Scheduler";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(887, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Assignment Scheduler";
			// 
			// AcaSubject
			// 
			this->AcaSubject->Location = System::Drawing::Point(325, 71);
			this->AcaSubject->Name = L"AcaSubject";
			this->AcaSubject->Size = System::Drawing::Size(228, 22);
			this->AcaSubject->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(195, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Subject";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(181, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 16);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Subject Code";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(195, 178);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Date";
			// 
			// AcaSC
			// 
			this->AcaSC->Location = System::Drawing::Point(325, 112);
			this->AcaSC->Name = L"AcaSC";
			this->AcaSC->Size = System::Drawing::Size(228, 22);
			this->AcaSC->TabIndex = 6;
			// 
			// AcaDate
			// 
			this->AcaDate->Location = System::Drawing::Point(325, 178);
			this->AcaDate->Name = L"AcaDate";
			this->AcaDate->Size = System::Drawing::Size(200, 22);
			this->AcaDate->TabIndex = 7;
			// 
			// AcaAdd
			// 
			this->AcaAdd->Location = System::Drawing::Point(325, 215);
			this->AcaAdd->Name = L"AcaAdd";
			this->AcaAdd->Size = System::Drawing::Size(75, 23);
			this->AcaAdd->TabIndex = 8;
			this->AcaAdd->Text = L"Add";
			this->AcaAdd->UseVisualStyleBackColor = true;
			this->AcaAdd->Click += gcnew System::EventHandler(this, &AcadamicScheduler::AcaAdd_Click);
			// 
			// AssAdd
			// 
			this->AssAdd->Location = System::Drawing::Point(909, 211);
			this->AssAdd->Name = L"AssAdd";
			this->AssAdd->Size = System::Drawing::Size(75, 23);
			this->AssAdd->TabIndex = 15;
			this->AssAdd->Text = L"Add";
			this->AssAdd->UseVisualStyleBackColor = true;
			this->AssAdd->Click += gcnew System::EventHandler(this, &AcadamicScheduler::AssAdd_Click);
			// 
			// AssStartDate
			// 
			this->AssStartDate->Location = System::Drawing::Point(909, 136);
			this->AssStartDate->Name = L"AssStartDate";
			this->AssStartDate->Size = System::Drawing::Size(200, 22);
			this->AssStartDate->TabIndex = 14;
			// 
			// AssSubjectCode
			// 
			this->AssSubjectCode->Location = System::Drawing::Point(909, 100);
			this->AssSubjectCode->Name = L"AssSubjectCode";
			this->AssSubjectCode->Size = System::Drawing::Size(228, 22);
			this->AssSubjectCode->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(801, 141);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 16);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Start_Date";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(768, 100);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 16);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Subject Code";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(779, 59);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 16);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Assignment";
			// 
			// AssName
			// 
			this->AssName->Location = System::Drawing::Point(909, 59);
			this->AssName->Name = L"AssName";
			this->AssName->Size = System::Drawing::Size(228, 22);
			this->AssName->TabIndex = 9;
			// 
			// AssEndDate
			// 
			this->AssEndDate->Location = System::Drawing::Point(909, 174);
			this->AssEndDate->Name = L"AssEndDate";
			this->AssEndDate->Size = System::Drawing::Size(200, 22);
			this->AssEndDate->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(801, 179);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 16);
			this->label9->TabIndex = 16;
			this->label9->Text = L"End_Date";
			// 
			// gridAcademicSchedule
			// 
			this->gridAcademicSchedule->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAcademicSchedule->Location = System::Drawing::Point(448, 356);
			this->gridAcademicSchedule->Name = L"gridAcademicSchedule";
			this->gridAcademicSchedule->RowHeadersWidth = 51;
			this->gridAcademicSchedule->RowTemplate->Height = 24;
			this->gridAcademicSchedule->Size = System::Drawing::Size(853, 127);
			this->gridAcademicSchedule->TabIndex = 19;
			// 
			// gridAssignments
			// 
			this->gridAssignments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAssignments->Location = System::Drawing::Point(448, 489);
			this->gridAssignments->Name = L"gridAssignments";
			this->gridAssignments->RowHeadersWidth = 51;
			this->gridAssignments->RowTemplate->Height = 24;
			this->gridAssignments->Size = System::Drawing::Size(853, 127);
			this->gridAssignments->TabIndex = 20;
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(71, 356);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->TabIndex = 21;
			// 
			// Time
			// 
			this->Time->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->Time->Location = System::Drawing::Point(325, 146);
			this->Time->Name = L"Time";
			this->Time->Size = System::Drawing::Size(123, 22);
			this->Time->TabIndex = 22;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(195, 146);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(72, 16);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Start_Time";
			// 
			// AcadamicScheduler
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->Time);
			this->Controls->Add(this->monthCalendar);
			this->Controls->Add(this->gridAssignments);
			this->Controls->Add(this->gridAcademicSchedule);
			this->Controls->Add(this->AssEndDate);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->AssAdd);
			this->Controls->Add(this->AssStartDate);
			this->Controls->Add(this->AssSubjectCode);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->AssName);
			this->Controls->Add(this->AcaAdd);
			this->Controls->Add(this->AcaDate);
			this->Controls->Add(this->AcaSC);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->AcaSubject);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AcadamicScheduler";
			this->Text = L"AcadamicScheduler";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAcademicSchedule))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAssignments))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AcaAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ subject = AcaSubject->Text;
		String^ subjectCode = AcaSC->Text;
		DateTime date = AcaDate->Value;

		// Create an instance of DatabaseHelper and call the AddAcademicSchedule method
		DatabaseHelper^ dbHelper = gcnew DatabaseHelper();
		dbHelper->AddAcademicSchedule(subject, subjectCode, date);

		// Optionally, clear the input fields after adding the record
		AcaSubject->Clear();
		AcaSC->Clear();
		AcaDate->ResetText();
	}
private: System::Void AssAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ assignmentName = AssName->Text;
	String^ subjectCode = AssSubjectCode->Text;
	DateTime startDate = AssStartDate->Value;
	DateTime endDate = AssEndDate->Value;

	// Create an instance of DatabaseHelper and call the AddAssignment method
	DatabaseHelper^ dbHelper = gcnew DatabaseHelper();
	dbHelper->AddAssignment(assignmentName, subjectCode, startDate, endDate);

	// Optionally, clear the input fields after adding the record
	AssName->Clear();
	AssSubjectCode->Clear();
	AssStartDate->ResetText();
	AssEndDate->ResetText();
}
};
}

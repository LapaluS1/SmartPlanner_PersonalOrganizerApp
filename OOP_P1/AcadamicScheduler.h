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
			this->StartPosition = FormStartPosition::CenterScreen;

			this->assignmentDeadlineTimer = (gcnew System::Windows::Forms::Timer());
			this->assignmentDeadlineTimer->Interval = 60000; // Check every 60 seconds
			this->assignmentDeadlineTimer->Tick += gcnew System::EventHandler(this, &AcadamicScheduler::assignmentDeadlineTimer_Tick);
			this->assignmentDeadlineTimer->Start();
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
	private: System::Windows::Forms::Timer^ assignmentDeadlineTimer;

	protected:
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
	private: System::Windows::Forms::Button^ AcaAdd;
	private: System::Windows::Forms::DateTimePicker^ AcaDate;
	private: System::Windows::Forms::TextBox^ AcaSC;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ AcaSubject;
	private: System::Windows::Forms::DateTimePicker^ AcaTime;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;

	private: System::Windows::Forms::MonthCalendar^ monthCalendar;
	private: System::Void monthCalendar_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		DateTime selectedDate = monthCalendar->SelectionStart;

		// Create an instance of DatabaseHelper to get data
		DatabaseHelper^ dbHelper = gcnew DatabaseHelper();

		// Get academic schedules for the selected date
		DataTable^ academicData = dbHelper->GetAcademicSchedule(selectedDate);
		gridAcademicSchedule->DataSource = academicData;

		// Hide columns in gridAcademicSchedule (if they exist)
		if (gridAcademicSchedule->Columns->Contains("ScheduleID"))
		{
			gridAcademicSchedule->Columns["ScheduleID"]->Visible = false; // Hide ScheduleID column
		}

		// Get assignments for the selected date
		DataTable^ assignmentData = dbHelper->GetAssignments(selectedDate);
		gridAssignments->DataSource = assignmentData;

		// Hide columns in gridAssignments (if they exist)
		if (gridAssignments->Columns->Contains("AssignmentID"))
		{
			gridAssignments->Columns["AssignmentID"]->Visible = false; // Hide AssignmentID column
		}

		// Optional: If you need to remove the columns instead of hiding them, uncomment the following lines:
		// gridAcademicSchedule->Columns->Remove("ScheduleID");
		// gridAssignments->Columns->Remove("AssignmentID");
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AcadamicScheduler::typeid));
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
			this->AcaAdd = (gcnew System::Windows::Forms::Button());
			this->AcaDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->AcaSC = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->AcaSubject = (gcnew System::Windows::Forms::TextBox());
			this->AcaTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAcademicSchedule))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAssignments))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// AssAdd
			// 
			this->AssAdd->BackColor = System::Drawing::Color::DodgerBlue;
			this->AssAdd->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold));
			this->AssAdd->ForeColor = System::Drawing::Color::White;
			this->AssAdd->Location = System::Drawing::Point(1105, 631);
			this->AssAdd->Name = L"AssAdd";
			this->AssAdd->Size = System::Drawing::Size(337, 46);
			this->AssAdd->TabIndex = 15;
			this->AssAdd->Text = L"Add";
			this->AssAdd->UseVisualStyleBackColor = false;
			this->AssAdd->Click += gcnew System::EventHandler(this, &AcadamicScheduler::AssAdd_Click);
			// 
			// AssStartDate
			// 
			this->AssStartDate->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AssStartDate->Location = System::Drawing::Point(1104, 423);
			this->AssStartDate->Name = L"AssStartDate";
			this->AssStartDate->Size = System::Drawing::Size(338, 31);
			this->AssStartDate->TabIndex = 14;
			// 
			// AssSubjectCode
			// 
			this->AssSubjectCode->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AssSubjectCode->Location = System::Drawing::Point(1104, 319);
			this->AssSubjectCode->Name = L"AssSubjectCode";
			this->AssSubjectCode->Size = System::Drawing::Size(338, 31);
			this->AssSubjectCode->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label6->Location = System::Drawing::Point(1100, 390);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 26);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Start_Date";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label7->Location = System::Drawing::Point(1099, 288);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 26);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Subject Code";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::White;
			this->label8->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label8->Location = System::Drawing::Point(1100, 187);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(111, 26);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Assignment";
			// 
			// AssName
			// 
			this->AssName->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AssName->Location = System::Drawing::Point(1105, 216);
			this->AssName->Name = L"AssName";
			this->AssName->Size = System::Drawing::Size(337, 31);
			this->AssName->TabIndex = 9;
			// 
			// AssEndDate
			// 
			this->AssEndDate->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AssEndDate->Location = System::Drawing::Point(1104, 533);
			this->AssEndDate->Name = L"AssEndDate";
			this->AssEndDate->Size = System::Drawing::Size(338, 31);
			this->AssEndDate->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label9->Location = System::Drawing::Point(1100, 504);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(92, 26);
			this->label9->TabIndex = 16;
			this->label9->Text = L"End_Date";
			// 
			// gridAcademicSchedule
			// 
			this->gridAcademicSchedule->BackgroundColor = System::Drawing::SystemColors::Control;
			this->gridAcademicSchedule->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->gridAcademicSchedule->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAcademicSchedule->Location = System::Drawing::Point(430, 346);
			this->gridAcademicSchedule->Name = L"gridAcademicSchedule";
			this->gridAcademicSchedule->RowHeadersWidth = 51;
			this->gridAcademicSchedule->RowTemplate->Height = 24;
			this->gridAcademicSchedule->Size = System::Drawing::Size(632, 155);
			this->gridAcademicSchedule->TabIndex = 19;
			// 
			// gridAssignments
			// 
			this->gridAssignments->BackgroundColor = System::Drawing::SystemColors::Control;
			this->gridAssignments->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->gridAssignments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAssignments->Location = System::Drawing::Point(430, 517);
			this->gridAssignments->Name = L"gridAssignments";
			this->gridAssignments->RowHeadersWidth = 51;
			this->gridAssignments->RowTemplate->Height = 24;
			this->gridAssignments->Size = System::Drawing::Size(632, 160);
			this->gridAssignments->TabIndex = 20;
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(618, 107);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->TabIndex = 21;
			// 
			// AcaAdd
			// 
			this->AcaAdd->BackColor = System::Drawing::Color::DodgerBlue;
			this->AcaAdd->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AcaAdd->ForeColor = System::Drawing::Color::White;
			this->AcaAdd->Location = System::Drawing::Point(41, 631);
			this->AcaAdd->Name = L"AcaAdd";
			this->AcaAdd->Size = System::Drawing::Size(334, 46);
			this->AcaAdd->TabIndex = 8;
			this->AcaAdd->Text = L"Add";
			this->AcaAdd->UseVisualStyleBackColor = false;
			this->AcaAdd->Click += gcnew System::EventHandler(this, &AcadamicScheduler::AcaAdd_Click);
			// 
			// AcaDate
			// 
			this->AcaDate->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AcaDate->Location = System::Drawing::Point(41, 533);
			this->AcaDate->Name = L"AcaDate";
			this->AcaDate->Size = System::Drawing::Size(334, 31);
			this->AcaDate->TabIndex = 7;
			// 
			// AcaSC
			// 
			this->AcaSC->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AcaSC->Location = System::Drawing::Point(41, 319);
			this->AcaSC->Name = L"AcaSC";
			this->AcaSC->Size = System::Drawing::Size(334, 31);
			this->AcaSC->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label5->Location = System::Drawing::Point(38, 504);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 26);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Date";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label4->Location = System::Drawing::Point(40, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 26);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Subject Code";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"PT Sans", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(38, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Subject";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::White;
			this->label10->Font = (gcnew System::Drawing::Font(L"PT Sans", 12));
			this->label10->Location = System::Drawing::Point(41, 390);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(103, 26);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Start_Time";
			// 
			// AcaSubject
			// 
			this->AcaSubject->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AcaSubject->Location = System::Drawing::Point(41, 221);
			this->AcaSubject->Name = L"AcaSubject";
			this->AcaSubject->Size = System::Drawing::Size(334, 31);
			this->AcaSubject->TabIndex = 2;
			// 
			// AcaTime
			// 
			this->AcaTime->Font = (gcnew System::Drawing::Font(L"PT Sans", 10.8F));
			this->AcaTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->AcaTime->ImeMode = System::Windows::Forms::ImeMode::On;
			this->AcaTime->Location = System::Drawing::Point(46, 423);
			this->AcaTime->Name = L"AcaTime";
			this->AcaTime->Size = System::Drawing::Size(137, 31);
			this->AcaTime->TabIndex = 24;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(10, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(396, 735);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 25;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1076, 6);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(396, 735);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 27;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(658, 707);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(180, 34);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 28;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Sans", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(582, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(342, 52);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Acadamic Sheduler";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(412, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(45, 36);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 30;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &AcadamicScheduler::pictureBox4_Click);
			// 
			// AcadamicScheduler
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->AcaTime);
			this->Controls->Add(this->label10);
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
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AcadamicScheduler";
			this->Text = L"SmartPlanner Acadamic Scheduler";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAcademicSchedule))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAssignments))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void assignmentDeadlineTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		DatabaseHelper^ dbHelper = gcnew DatabaseHelper();
		DateTime today = DateTime::Now;
		DateTime alertThreshold = today.AddDays(2); // Example: Alert if deadline is within 2 days

		// Query assignments near the deadline
		DataTable^ nearDeadlineAssignments = dbHelper->GetAssignmentsNearDeadline(today, alertThreshold);

		// If there are assignments near deadline, show an alert
		if (nearDeadlineAssignments->Rows->Count > 0)
		{
			String^ message = "Upcoming Assignment Deadlines:\n";
			for each (DataRow ^ row in nearDeadlineAssignments->Rows)
			{
				message += row["Name"]->ToString() + " (End Date: " + row["EndDate"]->ToString() + ")\n";
			}
			MessageBox::Show(message, "Assignment Deadline Alert", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	private: System::Void AcaAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ subject = AcaSubject->Text;
		String^ subjectCode = AcaSC->Text;
		DateTime date = AcaDate->Value;
		DateTime startTime = AcaTime->Value; // Assuming AcaTime is a DateTimePicker for time selection.

		// Create an instance of DatabaseHelper and call the AddAcademicSchedule method
		DatabaseHelper^ dbHelper = gcnew DatabaseHelper();
		dbHelper->AddAcademicSchedule(subject, subjectCode, date, startTime);

		// Optionally, clear the input fields after adding the record
		AcaSubject->Clear();
		AcaSC->Clear();
		AcaDate->ResetText();
		AcaTime->ResetText();
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

private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

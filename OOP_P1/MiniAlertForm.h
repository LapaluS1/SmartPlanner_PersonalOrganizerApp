#pragma once

namespace OOPP1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MiniAlertForm
	/// </summary>
	public ref class MiniAlertForm : public System::Windows::Forms::Form
	{
	public:
		MiniAlertForm(void)
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
		~MiniAlertForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		// Method to set the alert message on the label
		void SetAlertMessage(String^ message)
		{
			this->lblAlertMessage->Text = message;  // Set the label text to the alert message
		}
	private: System::Windows::Forms::Label^ lblAlertMessage;
	protected:

	protected:

	protected:
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
			this->lblAlertMessage = (gcnew System::Windows::Forms::Label());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblAlertMessage
			// 
			this->lblAlertMessage->AutoSize = true;
			this->lblAlertMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAlertMessage->Location = System::Drawing::Point(12, 9);
			this->lblAlertMessage->Name = L"lblAlertMessage";
			this->lblAlertMessage->Size = System::Drawing::Size(92, 25);
			this->lblAlertMessage->TabIndex = 0;
			this->lblAlertMessage->Text = L"No Alerts";
			// 
			// btnclose
			// 
			this->btnclose->Location = System::Drawing::Point(15, 68);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(75, 23);
			this->btnclose->TabIndex = 1;
			this->btnclose->Text = L"close";
			this->btnclose->UseVisualStyleBackColor = true;
			this->btnclose->Click += gcnew System::EventHandler(this, &MiniAlertForm::btnclose_Click);
			// 
			// MiniAlertForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 103);
			this->Controls->Add(this->btnclose);
			this->Controls->Add(this->lblAlertMessage);
			this->Name = L"MiniAlertForm";
			this->Text = L"MiniAlertForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnclose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}

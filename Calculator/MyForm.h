#pragma once
#include "MyForm1.h"
#include <cmath>

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::TextBox^ Loan;
	protected:


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ Months;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Years;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ Rate;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ MonthlyPayment;

	private: System::Windows::Forms::Button^ Calculate;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ TotalPayment;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ToolTip^ toolTip2;

	private: System::Windows::Forms::ToolTip^ toolTip4;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolTip^ toolTip5;





	private: System::ComponentModel::IContainer^ components;




	protected:



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Loan = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Months = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Years = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Rate = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->MonthlyPayment = (gcnew System::Windows::Forms::TextBox());
			this->Calculate = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TotalPayment = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// Loan
			// 
			this->Loan->BackColor = System::Drawing::Color::DarkViolet;
			resources->ApplyResources(this->Loan, L"Loan");
			this->Loan->ForeColor = System::Drawing::Color::Gold;
			this->Loan->Name = L"Loan";
			this->Loan->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::Color::Lavender;
			this->label3->Name = L"label3";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::Color::Lavender;
			this->label4->Name = L"label4";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Gold;
			this->label2->Name = L"label2";
			// 
			// Months
			// 
			this->Months->BackColor = System::Drawing::Color::DarkViolet;
			resources->ApplyResources(this->Months, L"Months");
			this->Months->ForeColor = System::Drawing::Color::Gold;
			this->Months->Name = L"Months";
			this->toolTip4->SetToolTip(this->Months, resources->GetString(L"Months.ToolTip"));
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->ForeColor = System::Drawing::Color::Gold;
			this->label5->Name = L"label5";
			// 
			// Years
			// 
			this->Years->BackColor = System::Drawing::Color::DarkViolet;
			resources->ApplyResources(this->Years, L"Years");
			this->Years->ForeColor = System::Drawing::Color::Gold;
			this->Years->Name = L"Years";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->ForeColor = System::Drawing::Color::Lavender;
			this->label6->Name = L"label6";
			// 
			// Rate
			// 
			this->Rate->BackColor = System::Drawing::Color::DarkViolet;
			resources->ApplyResources(this->Rate, L"Rate");
			this->Rate->ForeColor = System::Drawing::Color::Fuchsia;
			this->Rate->Name = L"Rate";
			this->toolTip1->SetToolTip(this->Rate, resources->GetString(L"Rate.ToolTip"));
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->ForeColor = System::Drawing::Color::Lavender;
			this->label7->Name = L"label7";
			// 
			// MonthlyPayment
			// 
			this->MonthlyPayment->BackColor = System::Drawing::Color::Lavender;
			resources->ApplyResources(this->MonthlyPayment, L"MonthlyPayment");
			this->MonthlyPayment->ForeColor = System::Drawing::Color::Yellow;
			this->MonthlyPayment->Name = L"MonthlyPayment";
			// 
			// Calculate
			// 
			this->Calculate->BackColor = System::Drawing::Color::BlueViolet;
			this->Calculate->FlatAppearance->BorderColor = System::Drawing::Color::SlateBlue;
			resources->ApplyResources(this->Calculate, L"Calculate");
			this->Calculate->ForeColor = System::Drawing::Color::Gold;
			this->Calculate->Name = L"Calculate";
			this->toolTip2->SetToolTip(this->Calculate, resources->GetString(L"Calculate.ToolTip"));
			this->Calculate->UseVisualStyleBackColor = false;
			this->Calculate->Click += gcnew System::EventHandler(this, &MyForm::Calculate_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::BlueViolet;
			resources->ApplyResources(this->button2, L"button2");
			this->button2->ForeColor = System::Drawing::Color::Violet;
			this->button2->Name = L"button2";
			this->toolTip3->SetToolTip(this->button2, resources->GetString(L"button2.ToolTip"));
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->ForeColor = System::Drawing::Color::Lavender;
			this->label8->Name = L"label8";
			// 
			// TotalPayment
			// 
			this->TotalPayment->BackColor = System::Drawing::Color::Lavender;
			resources->ApplyResources(this->TotalPayment, L"TotalPayment");
			this->TotalPayment->ForeColor = System::Drawing::Color::Red;
			this->TotalPayment->Name = L"TotalPayment";
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->ForeColor = System::Drawing::Color::Fuchsia;
			this->label9->Name = L"label9";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->ForeColor = System::Drawing::Color::Fuchsia;
			this->label10->Name = L"label10";
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->BackColor = System::Drawing::Color::BlueViolet;
			this->toolTip1->ForeColor = System::Drawing::Color::Lavender;
			this->toolTip1->InitialDelay = 200;
			this->toolTip1->ReshowDelay = 100;
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->toolTip1->ToolTipTitle = L"¬нимание!";
			// 
			// toolTip2
			// 
			this->toolTip2->AutoPopDelay = 5000;
			this->toolTip2->BackColor = System::Drawing::Color::BlueViolet;
			this->toolTip2->ForeColor = System::Drawing::Color::Lavender;
			this->toolTip2->InitialDelay = 200;
			this->toolTip2->ReshowDelay = 100;
			this->toolTip2->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::BlueViolet;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Name = L"button1";
			this->toolTip2->SetToolTip(this->button1, resources->GetString(L"button1.ToolTip"));
			this->toolTip5->SetToolTip(this->button1, resources->GetString(L"button1.ToolTip1"));
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// toolTip3
			// 
			this->toolTip3->AutoPopDelay = 5000;
			this->toolTip3->BackColor = System::Drawing::Color::BlueViolet;
			this->toolTip3->ForeColor = System::Drawing::Color::Lavender;
			this->toolTip3->InitialDelay = 200;
			this->toolTip3->ReshowDelay = 100;
			this->toolTip3->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// toolTip4
			// 
			this->toolTip4->AutoPopDelay = 5000;
			this->toolTip4->BackColor = System::Drawing::Color::BlueViolet;
			this->toolTip4->ForeColor = System::Drawing::Color::Lavender;
			this->toolTip4->InitialDelay = 200;
			this->toolTip4->ReshowDelay = 100;
			this->toolTip4->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->toolTip4->ToolTipTitle = L"¬нимание!";
			// 
			// toolTip5
			// 
			this->toolTip5->AutoPopDelay = 5000;
			this->toolTip5->BackColor = System::Drawing::Color::BlueViolet;
			this->toolTip5->ForeColor = System::Drawing::Color::Lavender;
			this->toolTip5->InitialDelay = 200;
			this->toolTip5->ReshowDelay = 100;
			this->toolTip5->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Indigo;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->TotalPayment);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Calculate);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->MonthlyPayment);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->Rate);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Years);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Months);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Loan);
			this->ForeColor = System::Drawing::Color::LavenderBlush;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	   bool check_input_Loan() {
		   if (Loan->Text->Length == 0) return false;
		   for (unsigned int i = 0; i < Loan->Text->Length; i++) {
			   if (Loan->Text[i] >= '0' && Loan->Text[i] <= '9' || Loan->Text[i] == ',') {}
			   else return false;
			   return true;
		   }
	   }
	   bool check_input_Months() {
		   if (Months->Text->Length == 0) return false;
		   for (unsigned int i = 0; i < Months->Text->Length; i++) {
			   if (Months->Text[i] >= '0' && Months->Text[i] <= '9') {}
			   else return false;
			   return true;
		   }
	   }
	   bool check_input_Years() {
		   if (Years->Text->Length == 0) return false;
		   for (unsigned int i = 0; i < Years->Text->Length; i++) {
			   if (Years->Text[i] >= '0' && Years->Text[i] <= '9' || Years->Text[i] == ',') {}
			   else return false;
			   return true;
		   }
	   }
	   bool check_input_Rate() {
		   if (Rate->Text->Length == 0) return false;
		   for (unsigned int i = 0; i < Rate->Text->Length; i++) {
			   if (Rate->Text[i] >= '0' && Rate->Text[i] <= '9' || Rate->Text[i] == ',') {}
			   else return false;
			   return true;
		   }
	   }

private: System::Void Calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (check_input_Loan() && check_input_Months() && check_input_Years() && check_input_Rate()) {
		double M, Sum = 0, S, MR, Month;
		S = System::Convert::ToDouble(Loan->Text);
		Month = (System::Convert::ToDouble(Months->Text) + System::Convert::ToDouble(Years->Text) * 12.0);
		MR = (System::Convert::ToDouble(Rate->Text) / 100.0) / 12.0;
		M = S * (MR + (MR / (pow(1 + MR, Month) - 1)));
		for (unsigned int i = 0; i < Month; i++)
			Sum += M;
		M = int(M);
		Sum = int(Sum);
		MonthlyPayment->Text = System::Convert::ToString(M);
		TotalPayment->Text = System::Convert::ToString(Sum);
	}else MessageBox::Show("¬ведены некорректные данные!");
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Loan->Text = "";
	Rate->Text = "";
	Months->Text = ""; Years->Text = "";
	MonthlyPayment->Text = ""; TotalPayment->Text = "";
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1^ f2 = gcnew MyForm1();
	f2->Show();
	f2->Owner = this;
	this->Hide();
}
};
}

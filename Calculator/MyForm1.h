#pragma once
#include <cmath>

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ Clear;
	private: System::Windows::Forms::Button^ Calculate2;
	private: System::Windows::Forms::Label^ label62;
	private: System::Windows::Forms::TextBox^ Rate2;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::TextBox^ Loan2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Days2;
	private: System::Windows::Forms::Label^ label82;
	private: System::Windows::Forms::TextBox^ TotalPayment2;


	private: System::Windows::Forms::Label^ label72;
	private: System::Windows::Forms::TextBox^ MonthlyPayment2;
	private: System::Windows::Forms::ToolTip^ toolTip11;
	private: System::Windows::Forms::ToolTip^ toolTip12;
	private: System::Windows::Forms::ToolTip^ toolTip13;
	private: System::Windows::Forms::ToolTip^ toolTip14;
	private: System::Windows::Forms::ToolTip^ toolTip15;
	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->Calculate2 = (gcnew System::Windows::Forms::Button());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->Rate2 = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->Loan2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Days2 = (gcnew System::Windows::Forms::TextBox());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->TotalPayment2 = (gcnew System::Windows::Forms::TextBox());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->MonthlyPayment2 = (gcnew System::Windows::Forms::TextBox());
			this->toolTip11 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip12 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip13 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip14 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip15 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::BlueViolet;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rubik", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(945, 218);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 67);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Анн. платежи";
			this->toolTip14->SetToolTip(this->button1, L"Переход к подсчёту кредитов с аннуитетными платежами");
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::Color::Fuchsia;
			this->label10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label10->Location = System::Drawing::Point(116, 144);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 25);
			this->label10->TabIndex = 32;
			this->label10->Text = L"%";
			// 
			// Clear
			// 
			this->Clear->BackColor = System::Drawing::Color::BlueViolet;
			this->Clear->Font = (gcnew System::Drawing::Font(L"Rubik", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Clear->ForeColor = System::Drawing::Color::Violet;
			this->Clear->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Clear->Location = System::Drawing::Point(362, 189);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(220, 38);
			this->Clear->TabIndex = 29;
			this->Clear->Text = L"Очистить";
			this->toolTip13->SetToolTip(this->Clear, L"Данная кнопка очищает все поля ввода (в том числе поля результатов)");
			this->Clear->UseVisualStyleBackColor = false;
			this->Clear->Click += gcnew System::EventHandler(this, &MyForm1::Clear_Click);
			// 
			// Calculate2
			// 
			this->Calculate2->BackColor = System::Drawing::Color::BlueViolet;
			this->Calculate2->FlatAppearance->BorderColor = System::Drawing::Color::SlateBlue;
			this->Calculate2->Font = (gcnew System::Drawing::Font(L"Rubik", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Calculate2->ForeColor = System::Drawing::Color::Gold;
			this->Calculate2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Calculate2->Location = System::Drawing::Point(102, 189);
			this->Calculate2->Name = L"Calculate2";
			this->Calculate2->Size = System::Drawing::Size(220, 38);
			this->Calculate2->TabIndex = 28;
			this->Calculate2->Text = L"Рассчитать";
			this->toolTip15->SetToolTip(this->Calculate2, L"Данная кнопка запускает расчёт с введёнными данными");
			this->Calculate2->UseVisualStyleBackColor = false;
			this->Calculate2->Click += gcnew System::EventHandler(this, &MyForm1::Calculate2_Click);
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->BackColor = System::Drawing::Color::Transparent;
			this->label62->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label62->ForeColor = System::Drawing::Color::Lavender;
			this->label62->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label62->Location = System::Drawing::Point(26, 105);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(332, 34);
			this->label62->TabIndex = 31;
			this->label62->Text = L"Годовая ставка по кредиту:";
			// 
			// Rate2
			// 
			this->Rate2->BackColor = System::Drawing::Color::DarkViolet;
			this->Rate2->Font = (gcnew System::Drawing::Font(L"Rubik", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Rate2->ForeColor = System::Drawing::Color::Fuchsia;
			this->Rate2->Location = System::Drawing::Point(29, 142);
			this->Rate2->MaxLength = 6;
			this->Rate2->Name = L"Rate2";
			this->Rate2->Size = System::Drawing::Size(81, 28);
			this->Rate2->TabIndex = 27;
			this->toolTip11->SetToolTip(this->Rate2, L"Десятичные числа вводить только через запятую");
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->BackColor = System::Drawing::Color::Transparent;
			this->label32->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label32->ForeColor = System::Drawing::Color::Lavender;
			this->label32->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label32->Location = System::Drawing::Point(26, 19);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(328, 34);
			this->label32->TabIndex = 30;
			this->label32->Text = L"Сумма желаемого кредита:";
			// 
			// Loan2
			// 
			this->Loan2->BackColor = System::Drawing::Color::DarkViolet;
			this->Loan2->Font = (gcnew System::Drawing::Font(L"Rubik", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Loan2->ForeColor = System::Drawing::Color::Gold;
			this->Loan2->Location = System::Drawing::Point(29, 56);
			this->Loan2->MaxLength = 12;
			this->Loan2->Name = L"Loan2";
			this->Loan2->Size = System::Drawing::Size(366, 28);
			this->Loan2->TabIndex = 26;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Lavender;
			this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label4->Location = System::Drawing::Point(422, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(403, 34);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Количество платёжных периодов:";
			// 
			// Days2
			// 
			this->Days2->BackColor = System::Drawing::Color::DarkViolet;
			this->Days2->Font = (gcnew System::Drawing::Font(L"Rubik", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Days2->ForeColor = System::Drawing::Color::Gold;
			this->Days2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Days2->Location = System::Drawing::Point(428, 56);
			this->Days2->MaxLength = 10;
			this->Days2->Name = L"Days2";
			this->Days2->Size = System::Drawing::Size(140, 28);
			this->Days2->TabIndex = 33;
			this->toolTip12->SetToolTip(this->Days2, L"Количество месяцев, за которое планируется погасить кредит");
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->BackColor = System::Drawing::Color::Transparent;
			this->label82->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label82->ForeColor = System::Drawing::Color::Lavender;
			this->label82->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label82->Location = System::Drawing::Point(433, 263);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(292, 34);
			this->label82->TabIndex = 40;
			this->label82->Text = L"Общая сумма переплат:";
			// 
			// TotalPayment2
			// 
			this->TotalPayment2->BackColor = System::Drawing::Color::Lavender;
			this->TotalPayment2->Enabled = false;
			this->TotalPayment2->Font = (gcnew System::Drawing::Font(L"Rubik", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TotalPayment2->ForeColor = System::Drawing::Color::Red;
			this->TotalPayment2->Location = System::Drawing::Point(439, 300);
			this->TotalPayment2->Name = L"TotalPayment2";
			this->TotalPayment2->Size = System::Drawing::Size(366, 28);
			this->TotalPayment2->TabIndex = 39;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->BackColor = System::Drawing::Color::Transparent;
			this->label72->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label72->ForeColor = System::Drawing::Color::Lavender;
			this->label72->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label72->Location = System::Drawing::Point(26, 263);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(224, 34);
			this->label72->TabIndex = 38;
			this->label72->Text = L"Основной платёж:";
			// 
			// MonthlyPayment2
			// 
			this->MonthlyPayment2->BackColor = System::Drawing::Color::Lavender;
			this->MonthlyPayment2->Enabled = false;
			this->MonthlyPayment2->Font = (gcnew System::Drawing::Font(L"Rubik", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MonthlyPayment2->ForeColor = System::Drawing::Color::Yellow;
			this->MonthlyPayment2->Location = System::Drawing::Point(31, 300);
			this->MonthlyPayment2->Name = L"MonthlyPayment2";
			this->MonthlyPayment2->Size = System::Drawing::Size(366, 28);
			this->MonthlyPayment2->TabIndex = 37;
			// 
			// toolTip11
			// 
			this->toolTip11->AutoPopDelay = 5000;
			this->toolTip11->BackColor = System::Drawing::Color::Lavender;
			this->toolTip11->InitialDelay = 200;
			this->toolTip11->ReshowDelay = 100;
			this->toolTip11->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->toolTip11->ToolTipTitle = L"Внимание!";
			// 
			// toolTip12
			// 
			this->toolTip12->AutoPopDelay = 5000;
			this->toolTip12->BackColor = System::Drawing::Color::Lavender;
			this->toolTip12->InitialDelay = 200;
			this->toolTip12->ReshowDelay = 100;
			this->toolTip12->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// toolTip13
			// 
			this->toolTip13->AutoPopDelay = 5000;
			this->toolTip13->BackColor = System::Drawing::Color::Lavender;
			this->toolTip13->InitialDelay = 200;
			this->toolTip13->ReshowDelay = 100;
			this->toolTip13->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// toolTip14
			// 
			this->toolTip14->AutoPopDelay = 5000;
			this->toolTip14->BackColor = System::Drawing::Color::Lavender;
			this->toolTip14->InitialDelay = 200;
			this->toolTip14->ReshowDelay = 100;
			this->toolTip14->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// toolTip15
			// 
			this->toolTip15->AutoPopDelay = 5000;
			this->toolTip15->BackColor = System::Drawing::Color::Lavender;
			this->toolTip15->InitialDelay = 200;
			this->toolTip15->ReshowDelay = 100;
			this->toolTip15->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Indigo;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1182, 423);
			this->Controls->Add(this->label82);
			this->Controls->Add(this->TotalPayment2);
			this->Controls->Add(this->label72);
			this->Controls->Add(this->MonthlyPayment2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Days2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->Calculate2);
			this->Controls->Add(this->label62);
			this->Controls->Add(this->Rate2);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->Loan2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm1";
			this->Text = L"Кредит с дифференцированными платежами";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->Close();
	}
		   //функции-проверки ввода полей
		   bool check_input_Loan2() {
			   if (Loan2->Text->Length == 0) return false;
			   for (unsigned int i = 0; i < Loan2->Text->Length; i++) {
				   if (Loan2->Text[i] >= '0' && Loan2->Text[i] <= '9' || Loan2->Text[i] == ',') {}
				   else return false;
				   return true;
			   }
		   }
		   bool check_input_Days2() {
			   if (Days2->Text->Length == 0) return false;
			   for (unsigned int i = 0; i < Days2->Text->Length; i++) {
				   if (Days2->Text[i] >= '0' && Days2->Text[i] <= '9') {}
				   else return false;
				   return true;
			   }
		   }
		   bool check_input_Rate2() {
			   if (Rate2->Text->Length == 0) return false;
			   for (unsigned int i = 0; i < Rate2->Text->Length; i++) {
				   if (Rate2->Text[i] >= '0' && Rate2->Text[i] <= '9' || Rate2->Text[i] == ',') {}
				   else return false;
				   return true;
			   }
		   }

	private: System::Void Calculate2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (check_input_Loan2() && check_input_Days2() && check_input_Rate2()) {
			double b, S, N, DP, P, Sum = 0, Ost;
			S = System::Convert::ToDouble(Loan2->Text);
			P = System::Convert::ToDouble(Rate2->Text);
			N = System::Convert::ToDouble(Days2->Text);
			Ost = S;
			b = S / N;
			P /= 100;
			while (Ost > 0) {
				DP = b + (Ost * (P / 12));
				Sum += DP;
				Ost -= b;
			}
			b = int(b);
			Sum = int(Sum);
			MonthlyPayment2->Text = System::Convert::ToString(b);
			TotalPayment2->Text = System::Convert::ToString(Sum);
		}else MessageBox::Show("Введены некорректные данные!");
	}
private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e) {
	Loan2->Text = "";
	Rate2->Text = "";
	Days2->Text = "";
	MonthlyPayment2->Text = ""; TotalPayment2->Text = "";
}
};
}

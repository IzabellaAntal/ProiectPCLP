#pragma once


namespace ProiectPCLP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loginButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  usernameTextbox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  passwordTextBox;

	protected:

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
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->usernameTextbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// loginButton
			// 
			this->loginButton->BackColor = System::Drawing::SystemColors::Control;
			this->loginButton->Cursor = System::Windows::Forms::Cursors::Default;
			this->loginButton->Location = System::Drawing::Point(187, 162);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(75, 23);
			this->loginButton->TabIndex = 0;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = false;
			this->loginButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(153, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Username";
			// 
			// usernameTextbox
			// 
			this->usernameTextbox->Location = System::Drawing::Point(227, 79);
			this->usernameTextbox->Name = L"usernameTextbox";
			this->usernameTextbox->Size = System::Drawing::Size(100, 20);
			this->usernameTextbox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(156, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(227, 115);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(100, 20);
			this->passwordTextBox->TabIndex = 4;
			this->passwordTextBox->UseSystemPasswordChar = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 254);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->usernameTextbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->loginButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ connectionInfo = "datasource=127.0.0.1;port=3306;username=root;password=;database=carrental;SslMode=none";
		String^ SQLQuery = "select * from utilizatori where NumeUtilizator = " + "'" + usernameTextbox->Text + "'" + " and Parola = " + "'" + passwordTextBox->Text + "'" + ";";
		MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
		MySqlCommand^ connCmd = gcnew MySqlCommand(SQLQuery, conn);
		MySqlDataReader^ dataReader;

		try {
			conn->Open();
			dataReader = connCmd->ExecuteReader();
			int count = 0;
			while (dataReader->Read()) {
				count++;
			}
			if (count == 1) {
				StartPage^ page = gcnew StartPage();
				this->Hide();
				page->Show(this);
			}
			else {
				usernameTextbox->Text = "";
				passwordTextBox->Text = "";
				MessageBox::Show("user si pass gresite");
			}

		}
		catch (Exception^ex) {
			MessageBox::Show(ex->Message);
		}
	}
	};
}

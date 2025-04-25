#pragma once
#include <string>
#include <list>
#include <msclr/marshal_cppstd.h>


namespace ProyectodeAplicacion2VERSION2HéctorFlores {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();




		}

		
		//Funcion que valida si se cumplieron los parámetros correctos para el ingreso del NIt, teléfono y correo del Proveedor

		bool ValidarProveedor(String^ nit, String^ telefono, String^ correo)
		{
			
			if (nit->Length != 9 || telefono->Length != 8 || correo->IndexOf('@') == -1 || correo->IndexOf('.') == -1)
			{
				return false;
			}
			
			return true;
		
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		bool Cerrar = false;


	private: System::Windows::Forms::Button^ EnterPro;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtDireccionF;
	private: System::Windows::Forms::TextBox^ txtNIT;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtDireccion;
	private: System::Windows::Forms::TextBox^ txtTelefono;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtCorreo;
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
			this->EnterPro = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtDireccionF = (gcnew System::Windows::Forms::TextBox());
			this->txtNIT = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtDireccion = (gcnew System::Windows::Forms::TextBox());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// EnterPro
			// 
			this->EnterPro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnterPro->Location = System::Drawing::Point(214, 328);
			this->EnterPro->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->EnterPro->Name = L"EnterPro";
			this->EnterPro->Size = System::Drawing::Size(85, 30);
			this->EnterPro->TabIndex = 0;
			this->EnterPro->Text = L"Ingresar";
			this->EnterPro->UseVisualStyleBackColor = true;
			this->EnterPro->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(209, 23);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Proveedor";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(150, 75);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(150, 112);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 19);
			this->label3->TabIndex = 3;
			this->label3->Text = L"NIT:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(150, 148);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 19);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Dirección Fiscal:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm1::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(150, 188);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 19);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Dirección:";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(150, 232);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 19);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Teléfono:";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm1::label6_Click);
			// 
			// txtDireccionF
			// 
			this->txtDireccionF->Location = System::Drawing::Point(276, 148);
			this->txtDireccionF->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtDireccionF->Name = L"txtDireccionF";
			this->txtDireccionF->Size = System::Drawing::Size(144, 20);
			this->txtDireccionF->TabIndex = 11;
			this->txtDireccionF->TextChanged += gcnew System::EventHandler(this, &MyForm1::txtDireccionF_TextChanged);
			// 
			// txtNIT
			// 
			this->txtNIT->Location = System::Drawing::Point(190, 112);
			this->txtNIT->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtNIT->Name = L"txtNIT";
			this->txtNIT->Size = System::Drawing::Size(119, 20);
			this->txtNIT->TabIndex = 12;
			this->txtNIT->TextChanged += gcnew System::EventHandler(this, &MyForm1::txtNIT_TextChanged);
			this->txtNIT->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::txtNIT_KeyPress);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(225, 75);
			this->txtNombre->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(106, 20);
			this->txtNombre->TabIndex = 13;
			this->txtNombre->TextChanged += gcnew System::EventHandler(this, &MyForm1::txtNombre_TextChanged);
			// 
			// txtDireccion
			// 
			this->txtDireccion->Location = System::Drawing::Point(239, 188);
			this->txtDireccion->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtDireccion->Name = L"txtDireccion";
			this->txtDireccion->Size = System::Drawing::Size(144, 20);
			this->txtDireccion->TabIndex = 14;
			this->txtDireccion->TextChanged += gcnew System::EventHandler(this, &MyForm1::txtDireccion_TextChanged);
			// 
			// txtTelefono
			// 
			this->txtTelefono->Location = System::Drawing::Point(225, 232);
			this->txtTelefono->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(90, 20);
			this->txtTelefono->TabIndex = 15;
			this->txtTelefono->TextChanged += gcnew System::EventHandler(this, &MyForm1::txtTelefono_TextChanged);
			this->txtTelefono->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::txtTelefono_KeyPress);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(147, 275);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 19);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Correo:";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm1::label7_Click);
			// 
			// txtCorreo
			// 
			this->txtCorreo->Location = System::Drawing::Point(223, 275);
			this->txtCorreo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(90, 20);
			this->txtCorreo->TabIndex = 17;
			this->txtCorreo->TextChanged += gcnew System::EventHandler(this, &MyForm1::txtCorreo_TextChanged);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 390);
			this->ControlBox = false;
			this->Controls->Add(this->txtCorreo);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txtTelefono);
			this->Controls->Add(this->txtDireccion);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->txtNIT);
			this->Controls->Add(this->txtDireccionF);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->EnterPro);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm1::MyForm1_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: String^ GetNameP()
		{
			return txtNombre->Text;
		}

		public: String^ GetNITForm()
		{
			return txtNIT->Text;
		}

		public: String^ GetDireccionFform()
		{
			return txtDireccionF->Text;
		}

		public: String^ GetDireccionForm()
		{
			return txtDireccion->Text;
		}

		public: String^ GetTelefonoForm()
		{
			return txtTelefono->Text;
		}

		public: String ^ GetCorreoForm()
		{
			return txtCorreo->Text;
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		

		if (txtNombre->Text != " " || txtNIT->Text != " " || txtDireccion->Text != " " || txtDireccionF->Text!= " " || txtTelefono->Text != " " || txtCorreo->Text != " ")
		{
			
			if (ValidarProveedor(GetNITForm(), GetTelefonoForm(), GetCorreoForm()))
			{
			
				Cerrar = true;

				this->Close();
					 
			}
			else 
			{
				MessageBox::Show("No ha ingresado correctamente el Nit, el Número de Teléfono o el correo electrónico", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

		}else
		{
			MessageBox::Show("Un campo de información esta vacío", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

	


	}
	private: System::Void txtNIT_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}

	}
private: System::Void txtTelefono_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}
private: System::Void MyForm1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

	if (Cerrar == false)
	{
		MessageBox::Show("Por favor, no cierre esta ventana hasta que haya completado el llenado de información", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Stop);

		e->Cancel = true;
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtNombre_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtNIT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtDireccionF_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtDireccion_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtTelefono_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtCorreo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

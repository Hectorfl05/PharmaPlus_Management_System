#pragma once
#include "Inventario.h"

namespace ProyectodeAplicacion2VERSION2HéctorFlores {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{


	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		bool TxtBoxLlenos(Panel^ panel)
		{
			for each (Control ^ control in panel->Controls)
			{
				if (control->GetType() == TextBox::typeid)
				{
					TextBox^ textBox = dynamic_cast<TextBox^>(control);
					if (String::IsNullOrWhiteSpace(textBox->Text))
					{
						return false; // Si algún TextBox está vacío, retorna falso
					}
				}
			}
			return true; // Si todos los TextBox están llenos, retorna verdadero
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	
		bool CambioVerdadero = true;
		
	
	


	protected:



	private:






	private:



	private:




	private:



	private:




	private:



	private:



	private:



	private:



	private:



	private:

	private:

	private:


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ PanelAct;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ BotonCancelar;
	private: System::Windows::Forms::Button^ BotonActualizar;
	internal: System::Windows::Forms::TextBox^ TVenta;
	private:
	internal: System::Windows::Forms::TextBox^ Tdia;
	private: System::Windows::Forms::Label^ label13;
	internal:
	internal: System::Windows::Forms::TextBox^ Tmes;
	private:
	private: System::Windows::Forms::Label^ label12;
	internal:
	internal: System::Windows::Forms::TextBox^ Tano;
	private:
	private: System::Windows::Forms::Label^ label11;
	internal:
	private: System::Windows::Forms::Label^ label10;
	internal: System::Windows::Forms::TextBox^ TCompra;
	private:
	private: System::Windows::Forms::Label^ label9;
	internal:
	internal: System::Windows::Forms::ComboBox^ TboxProveedor;
	private:
	private: System::Windows::Forms::Label^ label8;
	internal:
	private: System::Windows::Forms::Label^ label7;
	internal: System::Windows::Forms::TextBox^ TStock;
	private:
	private: System::Windows::Forms::Label^ label5;
	internal:
	internal: System::Windows::Forms::TextBox^ TC;
	private:
	private: System::Windows::Forms::Label^ lb5P1;
	internal:
	internal: System::Windows::Forms::TextBox^ TPrincipio;
	private:
	private: System::Windows::Forms::Label^ lb4P1;
	internal:
	internal: System::Windows::Forms::ComboBox^ TboxCategoria;
	private:
	private: System::Windows::Forms::Label^ lb3P1;
	internal:
	internal: System::Windows::Forms::TextBox^ Tnombre;
	private:
	private: System::Windows::Forms::Label^ label3;
	internal:


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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->PanelAct = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->BotonCancelar = (gcnew System::Windows::Forms::Button());
			this->BotonActualizar = (gcnew System::Windows::Forms::Button());
			this->TVenta = (gcnew System::Windows::Forms::TextBox());
			this->Tdia = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->Tmes = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->Tano = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->TCompra = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->TboxProveedor = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->TStock = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->TC = (gcnew System::Windows::Forms::TextBox());
			this->lb5P1 = (gcnew System::Windows::Forms::Label());
			this->TPrincipio = (gcnew System::Windows::Forms::TextBox());
			this->lb4P1 = (gcnew System::Windows::Forms::Label());
			this->TboxCategoria = (gcnew System::Windows::Forms::ComboBox());
			this->lb3P1 = (gcnew System::Windows::Forms::Label());
			this->Tnombre = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->PanelAct->SuspendLayout();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(136, -25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(542, 23);
			this->label4->TabIndex = 117;
			this->label4->Text = L"Ingrese la información del medicamento";
			// 
			// PanelAct
			// 
			this->PanelAct->Controls->Add(this->label2);
			this->PanelAct->Controls->Add(this->BotonCancelar);
			this->PanelAct->Controls->Add(this->BotonActualizar);
			this->PanelAct->Controls->Add(this->TVenta);
			this->PanelAct->Controls->Add(this->Tdia);
			this->PanelAct->Controls->Add(this->label13);
			this->PanelAct->Controls->Add(this->Tmes);
			this->PanelAct->Controls->Add(this->label12);
			this->PanelAct->Controls->Add(this->Tano);
			this->PanelAct->Controls->Add(this->label11);
			this->PanelAct->Controls->Add(this->label10);
			this->PanelAct->Controls->Add(this->TCompra);
			this->PanelAct->Controls->Add(this->label9);
			this->PanelAct->Controls->Add(this->TboxProveedor);
			this->PanelAct->Controls->Add(this->label8);
			this->PanelAct->Controls->Add(this->label7);
			this->PanelAct->Controls->Add(this->TStock);
			this->PanelAct->Controls->Add(this->label5);
			this->PanelAct->Controls->Add(this->TC);
			this->PanelAct->Controls->Add(this->lb5P1);
			this->PanelAct->Controls->Add(this->TPrincipio);
			this->PanelAct->Controls->Add(this->lb4P1);
			this->PanelAct->Controls->Add(this->TboxCategoria);
			this->PanelAct->Controls->Add(this->lb3P1);
			this->PanelAct->Controls->Add(this->Tnombre);
			this->PanelAct->Controls->Add(this->label3);
			this->PanelAct->Location = System::Drawing::Point(0, 0);
			this->PanelAct->Name = L"PanelAct";
			this->PanelAct->Size = System::Drawing::Size(822, 552);
			this->PanelAct->TabIndex = 118;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(363, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 22);
			this->label2->TabIndex = 171;
			this->label2->Text = L"(mg o ml)";
			// 
			// BotonCancelar
			// 
			this->BotonCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonCancelar->Location = System::Drawing::Point(480, 466);
			this->BotonCancelar->Name = L"BotonCancelar";
			this->BotonCancelar->Size = System::Drawing::Size(107, 38);
			this->BotonCancelar->TabIndex = 170;
			this->BotonCancelar->Text = L"Cancelar";
			this->BotonCancelar->UseVisualStyleBackColor = true;
			this->BotonCancelar->Click += gcnew System::EventHandler(this, &MyForm2::BotonCancelar_Click);
			// 
			// BotonActualizar
			// 
			this->BotonActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonActualizar->Location = System::Drawing::Point(292, 466);
			this->BotonActualizar->Name = L"BotonActualizar";
			this->BotonActualizar->Size = System::Drawing::Size(107, 38);
			this->BotonActualizar->TabIndex = 169;
			this->BotonActualizar->Text = L"Actualizar";
			this->BotonActualizar->UseVisualStyleBackColor = true;
			this->BotonActualizar->Click += gcnew System::EventHandler(this, &MyForm2::BotonActualizar_Click);
			// 
			// TVenta
			// 
			this->TVenta->Location = System::Drawing::Point(600, 399);
			this->TVenta->Name = L"TVenta";
			this->TVenta->Size = System::Drawing::Size(78, 22);
			this->TVenta->TabIndex = 168;
			// 
			// Tdia
			// 
			this->Tdia->Location = System::Drawing::Point(679, 254);
			this->Tdia->Name = L"Tdia";
			this->Tdia->Size = System::Drawing::Size(78, 22);
			this->Tdia->TabIndex = 167;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(631, 254);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(42, 22);
			this->label13->TabIndex = 166;
			this->label13->Text = L"Dia:";
			// 
			// Tmes
			// 
			this->Tmes->Location = System::Drawing::Point(521, 256);
			this->Tmes->Name = L"Tmes";
			this->Tmes->Size = System::Drawing::Size(78, 22);
			this->Tmes->TabIndex = 165;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(467, 256);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 22);
			this->label12->TabIndex = 164;
			this->label12->Text = L"Mes:";
			// 
			// Tano
			// 
			this->Tano->Location = System::Drawing::Point(369, 258);
			this->Tano->Name = L"Tano";
			this->Tano->Size = System::Drawing::Size(78, 22);
			this->Tano->TabIndex = 163;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(304, 258);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(47, 22);
			this->label11->TabIndex = 162;
			this->label11->Text = L"Año:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(444, 397);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(143, 22);
			this->label10->TabIndex = 161;
			this->label10->Text = L"Precio de Venta:";
			// 
			// TCompra
			// 
			this->TCompra->Location = System::Drawing::Point(308, 399);
			this->TCompra->Name = L"TCompra";
			this->TCompra->Size = System::Drawing::Size(78, 22);
			this->TCompra->TabIndex = 160;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(127, 397);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(159, 22);
			this->label9->TabIndex = 159;
			this->label9->Text = L"Precio de Compra:";
			// 
			// TboxProveedor
			// 
			this->TboxProveedor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TboxProveedor->FormattingEnabled = true;
			this->TboxProveedor->Location = System::Drawing::Point(458, 328);
			this->TboxProveedor->Name = L"TboxProveedor";
			this->TboxProveedor->Size = System::Drawing::Size(97, 24);
			this->TboxProveedor->TabIndex = 158;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(331, 330);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 22);
			this->label8->TabIndex = 157;
			this->label8->Text = L"Proveedor:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(95, 258);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(181, 22);
			this->label7->TabIndex = 156;
			this->label7->Text = L"Fecha de Caducidad:";
			// 
			// TStock
			// 
			this->TStock->Location = System::Drawing::Point(647, 186);
			this->TStock->Name = L"TStock";
			this->TStock->Size = System::Drawing::Size(78, 22);
			this->TStock->TabIndex = 155;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(467, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(162, 22);
			this->label5->TabIndex = 154;
			this->label5->Text = L"Cantidad en Stock:";
			// 
			// TC
			// 
			this->TC->Location = System::Drawing::Point(263, 186);
			this->TC->Name = L"TC";
			this->TC->Size = System::Drawing::Size(88, 22);
			this->TC->TabIndex = 153;
			// 
			// lb5P1
			// 
			this->lb5P1->AutoSize = true;
			this->lb5P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb5P1->Location = System::Drawing::Point(66, 186);
			this->lb5P1->Name = L"lb5P1";
			this->lb5P1->Size = System::Drawing::Size(181, 22);
			this->lb5P1->TabIndex = 152;
			this->lb5P1->Text = L"Dosis Recomendada:";
			// 
			// TPrincipio
			// 
			this->TPrincipio->Location = System::Drawing::Point(600, 78);
			this->TPrincipio->Name = L"TPrincipio";
			this->TPrincipio->Size = System::Drawing::Size(125, 22);
			this->TPrincipio->TabIndex = 151;
			// 
			// lb4P1
			// 
			this->lb4P1->AutoSize = true;
			this->lb4P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb4P1->Location = System::Drawing::Point(429, 78);
			this->lb4P1->Name = L"lb4P1";
			this->lb4P1->Size = System::Drawing::Size(138, 22);
			this->lb4P1->TabIndex = 150;
			this->lb4P1->Text = L"Principio Activo:";
			// 
			// TboxCategoria
			// 
			this->TboxCategoria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TboxCategoria->FormattingEnabled = true;
			this->TboxCategoria->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Orales", L"Inyectables", L"Soluciones", L"Sueros",
					L"Uso externo y antisépticos", L"Desinfectantes"
			});
			this->TboxCategoria->Location = System::Drawing::Point(220, 115);
			this->TboxCategoria->Name = L"TboxCategoria";
			this->TboxCategoria->Size = System::Drawing::Size(137, 24);
			this->TboxCategoria->TabIndex = 149;
			// 
			// lb3P1
			// 
			this->lb3P1->AutoSize = true;
			this->lb3P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb3P1->Location = System::Drawing::Point(80, 115);
			this->lb3P1->Name = L"lb3P1";
			this->lb3P1->Size = System::Drawing::Size(93, 22);
			this->lb3P1->TabIndex = 148;
			this->lb3P1->Text = L"Categoría:";
			// 
			// Tnombre
			// 
			this->Tnombre->Location = System::Drawing::Point(220, 49);
			this->Tnombre->Name = L"Tnombre";
			this->Tnombre->Size = System::Drawing::Size(125, 22);
			this->Tnombre->TabIndex = 147;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(95, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 22);
			this->label3->TabIndex = 146;
			this->label3->Text = L"Nombre:";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 549);
			this->ControlBox = false;
			this->Controls->Add(this->PanelAct);
			this->Controls->Add(this->label4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->PanelAct->ResumeLayout(false);
			this->PanelAct->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion

	public:

		bool GetStatusCambio()
		{
			return CambioVerdadero;
		}


	private: System::Void BotonCancelar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
			CambioVerdadero = false;
			this->Close();


	}

private: System::Void BotonActualizar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (TxtBoxLlenos(PanelAct) && TboxCategoria->Text != "" && TboxProveedor->Text != " ")
	{
		CambioVerdadero = true;
		this->Close();
	}
	else
	{

		MessageBox::Show("Llene todos los campos de información", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

	
}

private: System::Void Tregistro_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void TC_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}


private: System::Void TStock_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}


private: System::Void Tano_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}

private: System::Void Tmes_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}
private: System::Void Tdia_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}
private: System::Void TCompra_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void TVenta_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}

};
}

#pragma once
#include <list>
#include "Inventario.h"
#include "Medicamento.h"
#include <msclr/marshal_cppstd.h>
#include "MyForm1.h"
#include <string>
#include "MyForm2.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vcclr.h>





namespace ProyectodeAplicacion2VERSION2HéctorFlores {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;

	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	//Listas Globales 
	list<Inventario> Medicinas;

	list<Proveedor> proveedores;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			

		}

		
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ radioProveedor;
	private: System::Windows::Forms::RadioButton^ radioCategoria;
	private: System::Windows::Forms::RadioButton^ radioPrincipio;
	private: System::Windows::Forms::RadioButton^ radioNombre;
	private: System::Windows::Forms::DataGridView^ tablaFiltro;











	private: System::Windows::Forms::Label^ lbFiltro;

	private: System::Windows::Forms::ComboBox^ cboxFiltro;
	private: System::Windows::Forms::TextBox^ txtbfiltro;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NombreMed;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumRegistro;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumCateg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumPrincipio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumDosis;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumStock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumCaducidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumProveedor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumCompra;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumVenta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::Button^ BtnActPro;
	private: System::Windows::Forms::TabPage^ Tab9;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::ComboBox^ comboBoxActPro;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::TextBox^ txtbCorreoAct;

	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::TextBox^ txtbTelefonoAct;

	private: System::Windows::Forms::TextBox^ txtbDireccionAct;

	private: System::Windows::Forms::TextBox^ txtbNameAct;
	private: System::Windows::Forms::TextBox^ txtbNITAct;
	private: System::Windows::Forms::TextBox^ txtbDireccionFAct;



	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Button^ CancelarAct;
	private: System::Windows::Forms::Button^ btnActualizar;
	private: System::Windows::Forms::Button^ F6Regresar;




	public:

		//Variable Global para el No. de Registro de los medicamentos
		static int Id = 10000;

		//Funcion que comprueba que todos los TxtBox esten llenos

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

		void VaciarTxtbox(Panel^ panel)
		{
			for each(Control ^ control in panel-> Controls)
			{
				if(control -> GetType() == TextBox::typeid)
				{
					TextBox^ textbox = dynamic_cast<TextBox^>(control);
					
					textbox->Text = "";

				}
			
			}
		
		
		}



		void LLenarTabla(std::list<Inventario> listado, DataGridView^% tabla)
		{
			// Se inicializa el iterador

			list<Inventario>::iterator iterador;

			for (iterador = listado.begin(); iterador != listado.end(); ++iterador)
			{
				//Se agrega un nuevo renglon
				int n = tabla->Rows->Add();

				//Se coloca la información en la tabla

				tabla->Rows[n]->Cells[0]->Value = msclr::interop::marshal_as<String^>(iterador->GetName());
				tabla->Rows[n]->Cells[1]->Value = iterador->GetRegistro().ToString();
				tabla->Rows[n]->Cells[2]->Value = msclr::interop::marshal_as<String^>(iterador->GetCategoria());
				tabla->Rows[n]->Cells[3]->Value = msclr::interop::marshal_as<String^>(iterador->GetPrincipio());
				tabla->Rows[n]->Cells[4]->Value = iterador->GetDosis().ToString();
				tabla->Rows[n]->Cells[5]->Value = iterador->GetStock().ToString();
				tabla->Rows[n]->Cells[6]->Value = msclr::interop::marshal_as<String^>(iterador->GetCaducidad());
				tabla->Rows[n]->Cells[7]->Value = msclr::interop::marshal_as<String^>(iterador->GetProveedor().GetNombreP());

				tabla->Rows[n]->Cells[8]->Value = String::Format(" {0:0.00}", iterador->GetCompra());
				tabla->Rows[n]->Cells[9]->Value = String::Format(" {0:0.00}", iterador->GetVenta());


			}


		}

		void VaciarTabla(DataGridView^% tabla)
		{
			if (tabla->Rows->Count > 0)
			{
				for (int i = tabla->Rows->Count - 1; i >= 0; i--)
				{

					tabla->Rows->RemoveAt(i);

				}

			}
		
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
	private: System::Windows::Forms::TabControl^ Menus;
	private: System::Windows::Forms::TabPage^ Principal;


	protected:

	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TabPage^ Tab1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ Ingresar;
	private: System::Windows::Forms::TextBox^ txtVenta;
	private: System::Windows::Forms::TextBox^ txtdia;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ txtmes;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txtano;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtCompra;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ boxProveedor;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtStock;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtC;
	private: System::Windows::Forms::Label^ lb5P1;
	private: System::Windows::Forms::TextBox^ txtPrincipio;
	private: System::Windows::Forms::Label^ lb4P1;
	private: System::Windows::Forms::ComboBox^ boxCategoria;
	private: System::Windows::Forms::Label^ lb3P1;


	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ lb1P1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TabPage^ Tab2;
private: System::Windows::Forms::DataGridView^ TablaAct;










private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Button^ RegresarOp2;










private: System::Windows::Forms::TabPage^ Tab3;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::RadioButton^ ParametroPr;

private: System::Windows::Forms::RadioButton^ ParametroN;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ L4b1;
private: System::Windows::Forms::Button^ SearchInfo;
private: System::Windows::Forms::TextBox^ txtboxSearch1;

private: System::Windows::Forms::Label^ l4bPrincipio;
private: System::Windows::Forms::Label^ l4bDosis;
private: System::Windows::Forms::Label^ l4bCategoria;
private: System::Windows::Forms::Label^ l4bRegistro;
private: System::Windows::Forms::Label^ l4bnombre;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label18;

private: System::Windows::Forms::Button^ RegresarF3;
private: System::Windows::Forms::TabPage^ Tab4;
private: System::Windows::Forms::TabPage^ Tab5;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ MedDisponibles;

private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ PrecioTotal;
private: System::Windows::Forms::Button^ btnPromedio;
private: System::Windows::Forms::Label^ lbPromedio;

private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Button^ RegresarF5;

private: System::Windows::Forms::TabPage^ Tab6;
private: System::Windows::Forms::RichTextBox^ MostrarInventario;

private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::ComboBox^ NameBox;
private: System::Windows::Forms::Button^ RegresarF6;
private: System::Windows::Forms::TabPage^ Tab7;
private: System::Windows::Forms::TabPage^ Tab8;
private: System::Windows::Forms::Button^ button12;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::ComboBox^ ProveedorBox;
private: System::Windows::Forms::RichTextBox^ MostrarProveedor;

private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::Button^ RegresarF4;
private: System::Windows::Forms::Button^ btnExportar;
private: System::Windows::Forms::RichTextBox^ TxtboxInforme;



















	


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
			this->Menus = (gcnew System::Windows::Forms::TabControl());
			this->Principal = (gcnew System::Windows::Forms::TabPage());
			this->BtnActPro = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Tab1 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->Ingresar = (gcnew System::Windows::Forms::Button());
			this->txtVenta = (gcnew System::Windows::Forms::TextBox());
			this->txtdia = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtmes = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtano = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtCompra = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->boxProveedor = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtStock = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtC = (gcnew System::Windows::Forms::TextBox());
			this->lb5P1 = (gcnew System::Windows::Forms::Label());
			this->txtPrincipio = (gcnew System::Windows::Forms::TextBox());
			this->lb4P1 = (gcnew System::Windows::Forms::Label());
			this->boxCategoria = (gcnew System::Windows::Forms::ComboBox());
			this->lb3P1 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lb1P1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Tab2 = (gcnew System::Windows::Forms::TabPage());
			this->RegresarOp2 = (gcnew System::Windows::Forms::Button());
			this->TablaAct = (gcnew System::Windows::Forms::DataGridView());
			this->NombreMed = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumRegistro = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumCateg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumPrincipio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumDosis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumCaducidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumProveedor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumCompra = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumVenta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->Tab3 = (gcnew System::Windows::Forms::TabPage());
			this->RegresarF3 = (gcnew System::Windows::Forms::Button());
			this->l4bPrincipio = (gcnew System::Windows::Forms::Label());
			this->l4bDosis = (gcnew System::Windows::Forms::Label());
			this->l4bCategoria = (gcnew System::Windows::Forms::Label());
			this->l4bRegistro = (gcnew System::Windows::Forms::Label());
			this->l4bnombre = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->L4b1 = (gcnew System::Windows::Forms::Label());
			this->SearchInfo = (gcnew System::Windows::Forms::Button());
			this->txtboxSearch1 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->ParametroPr = (gcnew System::Windows::Forms::RadioButton());
			this->ParametroN = (gcnew System::Windows::Forms::RadioButton());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->Tab4 = (gcnew System::Windows::Forms::TabPage());
			this->RegresarF4 = (gcnew System::Windows::Forms::Button());
			this->btnExportar = (gcnew System::Windows::Forms::Button());
			this->TxtboxInforme = (gcnew System::Windows::Forms::RichTextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->Tab5 = (gcnew System::Windows::Forms::TabPage());
			this->RegresarF5 = (gcnew System::Windows::Forms::Button());
			this->lbPromedio = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->btnPromedio = (gcnew System::Windows::Forms::Button());
			this->PrecioTotal = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->MedDisponibles = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->Tab6 = (gcnew System::Windows::Forms::TabPage());
			this->RegresarF6 = (gcnew System::Windows::Forms::Button());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->NameBox = (gcnew System::Windows::Forms::ComboBox());
			this->MostrarInventario = (gcnew System::Windows::Forms::RichTextBox());
			this->Tab7 = (gcnew System::Windows::Forms::TabPage());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->ProveedorBox = (gcnew System::Windows::Forms::ComboBox());
			this->MostrarProveedor = (gcnew System::Windows::Forms::RichTextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->Tab8 = (gcnew System::Windows::Forms::TabPage());
			this->F6Regresar = (gcnew System::Windows::Forms::Button());
			this->txtbfiltro = (gcnew System::Windows::Forms::TextBox());
			this->lbFiltro = (gcnew System::Windows::Forms::Label());
			this->cboxFiltro = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioProveedor = (gcnew System::Windows::Forms::RadioButton());
			this->radioCategoria = (gcnew System::Windows::Forms::RadioButton());
			this->radioPrincipio = (gcnew System::Windows::Forms::RadioButton());
			this->radioNombre = (gcnew System::Windows::Forms::RadioButton());
			this->tablaFiltro = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->Tab9 = (gcnew System::Windows::Forms::TabPage());
			this->CancelarAct = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->comboBoxActPro = (gcnew System::Windows::Forms::ComboBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->txtbCorreoAct = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->txtbTelefonoAct = (gcnew System::Windows::Forms::TextBox());
			this->txtbDireccionAct = (gcnew System::Windows::Forms::TextBox());
			this->txtbNameAct = (gcnew System::Windows::Forms::TextBox());
			this->txtbNITAct = (gcnew System::Windows::Forms::TextBox());
			this->txtbDireccionFAct = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->Menus->SuspendLayout();
			this->Principal->SuspendLayout();
			this->Tab1->SuspendLayout();
			this->Tab2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaAct))->BeginInit();
			this->Tab3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->Tab4->SuspendLayout();
			this->Tab5->SuspendLayout();
			this->Tab6->SuspendLayout();
			this->Tab7->SuspendLayout();
			this->Tab8->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaFiltro))->BeginInit();
			this->Tab9->SuspendLayout();
			this->SuspendLayout();
			// 
			// Menus
			// 
			this->Menus->Controls->Add(this->Principal);
			this->Menus->Controls->Add(this->Tab1);
			this->Menus->Controls->Add(this->Tab2);
			this->Menus->Controls->Add(this->Tab3);
			this->Menus->Controls->Add(this->Tab4);
			this->Menus->Controls->Add(this->Tab5);
			this->Menus->Controls->Add(this->Tab6);
			this->Menus->Controls->Add(this->Tab7);
			this->Menus->Controls->Add(this->Tab8);
			this->Menus->Controls->Add(this->Tab9);
			this->Menus->Location = System::Drawing::Point(0, -27);
			this->Menus->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Menus->Name = L"Menus";
			this->Menus->SelectedIndex = 0;
			this->Menus->Size = System::Drawing::Size(1395, 738);
			this->Menus->TabIndex = 22;
			// 
			// Principal
			// 
			this->Principal->Controls->Add(this->BtnActPro);
			this->Principal->Controls->Add(this->label6);
			this->Principal->Controls->Add(this->button9);
			this->Principal->Controls->Add(this->button11);
			this->Principal->Controls->Add(this->button8);
			this->Principal->Controls->Add(this->button7);
			this->Principal->Controls->Add(this->button6);
			this->Principal->Controls->Add(this->button5);
			this->Principal->Controls->Add(this->button4);
			this->Principal->Controls->Add(this->button3);
			this->Principal->Controls->Add(this->button2);
			this->Principal->Controls->Add(this->button1);
			this->Principal->Location = System::Drawing::Point(4, 25);
			this->Principal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Principal->Name = L"Principal";
			this->Principal->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Principal->Size = System::Drawing::Size(1387, 681);
			this->Principal->TabIndex = 1;
			this->Principal->Text = L"Menu Principal";
			this->Principal->UseVisualStyleBackColor = true;
			// 
			// BtnActPro
			// 
			this->BtnActPro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnActPro->Location = System::Drawing::Point(9, 596);
			this->BtnActPro->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->BtnActPro->Name = L"BtnActPro";
			this->BtnActPro->Size = System::Drawing::Size(253, 43);
			this->BtnActPro->TabIndex = 119;
			this->BtnActPro->Text = L"Modificar Proveedor";
			this->BtnActPro->UseVisualStyleBackColor = true;
			this->BtnActPro->Visible = false;
			this->BtnActPro->Click += gcnew System::EventHandler(this, &MyForm::BtnActPro_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(581, 38);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(296, 65);
			this->label6->TabIndex = 31;
			this->label6->Text = L"FARMACIAS S.A.";
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(637, 448);
			this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(189, 37);
			this->button9->TabIndex = 29;
			this->button9->Text = L"Salir";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(592, 264);
			this->button11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(272, 39);
			this->button11->TabIndex = 30;
			this->button11->Text = L"Ingresar Proveedor";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(821, 364);
			this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(263, 43);
			this->button8->TabIndex = 28;
			this->button8->Text = L"Busqueda de Medicamentos";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(452, 364);
			this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(193, 43);
			this->button7->TabIndex = 27;
			this->button7->Text = L"Precio más alto ";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(915, 265);
			this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(235, 46);
			this->button6->TabIndex = 26;
			this->button6->Text = L"Inventario del medicamento";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(637, 265);
			this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(188, 46);
			this->button5->TabIndex = 25;
			this->button5->Text = L"Precio Promedio";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(325, 265);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(188, 38);
			this->button4->TabIndex = 24;
			this->button4->Text = L"Generar Informe";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(915, 140);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(227, 47);
			this->button3->TabIndex = 23;
			this->button3->Text = L"Consultar Información";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(627, 140);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(199, 47);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Actualizar Inventario";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(315, 140);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(197, 47);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Nuevo medicamento";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Tab1
			// 
			this->Tab1->Controls->Add(this->label2);
			this->Tab1->Controls->Add(this->button10);
			this->Tab1->Controls->Add(this->Ingresar);
			this->Tab1->Controls->Add(this->txtVenta);
			this->Tab1->Controls->Add(this->txtdia);
			this->Tab1->Controls->Add(this->label13);
			this->Tab1->Controls->Add(this->txtmes);
			this->Tab1->Controls->Add(this->label12);
			this->Tab1->Controls->Add(this->txtano);
			this->Tab1->Controls->Add(this->label11);
			this->Tab1->Controls->Add(this->label10);
			this->Tab1->Controls->Add(this->txtCompra);
			this->Tab1->Controls->Add(this->label9);
			this->Tab1->Controls->Add(this->boxProveedor);
			this->Tab1->Controls->Add(this->label8);
			this->Tab1->Controls->Add(this->label7);
			this->Tab1->Controls->Add(this->txtStock);
			this->Tab1->Controls->Add(this->label5);
			this->Tab1->Controls->Add(this->txtC);
			this->Tab1->Controls->Add(this->lb5P1);
			this->Tab1->Controls->Add(this->txtPrincipio);
			this->Tab1->Controls->Add(this->lb4P1);
			this->Tab1->Controls->Add(this->boxCategoria);
			this->Tab1->Controls->Add(this->lb3P1);
			this->Tab1->Controls->Add(this->txtNombre);
			this->Tab1->Controls->Add(this->label3);
			this->Tab1->Controls->Add(this->label4);
			this->Tab1->Controls->Add(this->lb1P1);
			this->Tab1->Controls->Add(this->label1);
			this->Tab1->Location = System::Drawing::Point(4, 25);
			this->Tab1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab1->Name = L"Tab1";
			this->Tab1->Size = System::Drawing::Size(1387, 709);
			this->Tab1->TabIndex = 2;
			this->Tab1->Text = L"Nuevo Med";
			this->Tab1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(575, 222);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 22);
			this->label2->TabIndex = 116;
			this->label2->Text = L"(mg o ml)";
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(751, 518);
			this->button10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(107, 38);
			this->button10->TabIndex = 115;
			this->button10->Text = L"Regresar";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// Ingresar
			// 
			this->Ingresar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ingresar->Location = System::Drawing::Point(565, 518);
			this->Ingresar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Ingresar->Name = L"Ingresar";
			this->Ingresar->Size = System::Drawing::Size(107, 38);
			this->Ingresar->TabIndex = 114;
			this->Ingresar->Text = L"Ingresar";
			this->Ingresar->UseVisualStyleBackColor = true;
			this->Ingresar->Click += gcnew System::EventHandler(this, &MyForm::Ingresar_Click);
			// 
			// txtVenta
			// 
			this->txtVenta->Location = System::Drawing::Point(845, 434);
			this->txtVenta->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtVenta->Name = L"txtVenta";
			this->txtVenta->Size = System::Drawing::Size(79, 22);
			this->txtVenta->TabIndex = 113;
			this->txtVenta->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtVenta_KeyPress);
			// 
			// txtdia
			// 
			this->txtdia->Location = System::Drawing::Point(909, 290);
			this->txtdia->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtdia->Name = L"txtdia";
			this->txtdia->Size = System::Drawing::Size(79, 22);
			this->txtdia->TabIndex = 112;
			this->txtdia->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtdia_KeyPress);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(861, 290);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(42, 22);
			this->label13->TabIndex = 111;
			this->label13->Text = L"Dia:";
			// 
			// txtmes
			// 
			this->txtmes->Location = System::Drawing::Point(751, 293);
			this->txtmes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtmes->Name = L"txtmes";
			this->txtmes->Size = System::Drawing::Size(79, 22);
			this->txtmes->TabIndex = 110;
			this->txtmes->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtmes_KeyPress);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(697, 293);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 22);
			this->label12->TabIndex = 109;
			this->label12->Text = L"Mes:";
			// 
			// txtano
			// 
			this->txtano->Location = System::Drawing::Point(599, 295);
			this->txtano->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtano->Name = L"txtano";
			this->txtano->Size = System::Drawing::Size(79, 22);
			this->txtano->TabIndex = 108;
			this->txtano->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtano_KeyPress);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(533, 295);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(47, 22);
			this->label11->TabIndex = 107;
			this->label11->Text = L"Año:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(685, 434);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(143, 22);
			this->label10->TabIndex = 106;
			this->label10->Text = L"Precio de Venta:";
			// 
			// txtCompra
			// 
			this->txtCompra->Location = System::Drawing::Point(565, 434);
			this->txtCompra->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtCompra->Name = L"txtCompra";
			this->txtCompra->Size = System::Drawing::Size(79, 22);
			this->txtCompra->TabIndex = 105;
			this->txtCompra->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtCompra_KeyPress);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(387, 434);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(159, 22);
			this->label9->TabIndex = 104;
			this->label9->Text = L"Precio de Compra:";
			// 
			// boxProveedor
			// 
			this->boxProveedor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->boxProveedor->FormattingEnabled = true;
			this->boxProveedor->Location = System::Drawing::Point(688, 366);
			this->boxProveedor->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->boxProveedor->Name = L"boxProveedor";
			this->boxProveedor->Size = System::Drawing::Size(97, 24);
			this->boxProveedor->TabIndex = 103;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(561, 367);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 22);
			this->label8->TabIndex = 102;
			this->label8->Text = L"Proveedor:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(325, 295);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(181, 22);
			this->label7->TabIndex = 101;
			this->label7->Text = L"Fecha de Caducidad:";
			// 
			// txtStock
			// 
			this->txtStock->Location = System::Drawing::Point(877, 223);
			this->txtStock->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStock->Name = L"txtStock";
			this->txtStock->Size = System::Drawing::Size(79, 22);
			this->txtStock->TabIndex = 100;
			this->txtStock->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtStock_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(697, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(162, 22);
			this->label5->TabIndex = 99;
			this->label5->Text = L"Cantidad en Stock:";
			// 
			// txtC
			// 
			this->txtC->Location = System::Drawing::Point(469, 222);
			this->txtC->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtC->Name = L"txtC";
			this->txtC->Size = System::Drawing::Size(87, 22);
			this->txtC->TabIndex = 98;
			this->txtC->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtC_KeyPress);
			// 
			// lb5P1
			// 
			this->lb5P1->AutoSize = true;
			this->lb5P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb5P1->Location = System::Drawing::Point(261, 222);
			this->lb5P1->Name = L"lb5P1";
			this->lb5P1->Size = System::Drawing::Size(181, 22);
			this->lb5P1->TabIndex = 97;
			this->lb5P1->Text = L"Dosis Recomendada:";
			// 
			// txtPrincipio
			// 
			this->txtPrincipio->Location = System::Drawing::Point(845, 117);
			this->txtPrincipio->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtPrincipio->Name = L"txtPrincipio";
			this->txtPrincipio->Size = System::Drawing::Size(125, 22);
			this->txtPrincipio->TabIndex = 96;
			// 
			// lb4P1
			// 
			this->lb4P1->AutoSize = true;
			this->lb4P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb4P1->Location = System::Drawing::Point(664, 117);
			this->lb4P1->Name = L"lb4P1";
			this->lb4P1->Size = System::Drawing::Size(138, 22);
			this->lb4P1->TabIndex = 95;
			this->lb4P1->Text = L"Principio Activo:";
			// 
			// boxCategoria
			// 
			this->boxCategoria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->boxCategoria->FormattingEnabled = true;
			this->boxCategoria->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Orales", L"Inyectables", L"Soluciones", L"Sueros",
					L"Uso externo y antisépticos", L"Desinfectantes"
			});
			this->boxCategoria->Location = System::Drawing::Point(451, 153);
			this->boxCategoria->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->boxCategoria->Name = L"boxCategoria";
			this->boxCategoria->Size = System::Drawing::Size(145, 24);
			this->boxCategoria->TabIndex = 94;
			// 
			// lb3P1
			// 
			this->lb3P1->AutoSize = true;
			this->lb3P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb3P1->Location = System::Drawing::Point(309, 153);
			this->lb3P1->Name = L"lb3P1";
			this->lb3P1->Size = System::Drawing::Size(93, 22);
			this->lb3P1->TabIndex = 93;
			this->lb3P1->Text = L"Categoría:";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(469, 86);
			this->txtNombre->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(125, 22);
			this->txtNombre->TabIndex = 90;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(325, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 22);
			this->label3->TabIndex = 89;
			this->label3->Text = L"Nombre:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(400, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(542, 23);
			this->label4->TabIndex = 88;
			this->label4->Text = L"Ingrese la información del medicamento";
			// 
			// lb1P1
			// 
			this->lb1P1->AutoSize = true;
			this->lb1P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb1P1->Location = System::Drawing::Point(-75, 15);
			this->lb1P1->Name = L"lb1P1";
			this->lb1P1->Size = System::Drawing::Size(78, 22);
			this->lb1P1->TabIndex = 87;
			this->lb1P1->Text = L"Nombre:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(105, -31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(542, 23);
			this->label1->TabIndex = 86;
			this->label1->Text = L"Ingrese la información del medicamento";
			// 
			// Tab2
			// 
			this->Tab2->Controls->Add(this->RegresarOp2);
			this->Tab2->Controls->Add(this->TablaAct);
			this->Tab2->Controls->Add(this->label14);
			this->Tab2->Location = System::Drawing::Point(4, 25);
			this->Tab2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab2->Name = L"Tab2";
			this->Tab2->Size = System::Drawing::Size(1387, 686);
			this->Tab2->TabIndex = 3;
			this->Tab2->Text = L"Actualizar";
			this->Tab2->UseVisualStyleBackColor = true;
			// 
			// RegresarOp2
			// 
			this->RegresarOp2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegresarOp2->Location = System::Drawing::Point(651, 555);
			this->RegresarOp2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RegresarOp2->Name = L"RegresarOp2";
			this->RegresarOp2->Size = System::Drawing::Size(115, 38);
			this->RegresarOp2->TabIndex = 91;
			this->RegresarOp2->Text = L"Regresar";
			this->RegresarOp2->UseVisualStyleBackColor = true;
			this->RegresarOp2->Click += gcnew System::EventHandler(this, &MyForm::RegresarOp2_Click);
			// 
			// TablaAct
			// 
			this->TablaAct->AllowUserToAddRows = false;
			this->TablaAct->AllowUserToDeleteRows = false;
			this->TablaAct->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TablaAct->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->NombreMed, this->ColumRegistro,
					this->ColumCateg, this->ColumPrincipio, this->ColumDosis, this->ColumStock, this->ColumCaducidad, this->ColumProveedor, this->ColumCompra,
					this->ColumVenta
			});
			this->TablaAct->Location = System::Drawing::Point(87, 80);
			this->TablaAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TablaAct->Name = L"TablaAct";
			this->TablaAct->RowHeadersVisible = false;
			this->TablaAct->RowHeadersWidth = 51;
			this->TablaAct->RowTemplate->Height = 24;
			this->TablaAct->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->TablaAct->Size = System::Drawing::Size(1251, 455);
			this->TablaAct->TabIndex = 90;
			this->TablaAct->DoubleClick += gcnew System::EventHandler(this, &MyForm::TablaAct_DoubleClick);
			// 
			// NombreMed
			// 
			this->NombreMed->HeaderText = L"Nombre";
			this->NombreMed->MinimumWidth = 6;
			this->NombreMed->Name = L"NombreMed";
			this->NombreMed->Width = 125;
			// 
			// ColumRegistro
			// 
			this->ColumRegistro->HeaderText = L"No. de Registro";
			this->ColumRegistro->MinimumWidth = 6;
			this->ColumRegistro->Name = L"ColumRegistro";
			this->ColumRegistro->Width = 125;
			// 
			// ColumCateg
			// 
			this->ColumCateg->HeaderText = L"Categoría";
			this->ColumCateg->MinimumWidth = 6;
			this->ColumCateg->Name = L"ColumCateg";
			this->ColumCateg->Width = 125;
			// 
			// ColumPrincipio
			// 
			this->ColumPrincipio->HeaderText = L"Principio activo";
			this->ColumPrincipio->MinimumWidth = 6;
			this->ColumPrincipio->Name = L"ColumPrincipio";
			this->ColumPrincipio->Width = 125;
			// 
			// ColumDosis
			// 
			this->ColumDosis->HeaderText = L"Dosis Recomendada (mg/ml)";
			this->ColumDosis->MinimumWidth = 6;
			this->ColumDosis->Name = L"ColumDosis";
			this->ColumDosis->Width = 125;
			// 
			// ColumStock
			// 
			this->ColumStock->HeaderText = L"Cantidad de Stock (unidades)";
			this->ColumStock->MinimumWidth = 6;
			this->ColumStock->Name = L"ColumStock";
			this->ColumStock->Width = 125;
			// 
			// ColumCaducidad
			// 
			this->ColumCaducidad->HeaderText = L"Fecha de Caducidad (año/mes/dia)";
			this->ColumCaducidad->MinimumWidth = 6;
			this->ColumCaducidad->Name = L"ColumCaducidad";
			this->ColumCaducidad->Width = 125;
			// 
			// ColumProveedor
			// 
			this->ColumProveedor->HeaderText = L"Proveedor";
			this->ColumProveedor->MinimumWidth = 6;
			this->ColumProveedor->Name = L"ColumProveedor";
			this->ColumProveedor->Width = 125;
			// 
			// ColumCompra
			// 
			this->ColumCompra->HeaderText = L"Precio de Compra (Q)";
			this->ColumCompra->MinimumWidth = 6;
			this->ColumCompra->Name = L"ColumCompra";
			this->ColumCompra->Width = 125;
			// 
			// ColumVenta
			// 
			this->ColumVenta->HeaderText = L"Precio de Venta (Q)";
			this->ColumVenta->MinimumWidth = 6;
			this->ColumVenta->Name = L"ColumVenta";
			this->ColumVenta->Width = 125;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Lucida Fax", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(504, 30);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(405, 38);
			this->label14->TabIndex = 89;
			this->label14->Text = L"Actualizar información";
			// 
			// Tab3
			// 
			this->Tab3->Controls->Add(this->RegresarF3);
			this->Tab3->Controls->Add(this->l4bPrincipio);
			this->Tab3->Controls->Add(this->l4bDosis);
			this->Tab3->Controls->Add(this->l4bCategoria);
			this->Tab3->Controls->Add(this->l4bRegistro);
			this->Tab3->Controls->Add(this->l4bnombre);
			this->Tab3->Controls->Add(this->label21);
			this->Tab3->Controls->Add(this->label20);
			this->Tab3->Controls->Add(this->label19);
			this->Tab3->Controls->Add(this->label18);
			this->Tab3->Controls->Add(this->label17);
			this->Tab3->Controls->Add(this->L4b1);
			this->Tab3->Controls->Add(this->SearchInfo);
			this->Tab3->Controls->Add(this->txtboxSearch1);
			this->Tab3->Controls->Add(this->label16);
			this->Tab3->Controls->Add(this->groupBox1);
			this->Tab3->Controls->Add(this->label15);
			this->Tab3->Location = System::Drawing::Point(4, 25);
			this->Tab3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab3->Name = L"Tab3";
			this->Tab3->Size = System::Drawing::Size(1387, 681);
			this->Tab3->TabIndex = 4;
			this->Tab3->Text = L"Consultar Informacion";
			this->Tab3->UseVisualStyleBackColor = true;
			// 
			// RegresarF3
			// 
			this->RegresarF3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegresarF3->Location = System::Drawing::Point(715, 294);
			this->RegresarF3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RegresarF3->Name = L"RegresarF3";
			this->RegresarF3->Size = System::Drawing::Size(152, 42);
			this->RegresarF3->TabIndex = 127;
			this->RegresarF3->Text = L"Regresar";
			this->RegresarF3->UseVisualStyleBackColor = true;
			this->RegresarF3->Click += gcnew System::EventHandler(this, &MyForm::RegresarF3_Click);
			// 
			// l4bPrincipio
			// 
			this->l4bPrincipio->AutoSize = true;
			this->l4bPrincipio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l4bPrincipio->Location = System::Drawing::Point(1049, 481);
			this->l4bPrincipio->Name = L"l4bPrincipio";
			this->l4bPrincipio->Size = System::Drawing::Size(177, 25);
			this->l4bPrincipio->TabIndex = 126;
			this->l4bPrincipio->Text = L"_______________";
			// 
			// l4bDosis
			// 
			this->l4bDosis->AutoSize = true;
			this->l4bDosis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l4bDosis->Location = System::Drawing::Point(680, 505);
			this->l4bDosis->Name = L"l4bDosis";
			this->l4bDosis->Size = System::Drawing::Size(177, 25);
			this->l4bDosis->TabIndex = 125;
			this->l4bDosis->Text = L"_______________";
			// 
			// l4bCategoria
			// 
			this->l4bCategoria->AutoSize = true;
			this->l4bCategoria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l4bCategoria->Location = System::Drawing::Point(680, 441);
			this->l4bCategoria->Name = L"l4bCategoria";
			this->l4bCategoria->Size = System::Drawing::Size(177, 25);
			this->l4bCategoria->TabIndex = 124;
			this->l4bCategoria->Text = L"_______________";
			// 
			// l4bRegistro
			// 
			this->l4bRegistro->AutoSize = true;
			this->l4bRegistro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l4bRegistro->Location = System::Drawing::Point(247, 505);
			this->l4bRegistro->Name = L"l4bRegistro";
			this->l4bRegistro->Size = System::Drawing::Size(177, 25);
			this->l4bRegistro->TabIndex = 123;
			this->l4bRegistro->Text = L"_______________";
			// 
			// l4bnombre
			// 
			this->l4bnombre->AutoSize = true;
			this->l4bnombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l4bnombre->Location = System::Drawing::Point(247, 441);
			this->l4bnombre->Name = L"l4bnombre";
			this->l4bnombre->Size = System::Drawing::Size(177, 25);
			this->l4bnombre->TabIndex = 122;
			this->l4bnombre->Text = L"_______________";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(892, 481);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(151, 25);
			this->label21->TabIndex = 121;
			this->label21->Text = L"Principio Activo:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(465, 505);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(199, 25);
			this->label20->TabIndex = 120;
			this->label20->Text = L"Dosis Recomendada:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(561, 441);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(103, 25);
			this->label19->TabIndex = 119;
			this->label19->Text = L"Categoria:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(80, 505);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(151, 25);
			this->label18->TabIndex = 118;
			this->label18->Text = L"No. de Registro:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(144, 441);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(87, 25);
			this->label17->TabIndex = 117;
			this->label17->Text = L"Nombre:";
			// 
			// L4b1
			// 
			this->L4b1->AutoSize = true;
			this->L4b1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L4b1->Location = System::Drawing::Point(80, 373);
			this->L4b1->Name = L"L4b1";
			this->L4b1->Size = System::Drawing::Size(273, 25);
			this->L4b1->TabIndex = 116;
			this->L4b1->Text = L"Información del Medicamento:";
			// 
			// SearchInfo
			// 
			this->SearchInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchInfo->Location = System::Drawing::Point(512, 294);
			this->SearchInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchInfo->Name = L"SearchInfo";
			this->SearchInfo->Size = System::Drawing::Size(152, 42);
			this->SearchInfo->TabIndex = 115;
			this->SearchInfo->Text = L"Buscar";
			this->SearchInfo->UseVisualStyleBackColor = true;
			this->SearchInfo->Click += gcnew System::EventHandler(this, &MyForm::SearchInfo_Click);
			// 
			// txtboxSearch1
			// 
			this->txtboxSearch1->Location = System::Drawing::Point(608, 199);
			this->txtboxSearch1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtboxSearch1->Name = L"txtboxSearch1";
			this->txtboxSearch1->Size = System::Drawing::Size(172, 22);
			this->txtboxSearch1->TabIndex = 3;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(515, 116);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(363, 25);
			this->label16->TabIndex = 2;
			this->label16->Text = L"Ingrese el elemento que desea consultar";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ParametroPr);
			this->groupBox1->Controls->Add(this->ParametroN);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(1004, 116);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(331, 206);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parámetro";
			// 
			// ParametroPr
			// 
			this->ParametroPr->AutoSize = true;
			this->ParametroPr->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ParametroPr->Location = System::Drawing::Point(67, 135);
			this->ParametroPr->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ParametroPr->Name = L"ParametroPr";
			this->ParametroPr->Size = System::Drawing::Size(207, 28);
			this->ParametroPr->TabIndex = 1;
			this->ParametroPr->TabStop = true;
			this->ParametroPr->Text = L"Principio activo";
			this->ParametroPr->UseVisualStyleBackColor = true;
			// 
			// ParametroN
			// 
			this->ParametroN->AutoSize = true;
			this->ParametroN->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ParametroN->Location = System::Drawing::Point(67, 65);
			this->ParametroN->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ParametroN->Name = L"ParametroN";
			this->ParametroN->Size = System::Drawing::Size(108, 28);
			this->ParametroN->TabIndex = 0;
			this->ParametroN->TabStop = true;
			this->ParametroN->Text = L"Nombre ";
			this->ParametroN->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(352, 33);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(659, 38);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Consultar Información del Medicamento";
			// 
			// Tab4
			// 
			this->Tab4->Controls->Add(this->RegresarF4);
			this->Tab4->Controls->Add(this->btnExportar);
			this->Tab4->Controls->Add(this->TxtboxInforme);
			this->Tab4->Controls->Add(this->label31);
			this->Tab4->Location = System::Drawing::Point(4, 25);
			this->Tab4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab4->Name = L"Tab4";
			this->Tab4->Size = System::Drawing::Size(1387, 686);
			this->Tab4->TabIndex = 5;
			this->Tab4->Text = L"Generar Informe";
			this->Tab4->UseVisualStyleBackColor = true;
			// 
			// RegresarF4
			// 
			this->RegresarF4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegresarF4->Location = System::Drawing::Point(799, 530);
			this->RegresarF4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RegresarF4->Name = L"RegresarF4";
			this->RegresarF4->Size = System::Drawing::Size(152, 42);
			this->RegresarF4->TabIndex = 118;
			this->RegresarF4->Text = L"Regresar";
			this->RegresarF4->UseVisualStyleBackColor = true;
			this->RegresarF4->Click += gcnew System::EventHandler(this, &MyForm::RegresarF4_Click_1);
			// 
			// btnExportar
			// 
			this->btnExportar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExportar->Location = System::Drawing::Point(483, 530);
			this->btnExportar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(152, 42);
			this->btnExportar->TabIndex = 117;
			this->btnExportar->Text = L"Exportar";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &MyForm::btnExportar_Click);
			// 
			// TxtboxInforme
			// 
			this->TxtboxInforme->Location = System::Drawing::Point(251, 71);
			this->TxtboxInforme->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TxtboxInforme->Name = L"TxtboxInforme";
			this->TxtboxInforme->Size = System::Drawing::Size(855, 418);
			this->TxtboxInforme->TabIndex = 2;
			this->TxtboxInforme->Text = L"";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(412, 20);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(500, 38);
			this->label31->TabIndex = 1;
			this->label31->Text = L"Informe de los Medicamentos ";
			// 
			// Tab5
			// 
			this->Tab5->Controls->Add(this->RegresarF5);
			this->Tab5->Controls->Add(this->lbPromedio);
			this->Tab5->Controls->Add(this->label26);
			this->Tab5->Controls->Add(this->btnPromedio);
			this->Tab5->Controls->Add(this->PrecioTotal);
			this->Tab5->Controls->Add(this->label25);
			this->Tab5->Controls->Add(this->MedDisponibles);
			this->Tab5->Controls->Add(this->label24);
			this->Tab5->Controls->Add(this->label23);
			this->Tab5->Location = System::Drawing::Point(4, 25);
			this->Tab5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab5->Name = L"Tab5";
			this->Tab5->Size = System::Drawing::Size(1387, 686);
			this->Tab5->TabIndex = 6;
			this->Tab5->Text = L"Precio Promedio";
			this->Tab5->UseVisualStyleBackColor = true;
			// 
			// RegresarF5
			// 
			this->RegresarF5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegresarF5->Location = System::Drawing::Point(704, 331);
			this->RegresarF5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RegresarF5->Name = L"RegresarF5";
			this->RegresarF5->Size = System::Drawing::Size(152, 42);
			this->RegresarF5->TabIndex = 119;
			this->RegresarF5->Text = L"Regresar";
			this->RegresarF5->UseVisualStyleBackColor = true;
			this->RegresarF5->Click += gcnew System::EventHandler(this, &MyForm::RegresarF4_Click);
			// 
			// lbPromedio
			// 
			this->lbPromedio->AutoSize = true;
			this->lbPromedio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPromedio->Location = System::Drawing::Point(679, 466);
			this->lbPromedio->Name = L"lbPromedio";
			this->lbPromedio->Size = System::Drawing::Size(177, 25);
			this->lbPromedio->TabIndex = 118;
			this->lbPromedio->Text = L"_______________";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(425, 462);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(248, 32);
			this->label26->TabIndex = 117;
			this->label26->Text = L"Precio Promedio:";
			// 
			// btnPromedio
			// 
			this->btnPromedio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPromedio->Location = System::Drawing::Point(453, 331);
			this->btnPromedio->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnPromedio->Name = L"btnPromedio";
			this->btnPromedio->Size = System::Drawing::Size(152, 42);
			this->btnPromedio->TabIndex = 116;
			this->btnPromedio->Text = L"Calcular";
			this->btnPromedio->UseVisualStyleBackColor = true;
			this->btnPromedio->Click += gcnew System::EventHandler(this, &MyForm::btnPromedio_Click);
			// 
			// PrecioTotal
			// 
			this->PrecioTotal->AutoSize = true;
			this->PrecioTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PrecioTotal->Location = System::Drawing::Point(799, 208);
			this->PrecioTotal->Name = L"PrecioTotal";
			this->PrecioTotal->Size = System::Drawing::Size(177, 25);
			this->PrecioTotal->TabIndex = 6;
			this->PrecioTotal->Text = L"_______________";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(368, 208);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(415, 25);
			this->label25->TabIndex = 5;
			this->label25->Text = L"Precio Total de los Medicamentos disponibles:";
			// 
			// MedDisponibles
			// 
			this->MedDisponibles->AutoSize = true;
			this->MedDisponibles->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MedDisponibles->Location = System::Drawing::Point(799, 135);
			this->MedDisponibles->Name = L"MedDisponibles";
			this->MedDisponibles->Size = System::Drawing::Size(177, 25);
			this->MedDisponibles->TabIndex = 4;
			this->MedDisponibles->Text = L"_______________";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(417, 135);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(360, 25);
			this->label24->TabIndex = 3;
			this->label24->Text = L"Cantidad de Medicamentos disponibles:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(260, 50);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(807, 38);
			this->label23->TabIndex = 1;
			this->label23->Text = L"Calcular el Precio Promedio de los Medicamentos";
			// 
			// Tab6
			// 
			this->Tab6->Controls->Add(this->RegresarF6);
			this->Tab6->Controls->Add(this->label28);
			this->Tab6->Controls->Add(this->label27);
			this->Tab6->Controls->Add(this->NameBox);
			this->Tab6->Controls->Add(this->MostrarInventario);
			this->Tab6->Location = System::Drawing::Point(4, 25);
			this->Tab6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab6->Name = L"Tab6";
			this->Tab6->Size = System::Drawing::Size(1387, 686);
			this->Tab6->TabIndex = 7;
			this->Tab6->Text = L"Inventario del Medicamento";
			this->Tab6->UseVisualStyleBackColor = true;
			// 
			// RegresarF6
			// 
			this->RegresarF6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegresarF6->Location = System::Drawing::Point(655, 556);
			this->RegresarF6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RegresarF6->Name = L"RegresarF6";
			this->RegresarF6->Size = System::Drawing::Size(152, 42);
			this->RegresarF6->TabIndex = 142;
			this->RegresarF6->Text = L"Regresar";
			this->RegresarF6->UseVisualStyleBackColor = true;
			this->RegresarF6->Click += gcnew System::EventHandler(this, &MyForm::RegresarF6_Click);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(415, 112);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(224, 25);
			this->label28->TabIndex = 141;
			this->label28->Text = L"Escoja el medicamento: ";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(307, 18);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(714, 38);
			this->label27->TabIndex = 140;
			this->label27->Text = L"Información de Inventario del Medicamento";
			// 
			// NameBox
			// 
			this->NameBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->NameBox->FormattingEnabled = true;
			this->NameBox->Location = System::Drawing::Point(709, 112);
			this->NameBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(225, 24);
			this->NameBox->TabIndex = 139;
			this->NameBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::NameBox_SelectedIndexChanged);
			// 
			// MostrarInventario
			// 
			this->MostrarInventario->Font = (gcnew System::Drawing::Font(L"Lucida Console", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MostrarInventario->Location = System::Drawing::Point(349, 174);
			this->MostrarInventario->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MostrarInventario->Name = L"MostrarInventario";
			this->MostrarInventario->Size = System::Drawing::Size(707, 331);
			this->MostrarInventario->TabIndex = 138;
			this->MostrarInventario->Text = L"";
			// 
			// Tab7
			// 
			this->Tab7->Controls->Add(this->button12);
			this->Tab7->Controls->Add(this->label30);
			this->Tab7->Controls->Add(this->ProveedorBox);
			this->Tab7->Controls->Add(this->MostrarProveedor);
			this->Tab7->Controls->Add(this->label29);
			this->Tab7->Location = System::Drawing::Point(4, 25);
			this->Tab7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab7->Name = L"Tab7";
			this->Tab7->Size = System::Drawing::Size(1387, 686);
			this->Tab7->TabIndex = 8;
			this->Tab7->Text = L"Precio más alto";
			this->Tab7->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(645, 566);
			this->button12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(152, 42);
			this->button12->TabIndex = 145;
			this->button12->Text = L"Regresar";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(453, 124);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(195, 25);
			this->label30->TabIndex = 144;
			this->label30->Text = L"Escoja el proveedor: ";
			// 
			// ProveedorBox
			// 
			this->ProveedorBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ProveedorBox->FormattingEnabled = true;
			this->ProveedorBox->Location = System::Drawing::Point(717, 124);
			this->ProveedorBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ProveedorBox->Name = L"ProveedorBox";
			this->ProveedorBox->Size = System::Drawing::Size(225, 24);
			this->ProveedorBox->TabIndex = 143;
			this->ProveedorBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ProveedorBox_SelectedIndexChanged);
			// 
			// MostrarProveedor
			// 
			this->MostrarProveedor->Font = (gcnew System::Drawing::Font(L"Lucida Console", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MostrarProveedor->Location = System::Drawing::Point(371, 185);
			this->MostrarProveedor->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MostrarProveedor->Name = L"MostrarProveedor";
			this->MostrarProveedor->Size = System::Drawing::Size(707, 331);
			this->MostrarProveedor->TabIndex = 142;
			this->MostrarProveedor->Text = L"";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(452, 34);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(508, 38);
			this->label29->TabIndex = 141;
			this->label29->Text = L"Precio más Alto por Proveedor";
			// 
			// Tab8
			// 
			this->Tab8->Controls->Add(this->F6Regresar);
			this->Tab8->Controls->Add(this->txtbfiltro);
			this->Tab8->Controls->Add(this->lbFiltro);
			this->Tab8->Controls->Add(this->cboxFiltro);
			this->Tab8->Controls->Add(this->groupBox2);
			this->Tab8->Controls->Add(this->tablaFiltro);
			this->Tab8->Controls->Add(this->label22);
			this->Tab8->Location = System::Drawing::Point(4, 25);
			this->Tab8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab8->Name = L"Tab8";
			this->Tab8->Size = System::Drawing::Size(1387, 686);
			this->Tab8->TabIndex = 9;
			this->Tab8->Text = L"Busqueda y Filtrado";
			this->Tab8->UseVisualStyleBackColor = true;
			// 
			// F6Regresar
			// 
			this->F6Regresar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F6Regresar->Location = System::Drawing::Point(653, 582);
			this->F6Regresar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->F6Regresar->Name = L"F6Regresar";
			this->F6Regresar->Size = System::Drawing::Size(152, 42);
			this->F6Regresar->TabIndex = 128;
			this->F6Regresar->Text = L"Regresar";
			this->F6Regresar->UseVisualStyleBackColor = true;
			this->F6Regresar->Click += gcnew System::EventHandler(this, &MyForm::F6Regresar_Click);
			// 
			// txtbfiltro
			// 
			this->txtbfiltro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtbfiltro->Location = System::Drawing::Point(653, 130);
			this->txtbfiltro->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbfiltro->Name = L"txtbfiltro";
			this->txtbfiltro->Size = System::Drawing::Size(195, 27);
			this->txtbfiltro->TabIndex = 95;
			this->txtbfiltro->Visible = false;
			this->txtbfiltro->TextChanged += gcnew System::EventHandler(this, &MyForm::txtbfiltro_TextChanged);
			// 
			// lbFiltro
			// 
			this->lbFiltro->AutoSize = true;
			this->lbFiltro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbFiltro->Location = System::Drawing::Point(571, 79);
			this->lbFiltro->Name = L"lbFiltro";
			this->lbFiltro->Size = System::Drawing::Size(363, 25);
			this->lbFiltro->TabIndex = 94;
			this->lbFiltro->Text = L"Ingrese el elemento que desea consultar";
			// 
			// cboxFiltro
			// 
			this->cboxFiltro->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboxFiltro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cboxFiltro->FormattingEnabled = true;
			this->cboxFiltro->Location = System::Drawing::Point(653, 130);
			this->cboxFiltro->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cboxFiltro->Name = L"cboxFiltro";
			this->cboxFiltro->Size = System::Drawing::Size(195, 28);
			this->cboxFiltro->TabIndex = 93;
			this->cboxFiltro->Visible = false;
			this->cboxFiltro->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cboxFiltro_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioProveedor);
			this->groupBox2->Controls->Add(this->radioCategoria);
			this->groupBox2->Controls->Add(this->radioPrincipio);
			this->groupBox2->Controls->Add(this->radioNombre);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(31, 65);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(383, 139);
			this->groupBox2->TabIndex = 92;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Criterios";
			// 
			// radioProveedor
			// 
			this->radioProveedor->AutoSize = true;
			this->radioProveedor->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioProveedor->Location = System::Drawing::Point(224, 89);
			this->radioProveedor->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioProveedor->Name = L"radioProveedor";
			this->radioProveedor->Size = System::Drawing::Size(123, 25);
			this->radioProveedor->TabIndex = 3;
			this->radioProveedor->TabStop = true;
			this->radioProveedor->Text = L"Proveedor";
			this->radioProveedor->UseVisualStyleBackColor = true;
			this->radioProveedor->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioProveedor_CheckedChanged);
			// 
			// radioCategoria
			// 
			this->radioCategoria->AutoSize = true;
			this->radioCategoria->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioCategoria->Location = System::Drawing::Point(224, 39);
			this->radioCategoria->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioCategoria->Name = L"radioCategoria";
			this->radioCategoria->Size = System::Drawing::Size(121, 25);
			this->radioCategoria->TabIndex = 2;
			this->radioCategoria->TabStop = true;
			this->radioCategoria->Text = L"Categoría";
			this->radioCategoria->UseVisualStyleBackColor = true;
			this->radioCategoria->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioCategoria_CheckedChanged);
			// 
			// radioPrincipio
			// 
			this->radioPrincipio->AutoSize = true;
			this->radioPrincipio->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioPrincipio->Location = System::Drawing::Point(29, 89);
			this->radioPrincipio->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioPrincipio->Name = L"radioPrincipio";
			this->radioPrincipio->Size = System::Drawing::Size(165, 25);
			this->radioPrincipio->TabIndex = 1;
			this->radioPrincipio->TabStop = true;
			this->radioPrincipio->Text = L"Principio activo";
			this->radioPrincipio->UseVisualStyleBackColor = true;
			this->radioPrincipio->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioPrincipio_CheckedChanged);
			// 
			// radioNombre
			// 
			this->radioNombre->AutoSize = true;
			this->radioNombre->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioNombre->Location = System::Drawing::Point(29, 39);
			this->radioNombre->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioNombre->Name = L"radioNombre";
			this->radioNombre->Size = System::Drawing::Size(107, 25);
			this->radioNombre->TabIndex = 0;
			this->radioNombre->TabStop = true;
			this->radioNombre->Text = L"Nombre ";
			this->radioNombre->UseVisualStyleBackColor = true;
			this->radioNombre->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioNombre_CheckedChanged);
			// 
			// tablaFiltro
			// 
			this->tablaFiltro->AllowUserToAddRows = false;
			this->tablaFiltro->AllowUserToDeleteRows = false;
			this->tablaFiltro->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tablaFiltro->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9,
					this->dataGridViewTextBoxColumn10
			});
			this->tablaFiltro->Location = System::Drawing::Point(92, 219);
			this->tablaFiltro->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tablaFiltro->Name = L"tablaFiltro";
			this->tablaFiltro->RowHeadersVisible = false;
			this->tablaFiltro->RowHeadersWidth = 51;
			this->tablaFiltro->RowTemplate->Height = 24;
			this->tablaFiltro->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->tablaFiltro->Size = System::Drawing::Size(1253, 338);
			this->tablaFiltro->TabIndex = 91;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Nombre";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"No. de Registro";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Categoría";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Principio activo";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 125;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Dosis Recomendada (mg/ml)";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 125;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Cantidad de Stock (unidades)";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 125;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Fecha de Caducidad (año/mes/dia)";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 125;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"Proveedor";
			this->dataGridViewTextBoxColumn8->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->Width = 125;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"Precio de Compra (Q)";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->Width = 125;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"Precio de Venta (Q)";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->Width = 125;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(411, 12);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(628, 38);
			this->label22->TabIndex = 1;
			this->label22->Text = L"Búsqueda y Filtrado de Medicamentos";
			// 
			// Tab9
			// 
			this->Tab9->Controls->Add(this->CancelarAct);
			this->Tab9->Controls->Add(this->btnActualizar);
			this->Tab9->Controls->Add(this->label39);
			this->Tab9->Controls->Add(this->comboBoxActPro);
			this->Tab9->Controls->Add(this->label38);
			this->Tab9->Controls->Add(this->txtbCorreoAct);
			this->Tab9->Controls->Add(this->label32);
			this->Tab9->Controls->Add(this->txtbTelefonoAct);
			this->Tab9->Controls->Add(this->txtbDireccionAct);
			this->Tab9->Controls->Add(this->txtbNameAct);
			this->Tab9->Controls->Add(this->txtbNITAct);
			this->Tab9->Controls->Add(this->txtbDireccionFAct);
			this->Tab9->Controls->Add(this->label33);
			this->Tab9->Controls->Add(this->label34);
			this->Tab9->Controls->Add(this->label35);
			this->Tab9->Controls->Add(this->label36);
			this->Tab9->Controls->Add(this->label37);
			this->Tab9->Location = System::Drawing::Point(4, 25);
			this->Tab9->Margin = System::Windows::Forms::Padding(4);
			this->Tab9->Name = L"Tab9";
			this->Tab9->Size = System::Drawing::Size(1387, 686);
			this->Tab9->TabIndex = 10;
			this->Tab9->Text = L"ModificarProveedor";
			this->Tab9->UseVisualStyleBackColor = true;
			// 
			// CancelarAct
			// 
			this->CancelarAct->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CancelarAct->Location = System::Drawing::Point(677, 539);
			this->CancelarAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CancelarAct->Name = L"CancelarAct";
			this->CancelarAct->Size = System::Drawing::Size(152, 42);
			this->CancelarAct->TabIndex = 145;
			this->CancelarAct->Text = L"Cancelar";
			this->CancelarAct->UseVisualStyleBackColor = true;
			this->CancelarAct->Click += gcnew System::EventHandler(this, &MyForm::CancelarAct_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->Location = System::Drawing::Point(437, 539);
			this->btnActualizar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(152, 42);
			this->btnActualizar->TabIndex = 144;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = true;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &MyForm::btnActualizar_Click);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->Location = System::Drawing::Point(467, 112);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(111, 22);
			this->label39->TabIndex = 143;
			this->label39->Text = L"Proveedor:";
			// 
			// comboBoxActPro
			// 
			this->comboBoxActPro->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxActPro->FormattingEnabled = true;
			this->comboBoxActPro->Location = System::Drawing::Point(596, 110);
			this->comboBoxActPro->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxActPro->Name = L"comboBoxActPro";
			this->comboBoxActPro->Size = System::Drawing::Size(217, 24);
			this->comboBoxActPro->TabIndex = 142;
			this->comboBoxActPro->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxActPro_SelectedIndexChanged);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->Location = System::Drawing::Point(352, 23);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(642, 38);
			this->label38->TabIndex = 141;
			this->label38->Text = L"Actualizar Información de Proveedores";
			// 
			// txtbCorreoAct
			// 
			this->txtbCorreoAct->Location = System::Drawing::Point(573, 454);
			this->txtbCorreoAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbCorreoAct->Name = L"txtbCorreoAct";
			this->txtbCorreoAct->Size = System::Drawing::Size(156, 22);
			this->txtbCorreoAct->TabIndex = 30;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(467, 455);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(80, 22);
			this->label32->TabIndex = 29;
			this->label32->Text = L"Correo:";
			// 
			// txtbTelefonoAct
			// 
			this->txtbTelefonoAct->Location = System::Drawing::Point(572, 399);
			this->txtbTelefonoAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbTelefonoAct->Name = L"txtbTelefonoAct";
			this->txtbTelefonoAct->Size = System::Drawing::Size(167, 22);
			this->txtbTelefonoAct->TabIndex = 28;
			this->txtbTelefonoAct->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtRegistro_KeyPress);
			// 
			// txtbDireccionAct
			// 
			this->txtbDireccionAct->Location = System::Drawing::Point(572, 338);
			this->txtbDireccionAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbDireccionAct->Name = L"txtbDireccionAct";
			this->txtbDireccionAct->Size = System::Drawing::Size(191, 22);
			this->txtbDireccionAct->TabIndex = 27;
			// 
			// txtbNameAct
			// 
			this->txtbNameAct->Location = System::Drawing::Point(572, 170);
			this->txtbNameAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbNameAct->Name = L"txtbNameAct";
			this->txtbNameAct->Size = System::Drawing::Size(224, 22);
			this->txtbNameAct->TabIndex = 26;
			// 
			// txtbNITAct
			// 
			this->txtbNITAct->Location = System::Drawing::Point(572, 222);
			this->txtbNITAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbNITAct->Name = L"txtbNITAct";
			this->txtbNITAct->Size = System::Drawing::Size(157, 22);
			this->txtbNITAct->TabIndex = 25;
			this->txtbNITAct->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::txtRegistro_KeyPress);
			// 
			// txtbDireccionFAct
			// 
			this->txtbDireccionFAct->Location = System::Drawing::Point(572, 282);
			this->txtbDireccionFAct->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtbDireccionFAct->Name = L"txtbDireccionFAct";
			this->txtbDireccionFAct->Size = System::Drawing::Size(191, 22);
			this->txtbDireccionFAct->TabIndex = 24;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(455, 398);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(94, 22);
			this->label33->TabIndex = 23;
			this->label33->Text = L"Teléfono:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(445, 337);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(104, 22);
			this->label34->TabIndex = 22;
			this->label34->Text = L"Dirección:";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->Location = System::Drawing::Point(395, 281);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(162, 22);
			this->label35->TabIndex = 21;
			this->label35->Text = L"Dirección Fiscal:";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->Location = System::Drawing::Point(504, 220);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(47, 22);
			this->label36->TabIndex = 20;
			this->label36->Text = L"NIT:";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label37->Location = System::Drawing::Point(467, 171);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(90, 22);
			this->label37->TabIndex = 19;
			this->label37->Text = L"Nombre:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1397, 677);
			this->Controls->Add(this->Menus);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Menus->ResumeLayout(false);
			this->Principal->ResumeLayout(false);
			this->Principal->PerformLayout();
			this->Tab1->ResumeLayout(false);
			this->Tab1->PerformLayout();
			this->Tab2->ResumeLayout(false);
			this->Tab2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TablaAct))->EndInit();
			this->Tab3->ResumeLayout(false);
			this->Tab3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->Tab4->ResumeLayout(false);
			this->Tab4->PerformLayout();
			this->Tab5->ResumeLayout(false);
			this->Tab5->PerformLayout();
			this->Tab6->ResumeLayout(false);
			this->Tab6->PerformLayout();
			this->Tab7->ResumeLayout(false);
			this->Tab7->PerformLayout();
			this->Tab8->ResumeLayout(false);
			this->Tab8->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaFiltro))->EndInit();
			this->Tab9->ResumeLayout(false);
			this->Tab9->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

//Evento del boton 1 "Ingresar Medicamento"
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//Inicializa un iterador de la lista Proveedores
		list<Proveedor>::iterator it;

		//Recorre la lista y añade los elementos a un ComboBox
		for (it = proveedores.begin(); it != proveedores.end(); ++it)
		{
			boxProveedor->Items->Add(msclr::interop::marshal_as<String^>(it->GetNombreP()));

		}

		//Dirige al usuario a la pestaña No.1
		Menus->SelectedIndex = 1;


	}

//Evento del botón Ingresar en la función "Ingresar Medicamento"
private: System::Void Ingresar_Click(System::Object^ sender, System::EventArgs^ e) {

	//Verifica que todos los txtBox esten llenos, incluyendo los comboBox
	if (TxtBoxLlenos(Tab1) && boxCategoria->Text != " " && boxProveedor->Text != " ")
	{
		//Inicializacion de las instancias de las clases Proveedor e Inventario
		Inventario Nuevo;
		Proveedor New;

		//Variable booleana que indica si el nombre de un medicamento está repetido
		bool NombreRepetido = false;

		//Incrementa el ID de cada Medicamento
		Id++;

		//Modifica los atributos del objeto Inventario según la información de los TxtBox y Combobox
		Nuevo.SetName(msclr::interop::marshal_as<std::string>(txtNombre->Text));
		Nuevo.SetRegistro(Id);
		Nuevo.SetCategoria(msclr::interop::marshal_as<std::string>(boxCategoria->Text));
		Nuevo.SetPrincipio(msclr::interop::marshal_as<std::string>(txtPrincipio->Text));
		Nuevo.SetDosis(Convert::ToInt32(txtC->Text));
		Nuevo.SetStock(Convert::ToInt32(txtStock->Text));

		string anio = msclr::interop::marshal_as<std::string>(txtano->Text);
		string mes = msclr::interop::marshal_as<std::string>(txtmes->Text);
		string dia = msclr::interop::marshal_as<std::string>(txtdia->Text);

		string Fecha = anio + "/" + mes + "/" + dia;

		//Busca el nombre del proveedor dentro del listado de proveedores
		for (list<Proveedor>::iterator it1 = proveedores.begin(); it1 != proveedores.end(); ++it1)
		{
			if (boxProveedor->Text == msclr::interop::marshal_as<String^>(it1->GetNombreP()))
			{
				//Le asigna el "Proveedor" al "Medicamento"
				Nuevo.SetProveedor(*it1);
			}

		}

		//Recorre el listado de Inventario para verificar que no exista un nombre repetido
		for (list<Inventario>::iterator it2 = Medicinas.begin(); it2 != Medicinas.end(); ++it2)
		{
			if (Nuevo.GetName() == it2->GetName())
			{

				NombreRepetido = true;

			}
		}

		Nuevo.SetCaducidad(Fecha);
		Nuevo.SetVenta(Convert::ToDouble(txtVenta->Text));
		Nuevo.SetCompra(Convert::ToDouble(txtCompra->Text));

		//Verifica que los datos obtenidos cumplan con los parametros establecidos
		if (!Nuevo.ValidarInfo(Nuevo.GetDosis(), anio, dia, mes, Nuevo.GetCompra(), Nuevo.GetVenta(), Nuevo.GetStock()))
		{
			//Sino cumple muestra un mensaje de error al usuario
			MessageBox::Show("Verifique que haya ingresado correctamente los datos numericos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

			//Resta -1 a la id, para simular que no creo la entrada
			Id--;

		}
		else if (NombreRepetido)
		{
			//Si se encuentra un nombre de medicamento repetido, se muestra un mensaje de error al usuario
			MessageBox::Show("Nombre de Medicamento repetido", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Id--;

		}
		else
		{
			//Si cumple con los parametros, se muestra un mensaje de confirmacion al usuario
			MessageBox::Show("Se ha ingresado correctamente el medicamento", "Informacion", MessageBoxButtons::OK, MessageBoxIcon::Information);

			//Se vacian todos los txtbox y combobox de la pestaña, para el ingreso de la nueva entrada
			VaciarTxtbox(Tab1);

			boxCategoria->SelectedIndex = -1;

			boxProveedor->SelectedIndex = -1;

			//Agrega a la lista de Inventario, el medicamento ingresado
			Medicinas.push_back(Nuevo);

		}

	}
	else
	{
		//Si hay un txtbox o combobox vacio, muestra un mensaje de error
		MessageBox::Show("Un campo de Información esta vacío", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}
}

//Evento del boton 
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {

	//Bucle que tiene como condicion de salida que el numero de elementos de la lista Proveedores sea igual a 4
	while(proveedores.size() != 4)
	{
		//Declaracion de variables e objetos
		bool proveedorRepetido = false;

		MyForm1^ form1 = gcnew MyForm1;
		
		Proveedor Nuevo;

		//Abre el formulario secundario
		form1->ShowDialog();

		//Al cerrar el formulario, recolecta la información de lox txtbox y la asigna al objeto Proveedor
		Nuevo.SetNombreP(msclr::interop::marshal_as<std::string>(form1->GetNameP()));
		Nuevo.SetNIT(Convert::ToInt32(form1->GetNITForm()));
		Nuevo.SetDireccionF(msclr::interop::marshal_as<std::string>(form1->GetDireccionFform()));
		Nuevo.SetDireccion(msclr::interop::marshal_as<std::string>(form1->GetDireccionForm()));
		Nuevo.SetTel(Convert::ToInt32(form1->GetTelefonoForm()));
		Nuevo.SetEmail(msclr::interop::marshal_as<std::string>(form1->GetCorreoForm()));

		//Iterador que verifica que no exista datos como NIT, Nombre o Tel Repetidos
		for (list<Proveedor>::iterator repetidor = proveedores.begin(); repetidor != proveedores.end(); ++repetidor)
		{
			if(Nuevo.GetNIT() == repetidor->GetNIT() || Nuevo.GetNombreP() == repetidor->GetNombreP() || Nuevo.GetTel() == repetidor->GetTel())
			{
				//Si se repite, vuelve la variable booleana igual a true
				proveedorRepetido = true;
			}
		}

		//Si no hay informacion única repetida
		if(!proveedorRepetido)
		{
			//Agrega el proveedor a la lista proveedores
			proveedores.push_back(Nuevo);

			//Muestra un mensaje de confirmación
			MessageBox::Show("Se ha ingresado la información correctamente", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		else
		{
			//Sino muestra un mensaje de error
			MessageBox::Show("Ha ingresado dos Proveedores con el mismo nombre, Nit o télefono", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		

	}

	//Al terminar el bucle, vuelve visibles todos los botones del Menú
	button1->Visible = true;
	button2->Visible = true;
	button3->Visible = true;
	button4->Visible = true;
	button5->Visible = true;
	button6->Visible = true;
	button7->Visible = true;
	button8->Visible = true;
	button9->Visible = true;
	BtnActPro->Visible = true;

	button11->Visible = false;

	

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	//Abre la pestaña

	Menus->SelectedIndex = 2;
	
	//Funcion que llena la informacion en el DataGridView
	LLenarTabla(Medicinas, TablaAct);

}

private: System::Void RegresarOp2_Click(System::Object^ sender, System::EventArgs^ e) {

	//Regresa al menu principal
	Menus->SelectedIndex = 0;
	
	if(TablaAct->Rows->Count > 0)
	{
		for(int i = TablaAct->Rows->Count - 1; i >= 0; i--)
		{
			
			TablaAct->Rows->RemoveAt(i);
			
		}
	
	}

}

//Evento al dar doble click sobre una fila del DatagridView
private: System::Void TablaAct_DoubleClick(System::Object^ sender, System::EventArgs^ e) {

	//Conversion de la información del Datagridview a String^
	String^ NombreAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[0]->Value);
	
	String^ CategoriaAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[2]->Value);
	String^ PrincipioAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[3]->Value);
	String^ DosisAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[4]->Value);
	String^ StockAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[5]->Value);
	String^ FechaAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[6]->Value);

	//Separa la fecha de caducidad por año, mes y dia
	int primerSlash = FechaAct->IndexOf('/');
	int segundoSlash = FechaAct->LastIndexOf('/');

	String^ anio, ^mes, ^dia;

	if (primerSlash != -1 && segundoSlash != -1 && primerSlash != segundoSlash) {
		 anio = FechaAct->Substring(0, primerSlash);
		 mes = FechaAct->Substring(primerSlash + 1, segundoSlash - primerSlash - 1);
		 dia = FechaAct->Substring(segundoSlash + 1);
	}

	String^ ProveedorAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[7]->Value);
	String^ CompraAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[8]->Value);
	String^ VentaAct = Convert::ToString(TablaAct->SelectedRows[0]->Cells[9]->Value);


	//Inicialización y Traspaso de Información al otro Formulario
	MyForm2^ form2 = gcnew MyForm2;

	form2->Tnombre->Text = NombreAct;
	
	form2->TboxCategoria->Text = CategoriaAct;
	form2->TPrincipio->Text = PrincipioAct;
	form2->TC->Text = DosisAct;
	form2->TStock->Text = StockAct;
	form2->Tano->Text = anio;
	form2->Tmes->Text = mes;
	form2->Tdia->Text = dia;

	//LLenado del ComboBox de Proveedores
	list<Proveedor>::iterator it;

	for (it = proveedores.begin(); it != proveedores.end(); ++it)
	{
		form2->TboxProveedor->Items->Add(msclr::interop::marshal_as<String^>(it->GetNombreP()));

	}

	form2->TboxProveedor->Text = ProveedorAct;
	form2->TCompra->Text = CompraAct;
	form2->TVenta->Text = VentaAct;
	
	//Apertura del formulario
	form2->ShowDialog();

	Inventario elemento;

	//Verifica si es válido realizar la modificación
	if (form2->GetStatusCambio())
	{
		//Obtiene el índice de la fila seleccionada e inicializa una variable contador
		int indice = TablaAct->SelectedRows[0]->Index;
		int contador = 0;

		//Iterador que recorre la lista Inventario hasta que el contador coincida con el índice de la fila seleccionada
		for (list<Inventario>::iterator it = Medicinas.begin(); it != Medicinas.end(); ++it)
		{
			if (contador == indice)
			{
				//Asigna la nueva información al objeto Inventario
				elemento.SetName(msclr::interop::marshal_as<std::string>(form2->Tnombre->Text));
				elemento.SetRegistro(it->GetRegistro());
				elemento.SetCategoria(msclr::interop::marshal_as<std::string>(form2->TboxCategoria->Text));
				elemento.SetPrincipio(msclr::interop::marshal_as<std::string>(form2->TPrincipio->Text));
				elemento.SetDosis(Convert::ToInt32(form2->TC->Text));
				elemento.SetStock(Convert::ToInt32(form2->TStock->Text));

				string anio = msclr::interop::marshal_as<std::string>(form2->Tano->Text);
				string mes = msclr::interop::marshal_as<std::string>(form2->Tmes->Text);
				string dia = msclr::interop::marshal_as<std::string>(form2->Tdia->Text);

				string Fecha2 = anio + "/" + mes + "/" + dia;


				for (list<Proveedor>::iterator ite = proveedores.begin(); ite != proveedores.end(); ++ite)
				{
					if (form2->TboxProveedor->Text == msclr::interop::marshal_as<String^>(ite->GetNombreP()))
					{
						elemento.SetProveedor(*ite);
					}

				}

				elemento.SetCaducidad(Fecha2);
				elemento.SetVenta(Convert::ToDouble(form2->TVenta->Text));
				elemento.SetCompra(Convert::ToDouble(form2->TCompra->Text));

				//Verifica que la información actualizada este en el formato correcto
				if(elemento.ValidarInfo(elemento.GetDosis(), anio, dia, mes, elemento.GetCompra(), elemento.GetVenta(), elemento.GetStock()))
				{		
					//Reemplaza el objeto Inventario en la lista de Inventario

						*it = elemento;

					//Muestra un mensaje de confirmación
					MessageBox::Show("Se ha actualizado la informacion correctamente");

				}else
				{
					
					//Muestra un mensaje de error
					MessageBox::Show("No se ha podido actualizar la información", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

				}
				
				//Rompe la iteración
				break;
			}

			//aumenta el contador
			contador++;
		}
	}
		//Elimina las filas del Datagridview
		if (TablaAct->Rows->Count > 0)
		{
			for (int i = TablaAct->Rows->Count - 1; i >= 0; i--)
			{

				TablaAct->Rows->RemoveAt(i);

			}

		}

		//LLena las filas del Datagridview con la información de la lista de Inventario 

		LLenarTabla(Medicinas, TablaAct);


}


//Boton de la Funcion No.3
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Dirige al usuario a la Función 3 del Menu 

	Menus->SelectedIndex = 3;

	l4bnombre->Text = "_______________";
	l4bRegistro->Text = "_______________";
	l4bCategoria->Text = "_______________";
	l4bDosis->Text = "_______________";
	l4bPrincipio->Text = "_______________";

}

//Boton Búsqueda de la Función 3 "Consultar Información"
private: System::Void SearchInfo_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Creación de un objeto de la clase Inventario para llevar a cabo las operaciones de búsqueda.
	Inventario Busqueda;

	// Variable para almacenar la información a buscar.
	string InfoBuscar;

	// Iterador para recorrer la lista de medicamentos.
	list<Inventario>::iterator i;

	// Verifica si el campo de búsqueda no está vacío.
	if (txtboxSearch1->Text != "")
	{
		// Verifica si la opción de búsqueda por nombre está seleccionada.
		if (ParametroN->Checked)
		{
			// Obtiene la información a buscar desde el campo de texto.
			InfoBuscar = msclr::interop::marshal_as<string>(txtboxSearch1->Text);

			// Realiza la búsqueda por nombre.
			if (Busqueda.BusquedaEncontradaNombre(Medicinas, InfoBuscar))
			{
				// Itera sobre la lista de medicamentos.
				for (i = Medicinas.begin(); i != Medicinas.end(); ++i)
				{
					// Si se encuentra un medicamento con el nombre buscado, actualiza las etiquetas de la interfaz.
					if (InfoBuscar == i->GetName())
					{
						l4bnombre->Text = msclr::interop::marshal_as<String^>(i->GetName());
						l4bRegistro->Text = i->GetRegistro().ToString();
						l4bCategoria->Text = msclr::interop::marshal_as<String^>(i->GetCategoria());
						l4bDosis->Text = i->GetDosis().ToString() + " (mg o ml)";
						l4bPrincipio->Text = msclr::interop::marshal_as<String^>(i->GetPrincipio());
					}
				}
			}
			else
			{
				// Si no se encuentra el elemento buscado, muestra un mensaje de error.
				MessageBox::Show("No se encontro el elemento buscado ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		// Verifica si la opción de búsqueda por principio activo está seleccionada.
		else if (ParametroPr->Checked)
		{
			// Obtiene la información a buscar desde el campo de texto.
			InfoBuscar = msclr::interop::marshal_as<string>(txtboxSearch1->Text);

			// Realiza la búsqueda por principio activo.
			if (Busqueda.BusquedaEncontradaPrincipio(Medicinas, InfoBuscar))
			{
				// Itera sobre la lista de medicamentos.
				for (i = Medicinas.begin(); i != Medicinas.end(); ++i)
				{
					// Si se encuentra un medicamento con el principio activo buscado, actualiza las etiquetas de la interfaz.
					if (InfoBuscar == i->GetPrincipio())
					{
						l4bnombre->Text = msclr::interop::marshal_as<String^>(i->GetName());
						l4bRegistro->Text = i->GetRegistro().ToString();
						l4bCategoria->Text = msclr::interop::marshal_as<String^>(i->GetCategoria());
						l4bDosis->Text = i->GetDosis().ToString() + " (mg o ml)";
						l4bPrincipio->Text = msclr::interop::marshal_as<String^>(i->GetPrincipio());
					}
				}
			}
			else
			{
				// Si no se encuentra el elemento buscado, muestra un mensaje de error.
				MessageBox::Show("No se encontro el elemento buscado ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		else
		{
			// Si no se ha seleccionado un parámetro de búsqueda, muestra un mensaje de error.
			MessageBox::Show("No ha seleccionado un parámetro de búsqueda ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	else
	{
		// Si el campo de búsqueda está vacío, muestra un mensaje indicando que el usuario debe ingresar información.
		MessageBox::Show("Debe ingresar el nombre o el principio activo del medicamento para consultar la información", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

}

//Restringe los Textbox correspondientes para que la entrada de información sea solo valida cuando se ingrese números

private: System::Void txtRegistro_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
{
	//Limita que el usuario solo ingrese numeros en el textbox
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}
private: System::Void txtC_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}
private: System::Void txtano_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void txtmes_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}

private: System::Void txtCompra_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void txtVenta_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {

	Menus->SelectedIndex = 0;
	
	boxProveedor->Items->Clear();
	
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void txtStock_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}

}
private: System::Void txtdia_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}



//Boton Regresar de la Función 3
private: System::Void RegresarF3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Dirige al usuario al Menu Principal 

	Menus->SelectedIndex = 0;

	//Borra la informacion del medicamento encontrado
	l4bnombre->Text = "_______________";
	l4bRegistro->Text = "_______________";
	l4bCategoria->Text = "_______________";
	l4bDosis->Text = "_______________";
	l4bPrincipio->Text = "_______________";

	VaciarTxtbox(Tab3);

}


//Boton 4 De la función 4 "Generar Informe"
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Menus->SelectedIndex = 4;

	Inventario objeto;

	list<Inventario> Informe = objeto.OrdenamientoPorNombre(Medicinas);

	for each(Inventario Med in Informe)
	{
		String^ informe = String::Format(" {0},{1},{2},{3},{4},{5},{6},{7},{8},{9}\n",
			msclr::interop::marshal_as<String^>(Med.GetName()), Med.GetRegistro().ToString(), msclr::interop::marshal_as<String^>(Med.GetCategoria()),
			msclr::interop::marshal_as<String^>(Med.GetPrincipio()), Med.GetDosis().ToString(), Med.GetStock().ToString()	,
			msclr::interop::marshal_as<String^>(Med.GetCaducidad()), msclr::interop::marshal_as<String^>(Med.GetProveedor().GetNombreP()),
			String::Format("Q {0:0.00}", Med.GetCompra()), String::Format("Q {0:0.00}", Med.GetVenta()));

		TxtboxInforme->AppendText(informe);



	}

	


}

//Boton Regresar de la función 4 "Generar Informe"
private: System::Void RegresarF4_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
	//Regresa al menú principal
	Menus->SelectedIndex = 0;

	//Borra todo el texto en el RichBoxText sobre el informe de los medicamentos
	
	TxtboxInforme->Clear();


}
//Boton "Exportar" de la Funcion "Generar Informe"
private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Creación de un nuevo objeto FolderBrowserDialog
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();

	//Mostrar la ventana emergente de seleccion de carpeta
	if(fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//Obtener la ruta seleccionada por el usuario
		String^ Ruta = fbd->SelectedPath;

		//Convertir la ruta seleccionada en un string
		string RutaArchivo = msclr::interop::marshal_as<string>(Ruta);

		//Crea un archivo .csv con el informe del inventario
		ofstream Archivo(RutaArchivo + "/" + "Inventario.csv");

		//Agrega el encabezado de la Tabla al archivo csv
		Archivo << "Nombre,No. de Registro, Categoria, Principio Activo, Dosis (mg/ml), Stock (unidades), Fecha de Caducidad, Proveedor, Precio de Compra (Q) , Precio de Venta (Q)\n";

		//Añade la información del informe al Archivo.csv
		Archivo << msclr::interop::marshal_as<string>(TxtboxInforme->Text);

		//Cierra Archivo
		Archivo.close();

		MessageBox::Show("Archivo guardado" , "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}



}


//Botón 5 de la Funcion 5 "Precio Promedio"
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Inventario Texto;

	Menus->SelectedIndex = 5;

	MedDisponibles->Text = Texto.TotalMedicamentos(Medicinas).ToString() + " unidades";
	
	PrecioTotal->Text = String::Format("Q {0:0.00}", Texto.TotalPrecios(Medicinas));

}


//Botón Calcular de la Función 5 "Precio Promedio"
private: System::Void btnPromedio_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Inventario Calculo;

	int CantidadTotal = Calculo.TotalMedicamentos(Medicinas);

	double SumatoriaP = Calculo.TotalPrecios(Medicinas);

	lbPromedio->Text = String::Format("Q {0:0.00}", (SumatoriaP / CantidadTotal));


}

//Botón Regresar de la Funcion 5 "Precio Promedio"
private: System::Void RegresarF4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Realiza un "reset" del precio promedio
	lbPromedio->Text = "";

	//Dirige al menú principal
	Menus->SelectedIndex = 0;

}

//Boton 6 de la Función 6 "Inventario del Medicamento"
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Menus->SelectedIndex = 6;

	for(list<Inventario>::iterator it = Medicinas.begin(); it != Medicinas.end(); ++it)
	{
	
		NameBox->Items->Add(msclr::interop::marshal_as<String^>(it->GetName()));

	}


}

//Combobox de Nombres de Medicamentos en la Función 6 "Inventario del Medicamento"
private: System::Void NameBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (NameBox->Text != "")
	{
		for (list<Inventario>::iterator it = Medicinas.begin(); it != Medicinas.end(); ++it)
		{

			if (it->GetName() == msclr::interop::marshal_as<string>(NameBox->Text))
			{

				String^ TextoaMostrar = "Cantidad en Stock: " + String::Format("{0:0.00}", it->GetStock()) + "\n" + "\n";
				TextoaMostrar += "Fecha de Caducidad: " + msclr::interop::marshal_as<String^>(it->GetCaducidad()) + "\n" + "\n";
				TextoaMostrar += "Proveedor: " + msclr::interop::marshal_as<String^>(it->GetProveedor().GetNombreP()) + "\n" + "\n";
				TextoaMostrar += "Precio de Compra: " + String::Format("Q {0:0.00}", it->GetCompra()) + "\n" + "\n";
				TextoaMostrar += "Precio de Venta: " + String::Format("Q {0:0.00}", it->GetVenta());

				MostrarInventario->Text = TextoaMostrar;

			}
		}
	}

	

	

}

//Boton Regresar de la Función 6 
private: System::Void RegresarF6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Dirige al usuario al Menú Principal
	Menus->SelectedIndex = 0;

	//Limpiar el RichTextBox

	MostrarInventario->Clear();

	NameBox->SelectedIndex = -1;

}

//Boton 7 de la Función 7 "Precio más alto por Proveedor"
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Menus->SelectedIndex = 7;

	//Añade al ComboBox los nombres de los proveedores registrados

	for (list<Proveedor>::iterator it = proveedores.begin(); it != proveedores.end(); ++it)
	{
		ProveedorBox->Items->Add(msclr::interop::marshal_as<String^>(it->GetNombreP()));

	}

}

//Funcion de la ComboBox del nombre de Proveedores

private: System::Void ProveedorBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	Inventario Nuevo;
	
	MostrarProveedor->Clear();

	if(ProveedorBox->Text != "")
	{
		string ProveedorPrecio = msclr::interop::marshal_as<string>(ProveedorBox->Text);

			Inventario Med = Nuevo.PrecioMasAlto(Medicinas, ProveedorPrecio);
			
			String^ MedaMostrar = "Nombre del Medicamento: " + msclr::interop::marshal_as<String^>(Med.GetName()) + "\n\n";
			MedaMostrar += "No. de Registro: " + Med.GetRegistro().ToString() + "\n\n";
			MedaMostrar += "Categoria: " + msclr::interop::marshal_as<String^>(Med.GetCategoria()) + "\n\n";
			MedaMostrar += "Principio Activo: " + msclr::interop::marshal_as<String^>(Med.GetPrincipio()) + "\n\n";
			MedaMostrar += "Dosis Recomendada: " + Med.GetDosis().ToString() + " (mg/ml)" + "\n\n";
			MedaMostrar += "Precio del Medicamento por el Proveedor: " + String::Format("Q {0:0.00}", Med.GetCompra());

			MostrarProveedor->Text = MedaMostrar;
		
		
	}

}

//Boton Regresar al Menu Principal de la Función 7 "Precio más alto por Proveedor"
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MostrarProveedor->Clear();

	Menus->SelectedIndex = 0;

	ProveedorBox->SelectedIndex = -1;


}


//EVENTOS Y BOTONES DE LA FUNCION 8 "Busqueda y Filtrado"

//Evento si presionan el Boton 8 en el Menú Principal
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Direcciona al usuario al menu de la funcion 8 "Busqueda y Filtrado"
	Menus->SelectedIndex = 8;

	//Llena el Datagridview con la informacion de Inventario
	LLenarTabla(Medicinas, tablaFiltro);


}

//Evento si se selecciona el filtro "Categoria"
private: System::Void radioCategoria_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	//Vuelve invisible el txtbox
	txtbfiltro->Visible = false;

	//Reinicia la opcion seleccionada en el ComboBox
	cboxFiltro->SelectedIndex = -1;

	//Limpia la tabla de Inventario
	VaciarTabla(tablaFiltro);

	//Llena la tabla con la informacion de la lista "Medicinas"
	LLenarTabla(Medicinas, tablaFiltro);

	lbFiltro->Text = "Escoja la categoria a filtrar";

	lbFiltro->Visible = true;

	//Limpia el Combobox
	cboxFiltro->Items->Clear();

	//Llenado del Combobox
	cboxFiltro->Items->Add("Orales");
	cboxFiltro->Items->Add("Inyectables");
	cboxFiltro->Items->Add("Soluciones");
	cboxFiltro->Items->Add("Sueros");
	cboxFiltro->Items->Add("Uso externo y antisépticos");
	cboxFiltro->Items->Add("Desinfectantes");

	//Vuelve visible el combobox
	cboxFiltro->Visible = true;

}

//Evento si se selecciona el filtro "Proveedor"
private: System::Void radioProveedor_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{

	cboxFiltro->Items->Clear();

	cboxFiltro->SelectedIndex = -1;

	//Vuelve invisible el txtbox
	txtbfiltro->Visible = false;

	//Limpia la tabla de Inventario
	VaciarTabla(tablaFiltro);

	//Llena la tabla con la informacion de la lista "Medicinas"
	LLenarTabla(Medicinas, tablaFiltro);

	lbFiltro->Text = "Escoja el proveedor a filtrar";

	lbFiltro->Visible = true;

	//Limpia el Combobox
	cboxFiltro->Items->Clear();

	//Llenado del Combobox
	for (list<Proveedor>::iterator it = proveedores.begin(); it != proveedores.end(); ++it)
	{


		cboxFiltro->Items->Add(msclr::interop::marshal_as<String^>(it->GetNombreP()));

	}


	//Vuelve visible el combobox
	cboxFiltro->Visible = true;


}

//Evento al seleccionar una opción del combobox
private: System::Void cboxFiltro_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	Inventario Filtros;

	list<Inventario> ListaFiltrada = Medicinas;

	// Limpia la tabla de Inventario
		VaciarTabla(tablaFiltro);

	if (radioCategoria->Checked)
	{

		Filtros.FiltradoCategoria(ListaFiltrada, msclr::interop::marshal_as<string>(cboxFiltro->Text));

		LLenarTabla(ListaFiltrada, tablaFiltro);

	}else if(radioProveedor->Checked)
	{

	
		Filtros.FiltradoProveedor(ListaFiltrada, msclr::interop::marshal_as<string>(cboxFiltro->Text));
		
		LLenarTabla(ListaFiltrada, tablaFiltro);
	
	}
	
}

//Evento si se selecciona el filtro "Nombre"
private: System::Void radioNombre_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	cboxFiltro->Visible = false;

	txtbfiltro->Text = "";
	
	// Limpia la tabla de Inventario
	VaciarTabla(tablaFiltro);

	//Llena la tabla con la informacion de la lista "Medicinas"
	LLenarTabla(Medicinas, tablaFiltro);

	txtbfiltro->Visible = true;


}


//Evento si se selecciona el filtro "Principio Activo"
private: System::Void radioPrincipio_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	cboxFiltro->Visible = false;

	txtbfiltro->Text = "";

	// Limpia la tabla de Inventario
	VaciarTabla(tablaFiltro);

	//Llena la tabla con la informacion de la lista "Medicinas"
	LLenarTabla(Medicinas, tablaFiltro);

	txtbfiltro->Visible = true;

}





private: System::Void txtbfiltro_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{

	Inventario NuevoFiltro;

	list<Inventario> ListaFiltrada = Medicinas;

	//Convierte el texto del TextBox en un string

	string Buscador = msclr::interop::marshal_as<string>(txtbfiltro->Text);

	if (Buscador != "")
	{
		//Limpia la tabla de Inventario
		VaciarTabla(tablaFiltro);

		if (radioNombre->Checked)
		{

			NuevoFiltro.FiltradoNombre(ListaFiltrada, Buscador);
			LLenarTabla(ListaFiltrada, tablaFiltro);

		}else if(radioPrincipio->Checked)
		{
			NuevoFiltro.FiltradoPrincipio(ListaFiltrada, Buscador);
			LLenarTabla(ListaFiltrada, tablaFiltro);
	
		}
	}else
	{
		// Limpia la tabla de Inventario
		VaciarTabla(tablaFiltro);

		//Llena la tabla con la informacion de la lista "Medicinas"
		LLenarTabla(Medicinas, tablaFiltro);

	}
}

//Boton de Regresar de la Funcion 5
private: System::Void F6Regresar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Redirige al usuario al menu principal
	Menus->SelectedIndex = 0;

	//Limpia la tabla
	VaciarTabla(tablaFiltro);

}

//Evento si presiona el boton de "Actualizar Proveedor"
private: System::Void BtnActPro_Click(System::Object^ sender, System::EventArgs^ e) 
{

	//LLena el ComboBox de la opcion "Actualizar Proveedor" con la lista de Proveedores

	for (list<Proveedor>::iterator it = proveedores.begin(); it != proveedores.end(); ++it)
	{
		comboBoxActPro->Items->Add(msclr::interop::marshal_as<String^>(it->GetNombreP()));

	}

	//Direcciona al usuario a la pestaña correspondiente
	Menus->SelectedIndex = 9;


}

//Evento si presiona el boton Actualizar en la opción "Actualizar Proveedor"
private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (TxtBoxLlenos(Tab9) && txtbNITAct->Text->Length == 9 && txtbTelefonoAct->Text->Length == 8 && txtbCorreoAct->Text->IndexOf('@') != -1 && comboBoxActPro->Text != "")
	{
		// Declaración de variables para la función
		Proveedor Objeto;
		Proveedor Anterior;

		bool Repetido = false;

		// Ingresa la información de los txtbox a la instancia de la clase Proveedor
		Objeto.SetNombreP(msclr::interop::marshal_as<string>(txtbNameAct->Text));
		Objeto.SetNIT(Convert::ToInt32(txtbNITAct->Text));
		Objeto.SetDireccion(msclr::interop::marshal_as<string>(txtbDireccionFAct->Text));
		Objeto.SetDireccionF(msclr::interop::marshal_as<string>(txtbDireccionAct->Text));
		Objeto.SetTel(Convert::ToInt32(txtbTelefonoAct->Text));
		Objeto.SetEmail(msclr::interop::marshal_as<string>(txtbCorreoAct->Text));

		// Encuentra y obtiene el iterador al proveedor que se actualizará
		list<Proveedor>::iterator it = proveedores.begin();
		while (it != proveedores.end()) {
			if (it->GetNombreP() == msclr::interop::marshal_as<string>(comboBoxActPro->Text)) {
				break;
			}
			++it;
		}

		if (it != proveedores.end()) {

			// Copia el proveedor anterior para restaurarlo si es necesario
			Anterior = *it;

			// Actualiza los atributos del proveedor
			it->SetNombreP(msclr::interop::marshal_as<string>(txtbNameAct->Text));
			it->SetNIT(Convert::ToInt32(txtbNITAct->Text));
			it->SetDireccion(msclr::interop::marshal_as<string>(txtbDireccionFAct->Text));
			it->SetDireccionF(msclr::interop::marshal_as<string>(txtbDireccionAct->Text));
			it->SetTel(Convert::ToInt32(txtbTelefonoAct->Text));
			it->SetEmail(msclr::interop::marshal_as<string>(txtbCorreoAct->Text));

			// Bucle que verifica que la información actualizada no concuerde con la información de otros proveedores
			for (list<Proveedor>::iterator check = proveedores.begin(); check != proveedores.end(); ++check)
			{
				if (check != it) // Verifica que el iterador check no sea igual al iterador it (proveedor que estás actualizando)
				{
					if (Objeto.GetNombreP() == check->GetNombreP() || Objeto.GetNIT() == check->GetNIT() || Objeto.GetTel() == check->GetTel())
					{
						MessageBox::Show("No se pudo actualizar la informacion, debido a que se repitieron datos únicos (Nombre,Telefono,NIT) ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

						Repetido = true;
						break;
					}
				}
			}


			if (Repetido)
			{
				// Restaura el proveedor anterior
				*it = Anterior;
			}
			else
			{
				// Muestra un mensaje de éxito y realiza otras acciones si es necesario
				MessageBox::Show("Se ha actualizado correctamente la información del proveedor ", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);

				for (list<Inventario>::iterator invIt = Medicinas.begin(); invIt != Medicinas.end(); ++invIt)
				{
					if (invIt->GetProveedor().GetNombreP() == Anterior.GetNombreP())
					{
						invIt->SetProveedor(*it);
					}
				}

				comboBoxActPro->Items->Clear();
				Menus->SelectedIndex = 0;	

				//Vacia los TxtBox
				VaciarTxtbox(Tab9);
			}
		}
		else
		{
			MessageBox::Show("No se encontró el proveedor para actualizar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else
	{
		MessageBox::Show("No ha ingresado correctamente la información del proveedor", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}




}

//Evento del cambio de selección de opción del ComboBox de Proveedores de la opción "Actualizar Proveedor"
private: System::Void comboBoxActPro_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{

	if(comboBoxActPro->Text != "")
	{
		//Busca el proveedor seleccionado en la lista de Proveedores
		for(list<Proveedor>::iterator it = proveedores.begin(); it != proveedores.end(); it++)
		{
			//Si lo encuentra, coloca la información del Proveedor en los txtBox correspondientes
			if(comboBoxActPro->Text == msclr::interop::marshal_as<String^>(it->GetNombreP()))
			{
				txtbNameAct->Text = msclr::interop::marshal_as<String^>(it->GetNombreP());
				txtbNITAct->Text = it->GetNIT().ToString();
				txtbDireccionFAct->Text = msclr::interop::marshal_as<String^>(it->GetDireccionF());
				txtbDireccionAct->Text = msclr::interop::marshal_as<String^>(it->GetDireccion());
				txtbTelefonoAct->Text = it->GetTel().ToString();
				txtbCorreoAct->Text = msclr::interop::marshal_as<String^>(it->GetEmail());

			}
		}

	}else
	{
		//Vacia los TxtBox
		VaciarTxtbox(Tab9);
	
	}



}
private: System::Void CancelarAct_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Vuelve al menu principal
	Menus->SelectedIndex = 0;

	//Deja como sin Seleccionar las opciones del ComboBox
	comboBoxActPro->SelectedIndex = -1;

	//Vacia los TxtBox
	VaciarTxtbox(Tab9);


}


//Evento del Boton 9 "Salir"
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//Cierra el formulario principal
	this->Close();

}
};
}

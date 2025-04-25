#pragma once
#include <string>

 class Proveedor
{
	private:

		std::string NombreP;
		int NIT;
		std::string DireccionFiscal;
		std::string Direccion;
		int Telefono;
		std::string Correo;
	
	public:

		Proveedor();

		Proveedor(std::string name, int nit, std::string direccionF, std::string direccion, int tel, std::string email);

		std::string GetNombreP();
		void SetNombreP(std::string nombre);

		int GetNIT();
		void SetNIT(int nit);

		std::string GetDireccionF();
		void SetDireccionF(std::string direccionf);

		std::string GetDireccion();
		void SetDireccion(std::string direccion);

		int GetTel();
		void SetTel(int telefono);

		std::string GetEmail();
		void SetEmail(std::string email);



};


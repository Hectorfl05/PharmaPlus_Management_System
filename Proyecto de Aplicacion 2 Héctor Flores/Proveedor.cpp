#include "Proveedor.h"


Proveedor::Proveedor()
{
}

Proveedor::Proveedor(std::string name, int nit, std::string direccionF, std::string direccion, int tel, std::string email)
{

	this->NombreP = name;
	this->NIT = nit;
	this->DireccionFiscal = direccionF;
	this->Direccion = direccion;
	this->Telefono = tel;
	this->Correo = email;

}

std::string Proveedor::GetNombreP()
{
	return NombreP;
}

void Proveedor::SetNombreP(std::string nombre)
{
	NombreP = nombre;

}

int Proveedor::GetNIT()
{
	return NIT;
}

void Proveedor::SetNIT(int nit)
{
	NIT = nit;
}

std::string Proveedor::GetDireccionF()
{
	return DireccionFiscal;
}

void Proveedor::SetDireccionF(std::string direccionf)
{
	DireccionFiscal = direccionf;
}

std::string Proveedor::GetDireccion()
{
	return Direccion;
}

void Proveedor::SetDireccion(std::string direccion)
{
	Direccion = direccion;
}

int Proveedor::GetTel()
{
	return Telefono;
}

void Proveedor::SetTel(int tel)
{
	Telefono = tel;
}

std::string Proveedor::GetEmail()
{
	return Correo;
}

void Proveedor::SetEmail(std::string email)
{
	Correo = email;
}


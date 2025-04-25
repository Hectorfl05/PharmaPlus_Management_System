#include "Medicamento.h"

using namespace std;


Medicamento::Medicamento()
{
}

Medicamento::Medicamento(std::string nombre, int registro, std::string categoria, std::string principio, int dosis)
{
	this->NombreM = nombre;
	this->Registro = registro;
	this->Categoria = categoria;
	this->Principio = principio;
	this->Dosis = dosis;

}

std::string Medicamento::GetName()
{
	return NombreM;
}

void Medicamento::SetName(std::string name)
{
	NombreM = name;
}

int Medicamento::GetRegistro()
{
	return Registro;
}

void Medicamento::SetRegistro(int reg)
{

	Registro = reg;

}

std::string Medicamento::GetCategoria()
{
	return Categoria;
}

void Medicamento::SetCategoria(std::string cat)
{
	Categoria = cat;
}

std::string Medicamento::GetPrincipio()
{
	return Principio;
}

void Medicamento::SetPrincipio(std::string principio)
{
	Principio = principio;
}

int Medicamento::GetDosis()
{
	return Dosis;
}

void Medicamento::SetDosis(int dosis)
{
	Dosis = dosis;
}
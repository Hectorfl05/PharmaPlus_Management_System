#pragma once
#include <string>

 class Medicamento
{
	protected:

		std::string NombreM;
		int Registro;
		std::string Categoria;
		std::string Principio;
		int Dosis;

	public:

		Medicamento();

		Medicamento(std::string NombreM, int Registro, std::string Categoria, std::string Principio, int dosis);

		std::string GetName();
		void SetName(std::string Name);

		int GetRegistro();
		void SetRegistro(int reg);

		std::string GetCategoria();
		void SetCategoria(std::string cat);

		std::string GetPrincipio();
		void SetPrincipio(std::string principio);

		int GetDosis();
		void SetDosis(int dosis);


};


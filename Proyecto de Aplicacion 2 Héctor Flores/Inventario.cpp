#include "Inventario.h"
#include <vector>
#include <iostream>



using namespace std;

Inventario::Inventario()
{
}



Inventario::Inventario(int stock, string caducidad, Proveedor supplier, double compra, double venta, std::string NombreM, int Registro, std::string Categoria, std::string Principio, int dosis)
	:Medicamento(NombreM, Registro, Categoria, Principio, dosis)
{
	//Definición de Construcción

	this->Stock = stock;
	this->Caducidad = caducidad;
	this->proveedor = supplier;
	this->Compra = compra;
	this->Venta = venta;


}

int Inventario::GetStock()
{
	return Stock;
}

void Inventario::SetStock(int cant)
{
	Stock = cant;
}

std::string Inventario::GetCaducidad()
{
	return Caducidad;
}

void Inventario::SetCaducidad(std::string caducidad)
{
	Caducidad = caducidad;
}

Proveedor Inventario::GetProveedor()
{
	return proveedor;
}

void Inventario::SetProveedor(Proveedor nuevo)
{
	proveedor = nuevo;
}

double Inventario::GetCompra()
{
	return Compra;
}

void Inventario::SetCompra(double compra)
{
	Compra = compra;
}

double Inventario::GetVenta()
{
	return Venta;
}                                 

void Inventario::SetVenta(double venta)
{
	Venta = venta;
}

bool Inventario::ValidarInfo( int dosis, string año, string dia, string mes, double compra, double venta, int stock)
{
	//Convierte la fecha de caducidad en enteros
	int añonum = stoi(año);
	int dianum = stoi(dia);
	int mesnum = stoi(mes);

	//Valida que la dosis y la fecha de cadudicad sean validas
	if(dosis == 0 || (dianum < 1 || dianum > 31) || (mesnum < 1 || mesnum > 12) || añonum <= 2023)
	{
	
		return false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

	}

	//Valida que el precio de compra y venta sea lógico
	if(compra > venta)
	{
	
		return false;
	
	}


	return true;
}

int Inventario::ContadorNum(int num)
{
	string Numero = to_string(num);

	return Numero.length();
}

bool Inventario::BusquedaEncontradaNombre(std::list<Inventario> Listado, std::string buscar)
{
	for(list<Inventario>::iterator It = Listado.begin(); It != Listado.end(); ++It)
	{
		if(buscar == It->GetName())
		{
			return true;
		}

	}
	return false;
}

bool Inventario::BusquedaEncontradaPrincipio(std::list<Inventario> Listado, string buscar)
{
	for (list<Inventario>::iterator It = Listado.begin(); It != Listado.end(); ++It)
	{
		if (buscar == It->GetPrincipio())
		{
			return true;
		}

	}

	return false;
}

int Inventario::TotalMedicamentos(std::list<Inventario> Listado)
{
	int contadortotal = 0;

	for(list<Inventario>::iterator elem = Listado.begin(); elem != Listado.end(); ++elem)
	{
		contadortotal += elem->GetStock();

	}

	return contadortotal;

}

double Inventario::TotalPrecios(std::list<Inventario> Listado)
{
	double PrecioTotal = 0;

	for (list<Inventario>::iterator precio = Listado.begin(); precio != Listado.end(); ++precio)
	{
		PrecioTotal += (precio->GetStock() * precio->GetCompra());

	}

	return PrecioTotal;

}

bool Inventario::ComprobarProveedor(std::list<Inventario> proveedores, std::string proveedor)
{
	for(list<Inventario>::iterator it = proveedores.begin(); it != proveedores.end(); ++it)
	{
		if(it->GetProveedor().GetNombreP() == proveedor)
		{
		
			return true;
		
		}
	}

	return false;
}

Inventario Inventario::PrecioMasAlto(std::list<Inventario> listado, std::string proveedor)
{
	double Alto = 0;

	list<Inventario>SelectProveedor;

	Inventario MedicamentoCaro;

	for (list<Inventario>::iterator it = listado.begin(); it != listado.end(); ++it)
	{
		if (proveedor == it->GetProveedor().GetNombreP())
		{
			SelectProveedor.push_back(*it);
		
		}
	
	}

	
	for(list<Inventario>::iterator it2 = SelectProveedor.begin(); it2 != SelectProveedor.end(); ++it2)
	{
		if(Alto < it2->GetCompra())
		{
			MedicamentoCaro = *it2;

			Alto = it2->GetCompra();
		
		}
	}


	return MedicamentoCaro;


}

std::list<Inventario> Inventario::OrdenamientoPorNombre(std::list<Inventario> listado)
{
	vector<Inventario> Ordenar;

	list<Inventario> NuevoOrden;

	Ordenar.assign(listado.begin(), listado.end());

	Inventario key;
	int i, j;
	int n = Ordenar.size();

	for( i = 1 ; i < n; i++)
	{
		key = Ordenar[i];
	
		j = i - 1;

		while (j >= 0 && Ordenar[j].GetName() > key.GetName())
		{
			Ordenar[j + 1] = Ordenar[j];
		
			j--;
		}

		Ordenar[j + 1] = key;
	
	}

	
	NuevoOrden.assign(Ordenar.begin(), Ordenar.end());

	Ordenar.clear();

	return NuevoOrden;
}

void Inventario::FiltradoCategoria(std::list<Inventario> &listado, string categoria)
{
	list<Inventario> NuevoListado;


	for(list<Inventario>::iterator it = listado.begin(); it != listado.end(); ++it )
	{
		if(categoria == it->GetCategoria())
		{
		
			NuevoListado.push_back(*it);
		
		}
	
	}

	listado = NuevoListado;

}

void Inventario::FiltradoProveedor(std::list<Inventario>& listado, std::string proveedor)
{
	list<Inventario> NuevoListado;


	for (list<Inventario>::iterator it = listado.begin(); it != listado.end(); ++it)
	{
		if (proveedor == it->GetProveedor().GetNombreP())
		{

			NuevoListado.push_back(*it);

		}

	}

	listado = NuevoListado;

}

void Inventario::FiltradoNombre(std::list<Inventario>& listado, std::string buscador)
{
	list<Inventario> NuevoListado;

	string BuscadorMin = Minusculas(buscador);

	for (list<Inventario>::iterator it = listado.begin(); it != listado.end(); ++it)
	{

		if(Minusculas(it->GetName()).find(BuscadorMin) != string::npos)
		{

			NuevoListado.push_back(*it);

		}

	}

	listado = NuevoListado;

}

void Inventario::FiltradoPrincipio(std::list<Inventario>& listado, std::string buscador)
{
	list<Inventario> NuevoListado;

	string BuscadorMin = Minusculas(buscador);

	for (list<Inventario>::iterator it = listado.begin(); it != listado.end(); ++it)
	{

		if (Minusculas(it->GetPrincipio()).find(BuscadorMin) != string::npos)
		{

			NuevoListado.push_back(*it);

		}

	}

	listado = NuevoListado;


}

string Inventario::Minusculas(std::string palabra)
{
	for(int i = 0; i < palabra.length(); i++)
	{
	
		palabra[i] = tolower(palabra[i]);

	}

	return palabra;
}












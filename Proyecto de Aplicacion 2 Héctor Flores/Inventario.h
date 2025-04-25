#pragma once
#include "Medicamento.h"
#include "Proveedor.h"
#include <list>



class Inventario : public Medicamento
{
private:

	int Stock;
	std::string Caducidad;
	Proveedor proveedor;
	double Compra;
	double Venta;

public:

	Inventario();

	Inventario(int stock, std::string caducidad, Proveedor proveedor, double compra, double venta, std::string NombreM, int Registro, std::string Categoria, std::string Principio, int dosis);

	int GetStock();
	void SetStock(int cant);

	std::string GetCaducidad();
	void SetCaducidad(std::string caducidad);

	Proveedor GetProveedor();
	void SetProveedor(Proveedor nuevo);

	double GetCompra();
	void SetCompra(double compra);

	double GetVenta();
	void SetVenta(double venta);

	bool ValidarInfo(int dosis, std::string año, std::string dia, std::string mes, double compra, double venta, int stock);

	int ContadorNum(int num);

	bool BusquedaEncontradaNombre(std::list<Inventario> Listado, std::string buscar);

	bool BusquedaEncontradaPrincipio(std::list<Inventario> Listado, std::string buscar);

	int TotalMedicamentos(std::list<Inventario> Listado);

	double TotalPrecios(std::list<Inventario> Listado);

	bool ComprobarProveedor(std::list<Inventario> proveedores, std::string proveedor);

	Inventario PrecioMasAlto(std::list<Inventario> listado, std::string proveedor);

	std::list<Inventario> OrdenamientoPorNombre(std::list<Inventario> listado);

	void FiltradoCategoria(std::list<Inventario>& listado, std::string categoria);

	void FiltradoProveedor(std::list<Inventario>& listado, std::string proveedor);

	void FiltradoNombre(std::list<Inventario>& listado, std::string buscador);

	void FiltradoPrincipio(std::list<Inventario>& listado, std::string buscador);
	
	std::string Minusculas(std::string palabra);



};


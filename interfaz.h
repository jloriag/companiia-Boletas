#ifndef INTERFAZ_H
#define	INTERFAZ_H
#include"Lectura.h"
#include"Boletas.h"
class interfaz
{
private:
	Lista _objetosBoletas;
	Lectura _lectura;
	char opcion; 
	char opcionPrincipal;
public:
	interfaz();
	//Menus
	char MenuPrincipal();
	char MenuBoletas();
	char MenuBoletasCarro();
	char MenuBoletasMoto();
	char MenuBoletasMotoclicleta();
	char MenuBoletasCuadraCiclo();
	int MenuBorrarBoleta();

	//Controladores Menus
	void Principal();
	void Boletas();
	void BoletasCarro();
	void BoletasMoto();
	void BoletasMotocicleta();
	void BoletasCuadraciclo();
	void BorraBoleta();
	~interfaz();

	bool insert;
};
#endif


#include "Articulo.h"

Articulo::Articulo() :Objeto(), _nombre("Sin Definir"), _descripcion("Sin Definir")
{
}
Articulo::Articulo(string nombre, string descripcion) : Objeto(), _nombre(nombre), _descripcion(descripcion){
}

string Articulo::getNombre()const {
	return _nombre;
}

string Articulo::getDescripcion()const {
	return _descripcion;
}

void Articulo::setNombre(string nombre) {
	_nombre = nombre;
}

void Articulo::setDescripcion(string descripcion) {
	_descripcion = descripcion;
}
string Articulo::toString() {
	stringstream s;
	s << "Articulo: " << getNombre() << endl << "Descripcion: " << getDescripcion() << endl;
	return s.str();
}

void Articulo::captura(){
	cout << "----Agregar Articulo ----" << endl;
	cout << "Nombre: " << endl;
	cin >> _nombre;
	cout << "Descripcion: " << endl;
	cin >> _descripcion;
}


Articulo::~Articulo() {
}


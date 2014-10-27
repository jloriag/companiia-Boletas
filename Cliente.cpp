/*
* File:   Cliente.cpp
* Author: estudiante
*
* Created on 23 de octubre de 2014, 10:04 AM
*/

#include "Cliente.h"

Cliente::Cliente() :Objeto(), _nombre("Sin Definir"), _direccion("Sin Definir"), _telefonoCel("Sin definir"), _telefonoFijo("SIn definir")
{
}
Cliente::Cliente(string nombre, string direccion, string telefonoC, string telefonoF) : Objeto(), _nombre(nombre), _direccion(direccion), _telefonoCel(telefonoC), _telefonoFijo(telefonoF){
}

string Cliente::getNombre()const {
	return _nombre;
}

string Cliente::getDirrecion()const {
	return _direccion;
}

string Cliente::getTelefonoCel()const {
	return _telefonoCel;
}

string Cliente::getTelefonoFijo()const {
	return _telefonoFijo;
}

void Cliente::setNombre(string nombre) {
	_nombre = nombre;
}

void Cliente::setDireecion(string direccion) {
	_direccion = direccion;
}

void Cliente::setTelefonoCel(string telefonoC) {
	_telefonoCel = telefonoC;
}

void Cliente::setTelefonoFijo(string telelefonoF) {
	_telefonoFijo = telelefonoF;
}

string Cliente::toString() {


	stringstream s;
	s<<endl << "----- Informacion del Cliente------" << endl;
	s << "Cliente: " << getNombre() << endl << "Dirreccion: " << getDirrecion() << endl << "Telefono fijo: " << getTelefonoFijo() << endl << "Telefono Celular: " << getTelefonoCel() << endl;
	s << "----- FIN Informacion del Cliente------" << endl;
	return s.str();
}
void Cliente::captura(){
	_flushall();
	cout << "Agregar Cliente" << endl;
	cout << "Nombre: " << endl;
	getline(cin, _nombre);
	cout << "Direccion" << endl;
	getline(cin,_direccion);
	cout << "Telefono Fijo " << endl;
	getline(cin, _telefonoFijo);
	cout << "Telefono Celular " << endl;
	getline(cin, _telefonoCel);
}

Cliente::~Cliente() {
}


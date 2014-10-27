#include "Golpe.h"

Golpe::Golpe() :Objeto(), _lugar("Sin Definir"), _nivel("Sin Definir")
{
}
Golpe::Golpe(string lugar, string nivel) : Objeto(), _lugar(lugar), _nivel(nivel){
}

string Golpe::getLugar()const {
	return _lugar;
}

string Golpe::getNivel()const {
	return _nivel;
}

void Golpe::setLugar(string lugar) {
	_lugar = lugar;
}

void Golpe::setNivel(string nivel) {
	_nivel = nivel;
}
string Golpe::toString() {
	stringstream s;
	s << "Lugar del Golpe: " << getLugar() << endl << "Nivel: " << getNivel() << endl;
	return s.str();
}

void Golpe::captura(){
	cout << "Agregar nuevo Danno Vehicular" << endl;
	cout << "Lugar: " << endl;
	cin >> _lugar;
	cout << "Nivel" << endl;
	cin >> _nivel;
}
Golpe::~Golpe() {
}


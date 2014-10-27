/*
* File:   Lista.cpp
* Author: estudiante
*
* Created on 23 de octubre de 2014, 10:27 AM
*/

#include "Lista.h"


Nodo::Nodo(){
	setSig(NULL);
}
Nodo* Nodo::getSig()const {
	return _sig;
}

void Nodo::setSig(Nodo* nodo) {
	_sig = nodo;
}

Objeto* Nodo::getObjeto()const {
	return _objeto;
}

void Nodo::setObjeto(Objeto* o) {
	_objeto = o;
}

Lista::Lista() {
	setLargo(0);
}
void Lista::setPrimero(Nodo* n){
	_primera = n;
}

Nodo* Lista::getPrimero()const{
	return _primera;
}

int Lista::getLargo()const{
	return _largo;
}
void Lista::setLargo(int l){
	_largo = l;
}

void Lista::Inserta(Objeto *NuevoObjeto) {
	Nodo *NodoTemp, *NuevoNodo;
	NuevoNodo = new Nodo();
	NuevoNodo->setObjeto(NuevoObjeto);
	if (getPrimero() == NULL)
		setPrimero(NuevoNodo);
	else {
		NodoTemp = getPrimero();
		while (NodoTemp->getSig() != NULL)
			NodoTemp = NodoTemp->getSig();
		NodoTemp->setSig(NuevoNodo);
	}
	setLargo(getLargo()+1);
}

string Lista::toString() {
	
	Nodo *Actual = getPrimero();
	stringstream s;
	if (Actual!=NULL){
		while (Actual != NULL) {
			s << Actual->getObjeto()->toString() << endl;
			Actual = Actual->getSig();
		}
	}
	else{
		s << "Lista Vacia " << endl;
	}
		return s.str();
	
}

Lista::~Lista() {
	destruir();
}

Nodo *Lista::locateInfo(int info){
	if (getPrimero() == NULL){
		return NULL;
	}
	else{
		return locateI(info, getPrimero());
	}
}

bool Lista::borrar(int info){
	bool borrado = false;
	if (getPrimero() == NULL){
		return borrado;
	}
	else{
		Nodo *aux = locateInfo(info);
		if (aux != NULL){
			if (aux = getPrimero()){
				setPrimero(getPrimero()->getSig());
			}
			else {
				Nodo *temp = previous(info);
				temp->setSig(aux->getSig());
			}
			delete aux;
			borrado = true;
			setLargo(getLargo() - 1);
		}
		else{
			return borrado;
		}
		
	}
	return borrado;

}

void Lista::destruir(){
	if (getPrimero()!=NULL){
		while (getLargo()>0){
			borrar(getPrimero()->getObjeto()->getKey());
		}
	}

}

/*Metodos Privados*/

Nodo *Lista::locateI(int _info, Nodo* s){
	if (_info == s->getObjeto()->getKey()){
		return s;
	}
	else{
		if (s->getSig() == NULL){
			return NULL;
		}
		else{
			return locateI(_info, s->getSig());
		}
	}

}

Nodo *Lista::previous(int _info){
	//Devolver la dirrecion del nodo que se encuentra antes del nodo _info
	if (getPrimero() == NULL){
		return NULL;
	}
	else{
		Nodo *aux = getPrimero();
		if (aux->getObjeto()->getKey() == _info){
			return NULL;
		}
		while (aux->getSig() != NULL){
			if (aux->getSig()->getObjeto()->getKey() == _info)
				return aux;
			else
				aux = aux->getSig();
		}
		return NULL;

	}


}
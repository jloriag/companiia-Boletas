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
}
void Lista:: setPrimero(Nodo* n){
_primera=n;
}

Nodo* Lista:: getPrimero()const{

}

void Lista::Inserta(Objeto *NuevoObjeto) {
   Nodo *NodoTemp, *NuevoNodo;
   NuevoNodo = new Nodo();
   NuevoNodo->setObjeto(NuevoObjeto);
   if(getPrimero()==NULL) 
       setPrimero(NuevoNodo);
   else {
        NodoTemp=getPrimero();
        while(NodoTemp->getSig() != NULL) 
           	NodoTemp=NodoTemp->getSig();
        NodoTemp->setSig(NuevoNodo);
   }
}

string Lista::toString() {
  Nodo *Actual=getPrimero();
  stringstream s;
  while(Actual != NULL) {
       s << Actual->getObjeto()->toString() << endl;
       Actual->setSig(Actual->getSig());
  }
  return s.str();
} 

Lista::~Lista() {
}


/* 
 * File:   Cliente.cpp
 * Author: estudiante
 * 
 * Created on 23 de octubre de 2014, 10:04 AM
 */

#include "Cliente.h"

Cliente::Cliente() 
{
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

Cliente::~Cliente() {
}


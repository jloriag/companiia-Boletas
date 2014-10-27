/*
 * File:   Boletas.cpp
 * Author: estudiante
 *
 * Created on 23 de octubre de 2014, 09:40 AM
 */

#include "Boletas.h"

Boleta::Boleta() : Objeto(), _modelo("Sin definir"), _estilo("Sin definir"), _fechaEntrada(NULL), _fechaSalida(NULL), _cliente(NULL) {
}

Boleta::~Boleta(){
}

string Boleta::getModelo()const {
    return _modelo;
}

string Boleta::getEstilo()const {
    return _estilo;
}

Date* Boleta::getFechaE()const {
    return _fechaEntrada;
}

Date* Boleta::getFechaS()const {
    return _fechaSalida;
}

Cliente* Boleta::getCliente()const {
    return _cliente;
}

int Boleta::getID()const {
    return _id;
}

void Boleta::setModelo(string modelo) {
    _modelo = modelo;
}

void Boleta::setEstilo(string estilo) {
    _estilo = estilo;
}

void Boleta::setFechaE(Date* date) {
    _fechaEntrada = date;
}

void Boleta::setFechaS(Date* date) {
    _fechaSalida = date;
}

void Boleta::setCliente(Cliente* cliente) {
    _cliente = cliente;
}

void Boleta::setId(int id) {
    _id = id;
}

string Boleta::toString() {
    stringstream s;
     s << "Boleta # : " << getID() << endl << "Modelo: " << getModelo() << endl<<"Estilo: "<<getEstilo()<<endl<<"Fecha Entrada: "<<getFechaE()<<"Fecha Salida: "<<getFechaS()<<endl;
    return s.str();
}
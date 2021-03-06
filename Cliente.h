/*
* File:   Cliente.h
* Author: estudiante
*
* Created on 23 de octubre de 2014, 10:04 AM
*/

#ifndef CLIENTE_H
#define	CLIENTE_H
#include"Objeto.h"
class Cliente : public Objeto {
public:
	Cliente();
	Cliente(string, string, string, string);

	string getNombre()const;
	string getDirrecion()const;
	string getTelefonoCel()const;
	string getTelefonoFijo()const;

	void setNombre(string);
	void setDireecion(string);
	void setTelefonoCel(string);
	void setTelefonoFijo(string);

	//SobreEscritura
	string toString();
	void captura();
	~Cliente();
private:
	string _nombre;
	string _direccion;
	string _telefonoCel;
	string _telefonoFijo;

};

#endif	/* CLIENTE_H */


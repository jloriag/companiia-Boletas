/*
* File:   Lista.h
* Author: estudiante
*
* Created on 23 de octubre de 2014, 10:27 AM
*/

#ifndef LISTA_H
#define	LISTA_H
#include"Objeto.h"
class Nodo{
private:
	Objeto* _objeto;
	Nodo* _sig;
public:
	Nodo();
	Nodo* getSig()const;
	void setSig(Nodo*);

	Objeto* getObjeto()const;
	void setObjeto(Objeto*);
};
//Lista Simple de Objetos
class Lista {
public:
	Lista();
	void setPrimero(Nodo*);
	Nodo* getPrimero()const;

	int getLargo()const;
	void setLargo(int);
	virtual void Inserta(Objeto *NuevoObjeto);

	Nodo* locateInfo(int);
	virtual bool borrar(int);
	virtual string toString();
	virtual void destruir();
	~Lista();
private:
	Nodo* _primera;
	int _largo;

	//Metodo para localizar Info
	Nodo *locateI(int, Nodo*);
	Nodo *previous(int);
};

#endif	/* LISTA_H */


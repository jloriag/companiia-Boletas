/*
* File:   Objeto.h
* Author: estudiante
*
* Created on 23 de octubre de 2014, 09:36 AM
*/

#ifndef OBJETO_H
#define	OBJETO_H
#include"std.h"

// Clase Abstracta
class Objeto {
protected:
	int _key;
public:
	// Método Virtual Puro
	virtual string toString() = 0;
	virtual void captura() = 0;

	int getKey()const{
		return _key;
	}

	void setKey(int key){
		_key = key;
	}


};

#endif	/* OBJETO_H */


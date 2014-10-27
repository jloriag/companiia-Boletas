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
public:
	// Método Virtual Puro
	virtual string toString() = 0;

};

#endif	/* OBJETO_H */


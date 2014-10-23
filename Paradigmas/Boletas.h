/* 
 * File:   Boletas.h
 * Author: estudiante
 *
 * Created on 23 de octubre de 2014, 09:40 AM
 */

#ifndef BOLETAS_H
#define	BOLETAS_H
#include"Objeto.h"
class Boletas {
public:
    Boletas();
    ~Boletas();
private:
    string _modelo;
    string _estilo;
    Date* _fecha;
};

#endif	/* BOLETAS_H */


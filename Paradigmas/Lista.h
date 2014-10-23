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
  virtual void Inserta(Objeto *NuevoObjeto);
  virtual string toString();
  ~Lista();
private:
    Nodo* _primera;
};

#endif	/* LISTA_H */


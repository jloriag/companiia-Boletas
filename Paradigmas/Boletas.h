/* 
 * File:   Boletas.h
 * Author: estudiante
 *
 * Created on 23 de octubre de 2014, 09:40 AM
 */

#ifndef BOLETAS_H
#define	BOLETAS_H
#include"Cliente.h"
#include "Fecha.h"
class Boleta:Objeto {
public:
    Boleta();
    ~Boleta();
    
    string getModelo()const;
    string getEstilo()const;
    Date* getFechaE()const;
    Date* getFechaS()const;
    Cliente* getCliente()const;
    int getID()const;
    
    void setModelo(string);
    void setEstilo(string);
    void setFechaE(Date*);
    void setFechaS(Date*);
    void setCliente(Cliente*);
    void setId(int);
    
    //SobreEscritura
    string toString();
private:
    string _modelo;
    string _estilo;
    Date* _fechaEntrada;
    Date* _fechaSalida;
    Cliente* _cliente;
    int _id; //KEY Boleta
};

class BoletaCarro:Boleta{
private:
    
};

#endif	/* BOLETAS_H */


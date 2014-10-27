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
#include"Lista.h"
#include"Golpe.h"
#include"Articulo.h"

//BOLETA DE ENTRADA
class Boleta :public Objeto {
public:
	Boleta();
	~Boleta();

	int getModelo()const;
	string getEstilo()const;
	Fecha getFechaE()const;
	Fecha getFechaS()const;
	Cliente getCliente()const;
	int getID()const;

	void setModelo(int);
	void setEstilo(string);
	void setFechaE(Fecha);
	void setFechaS(Fecha);
	void setCliente(Cliente);
	void setId(int);

	//SobreEscritura
	virtual string toString();
	virtual void captura();
protected:
	int _modelo;
	string _estilo;
	Fecha _fechaEntrada;
	Fecha _fechaSalida;
	Cliente _cliente;

};

//Boleta Garantía

class BoletaGarantia{
public:
	BoletaGarantia();
	~BoletaGarantia();

	double getKilometraje()const;
	bool getFaltado()const;
	Fecha getEmision()const;
	Fecha getFinalizacion()const;


	void setKilometraje(double);
	void setFaltado(bool);
	void setEmision(Fecha);
	void setFinalizacion(Fecha);

	//sobrescritura
	virtual string toString();
	virtual void captura();

	void capturaFalta();
protected:
	double _kilometraje;
	bool _faltado;
	Fecha _emision;
	Fecha _finalizacion;

};

//Boleta Falla

class BoletaFalla{
public:
	BoletaFalla();
	~BoletaFalla();

	string getDescripcion()const;


	void setDescripcion(string);

	//sobrescritura
	virtual string toString();
	virtual void captura();

protected:
	string _descripcion;

};

class BoletaCarro : public Boleta{
protected:
	Lista _articulos;
	Lista _golpes;
	int _numeroArticulos;
	int _numeroGolpes;
public:

	Lista getArticulos()const;
	Lista getGolpes()const;
	int getNumeroArticulos()const;
	int getNumeroGolpes()const;

	void setArticulos(Lista);
	void setGolpes(Lista);
	void setNumeroArticulos(int);
	void setNumeroGolpes(int);

	BoletaCarro();
	~BoletaCarro();
	virtual void captura();
	virtual string toString();
};

//Carro con Garantia
class BoletaCarroCG : public BoletaCarro, public BoletaGarantia{	
public:
	BoletaCarroCG();
	~BoletaCarroCG();

	virtual void captura();
	virtual string toString();
};

//Carro Sin Garantia
class BoletaCarroSG :public BoletaCarro, public BoletaFalla{
public:
	BoletaCarroSG();
	~BoletaCarroSG();
	double depositoGarantia();

	virtual void captura();
	virtual string toString();
};


//Moto
class BoletaMoto : public Boleta{
protected:
	string _tipoMotor;
	int _cilindros;
public:
	BoletaMoto();
	~BoletaMoto();

	string getTipoMotor()const;
	int getCilindros()const;

	void setTipoMotor(string);
	void setCilindros(int);

	virtual void captura();
	virtual string toString();
};

//Moto con Garantia
class BoletaMotoCG : public BoletaMoto, public BoletaGarantia{
public:
	BoletaMotoCG();
	~BoletaMotoCG();

	virtual void captura();
	virtual string toString();
};

//Moto Sin Garantia
class BoletaMotoSG :public BoletaMoto, public BoletaFalla{
public:
	BoletaMotoSG();
	~BoletaMotoSG();
	double depositoGarantia();

	virtual void captura();
	virtual string toString();
};


//Cuadra
class BoletaCuadra : public BoletaMoto{
protected:
	string _suspension;
	string _transmision;
public:
	BoletaCuadra();
	~BoletaCuadra();

	string getSuspension()const;
	string getTransmision()const;

	void setSuspension(string);
	void setTransmision(string);

	virtual void captura();
	virtual string toString();
};

//Cuadra con Garantia
class BoletaCuadraCG : public BoletaCuadra, public BoletaGarantia{
public:
	BoletaCuadraCG();
	~BoletaCuadraCG();

	virtual void captura();
	virtual string toString();
};

//Cuadra Sin Garantia
class BoletaCuadraSG :public BoletaCuadra, public BoletaFalla{
protected:
	double _estimado;
public:
	BoletaCuadraSG();
	~BoletaCuadraSG();

	double getEstimado()const;
	void setEstimado(double);

	double depositoGarantia();

	virtual void captura();
	virtual string toString();
};


#endif	/* BOLETAS_H */
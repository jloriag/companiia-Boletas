#ifndef GOLPE_H
#define	GOLPE_H
#include"Objeto.h"
class Golpe : public Objeto {
public:
	Golpe();
	Golpe(string, string);

	string getLugar()const;
	string getNivel()const;

	void setLugar(string);
	void setNivel(string);

	//SobreEscritura
	string toString();
	void captura();
	~Golpe();
private:
	string _lugar;
	string _nivel;

};

#endif	/* GOLPE_H */


#ifndef FECHA_H
#define FECHA_H
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include"std.h"
class Fecha
{
public:
	Fecha();
	Fecha(int, int, int);
	int getAnno() const;
	void setAnno(int);
	int getMes() const;
	void setMes(int);
	int getDia() const;
	void setDia(int);
	string getHora();
	string toString(int = 0);
	void setHora(string);

	void captura();
	//Archivos
	~Fecha();

private:
	int _anno;
	int _mes;
	int _dia;
	string _hora;
};
#endif
#endif


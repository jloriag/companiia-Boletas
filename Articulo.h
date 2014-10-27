#ifndef ARTICULO_H
#define	ARTICULO_H
#include"Objeto.h"
class Articulo :public Objeto {
public:
	Articulo();
	Articulo(string, string);

	string getNombre()const;
	string getDescripcion()const;

	void setNombre(string);
	void setDescripcion(string);

	//SobreEscritura
	string toString();
	void captura();
	~Articulo();
private:
	string _nombre;
	string _descripcion;

};

#endif	/* ARTICULO_H */


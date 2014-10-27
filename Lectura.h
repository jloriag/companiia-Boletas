#ifndef LECTURA_H
#define	LECTURA_H
#include"Boletas.h"
class Lectura
{
public:
	BoletaCarroCG * LeeBoletaCarroCG();
	BoletaCarroSG * LeeBoletaCarroSG();
	BoletaCuadraCG * LeeBoletaCuadraCG();
	BoletaCuadraSG* LeeBoletaCuadraSG();
	BoletaMotoCG* LeeBoletaMotoCG();
	BoletaMotoSG* LeeBoletaMotoSG();
};
#endif

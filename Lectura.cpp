#include "Lectura.h"


BoletaCarroCG * Lectura::LeeBoletaCarroCG(){
	BoletaCarroCG *b = new BoletaCarroCG();
	system("cls");
	b->captura();
	return b;
}

BoletaCarroSG * Lectura::LeeBoletaCarroSG(){
	BoletaCarroSG *b = new BoletaCarroSG();
	system("cls");
	b->captura();
	return b;
}

BoletaCuadraCG * Lectura::LeeBoletaCuadraCG(){
	BoletaCuadraCG *b = new BoletaCuadraCG();
	system("cls");
	b->captura();
	return b;
}
BoletaCuadraSG* Lectura::LeeBoletaCuadraSG(){
	BoletaCuadraSG *b = new BoletaCuadraSG();
	system("cls");
	b->captura();
	return b;
}

BoletaMotoCG* Lectura::LeeBoletaMotoCG(){
	BoletaMotoCG *b = new BoletaMotoCG();
	system("cls");
	b->captura();
	return b;
}

BoletaMotoSG* Lectura::LeeBoletaMotoSG(){
	BoletaMotoSG *b = new BoletaMotoSG();
	system("cls");
	b->captura();
	return b;
}

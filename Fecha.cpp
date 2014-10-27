#include "Fecha.h"
#include "time.h"


Fecha::Fecha(){
	//-----------------------------------------
	stringstream b;
	string hor = ""; //Agregan un 0 si la hora o los minutos son menores a 10
	string min = "";
	time_t feActual = time(NULL);
	struct tm *tmp = localtime(&feActual);
	if (tmp->tm_hour<10)
		hor = "0";
	if (tmp->tm_min<10)
		min = "0";
	b << hor << tmp->tm_hour << ":" << min << tmp->tm_min;
	this->_hora = b.str();
	//-----------------------------------------
	struct tm *tiempo;
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo = localtime(&fecha_sistema);

	_dia = tiempo->tm_mday;
	_mes = tiempo->tm_mon + 1;
	_anno = tiempo->tm_year + 1900;
}

string Fecha::getHora(){
	return this->_hora;
}

Fecha::Fecha(int a, int m, int d){
	setAnno(a);
	setMes(m);
	setDia(d);
}

int Fecha::getAnno()const{
	return this->_anno;
}

int Fecha::getMes()const{
	return this->_mes;
}

int Fecha::getDia()const{
	return this->_dia;
}

void Fecha::setAnno(int a){
	_anno = a;
}

void Fecha::setMes(int a){
	if (a>0 && a<13)
		this->_mes = a;
	else
		this->_mes = 0;
}

void Fecha::setDia(int a){
	switch (this->_mes){
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (a > 0 && a < 32)
			this->_dia = a;
		else
			this->_dia = 0;
		break;
	case 4:case 6:case 9:case 11:
		if (a > 0 && a < 31)
			this->_dia = a;
		else
			this->_dia = 0;
		break;
	case 2:
		if (a > 0 && a < 30)
			this->_dia = a;
		else
			this->_dia = 0;
		break;
	default:
		this->_dia = 0;
		break;
	}
}

string Fecha::toString(int variab){
	if (variab == 0){
		stringstream s;
		s << this->_dia << "/" << this->_mes << "/" << this->_anno;
		return s.str();
	}
	else{
		stringstream s;
		string mes;
		char* dS[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
		time_t tSac = time(NULL);       // instante actual
		struct tm* tmP = localtime(&tSac);
		switch (tmP->tm_mon + 1){
		case 1: mes = "Enero"; break;
		case 2: mes = "Febrero"; break;
		case 3: mes = "Marzo"; break;
		case 4: mes = "Abril"; break;
		case 5: mes = "Mayo"; break;
		case 6: mes = "Junio"; break;
		case 7: mes = "Julio"; break;
		case 8: mes = "Agosto"; break;
		case 9: mes = "Septiembre"; break;
		case 10: mes = "Octubre"; break;
		case 11: mes = "Noviembre"; break;
		case 12: mes = "Diciembre"; break;
		default: mes = "---"; break;
		}
		s << "                Fecha: ";
		s << dS[tmP->tm_wday] << " " << tmP->tm_mday << " de " << mes << " del " << tmP->tm_year + 1900 << endl;
		s << "                Hora: " << this->_hora << endl;
		return s.str();
	}
}
void Fecha::captura(){
	cin.clear();
	_flushall();
	int op;
	cout << "Si desea la Fecha Actual digite 1 o cualquier otra tecla para continuar"<<endl;
	cin >> op;
	if (op!=1){
		cout << "Ingrese la Fecha :" << endl;
		cout << "Dia: " << endl;
		cin >> _dia;
		cout << "Mes: " << endl;
		cin >> _mes;
		cout << "Annio" << endl;
		cin >> _anno;
	}
	else{
		cout << "->Fecha de Sistema Agregada!" << endl;
	}
}


void Fecha::setHora(string hor){
	this->_hora = hor;
}

Fecha::~Fecha()
{
}

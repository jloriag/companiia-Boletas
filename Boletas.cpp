/*
* File:   Boletas.cpp
* Author: estudiante
*
* Created on 23 de octubre de 2014, 09:40 AM
*/

#include "Boletas.h"

Boleta::Boleta() : Objeto(), _modelo(0), _estilo("Sin definir") {
}

Boleta::~Boleta(){
}

int Boleta::getModelo()const {
	return _modelo;
}

string Boleta::getEstilo()const {
	return _estilo;
}

Fecha Boleta::getFechaE()const {
	return _fechaEntrada;
}

Fecha Boleta::getFechaS()const {
	return _fechaSalida;
}

Cliente Boleta::getCliente()const {
	return _cliente;
}

int Boleta::getID()const {
	return getKey();
}

void Boleta::setModelo(int modelo) {
	_modelo = modelo;
}

void Boleta::setEstilo(string estilo) {
	_estilo = estilo;
}

void Boleta::setFechaE(Fecha Fecha) {
	_fechaEntrada = Fecha;
}

void Boleta::setFechaS(Fecha Fecha) {
	_fechaSalida = Fecha;
}

void Boleta::setCliente(Cliente cliente) {
	_cliente = cliente;
}

void Boleta::setId(int id) {
	setKey(id);
}

string Boleta::toString() {
	stringstream s;
	s << "Boleta # : " << getID();
	s << _cliente.toString() << endl;
	s<< endl << "Modelo: " << getModelo() << endl << "Estilo: " << getEstilo() << endl << "Fecha Entrada: " << getFechaE().toString(0) <<endl<< "Fecha Salida: " << getFechaS().toString(0) << endl;
	return s.str();
}
void Boleta::captura(){
	cout << "---Agregar Boleta---" << endl;
	cout << "Numero de ID (key) de Boleta"<<endl;
	cin >> _key;
	_cliente.captura();
	cout << "Modelo del Vehiculo: " << endl;
	cin >> _modelo;
	cout << "Estilo del Vehiculo: " << endl;
	cin >> _estilo;
	cout << "Fecha de Entrada:" << endl;
	_fechaEntrada.captura();
	cout << "Fecha de Salida" << endl;
	_fechaSalida.captura();

}

//-------------------------------------- FIN DE BOLETA -----------------------------------------

//-------------------------------------- INICIO DE BOLETA GARANTIA -----------------------------------------

BoletaGarantia::BoletaGarantia() :  _kilometraje(0.0), _faltado(false), _emision(), _finalizacion(){
}

BoletaGarantia::~BoletaGarantia(){
}

double BoletaGarantia::getKilometraje()const {
	return _kilometraje;
}

bool BoletaGarantia::getFaltado()const {
	return _faltado;
}

Fecha BoletaGarantia::getEmision()const{
	return _emision;
}

Fecha BoletaGarantia::getFinalizacion()const{
	return _finalizacion;
}


void BoletaGarantia::setKilometraje(double kilometraje) {
	_kilometraje = kilometraje;
}

void BoletaGarantia::setFaltado(bool faltado) {
	_faltado = faltado;
}

void BoletaGarantia::setEmision(Fecha emision){
	_emision = emision;
}

void BoletaGarantia::setFinalizacion(Fecha finalizacion){
	_finalizacion = finalizacion;
}

string BoletaGarantia::toString() {
	stringstream s;
	s << "Kilometraje de garantía: " << getKilometraje() << endl << "Ha faltado?: " << getFaltado()
		<< endl << "Fecha de emisión de garantía: " << getEmision().toString() << endl << "Fecha de finalización de garantía: " << getFinalizacion().toString() << endl;
	return s.str();
}
void BoletaGarantia::captura(){
	cout << "---Agregar Garantía---" << endl;
	cout << "Kilometraje: " << endl;
	cin >> _kilometraje;
	capturaFalta();
	cout << "Fecha de Emisión: " << endl;
	_emision.captura();
	cout << "Fecha de Finalización: " << endl;
	_finalizacion.captura();
	
}

void BoletaGarantia::capturaFalta(){ 
	char d;
	cout << "Ha faltado? (y/n) : " << endl;
	cin >> d;
	if (d == 'y'){
		_faltado = true;
	}
	else{
		_faltado = false;
	}
}

//-------------------------------------- FIN DE BOLETA GARANTIA	-----------------------------------------

//-------------------------------------- INICIO DE BOLETA FALLA	-----------------------------------------
BoletaFalla::BoletaFalla() : _descripcion("sin definir"){
}

BoletaFalla::~BoletaFalla(){
}

string BoletaFalla::getDescripcion()const {
	return _descripcion;
}

void BoletaFalla::setDescripcion(string descripcion) {
	_descripcion = descripcion;
}


string BoletaFalla::toString() {
	stringstream s;
	s << "Descripcion de Falla: " << getDescripcion() << endl;
	return s.str();
}
void BoletaFalla::captura(){
	cout << "---Agregar Falla---" << endl;
	cout << "Descripcion de la falla: " << endl;
	cin >> _descripcion;

}

//-------------------------------------- FIN DE BOLETA FALLA	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE CARRO	-----------------------------------------

BoletaCarro::BoletaCarro() :Boleta(){
}

Lista BoletaCarro::getArticulos()const {
	return _articulos;
}

Lista BoletaCarro::getGolpes()const {
	return _golpes;
}

int BoletaCarro::getNumeroArticulos()const{
	return _numeroArticulos;
}

int BoletaCarro::getNumeroGolpes()const{
	return _numeroGolpes;
}

void BoletaCarro::setArticulos(Lista articulos) {
	_articulos = articulos;
}

void BoletaCarro::setGolpes(Lista golpes){
	_golpes = golpes;
}

void BoletaCarro::setNumeroArticulos(int numeroArticulos){
	_numeroArticulos = numeroArticulos;
}

void BoletaCarro::setNumeroGolpes(int numeroGolpes){
	_numeroGolpes = numeroGolpes;
}

void BoletaCarro::captura(){
	Boleta::captura();
	cout << "Numero de Articulos del Vehiculo: ";
	cin >> _numeroArticulos;
	Articulo* _articulo;
	for (int i = 1; i <= _numeroArticulos; i++) {
		_articulo = new Articulo();
		_articulo->captura();
		_articulos.Inserta(_articulo);
	}
	cout << "Numero de Dannios del Vehiculos: " << endl;
	cin >> _numeroGolpes;
	Golpe* _dannio;
	for (int i = 1; i <= _numeroGolpes; i++) {
		_dannio = new Golpe();
		_dannio->captura();
		_golpes.Inserta(_dannio);
	}

}
string BoletaCarro::toString(){
	stringstream s;
	s << "Informacion de Boleta Carro" << endl;
	s << Boleta::toString() << endl;
	s << "Numero de Articulos del Carro: " << endl;
	s << _numeroArticulos << endl;
	s << "-----Lista de Articulos-----" << endl;
	s << _articulos.toString() << endl;
	s << "Numero de Golpes/Rayas del Carro: " << endl;
	s << _numeroGolpes << endl;
	s << "-----Lista de Golpes/Rayas-----" << endl;
	s << _golpes.toString() << endl;
	return s.str();

}
BoletaCarro::~BoletaCarro(){

}

//-------------------------------------- FIN DE BOLETA DE CARRO	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE CARRO CON GARANTIA	-----------------------------------------

BoletaCarroCG::BoletaCarroCG() :BoletaCarro(), BoletaGarantia(){
}
void BoletaCarroCG::captura(){
	BoletaCarro::captura();
	BoletaGarantia::captura();
}

string BoletaCarroCG::toString(){
	stringstream s;
	s << BoletaCarro::toString() << endl;
	s << BoletaGarantia::toString() << endl;
	return s.str();
}

BoletaCarroCG::~BoletaCarroCG(){
}

//-------------------------------------- FIN DE BOLETA DE CARRO CON GARANTIA	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE CARRO SIN GARANTIA	-----------------------------------------

BoletaCarroSG::BoletaCarroSG() :BoletaCarro(), BoletaFalla(){
}

void BoletaCarroSG::captura(){
	BoletaCarro::captura();
	BoletaFalla::captura();
}

string BoletaCarroSG::toString(){
	stringstream s;
	s << BoletaCarro::toString() << endl;
	s << BoletaFalla::toString() << endl;
	return s.str();
}

double BoletaCarroSG::depositoGarantia(){
	return (double)getModelo() * 100;
}

BoletaCarroSG::~BoletaCarroSG(){
}

//-------------------------------------- FIN DE BOLETA DE CARRO SIN GARANTIA	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA MOTO	-----------------------------------------

BoletaMoto::BoletaMoto() :Boleta(){
}

string BoletaMoto::getTipoMotor()const {
	return _tipoMotor;
}

int BoletaMoto::getCilindros()const {
	return _cilindros;
}

void BoletaMoto::setTipoMotor(string tipoMotor) {
	_tipoMotor = tipoMotor;
}

void BoletaMoto::setCilindros(int cilindros){
	_cilindros = cilindros;
}

void BoletaMoto::captura(){
	Boleta::captura();
	cout << "Tipo de motor: " << endl;
	cin >> _tipoMotor;
	cout << "Numero de Cilindros: " << endl;
	cin >> _cilindros;
}

string BoletaMoto::toString(){
	stringstream s;
	s << "Informacion de Boleta Moto" << endl;
	s << Boleta::toString() << endl;
	s << "tipo de motor: " << endl;
	s << _tipoMotor << endl;
	s << "cilindros: " << endl;
	s << _cilindros << endl;
	return s.str();

}
BoletaMoto::~BoletaMoto(){

}

//-------------------------------------- FIN DE BOLETA DE MOTO	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE MOTO CON GARANTIA	-----------------------------------------

BoletaMotoCG::BoletaMotoCG() :BoletaMoto(), BoletaGarantia(){
}
void BoletaMotoCG::captura(){
	BoletaMoto::captura();
	BoletaGarantia::captura();
}

string BoletaMotoCG::toString(){
	stringstream s;
	s << BoletaMoto::toString() << endl;
	s << BoletaGarantia::toString() << endl;
	return s.str();
}

BoletaMotoCG::~BoletaMotoCG(){
}

//-------------------------------------- FIN DE BOLETA DE MOTO CON GARANTIA	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE MOTO SIN GARANTIA	-----------------------------------------

BoletaMotoSG::BoletaMotoSG() :BoletaMoto(), BoletaFalla(){
}

void BoletaMotoSG::captura(){
	BoletaMoto::captura();
	BoletaFalla::captura();
}

string BoletaMotoSG::toString(){
	stringstream s;
	s << BoletaMoto::toString() << endl;
	s << BoletaFalla::toString() << endl;
	return s.str();
}

double BoletaMotoSG::depositoGarantia(){
	return (double)getModelo() * 10.0;
}

BoletaMotoSG::~BoletaMotoSG(){
}

//-------------------------------------- FIN DE BOLETA DE MOTO SIN GARANTIA	-----------------------------------------

//-------------------------------------- INICIO DE BOLETA CUADRA	-----------------------------------------

BoletaCuadra::BoletaCuadra() :BoletaMoto(){
}

string BoletaCuadra::getSuspension()const {
	return _suspension;
}

string BoletaCuadra::getTransmision()const {
	return _transmision;
}

void BoletaCuadra::setSuspension(string suspension) {
	_suspension = suspension;
}

void BoletaCuadra::setTransmision(string transmision){
	_transmision = transmision;
}

void BoletaCuadra::captura(){
	BoletaMoto::captura();
	cout << "Suspension: " << endl;
	cin >> _suspension;
	cout << "Transmision: " << endl;
	cin >> _transmision;
}

string BoletaCuadra::toString(){
	stringstream s;
	s << "Informacion de Boleta Cuadra" << endl;
	s << Boleta::toString() << endl;
	s << "Suspensión: " << endl;
	s << _suspension << endl;
	s << "Transmisión: " << endl;
	s << _transmision << endl;
	return s.str();

}
BoletaCuadra::~BoletaCuadra(){

}

//-------------------------------------- FIN DE BOLETA DE CUADRA	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE CUADRA CON GARANTIA	-----------------------------------------

BoletaCuadraCG::BoletaCuadraCG() :BoletaCuadra(), BoletaGarantia(){
}
void BoletaCuadraCG::captura(){
	BoletaCuadra::captura();
	BoletaGarantia::captura();
	
}

string BoletaCuadraCG::toString(){
	stringstream s;
	s << BoletaCuadra::toString() << endl;
	s << BoletaGarantia::toString() << endl;
	return s.str();
}

BoletaCuadraCG::~BoletaCuadraCG(){
}

//-------------------------------------- FIN DE BOLETA DE CUADRA CON GARANTIA	-----------------------------------------
//-------------------------------------- INICIO DE BOLETA DE CUADRA SIN GARANTIA	-----------------------------------------

BoletaCuadraSG::BoletaCuadraSG() :BoletaCuadra(), BoletaFalla(){
}

double BoletaCuadraSG::getEstimado()const {
	return _estimado;
}

void BoletaCuadraSG::setEstimado(double estimado) {
	_estimado = estimado;
}

void BoletaCuadraSG::captura(){
	BoletaCuadra::captura();
	BoletaFalla::captura();
	cout << "Estimado del Mecánico: " << endl;
	cin >> _estimado;
}

string BoletaCuadraSG::toString(){
	stringstream s;
	s << BoletaCuadra::toString() << endl;
	s << BoletaFalla::toString() << endl;
	s << "Estimado de Mecánico: " << endl;
	s << _estimado << endl;
	return s.str();
}

double BoletaCuadraSG::depositoGarantia(){
	return (double)getModelo() * 150 + _estimado;
}

BoletaCuadraSG::~BoletaCuadraSG(){
}

//-------------------------------------- FIN DE BOLETA DE CUADRA SIN GARANTIA	-----------------------------------------

#include "interfaz.h"


interfaz::interfaz()
{
}

char interfaz :: MenuPrincipal() {
	cin.clear();
	_flushall();
	system("cls");
	cout << "[1] Agregar Boleta" << endl;
	cout << "[2] Ver la Lista de Boletas" << endl;
	cout << "[3] Eliminar Boleta " << endl;
	cout << "[4] Eliminar TODAS las Boletas " << endl;
	cout << "[5] Salir" << endl;
	cin >> opcion;
	return opcion;
}

char interfaz :: MenuBoletas(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "---------AGREGAR BOLETAS----------" << endl;
	cout << "-> Que tipo de Boleta desea insertar? " << endl;
	cout << "[1] Agregar Boleta Carro" << endl;
	cout << "[2] Agregar Boleta Moto/Cuadra" << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}

char interfaz :: MenuBoletasCarro(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "---------AGREGAR BOLETA CARRO ----------" << endl;
	cout << "-> El Vehiculo tiene garantia ? " << endl;
	cout << "[1] SI" << endl;
	cout << "[2] NO" << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}

char interfaz :: MenuBoletasMoto(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "---------AGREGAR BOLETA MOTO/CUADRA ----------" << endl;
	cout << "-> Que tipo de vehiculo desea agregar ? " << endl;
	cout << "[1] Motoclicleta" << endl;
	cout << "[2] Cuadraciclo" << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}

char interfaz :: MenuBoletasMotoclicleta(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "---------AGREGAR BOLETA MOTOCICLETA ----------" << endl;
	cout << "-> El Vehiculo tiene garantia ? " << endl;
	cout << "[1] SI" << endl;
	cout << "[2] NO" << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}

char interfaz :: MenuBoletasCuadraCiclo(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "---------AGREGAR BOLETA CUADRACICLO ----------" << endl;
	cout << "-> El Vehiculo tiene garantia ? " << endl;
	cout << "[1] SI" << endl;
	cout << "[2] NO" << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}

int interfaz::MenuBorrarBoleta(){
	int key;
	cin.clear();
	_flushall();
	system("cls");
	cout << "---------ELIMINAR BOLETA ----------" << endl;
	cout << "-> Ingrese en ID(key) de la Boleta  " << endl;
	cin >> key;
	return key;
}

void interfaz::Principal(){
	do{
		insert = false;
		opcionPrincipal = MenuPrincipal();
		switch (opcion)
		{
		case'1':
			Boletas();
			break;
		case'2':
			system("cls");
			cout<<_objetosBoletas.toString()<<endl;
			system("pause");
			break;
		case'3':
			BorraBoleta();
			break;
		case'4':
			system("cls");
			_objetosBoletas.destruir();
			cout << "TODAS las Boletas eliminadas"<<endl;
			system("pause");
			break;
		default:
			break;
		}
	} while (opcion != '5' );
}

void interfaz::Boletas(){
	
	do{
		opcionPrincipal = MenuBoletas();
		switch (opcion)
		{
		case'1':
			BoletasCarro();
			break;
		case'2':
			BoletasMoto();
			break;
		default:
			break;
		}
	} while (opcion != '3' && !insert);

}

void interfaz::BoletasCarro(){
	
	do{
		opcionPrincipal = MenuBoletasCarro();
		switch (opcion)
		{
		case'1':
			_objetosBoletas.Inserta(_lectura.LeeBoletaCarroCG());
			insert = true;
			cout << "Se AGREGO una Boleta Carro CON Garantia" << endl;
			system("pause");
			break;
		case'2':
			_objetosBoletas.Inserta(_lectura.LeeBoletaCarroSG());
			insert = true;
			cout << "Se AGREGO una Boleta Motocicleta SIN Garantia" << endl;
			system("pause");
			break;
		default:
			break;
		}
	} while (opcion != '3' && !insert);
}

void interfaz::BoletasMoto(){
	
	do{
		opcionPrincipal = MenuBoletasMoto();
		switch (opcion)
		{
		case'1':
			BoletasMotocicleta();
			break;
		case'2':
			BoletasCuadraciclo();
			break;
		default:
			break;
		}
	} while (opcion != '3' && !insert);
}

void interfaz::BoletasMotocicleta(){
	
	do{
		opcionPrincipal = MenuBoletasMotoclicleta();
		switch (opcion)
		{
		case'1':
			_objetosBoletas.Inserta(_lectura.LeeBoletaMotoCG());
			insert = true;
			cout << "Se AGREGO una Boleta Motocicleta CON Garantia" << endl;
			system("pause");
			break;
		case'2':
			_objetosBoletas.Inserta(_lectura.LeeBoletaMotoSG());
			insert = true;
			cout << "Se AGREGO una Boleta Motocicleta SIN Garantia" << endl;
			system("pause");
			break;
		default:
			break;
		}
	} while (opcion != '3' && !insert );
}

void interfaz::BoletasCuadraciclo(){
	
	do{
		opcionPrincipal = MenuBoletasCuadraCiclo();
		switch (opcion)
		{
		case'1':
			_objetosBoletas.Inserta(_lectura.LeeBoletaCuadraCG());
			insert = true;
			cout << "Se AGREGO una Boleta Cuadraciclo CON Garantia" << endl;
			system("pause");
			break;
		case'2':
			_objetosBoletas.Inserta(_lectura.LeeBoletaCuadraSG());
			insert = true;
			cout << "Se AGREGO una Boleta Cuadraciclo SIN Garantia" << endl;
			system("pause");
			break;
		default:
			break;
		}
	} while (opcion != '3' && !insert);
}

void interfaz::BorraBoleta(){
	if (_objetosBoletas.borrar(MenuBorrarBoleta())){
		cout << "Se elimino la Boleta Correctamente"<<endl;
	}
	else{
		cout << "No se ha encontrando la Boleta " << endl;
	}
	system("pause");
}

interfaz::~interfaz() 
{
}


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declaración de estructura
struct Entradas{
	string Zona;
	string id;
	float totalPagado;
};

//Declaración de vector de tipo estructura
std::vector<Entradas> vtrEntradas;

/*
	Función encargada de agregar registro a archivo.
	Recibe los siguientes parámetros:
		-Zona
		-Identificador
		-Total Pagado
*/
void agregarRegistroArchivo(string _Zona, string _Id, float _TotalPagado){
	//Grabar registro en archivo
	ofstream archivoEntradas("HT5_EJERCICIO_02.txt", std::ios_base::app);
	
	archivoEntradas << _Zona << "\t" << _Id << "\t" << _TotalPagado << endl;
	
	//Cerrar Archivo
	archivoEntradas.close();
	cout << "--------------------------------" << endl;
	cout << "REGISTRO AGREGADO CORRECTAMENTE" << endl;
	cout << "--------------------------------" << endl;
}

/*
	Función encargada de aplicar un descuento si el usuario es socio
	Recibe los siguientes parámetros:
		-Total: El total sobre el que se aplicará el descuento
	
	Retorna un valor de tipo float.
*/
float descuentoSocio(float _total){
	float _granTotal;
	float descuento = _total * 0.08;
	
	_granTotal = _total - descuento;
	
	return _granTotal;
}

/*
	Función encargada de aplicar descuento por número de entradas compradas.
	Recibe los siguientes parámetros:
		-_nEntradas: Variable con el número de entradas
		-_precio: Variable con el precio según el tipo de entrada
	
	Retorna un valor de tipo float.
*/
float descuentoPorNumeroEntradas(int _nEntradas, float _precio){
	float total;
	float totalParcial;
	float granTotal;
	int opcion;
	
	if (_nEntradas >= 3 and _nEntradas <= 6){
		totalParcial = (_nEntradas*_precio) * 0.05;
		total = (_nEntradas*_precio) - totalParcial;
	}
	else if (_nEntradas >= 7 and _nEntradas <= 9){
		totalParcial = (_nEntradas*_precio) * 0.075;
		total = (_nEntradas*_precio) - totalParcial;
	}
	else if (_nEntradas > 9){
		totalParcial = (_nEntradas*_precio) * 0.1;
		total = (_nEntradas*_precio) - totalParcial;
	}
	else{
		total = _nEntradas * _precio;
	}
	
	cout << "¿Es Socio?" << endl;
	cout << "1. Sí" << endl;
	cout << "2. No" << endl;
	cin >> opcion;
	
	if (opcion = 1){
		granTotal = descuentoSocio(total);
	}else{
		granTotal = total;
	}
	
	return granTotal;	
}

//Función encargada de leer archivo
void leerArchivo(){
	//Declaración de variable de tipo archivo
	ifstream archivoEntradas;
	//Declaración de variable de tipo estructura
	Entradas strEntrada;
	
	//Función encargada de abrir el archivo correspondiente.
	archivoEntradas.open("HT5_EJERCICIO_02.txt", ios::in);
	
	//Extracción de datos en archivo
	while (archivoEntradas >> strEntrada.Zona >> strEntrada.id >> strEntrada.totalPagado){
		//Se llena el vector según los datos extraídos del archivo
		vtrEntradas.push_back(strEntrada);
	}
	
	//Cierra el archivo
	archivoEntradas.close();
	
	return;
}


//Función encargada de obtener el total global vendido
void totalVendido(){
	float totalVendido = 0.00;
	
	leerArchivo();
	
	for (int i = 0; i < vtrEntradas.size(); i ++){
		totalVendido = vtrEntradas[i].totalPagado + totalVendido;
	}
	
	cout <<"----------------------------------------" << endl;
	cout << "EL TOTAL GLOBAL VENDIDO ES: Q." << totalVendido << endl; 
	cout <<"----------------------------------------" << endl;
	vtrEntradas.clear();	
}

//Función encargada de obtener el total vendido por tipo de entrada
void totalVendidoXTipoEntrada(){
	float totalVIP = 0.00;
	float totalPlatea = 0.00;
	float totalPopular = 0.00;
	
	leerArchivo();
	
	for (int i = 0; i < vtrEntradas.size(); i ++){
		if (vtrEntradas[i].id == "V"){
			totalVIP = vtrEntradas[i].totalPagado + totalVIP;
		}
		else if (vtrEntradas[i].id == "P"){
			totalPlatea = vtrEntradas[i].totalPagado + totalPlatea;
		}
		else if (vtrEntradas[i].id == "E"){
			totalPopular = vtrEntradas[i].totalPagado + totalPopular;
		}
	}
	
	cout << "------------TOTAL VENDIDO POR TIPO DE ENTRADA------------" << endl;
	cout << "VIP: Q." << totalVIP << endl;
	cout << "PLATEA: Q." << totalPlatea << endl;
	cout << "POPULAR: Q." << totalPopular << endl;
	cout << "---------------------------------------------------------"<< endl;
	
	vtrEntradas.clear();
}

//Función encargada de procesar la compra de entradas
void compraDeEntradas(){
	int opcionEntrada;
	int nEntradas;
	Entradas strEntrada;
	
	cout << "----------------COMPRA DE ENTRADAS----------------" << endl;
	cout << "ZONA" << "\t" << "\t" << "PRECIO" << endl;
	cout << "1. VIP" << "\t" << "\t" << "Q.350" << endl;
	cout << "2. PLATEA" << "\t" << "Q.130" << endl;
	cout << "3. POPULAR" << "\t" << "Q.50" << endl;
	cin >> opcionEntrada;
	
	cout << "Ingrese el número de entradas: " << endl;
	cin >> nEntradas;
	
	
	switch (opcionEntrada){
		case 1:
			strEntrada.Zona = "VIP";
			strEntrada.id = "V";
			strEntrada.totalPagado = descuentoPorNumeroEntradas(nEntradas, 350.00);
			break;
		case 2:
			strEntrada.Zona = "PLATEA";
			strEntrada.id = "P";
			strEntrada.totalPagado = descuentoPorNumeroEntradas(nEntradas, 130.00);
			break;
		case 3:
			strEntrada.Zona = "POPULAR";
			strEntrada.id = "E";
			strEntrada.totalPagado = descuentoPorNumeroEntradas(nEntradas, 50.00);
			break;
		default:
			cout << "¡Opción incorrecta!" << endl;
			opcionEntrada = 0;
			break;
	}
	
	agregarRegistroArchivo(strEntrada.Zona, strEntrada.id, strEntrada.totalPagado);
}


//Función Principal
int main(){
	int opcion;
	bool finalizar = false;
	
	do{
		fflush(stdin);
		cin.clear();
		
		cout << "------------------------------MENU PRINCIPAL------------------------------" << endl;
		cout << "1. Compra de tickets" << endl;
		cout << "2. Total vendido" << endl;
		cout << "3. Total vendido por tipo de entrada" << endl;
		cout << "4. Salir" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				compraDeEntradas();
				break;
			case 2:
				totalVendido();
				break;
			case 3:
				totalVendidoXTipoEntrada();
				break;
			case 4:
				finalizar = true;
				break;
			default:
				cout << "¡Opción incorrecta!" << endl;
				opcion = 0;
				break;
		}
	}while (finalizar != true);
	
	return 0;
}

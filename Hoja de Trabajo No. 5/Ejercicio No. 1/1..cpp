//Importación de librerías
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declaración de estructura.
struct Terrenos{
	string categoria;
	string zona;
	string tipo;
	float precio;
	float precioPagado;
};

//Declaración de vector de tipo estructura 'Terrenos'
std::vector<Terrenos> vtrTerreno;

/* Función encargada de agregar datos en archivo,
	Recibe como parámetros los campos necesarios para guardar en el archivo:
		-Categoría
		-Zona
		-Tipo
		-Precio
		-Total Pagado
*/

void agregarRegistroArchivo(string _Categoria, string _Zona, string _Tipo, float _Precio, float _PrecioPagado){
	//Grabar registro en archivo
	ofstream archivoTerrenos("HT5_EJERCICIO_01.txt", std::ios_base::app);
	
	archivoTerrenos <<
	_Categoria << "\t"<< _Zona << "\t" << _Tipo << "\t" << _Precio << "\t" << _PrecioPagado << endl;
	
	//Cerrar Archivo
	archivoTerrenos.close();
	cout << "-------------------------------" << endl;
	cout << "REGISTRO AGREGADO CORRECTAMENTE" << endl;
	cout << "-------------------------------" << endl;
}

// Función encargada de leer el archivo
void leerArchivo(){
	//Declaración de variable de tipo archivo
	ifstream archivoTerrenos;
	//Declaración de variable de tipo estructura
	Terrenos strTerreno;
	
	//Función encargada de abrir el archivo correspondiente.
	archivoTerrenos.open("HT5_EJERCICIO_01.txt", ios::in);
	
	//Extracción de datos en archivo
	while (archivoTerrenos >> strTerreno.categoria >> strTerreno.zona >> strTerreno.tipo >> strTerreno.precio >> strTerreno.precioPagado){
		//Se llena el vector según los datos extraídos del archivo
		vtrTerreno.push_back(strTerreno);
	}
	
	//Cierra el archivo
	archivoTerrenos.close();
	
	return;
}

//Función encargada de las gestiones de la Categoría Comercial
void categoriaComercial(){
	//Declaración de variables
	Terrenos strTerreno;
	float metros;
	int opcionZona;
	string opcionTipo;
	
	//Limpiar buffer y métodos de entrada
	fflush(stdin);
	cin.clear();
	
	//Menú de la categoría COMERCIAL	
	cout << "----------COMERCIAL----------"<< endl;
	cout << "Seleccione la zona:" << endl;
	cout << "1. Zona A" << endl;
	cout << "2. Zona B" << endl;
	cin >> opcionZona;
	
	//Según la zona ingresada se muestran diferentes sub menús
	switch(opcionZona){
		case 1:
			//Si la zona elegida es la "A"
			cout << "Elija el tipo:" << endl;
			cout << "TIPO" << "\t" << "\t" << "Precio m2" << endl;
			cout << "1. Terreno" << "\t" << "$2,200" << endl;
			cout << "2. Casa" << "\t" << "\t" << "$2,500" << endl;
			cout << "3. Departamento" << "\t" << "$2,100" << endl;
			cin >> opcionTipo;
			
			cout << "Ingrese el número de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes según el tipo de inmueble elegido
			if (opcionTipo == "1"){
				strTerreno.categoria = "Comercial";
				strTerreno.zona = "A";
				strTerreno.tipo = "Terreno";
				strTerreno.precio = 2200;
				strTerreno.precioPagado = metros*2200;
			}
			else if(opcionTipo == "2"){
				strTerreno.categoria = "Comercial";
				strTerreno.zona = "A";
				strTerreno.tipo = "Casa";
				strTerreno.precio = 2500;
				strTerreno.precioPagado = metros*2500;
			}
			else if(opcionTipo == "3"){
				strTerreno.categoria = "Comercial";
				strTerreno.zona = "A";
				strTerreno.tipo = "Departamento";
				strTerreno.precio = 2100;
				strTerreno.precioPagado = metros*2100;
			}
			break;
		case 2:
			//Si la zona elegida es la "B"
			cout << "Elija el tipo:" << endl;
			cout << "TIPO" << "\t" << "\t" << "Precio m2" << endl;
			cout << "1. Terreno" << "\t" << "$1,300" << endl;
			cout << "2. Casa" << "\t" << "\t" << "$1,500" << endl;
			cout << "3. Departamento" << "\t" << "$1,200" << endl;
			cin >> opcionTipo;
			
			cout << "Ingrese el número de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes según el tipo de inmueble elegido
			if (opcionTipo == "1"){
				strTerreno.categoria = "Comercial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Terreno";
				strTerreno.precio = 1300;
				strTerreno.precioPagado = metros*1300;
			}
			else if(opcionTipo == "2"){
				strTerreno.categoria = "Comercial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Casa";
				strTerreno.precio = 1500;
				strTerreno.precioPagado = metros*1500;
			}
			else if(opcionTipo == "3"){
				strTerreno.categoria = "Comercial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Departamento";
				strTerreno.precio = 1200;
				strTerreno.precioPagado = metros*1200;
			}
			break;
		default:
			cout << "¡Opción inválida!" << endl;
			opcionZona = 0;
			break;
	}
	
	/*	Invocación de la función para agregar el registro al archivo. 
		Se ingresan los parámetros correspondientes según validaciones anteriores.
	*/
	agregarRegistroArchivo(strTerreno.categoria, strTerreno.zona, strTerreno.tipo, strTerreno.precio, strTerreno.precioPagado);
	
}

//Función encargada de las gestiones de la Categoría Residencial
void categoriaResidencial(){
	//Declaración de variables
	Terrenos strTerreno;
	float metros;
	int opcionZona;
	string opcionTipo;
	
	//Limpiar buffer y métodos de entrada
	fflush(stdin);
	cin.clear();
	
	//Menú de la categoría RESIDENCIAL
	cout << "----------RESIDENCIAL----------"<< endl;
	cout << "Seleccione la zona:" << endl;
	cout << "1. Zona A" << endl;
	cout << "2. Zona B" << endl;
	cout << "3. Zona C" << endl;
	cin >> opcionZona;
	
	switch (opcionZona){
		case 1:
			//Si la zona elegida es la "A"
			cout << "Elija el tipo:" << endl;
			cout << "TIPO" << "\t" << "\t" << "Precio m2" << endl;
			cout << "1. Terreno" << "\t" << "$2,100" << endl;
			cout << "2. Casa" << "\t" << "\t" << "$2,500" << endl;
			cout << "3. Departamento" << "\t" << "$2,100" << endl;
			cin >> opcionTipo;
			
			cout << "Ingrese el número de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes según el tipo de inmueble elegido
			if (opcionTipo == "1"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "A";
				strTerreno.tipo = "Terreno";
				strTerreno.precio = 2100;
				strTerreno.precioPagado = metros*2100;
			}
			else if(opcionTipo == "2"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "A";
				strTerreno.tipo = "Casa";
				strTerreno.precio = 2500;
				strTerreno.precioPagado = metros*2500;
			}
			else if(opcionTipo == "3"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "A";
				strTerreno.tipo = "Departamento";
				strTerreno.precio = 2100;
				strTerreno.precioPagado = metros*2100;
			}
			break;
		case 2:
			//Si la zona elegida es la "B"
			cout << "Elija el tipo:" << endl;
			cout << "TIPO" << "\t" << "\t" << "Precio m2" << endl;
			cout << "1. Terreno" << "\t" << "$1,500" << endl;
			cout << "2. Casa" << "\t" << "\t" << "$1,600" << endl;
			cout << "3. Departamento" << "\t" << "$1,300" << endl;
			cin >> opcionTipo;
			
			cout << "Ingrese el número de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes según el tipo de inmueble elegido
			if (opcionTipo == "1"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Terreno";
				strTerreno.precio = 1500;
				strTerreno.precioPagado = metros*1500;
			}
			else if(opcionTipo == "2"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Casa";
				strTerreno.precio = 1600;
				strTerreno.precioPagado = metros*1600;
			}
			else if(opcionTipo == "3"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Departamento";
				strTerreno.precio = 1300;
				strTerreno.precioPagado = metros*1300;
			}
			break;
		case 3:
			//Si la zona elegida es la "C"
			cout << "Elija el tipo:" << endl;
			cout << "TIPO" << "\t" << "\t" << "Precio m2" << endl;
			cout << "1. Terreno" << "\t" << "$1,100" << endl;
			cout << "2. Casa" << "\t" << "\t" << "$1,300" << endl;
			cout << "3. Departamento" << "\t" << "$1,000" << endl;
			cin >> opcionTipo;
			
			cout << "Ingrese el número de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes según el tipo de inmueble elegido
			if (opcionTipo == "1"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Terreno";
				strTerreno.precio = 1100;
				strTerreno.precioPagado = metros*1100;
			}
			else if(opcionTipo == "2"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Casa";
				strTerreno.precio = 1300;
				strTerreno.precioPagado = metros*1300;
			}
			else if(opcionTipo == "3"){
				strTerreno.categoria = "Residencial";
				strTerreno.zona = "B";
				strTerreno.tipo = "Departamento";
				strTerreno.precio = 1000;
				strTerreno.precioPagado = metros*1000;
			}
			break;
		default:
			cout << "¡Opción Inválida!" << endl;
			opcionZona = 0;
			break;
	}
	
	/*	Invocación de la función para agregar el registro al archivo. 
		Se ingresan los parámetros correspondientes según validaciones anteriores.
	*/
	agregarRegistroArchivo(strTerreno.categoria, strTerreno.zona, strTerreno.tipo, strTerreno.precio, strTerreno.precioPagado);
}

//Función encargada de gestionar el ingreso de inmuebles
void registroTerreno(){
	//Declaración de variables
	int opcionRegistroTerreno;
	bool finalizarRegistroTerreno = false;
	
	//Submenú para seleccionar el tipo de categoría
	do {
		cout << "Seleccione tipo de Categoría" << endl;
		cout << "1. Comercial" << endl;
		cout << "2. Residencial" << endl;
		cout << "3. Salir" << endl;
		cin >> opcionRegistroTerreno;
		
		switch (opcionRegistroTerreno){
			case 1:
				//Invocación de función para gestiones de categoría Comercial
				categoriaComercial();
				break;
			case 2:
				//Invocación de función para gestiones de categoría Residencial
				categoriaResidencial();
				break;
			case 3:
				//Variable bandera para finalizar la ejecución del menú
				finalizarRegistroTerreno = true;
				break;
			default:
				cout << "¡Opcion inválida!" << endl;
				opcionRegistroTerreno = 0;
		}
	}while (finalizarRegistroTerreno != true);
}

void totalVendidoXCategoria(){
	//Declaración de variables
	float totalCategoriaComercial;
	float totalCategoriaResidencial;
	
	//Invocación de función leer archivo
	leerArchivo();
	
	//Iteración del vector
	for (int i = 0; i < vtrTerreno.size(); i ++){
		
		//Si el item categoría es igual a Comercial entonces se realiza la suma correspondiente
		if (vtrTerreno[i].categoria == "Comercial"){
			totalCategoriaComercial = totalCategoriaComercial + vtrTerreno[i].precioPagado;
		}
		//Si el item categoría es igual a Residencial entonces se realiza la suma correspondiente
		else if (vtrTerreno[i].categoria == "Residencial"){
			totalCategoriaResidencial = totalCategoriaResidencial + vtrTerreno[i].precioPagado;
		}
	}
	
	//Salida de consola
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "EL TOTAL VENDIDO POR LA CATEGORÍA COMERCIAL ES: $" << totalCategoriaComercial << endl;
	cout << "EL TOTAL VENDIDO POR LA CATEGORÍA RESIDENCIAL ES: $" << totalCategoriaResidencial << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	
	//Limpia el vector
	vtrTerreno.clear();
	return;
}

//Función encargada de obtener el total vendido por zona
void totalVendidoXZona(){
	//Declaración de variables
	float zonaAComercial = 0.00;
	float zonaBComercial = 0.00;
	
	float zonaAResidencial = 0.00;
	float zonaBResidencial = 0.00;
	float zonaCResidencial = 0.00;
	
	//Invocación de función leer archivo
	leerArchivo();
	
	//Iteración del vector
	for (int i = 0; i < vtrTerreno.size(); i ++){
		
		//Si el item categoría es igual a Comercial y la zona es igual a A o B se realiza la suma correspondiente según tipo de zona
		if (vtrTerreno[i].categoria == "Comercial"){
			if (vtrTerreno[i].zona == "A"){
				zonaAComercial = zonaAComercial + vtrTerreno[i].precioPagado;
			}
			else if (vtrTerreno[i].zona == "B"){
				zonaBComercial = zonaBComercial + vtrTerreno[i].precioPagado;
			}
		}
		//Si el item categoría es igual a Comercial y la zona es igual a A, B o C se realiza la suma correspondiente según tipo de zona
		else if (vtrTerreno[i].categoria == "Residencial"){
			if (vtrTerreno[i].zona == "A"){
				zonaAResidencial = zonaAResidencial + vtrTerreno[i].precioPagado;
			}
			else if (vtrTerreno[i].zona == "B"){
				zonaBResidencial = zonaBResidencial + vtrTerreno[i].precioPagado;
			}
			else if (vtrTerreno[i].zona == "C"){
				zonaCResidencial = zonaCResidencial + vtrTerreno[i].precioPagado;
			}
		}
	}
	
	//Salida de Consola
	cout << "-------------------CATEGORÍA COMERCIAL-------------------" << endl;
	cout << "TOTAL VENDIDO ZONA A: $" << zonaAComercial << endl;
	cout << "TOTAL VENDIDO ZONA B: $" << zonaBComercial << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "-------------------CATEGORÍA RESIDENCIAL-------------------" << endl;
	cout << "TOTAL VENDIDO ZONA A: $" <<  zonaAResidencial << endl;
	cout << "TOTAL VENDIDO ZONA B: $" << zonaBResidencial << endl;
	cout << "TOTAL VENDIDO ZONA C: $" << zonaCResidencial << endl;
	cout << "---------------------------------------------------------" << endl;
	
	//Limpia el vector
	vtrTerreno.clear();
	return;
}

//Función encargada de obtener el total vendido por tipo de inmueble
void totalVendidoXTipoInmueble(){
	//Declaración de variables
	float Terreno = 0.00;
	float casa = 0.00;
	float departamento = 0.00;
	
	//Invocación de función leer archivo
	leerArchivo();
	
	//Iteración del vector
	for (int i = 0; i < vtrTerreno.size(); i ++){
		if (vtrTerreno[i].tipo == "Terreno"){
			Terreno = Terreno + vtrTerreno[i].precioPagado;
		}
		else if (vtrTerreno[i].tipo == "Departamento"){
			departamento = departamento + vtrTerreno[i].precioPagado;
		}
		else if (vtrTerreno[i].tipo == "Casa"){
			casa = casa + vtrTerreno[i].precioPagado;		
		}
	}
	
	//Salida de consola
	cout << "--------------------TOTAL POR TIPO DE INMUEBLE--------------------" << endl;
	cout << "TOTAL VENDIDO POR TERRENO: $" << Terreno << endl;
	cout << "TOTAL VENDIDO POR DEPARTAMENTO: $" <<  departamento << endl;
	cout << "TOTAL VENDIDO POR CASA: $" << casa << endl;
	cout << "------------------------------------------------------------------" << endl;
	//Limpia el vector
	vtrTerreno.clear();
	return;
}
//Función principal del programa
int main(){
	//Declaración de variables
	int opcion;
	bool finalizar = false;
	
	do {
		fflush(stdin);
		cin.clear();
		//Salida de consola
		cout << "------------------------------MENU PRINCIPAL------------------------------" << endl;
		cout << "1. Compra de terreno/casa/departamento" << endl;
		cout << "2. Total vendido por categoría" << endl;
		cout << "3. Total vendido por zona" << endl;
		cout << "4. Total vendido por tipo de inmueble" << endl;
		cout << "5. Salir" << endl;
		//Obtiene la opción ingresada por el usuario
		cin >> opcion;
		
		switch (opcion){
			case 1:
				//Invocación de la función para el registro del inmueble
				registroTerreno();
				break;
			case 2:
				//invocación de la función para obtener el total vendido por categoría
				 totalVendidoXCategoria();
				break;
			case 3:
				//invocación de la función para obtener el total vendido por zona
				totalVendidoXZona();
				break;
			case 4:
				//invocación de la función para obtener el total vendidpo por tipo de inmueble
				 totalVendidoXTipoInmueble();
				break;
			case 5:
				//Variable bandera para finalizar ejecución del menú
				finalizar = true;
				break;
			default:
				cout << "¡Opción inválida!" << endl;
				opcion = 0;
				break;
		}
		
	}while (finalizar != true);
	
	return 0;
}

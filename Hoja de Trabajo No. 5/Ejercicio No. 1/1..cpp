//Importaci�n de librer�as
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Declaraci�n de estructura.
struct Terrenos{
	string categoria;
	string zona;
	string tipo;
	float precio;
	float precioPagado;
};

//Declaraci�n de vector de tipo estructura 'Terrenos'
std::vector<Terrenos> vtrTerreno;

/* Funci�n encargada de agregar datos en archivo,
	Recibe como par�metros los campos necesarios para guardar en el archivo:
		-Categor�a
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

// Funci�n encargada de leer el archivo
void leerArchivo(){
	//Declaraci�n de variable de tipo archivo
	ifstream archivoTerrenos;
	//Declaraci�n de variable de tipo estructura
	Terrenos strTerreno;
	
	//Funci�n encargada de abrir el archivo correspondiente.
	archivoTerrenos.open("HT5_EJERCICIO_01.txt", ios::in);
	
	//Extracci�n de datos en archivo
	while (archivoTerrenos >> strTerreno.categoria >> strTerreno.zona >> strTerreno.tipo >> strTerreno.precio >> strTerreno.precioPagado){
		//Se llena el vector seg�n los datos extra�dos del archivo
		vtrTerreno.push_back(strTerreno);
	}
	
	//Cierra el archivo
	archivoTerrenos.close();
	
	return;
}

//Funci�n encargada de las gestiones de la Categor�a Comercial
void categoriaComercial(){
	//Declaraci�n de variables
	Terrenos strTerreno;
	float metros;
	int opcionZona;
	string opcionTipo;
	
	//Limpiar buffer y m�todos de entrada
	fflush(stdin);
	cin.clear();
	
	//Men� de la categor�a COMERCIAL	
	cout << "----------COMERCIAL----------"<< endl;
	cout << "Seleccione la zona:" << endl;
	cout << "1. Zona A" << endl;
	cout << "2. Zona B" << endl;
	cin >> opcionZona;
	
	//Seg�n la zona ingresada se muestran diferentes sub men�s
	switch(opcionZona){
		case 1:
			//Si la zona elegida es la "A"
			cout << "Elija el tipo:" << endl;
			cout << "TIPO" << "\t" << "\t" << "Precio m2" << endl;
			cout << "1. Terreno" << "\t" << "$2,200" << endl;
			cout << "2. Casa" << "\t" << "\t" << "$2,500" << endl;
			cout << "3. Departamento" << "\t" << "$2,100" << endl;
			cin >> opcionTipo;
			
			cout << "Ingrese el n�mero de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes seg�n el tipo de inmueble elegido
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
			
			cout << "Ingrese el n�mero de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes seg�n el tipo de inmueble elegido
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
			cout << "�Opci�n inv�lida!" << endl;
			opcionZona = 0;
			break;
	}
	
	/*	Invocaci�n de la funci�n para agregar el registro al archivo. 
		Se ingresan los par�metros correspondientes seg�n validaciones anteriores.
	*/
	agregarRegistroArchivo(strTerreno.categoria, strTerreno.zona, strTerreno.tipo, strTerreno.precio, strTerreno.precioPagado);
	
}

//Funci�n encargada de las gestiones de la Categor�a Residencial
void categoriaResidencial(){
	//Declaraci�n de variables
	Terrenos strTerreno;
	float metros;
	int opcionZona;
	string opcionTipo;
	
	//Limpiar buffer y m�todos de entrada
	fflush(stdin);
	cin.clear();
	
	//Men� de la categor�a RESIDENCIAL
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
			
			cout << "Ingrese el n�mero de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes seg�n el tipo de inmueble elegido
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
			
			cout << "Ingrese el n�mero de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes seg�n el tipo de inmueble elegido
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
			
			cout << "Ingrese el n�mero de metros cuadrados: " << endl;
			cin >> metros;
			
			//Validaciones correspondientes seg�n el tipo de inmueble elegido
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
			cout << "�Opci�n Inv�lida!" << endl;
			opcionZona = 0;
			break;
	}
	
	/*	Invocaci�n de la funci�n para agregar el registro al archivo. 
		Se ingresan los par�metros correspondientes seg�n validaciones anteriores.
	*/
	agregarRegistroArchivo(strTerreno.categoria, strTerreno.zona, strTerreno.tipo, strTerreno.precio, strTerreno.precioPagado);
}

//Funci�n encargada de gestionar el ingreso de inmuebles
void registroTerreno(){
	//Declaraci�n de variables
	int opcionRegistroTerreno;
	bool finalizarRegistroTerreno = false;
	
	//Submen� para seleccionar el tipo de categor�a
	do {
		cout << "Seleccione tipo de Categor�a" << endl;
		cout << "1. Comercial" << endl;
		cout << "2. Residencial" << endl;
		cout << "3. Salir" << endl;
		cin >> opcionRegistroTerreno;
		
		switch (opcionRegistroTerreno){
			case 1:
				//Invocaci�n de funci�n para gestiones de categor�a Comercial
				categoriaComercial();
				break;
			case 2:
				//Invocaci�n de funci�n para gestiones de categor�a Residencial
				categoriaResidencial();
				break;
			case 3:
				//Variable bandera para finalizar la ejecuci�n del men�
				finalizarRegistroTerreno = true;
				break;
			default:
				cout << "�Opcion inv�lida!" << endl;
				opcionRegistroTerreno = 0;
		}
	}while (finalizarRegistroTerreno != true);
}

void totalVendidoXCategoria(){
	//Declaraci�n de variables
	float totalCategoriaComercial;
	float totalCategoriaResidencial;
	
	//Invocaci�n de funci�n leer archivo
	leerArchivo();
	
	//Iteraci�n del vector
	for (int i = 0; i < vtrTerreno.size(); i ++){
		
		//Si el item categor�a es igual a Comercial entonces se realiza la suma correspondiente
		if (vtrTerreno[i].categoria == "Comercial"){
			totalCategoriaComercial = totalCategoriaComercial + vtrTerreno[i].precioPagado;
		}
		//Si el item categor�a es igual a Residencial entonces se realiza la suma correspondiente
		else if (vtrTerreno[i].categoria == "Residencial"){
			totalCategoriaResidencial = totalCategoriaResidencial + vtrTerreno[i].precioPagado;
		}
	}
	
	//Salida de consola
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "EL TOTAL VENDIDO POR LA CATEGOR�A COMERCIAL ES: $" << totalCategoriaComercial << endl;
	cout << "EL TOTAL VENDIDO POR LA CATEGOR�A RESIDENCIAL ES: $" << totalCategoriaResidencial << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	
	//Limpia el vector
	vtrTerreno.clear();
	return;
}

//Funci�n encargada de obtener el total vendido por zona
void totalVendidoXZona(){
	//Declaraci�n de variables
	float zonaAComercial = 0.00;
	float zonaBComercial = 0.00;
	
	float zonaAResidencial = 0.00;
	float zonaBResidencial = 0.00;
	float zonaCResidencial = 0.00;
	
	//Invocaci�n de funci�n leer archivo
	leerArchivo();
	
	//Iteraci�n del vector
	for (int i = 0; i < vtrTerreno.size(); i ++){
		
		//Si el item categor�a es igual a Comercial y la zona es igual a A o B se realiza la suma correspondiente seg�n tipo de zona
		if (vtrTerreno[i].categoria == "Comercial"){
			if (vtrTerreno[i].zona == "A"){
				zonaAComercial = zonaAComercial + vtrTerreno[i].precioPagado;
			}
			else if (vtrTerreno[i].zona == "B"){
				zonaBComercial = zonaBComercial + vtrTerreno[i].precioPagado;
			}
		}
		//Si el item categor�a es igual a Comercial y la zona es igual a A, B o C se realiza la suma correspondiente seg�n tipo de zona
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
	cout << "-------------------CATEGOR�A COMERCIAL-------------------" << endl;
	cout << "TOTAL VENDIDO ZONA A: $" << zonaAComercial << endl;
	cout << "TOTAL VENDIDO ZONA B: $" << zonaBComercial << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "-------------------CATEGOR�A RESIDENCIAL-------------------" << endl;
	cout << "TOTAL VENDIDO ZONA A: $" <<  zonaAResidencial << endl;
	cout << "TOTAL VENDIDO ZONA B: $" << zonaBResidencial << endl;
	cout << "TOTAL VENDIDO ZONA C: $" << zonaCResidencial << endl;
	cout << "---------------------------------------------------------" << endl;
	
	//Limpia el vector
	vtrTerreno.clear();
	return;
}

//Funci�n encargada de obtener el total vendido por tipo de inmueble
void totalVendidoXTipoInmueble(){
	//Declaraci�n de variables
	float Terreno = 0.00;
	float casa = 0.00;
	float departamento = 0.00;
	
	//Invocaci�n de funci�n leer archivo
	leerArchivo();
	
	//Iteraci�n del vector
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
//Funci�n principal del programa
int main(){
	//Declaraci�n de variables
	int opcion;
	bool finalizar = false;
	
	do {
		fflush(stdin);
		cin.clear();
		//Salida de consola
		cout << "------------------------------MENU PRINCIPAL------------------------------" << endl;
		cout << "1. Compra de terreno/casa/departamento" << endl;
		cout << "2. Total vendido por categor�a" << endl;
		cout << "3. Total vendido por zona" << endl;
		cout << "4. Total vendido por tipo de inmueble" << endl;
		cout << "5. Salir" << endl;
		//Obtiene la opci�n ingresada por el usuario
		cin >> opcion;
		
		switch (opcion){
			case 1:
				//Invocaci�n de la funci�n para el registro del inmueble
				registroTerreno();
				break;
			case 2:
				//invocaci�n de la funci�n para obtener el total vendido por categor�a
				 totalVendidoXCategoria();
				break;
			case 3:
				//invocaci�n de la funci�n para obtener el total vendido por zona
				totalVendidoXZona();
				break;
			case 4:
				//invocaci�n de la funci�n para obtener el total vendidpo por tipo de inmueble
				 totalVendidoXTipoInmueble();
				break;
			case 5:
				//Variable bandera para finalizar ejecuci�n del men�
				finalizar = true;
				break;
			default:
				cout << "�Opci�n inv�lida!" << endl;
				opcion = 0;
				break;
		}
		
	}while (finalizar != true);
	
	return 0;
}

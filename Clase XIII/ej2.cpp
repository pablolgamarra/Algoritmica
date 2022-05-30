#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

//Estructura de los Nodos
struct Nodo{
	double temperatura;
	int ciudad;
	int hora;
	Nodo *siguiente;
	Nodo *anterior;
};

//Prototipo de Funcion
int cargaCiudad(void);
int cargaHora(void);
double cargaTemp(void);
void cargarLista(Nodo *&, Nodo *&, int, int, double);
bool ciudadYHoraRepetida(Nodo *, int, int);
void mostrarLista(Nodo *);
int mostrarMenu(void);
void registrarTemperatura(int &ciudad, int &hora, double &temperatura, Nodo *&primero, Nodo *&ultimo);

string ciudades[4] = {"Ciudad del Este", "Hernandarias", "Pdte. Franco", "Minga Guazú"};

main(){
	Nodo *primero = NULL, *ultimo = NULL;
	int ciudad, hora;
	double temperatura;
	bool salir = false;
	setlocale(LC_ALL, "spanish");
	do{
		system("cls");
		cout<<"Programa para registrar la temperatura.\n";
		switch(mostrarMenu()){
			case 1:
				cout<<"Registrar Temperatura.\n";
				registrarTemperatura(ciudad, hora, temperatura, primero, ultimo);
				break;
			case 2:
				cout<<"Consulta de Temperaturas por Hora en Forma Ascendente.\n";
				break;
			case 3:
				cout<<"Consulta de Temperaturas por Hora en Forma Descendente.\n";
				break;
			case 4:
				cout<<"Consulta de Temperaturas Registradas por Ciudad\n";
				break;
			case 5:
				cout<<"Imprimir la Ciudad que Registró Mayor Temperatura en el Día\n";
				break;
			case 6:
				salir = true;
				break;
			default:
				cout<<"Carga de Temperatura.\n";
				break;
		}
	}while(!salir);
	mostrarLista(primero);
}

int cargaCiudad(void){
	int n;
	cout<<"Seleccione la ciudad:\n";
	cout<<"1- Ciudad Del Este\n";
	cout<<"2- Hernandarias\n";
	cout<<"3- Pte. Franco\n";
	cout<<"4- Minga Guazú\n";
	cout<<"Ciudad: ";
	cin>>n;
	while(n < 1 || n > 4){
		cout<<"El numero ingresado no corresponde a ninguna ciudad.\nVuelva a ingresar.\n";
		cout<<"Seleccione la ciudad:\n";
		cout<<"1- Ciudad Del Este\n";
		cout<<"2- Hernandarias\n";
		cout<<"3- Pte. Franco\n";
		cout<<"4- Minga Guazú\n";
		cout<<"Ciudad: ";
		cin>>n;
	}
	return n;
}

int cargaHora(void){
	int n;
	cout<<"Ingrese la hora (0-24): ";
	cin>>n;
	while(n < 0 || n > 24){
		cout<<"Error. Debe ingresar un numero entre 0 y 24.\n.Vuelva a cargar.\n";
		cout<<"Ingrese la hora (0-24): ";
		cin>>n;
	}
	return n;
}

double cargaTemp(void){
	double n;
	cout<<"Ingrese Temperatura Registrada: ";
	cin>>n;
	return n;
}

void registrarTemperatura(int &ciudad, int &hora, double &temperatura, Nodo *&primero, Nodo *&ultimo){
	ciudad = cargaCiudad();
	hora = cargaHora();
	temperatura = cargaTemp();
	if(primero != NULL){
		while(ciudadYHoraRepetida(primero, ciudad, hora)){
			ciudad = cargaCiudad();
			hora = cargaHora();
			temperatura = cargaTemp();
		}
		cargarLista(primero, ultimo, ciudad, hora, temperatura);			
	}else{
		cargarLista(primero, ultimo, ciudad, hora, temperatura);
	}
}

void cargarLista(Nodo *&primero, Nodo *& ultimo, int ciudad, int hora, double temperatura){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->ciudad = ciudad;
	nuevoNodo->hora = hora;
	nuevoNodo->temperatura = temperatura;
	if(primero == NULL){
		primero=nuevoNodo;
		nuevoNodo->anterior = NULL;
		nuevoNodo->siguiente = NULL;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevoNodo;
		nuevoNodo->siguiente=NULL;
		nuevoNodo->anterior=ultimo;
		ultimo=nuevoNodo;
	}
}

bool ciudadYHoraRepetida(Nodo *iniciador, int ciudad, int hora){
	Nodo *actual=iniciador;
	bool encontrado = false;
	if(actual != NULL){
		while(actual != NULL && !encontrado){
			if(actual->ciudad == ciudad && actual->hora == hora){
				encontrado=true;
				actual = actual->siguiente;				
			}
		}
		if(encontrado){
			cout<<"No se puede registrar la temperatura de una ciudad dos veces.\nVuelva a cargar.\n";
			return true;
		}
	}else{
		cout<<"La lista está vacía.\n";
		return false;
	}
}

void mostrarLista(Nodo *iniciador){
	Nodo *actual = new Nodo();
	actual = iniciador;
	if(actual != NULL){
		while(actual != NULL){
			cout<<"Ciudad: "<<ciudades[(actual->ciudad)-1]<<"\n";
			cout<<"Hora: "<<actual->hora<<"\n";
			cout<<"Temperatura Registrada: "<<actual->temperatura<<"\n";
			actual = actual->siguiente;
		}
	}else{
		cout<<"La lista no tiene elementos cargados dentro.\n";
	}
}

int mostrarMenu(void){
	int op;
	cout<<"Menú de Opciones:\n";
	cout<<"1- Registrar Temperatura\n";
	cout<<"2- Consulta de temperaturas por hora en forma ascendente\n";
	cout<<"3- Consulta de temperaturas por hora en forma descendente\n";
	cout<<"4- Consulta de temperaturas registradas por ciudad\n";
	cout<<"5- La ciudad que registro mayor temperatura en el día\n";
	cout<<"6- Salir del Programa\n";
	cout<<"Ingrese la opcion que desea: ";
	cin>>op;
	while(op < 1 || op > 6){
		cout<<"ERROR.\n El número seleccionado no se encuentra en el rango de opciones disponibles.\n";
		cout<<"Menú de Opciones:\n";
		cout<<"1- Registrar Temperatura\n";
		cout<<"2- Consulta de temperaturas por hora en forma ascendente\n";
		cout<<"3- Consulta de temperaturas por hora en forma descendente\n";
		cout<<"4- Consulta de temperaturas registradas por ciudad\n";
		cout<<"5- La ciudad que registro mayor temperatura en el día\n";
		cout<<"6- Salir del Programa\n";
		cout<<"Ingrese la opcion que desea: ";
		cin>>op;
	}
	return op;
}

/*
Crear un programa que permita registrar las temperaturas en °C durante el día,
de 4 ciudades,
en donde los datos a registrar son los siguientes:
- Temperatura
- Ciudad (1 = Ciudad del este, 2 = Hernandarias, 3 = Pte Franco, 4 = Minga Guasu)
- Hora (Horario 24hs)

Permitir el ingreso de datos en una lista doblemente enlazada 
y la consulta de los mismos a través del siguiente menú:
1) Registrar Temperatura
2) Consulta de temperaturas por hora en forma ascendente
3) Consulta de temperaturas por hora en forma descendente
4) Consulta de temperaturas registradas por ciudad
5) La ciudad que registro mayor temperatura en el día

Observación:
- Realiza las validaciones para el horario de 24hs 
y el código de las ciudades (1,2,3,4)
- en las consultas mostrar el nombre de la ciudad teniendo en cuenta su código (1,2,3,4) 
*/

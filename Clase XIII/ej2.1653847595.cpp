#include <iostream>
#include <windows.h>

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
double cargarTemp(void);
int cargaCiudad(void);
int cargarHora(void);
void cargarLista(Nodo *&, Nodo *&, int);
void mostrarLista(Nodo *);

main(){
	cout<<"Programa para registrar la temperatura.\n";
		
}

double cargarTemp(void){
	int n;
	cout<<"Ingrese Temperatura Registrada: ";
	cin>>n;
	return n;
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
	}
	return n;
}

int cargarHora(void){
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

void cargarLista(Nodo *&primero, Nodo *& ultimo, int n, int ciudad, int hora){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	if(primero == NULL){
		primero=nuevoNodo;
		nuevoNodo->anterior = NULL;
		nuevoNodo->siguiente = NULL;
		ultimo=primero;
	}else{
		ultimo-siguiente=nuevoNodo;
		nuevoNodo->siguiente=NULL;
		nuevoNodo->anterior=ultimo;
		ultimo=nuevoNodo;
	}
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

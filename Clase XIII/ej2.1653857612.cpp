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
double cargarTemp(void);
int cargaCiudad(void);
int cargarHora(void);
void cargarLista(Nodo *&, Nodo *&, int, int, double);
bool validarCiudadYHora(Nodo *, int, int);
void mostrarLista(Nodo *);


main(){
	Nodo *primero = NULL, *ultimo = NULL;
	char op;
	setlocale(LC_ALL, "spanish");
	do{
		system("cls");
		cout<<"Programa para registrar la temperatura.\n";
		cargarLista(primero, ultimo,  cargaCiudad(), cargarHora(), cargarTemp());		
		cout<<"¿Desea seguir ingresando numeros? (S/N):";
		cin>>op;
	}while(op == 's' || op == 'S');
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

double cargarTemp(void){
	double n;
	cout<<"Ingrese Temperatura Registrada: ";
	cin>>n;
	return n;
}

void cargarLista(Nodo *&primero, Nodo *& ultimo, int ciudad, int hora, double temperatura){
		Nodo *nuevoNodo = new Nodo();
		nuevoNodo->temperatura = temperatura;
		nuevoNodo->ciudad = ciudad;
		nuevoNodo->hora = hora;
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

bool validarCiudadYHora(Nodo *iniciador, int ciudad, int hora){
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
			cout<<"No se puede registrar la temperatura de un momento dos veces.\nVuelva a cargar.\n";
			return true;
		}
	}else{
		cout<<"La lista está vacía.\n";
		return false;
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

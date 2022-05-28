#include <iostream>
#include <windows.h>

using namespace std;

//Estructura de los Nodos
struct Nodo{
	int temperatura;
	int ciudad;
	int hora;
	Nodo *siguiente;
	Nodo *anterior;
};

//Prototipo de Funcion
int cargarTemp(void);
void cargarLista(Nodo *&, Nodo *&, int);
void mostrarLista(Nodo *);

main(){
	
}

int cargarTemp(void){
	int n;
	cout<<"Ingrese Temperatura Registrada: ";
	cin>>n;
	return n;
}

void cargarLista(Nodo *&primero, Nodo *& ultimo, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	if(primero == NULL){
		nuevoNodo->anterior = NULL;
		nuevoNodo
	}else{
		
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

#include <iostream>
#include <conio.h>
#include <windows.h>
//Configurar, Crear Apuestas, Correr, Encontrar al Ganador, Pagar Apuestas, Calcular el total pagado
using namespace std;

struct Caballo{
	int idCaballo;
	string nombre;
	int puntaje;
	int porcentajeIncremento;
};

int id = 0;

main(){
	srand(unsigned, time(NULL));
	Caballo *Caballos = NULL;
	cout<<"Configuracion de los Caballos.\n";
	cout<<"Ingrese un nombre para el caballo con Id "<<id<<":"; cin>>nombre;
}

void cargaLista(Caballos *&Caballos, int id, string nombre, int puntaje, int porcentaje){
	Caballo *nuevoNodo = new Nodo();
	nuevoNodo->idCaballo = id;
	nuevoNodo->nombre = nombre;
	nuevoNodo->puntaje = puntaje;
	nuevoNodo->porcentaje = porcentaje;
	Nodo *aux1 = lista;
	Nodo *aux2 = NULL;
	while(aux1 && aux1->idCaballo < id){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(lista == aux1){
		lista = nuevoNodo;
	}else{
		aux2->siguiente = nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
}


#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
	Nodo *anterior;
};

void cargarLista(Nodo *&, Nodo *&, int);
void mostrarLista(Nodo *);

main(){
	setlocale(LC_ALL, "spanish");
	Nodo *Primero = NULL, *Ultimo = NULL;
	int n;
	char op;
	do{
		cout<<"Programa para el manejo de listas doblemente enlazadas.\n";
		cout<<"Ingrese un número: ";
		cin>>n;
		cargarLista(Primero, Ultimo, n);
		cout<<"¿Desea seguir ingresando números?: (S/N)";
		cin>>op;
	}while(op == 'S' || op == 's');
	cout<<"Lista Cargada:\n";
	mostrarLista(Primero);
}

void cargarLista(Nodo *&Primero, Nodo *&Ultimo, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	if(Primero == NULL){
		Primero = nuevoNodo;
		Primero->siguiente = NULL;
		Primero->anterior = NULL;
		Ultimo = Primero;
	}else{
		Ultimo->siguiente = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		nuevoNodo->anterior = Ultimo;
		Ultimo = nuevoNodo;
	}
	cout<<"Se agregó el elemento "<<n<<"a la lista.\n";
}

void mostrarLista(Nodo *Primero){
	Nodo *actual = Primero;
	if(actual != NULL){
		while(actual != NULL){
			cout<<actual->dato<<"\n";
			actual = actual->siguiente;
		}
	}else{
		cout<<"No existen elementos cargados en la lista.\n";
	}
}

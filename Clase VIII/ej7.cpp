#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;
};

void cargarLista(Nodo *&, int);
void mostrarLista(Nodo *);

main(){
	
}

void cargarLista(Nodo *&lista, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	Nodo *aux1 = lista;
	Nodo *aux2;
	while((aux1 != NULL) && (aux1->n < n)){
		aux2 = aux1;
		aux1=aux1->siguiente;
	}
	if(lista == aux1){
		lista = nuevoNodo;
	}else{
		aux2->siguiente=nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
}

/*
Cargar una lista simplemente enlazada con números pares. Mostrar los
elementos cargados sin ordenar.
*/

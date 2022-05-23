#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void cargarLista(Nodo *&, int);
void mostrarLista(Nodo *, char);
int cargarNumero(void);

main(){
	setlocale(LC_ALL, "spanish");
	
	Nodo *Lista = NULL;
	char op;
	do{
		cout<<"Programa para manejar listas y hayar el mayor y el menor.\n";
		cargarLista(Lista, cargarNumero());
		cout<<"¿Desea seguir ingresando numeros a la lista? (S/N): ";
		cin>>op;
		if(op == 'N' || op == 'n'){
			cout<<"Ok...Se imprimirán el mayor y el menor elemento de la lista cargada.\n";
		}
	}while(op == 'S' || op == 's');
	
	cout<<"Lista Cargada:\n";
	mostrarLista(Lista, 'c');
	cout<<"Mayor y Menor Elemento:\n";
	mostrarLista(Lista, 'd');	
	system("pause");
	return 0;
}

void cargarLista(Nodo *&Lista, int n){
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = n;
	Nodo *aux1 = Lista;
	Nodo *aux2;
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(aux1 == Lista){
		Lista = nuevoNodo;
	}else{
		aux2->siguiente = nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
	return;
}

void mostrarLista(Nodo *Lista, char variante){
	Nodo *actual = new Nodo();
	actual = Lista;
	if(variante == 'c'){
		while(actual != NULL){
			cout<<actual->dato<<"\n";
			actual = actual->siguiente;
		}
	}else{
		int mayor=0, menor=0, i=1;
		while(actual != NULL){
			if(i == 1){
				mayor = actual->dato;
				menor = actual->dato;
			}else if(actual->dato > mayor){
				mayor = actual->dato;
			}else if(actual->dato < menor){
				menor = actual->dato;
			}
			i++;
			actual = actual->siguiente;
		}
		cout<<"El mayor elemento que se cargó a la lista es: "<<mayor<<"\n";
		cout<<"El menor elemento que se cargó a la lista es: "<<menor<<"\n";
	}
	return;
}

int cargarNumero(void){
	int n;
	cout<<"Ingrese un número para cargarlo a la lista: ";
	cin>>n;
	return n;
}

/*
2 – Cargar una lista hasta que el usuario lo decida. Imprimir el mayor y menor
elemento cargado en la lista.
*/


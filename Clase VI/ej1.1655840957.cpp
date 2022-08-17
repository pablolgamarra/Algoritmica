#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;
};

void cargarPila(Nodo *&, int);
void quitarPila(Nodo *&, int&);

main(){
	char op;
	int n;
	Nodo *Pila = NULL;
	setlocale(LC_ALL, "spanish");
	do{
		cout<<"Ingrese un número y el programa lo cargará a una pila: ";
		cin>>n;
		cargarPila(Pila, n);
		cout<<"¿Desea seguir ingresando numeros? (S/N): ";
		cin>>op;
	}while(op == 'S' || op == 's');
	system("cls");
	cout<<"Pila Cargada:\n";
	while(Pila != NULL){
		quitarPila(Pila, n);
		if(Pila == NULL){
			cout<<n<<". Fin de Pila\n";
		}else{
			cout<<n<<", ";			
		}
	}
	cout<<"\n";
	system("pause");
	return 0;
}

void cargarPila(Nodo *&Pila, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	nuevoNodo->siguiente = Pila;
	Pila = nuevoNodo;
}

void quitarPila(Nodo *&Pila, int &n){
	Nodo *aux= Pila;
	n = aux->n;
	Pila = aux->siguiente;
	delete aux;	
}

/*
1) Hacer un programa para agregar números enteros a una pila, hasta que el
usuario lo decida, después mostrar todos os números introducidos en la pila.
*/

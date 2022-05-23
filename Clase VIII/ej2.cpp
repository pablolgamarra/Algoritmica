#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;	
};

void cargaPila(Nodo *&, int );
void quitarPila(Nodo *&, int &);
bool pilaVacia(Nodo *);

main(){
	setlocale(LC_ALL, "spanish");

	Nodo *Pila = NULL;
	int n, m=0;
	char op;
	
	do{
		cout<<"Cargar un Vector.\n";
		cout<<"Número: ";
		cin>>n;
		m++;
		cargaPila(Pila, n);
		cout<<"¿Desea seguir cargando numeros? (S)/(N): ";
		cin>>op;
		while( (op != 'S' && op != 's') && (op != 'N' && op != 'n') ){
			cout<<"¿Desea seguir cargando numeros? (S)/(N): ";
			cin>>op;
		}
		if(op == 'N' && op == 'n'){
			cout<<"Ok...Se imprimirá el vector cargado...\n";
			system("pause");
		}
	}while(op == 'S' || op == 's');
	
	int N[m], i=0;
	
	while(!pilaVacia(Pila)){
		quitarPila(Pila, N[i]);
		i++;
	}
	
	system("cls");
	cout<<"Vector Cargado:\n";
	
	i=0;
	while(i < m){
		if(i == 0){
			cout<<"| "<<N[i]<<" | ";
		}else if(i == (m-1)){
			cout<<N[i]<<" |\n";
		}else{
			cout<<N[i]<<" | ";
		}
		i++;
	}
	
	delete Pila;
	
	system("pause");
	return 0;
}

bool pilaVacia(Nodo *Pila){
	if(Pila == NULL){
		return true;
	}else{
		return false;
	}
}

void cargaPila(Nodo *&Pila, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	nuevoNodo->siguiente = Pila;
	Pila = nuevoNodo;
	return;
}

void quitarPila(Nodo *&Pila, int &n){
	Nodo *aux = Pila;
	n = aux->n;
	Pila = aux->siguiente;
	delete aux;
	return;
}


/*
2) Cargar un vector N con la ayuda de una pila. Imprimir el vector cargado. 
*/

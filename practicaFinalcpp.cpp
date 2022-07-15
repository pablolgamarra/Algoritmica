#include <iostream>
#include <windows.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void cargaPila(Nodo *&, int);
void quitarPila(Nodo *&, int &);

int main(){
	setlocale(LC_ALL, "spanish");
	Nodo *pila = NULL;
	char op = 'n';
	int n;
	do{
		cout<<"Manejador de Pilas\n";
		cout<<"¿Desea Ingresar datos a la pila?: (S/N)"; cin>>op;
		if(op == 's' || op == 'S'){
			cout<<"Ingrese número: ";
			cin>>n;
			cargaPila(pila, n);
		}else{
			cout<<"Ok...Se imprimiran los datos que se cargaron a la pila.\n";
			Sleep(200);
		}
	}while(op == 'S' || op == 's');
	if(pila == NULL){
		cout<<"La lista no tiene elementos en su interior.\n";
	}else{
		while(pila){
			quitarPila(pila, n);
			cout<<"Dato: "<<n<<"\n";
		}
	}
}

void cargaPila(Nodo *&pila, int dato){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = pila;
	pila = nuevoNodo;
	cout<<"Se ha cargado correctamente el dato a la pila\n";
	return;
}

void quitarPila(Nodo *&pila, int &dato){
	Nodo *aux = pila;
	dato = pila->dato;
	pila = aux->siguiente;
	delete aux;
	return;
}

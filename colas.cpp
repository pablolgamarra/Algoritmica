#include <iostream>
#include <windows.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;	
};

void cargarCola(Nodo *&, Nodo *&, int);
void quitarCola(Nodo *&, Nodo *&, int &);

main(){
	setlocale(LC_ALL, "spanish");
	Nodo *frente = NULL, *fin = NULL;
	int n;
	char op = 's';
	do{
		cout<<"Manejador de Colas.\n";
		cout<<"¿Desea ingresar datos a la cola? (S/N): ";cin>>op;
		if(op == 'N' || op == 'n'){
			cout<<"Ok...Se imprimirán los datos cargados en la lista.\n";
		}else{
			cout<<"Ingrese número: ";cin>>n;
			cargarCola(frente, fin, n);
		}

	}while(op == 'S' || op == 's');
	if(frente == NULL){
		cout<<"La cola no contiene elementos en su interior.\n";
	}else{
		while(frente != NULL){
			quitarCola(frente, fin, n);
			cout<<n<<"\n";
		}
	}
	system("pause");
}

void cargarCola(Nodo *&frente, Nodo *&fin, int dato){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = dato;
	if(frente == NULL){
		frente = nuevoNodo;
	}else{
		fin->siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
	cout<<"Se ha cargado el elemento correctamente a la lista.\n";
	return;
}

void quitarCola(Nodo *&frente, Nodo *&fin, int &dato){
	Nodo *aux = frente;
	dato = aux->dato;
	if(frente == NULL){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente;
	}
	delete aux;
	return;
}


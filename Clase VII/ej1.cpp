#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;
};

void cargarCola(Nodo *&inicio, Nodo *&fin, int n);
void quitarCola(Nodo *&inicio, Nodo *&fin, int &n);
bool colaVacia(Nodo *frente);

main(){
	Nodo *inicioCola=NULL, *finCola=NULL;
	int n;
	
	setlocale(LC_ALL,"spanish");
	char op;
	system("cls");
	cout<<"Cargar numeros a una cola.\n";
	do{
		cout<<"Ingrese numero.\n";
		cin>>n;
		cargarCola(inicioCola, finCola, n);
		cout<<"¿Desea seguir cargando numeros? (S)/(N): ";
		cin>>op;
		if(op == 'n' || op == 'N'){
			system("cls");
			cout<<"Ok...Se imprimira la lista de los numeros cargados.\n";
			system("pause");
		}
	}while(op == 's' || op =='S');
	while(inicioCola != NULL){
		quitarCola(inicioCola, finCola, n);
		if(inicioCola == NULL){
			cout<<n<<"\nFin de la Cola\n";
		}else{
			cout<<n<<" ";
		}
	}
	
	inicio = NULL;
	fin = NULL;
	delete inicio, fin;
}

bool colaVacia(Nodo *frente){
	if(frente == NULL){
		return true;
	}else{
		return false;
	}
}

void cargarCola(Nodo *&inicio, Nodo *&fin, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	nuevoNodo->siguiente=NULL;
	if(colaVacia(inicio)){
		inicio = nuevoNodo;
	}else{
		fin->siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
	cout<<"El numero "<<n<<" fue cargado correctamente a la cola.\n";
	return;
}

void quitarCola(Nodo *&inicio, Nodo *&fin, int &n){
	n=inicio->n;
	Nodo *aux = inicio;
	if(inicio == NULL){
		inicio = NULL;
		fin = NULL;
	}else{
		inicio = inicio -> siguiente;
	}
	delete aux;
}


/*
1 – Hacer un programa para agregar números enteros a una cola, hasta que el
usuario lo decida, después mostrar todos os números introducidos en la cola.
*/

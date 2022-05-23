#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *Siguiente;
};

void cargarPila(Nodo *&, int);
void quitarPila(Nodo *&, int &);
void cantDatos(int &);

main(){
	int n, m;
	cout<<"Cargue un vector y el programa invertira el mismo utilizando pilas.\n";
	cantDatos(m);
	int A[m], A_Inv[m];
	Nodo *Pila = NULL;
	for(int i=0; i<m; i++){
		cout<<"Carga de Datos.\nPosicion "<<i+1<<": ";
		cin>>A[i];
		cargarPila(Pila, A[i]);
	}
	system("cls");
	cout<<"Vector Cargado\n";
	for(int i=0; i<m; i++){
		if(i == (m-1)){
			cout<<A[i]<<" |\n";
		}else if(i==0){
			cout<<"| "<<A[i]<<" | ";
		}else{
			cout<<A[i]<<" | ";			
		}
	}
	for(int i=0; i<m; i++){
		quitarPila(Pila, n);
		A_Inv[i]= n;
	}
	cout<<"Vector Cargado con los Elementos Invertidos:\n";
	for(int i=0; i<m; i++){
		if(i == (m-1)){
			cout<<A_Inv[i]<<" |\n";
		}else if(i==0){
			cout<<"| "<<A_Inv[i]<<" | ";
		}else{
			cout<<A_Inv[i]<<" | ";			
		}
	}
	
	
	system("pause");
	return 0;
}

void cargarPila(Nodo *&Pila, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	nuevoNodo->Siguiente=Pila;
	Pila=nuevoNodo;
	return;
}

void quitarPila(Nodo *&Pila, int &n){
	Nodo *aux= Pila;
	n=aux->n;
	Pila=aux->Siguiente;
	delete aux;
	return;
}

void cantDatos(int &m){
	cout<<"Ingrese la cantidad de datos que desea cargar en el vector: ";
	cin>>m;
	while(m < 1){
		cout<<"Debe ingresar al menos un numero.\nVuelva a intentar.\n";
		cout<<"Ingrese la cantidad de datos que desea cargar en el vector: ";
		cin>>m;	
	}
	return;
}

/*
3) Crear y cargar un vector A. Invertir los valores del vector utilizando pilas. 
*/

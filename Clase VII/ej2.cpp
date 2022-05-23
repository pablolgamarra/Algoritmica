#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;
};

void cargaCola(Nodo *&, Nodo *&, int);
void quitarCola(Nodo *&, Nodo *&, int &);
bool colaVacia(Nodo *);

main(){
	setlocale(LC_ALL, "spanish");
	
	int limites[4];
	cout<<"Cargar tres vectores.\n";
	
	for(int i=0; i<3; i++){
		cout<<"Ingrese la cantidad de elementos que tendrá el vector "<<i+1<<": ";
		cin>>limites[i];
	}
	
	limites[3] = limites[0] + limites[1] + limites[2];
	int A[limites[0]] ,B[limites[1]] ,C[limites[2]], D[limites[3]];
	
	Nodo *frente = NULL, *fin = NULL;
	
	for(int i=0; i<limites[0]; i++){
		cout<<"Carga de Datos.\nVector 1.\n";
		cout<<"Posicion: "<<i+1<<": ";
		cin>>A[i];
		cargaCola(frente, fin, A[i]);	
	}
	
	for(int i=0; i<limites[1]; i++){
		cout<<"Carga de Datos.\nVector 2.\n";
		cout<<"Posicion: "<<i+1<<": ";
		cin>>B[i];
		cargaCola(frente, fin, B[i]);		
	}
	
	for(int i=0; i<limites[2]; i++){
		cout<<"Carga de Datos.\nVector 3.\n";
		cout<<"Posicion: "<<i+1<<": ";
		cin>>C[i];
		cargaCola(frente, fin, C[i]);
	}
	
	int i=0;
	while(!colaVacia(frente)){
		quitarCola(frente, fin, D[i]);
		if(colaVacia(frente)){
			cout<<D[i];
		}
		i++;
	}
	
	cout<<"Se imprimiran los vectores cargados.\n";
	system("pause");
	
	system("cls");
	
	cout<<"Vector A:\n";
	for(int i=0; i<limites[0]; i++){
		if(i == ((limites[0]) - 1)){
			cout<<A[i]<<"|\n";
		}else if(i == 0){
			cout<<"| "<<A[i]<<" | ";
		}else{
			cout<<A[i]<<" | ";
		}
	}
	
	cout<<"Vector B:\n";
	for(int i=0; i<limites[1]; i++){
		if(i == ((limites[1]) - 1)){
			cout<<B[i]<<"|\n";
		}else if(i == 0){
			cout<<"| "<<B[i]<<" | ";
		}else{
			cout<<B[i]<<" | ";
		}
	}
	
	cout<<"Vector C:\n";
	for(int i=0; i<limites[2]; i++){
		if(i == ((limites[2]) - 1)){
			cout<<C[i]<<"|\n";
		}else if(i == 0){
			cout<<"| "<<C[i]<<" | ";
		}else{
			cout<<C[i]<<" | ";
		}
	}
	
	cout<<"Vector D:\n";
	for(int i=0; i<limites[3]; i++){
		if(i == ((limites[3]) - 1)){
			cout<<D[i]<<"|\n";
		}else if(i == 0){
			cout<<"| "<<D[i]<<" | ";
		}else{
			cout<<D[i]<<" | ";
		}
	}
	
	delete frente, fin;
	system("pause");
	return 0;
}

bool colaVacia(Nodo *frente){
	if(frente == NULL){
		return true;
	}else{
		return false;
	}
}

void cargaCola(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(frente)){
		frente = nuevoNodo;
	}else{
		fin->siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
	cout<<"Se agrego el elemento "<<n<<" a la cola.\n";
	return;
}

void quitarCola(Nodo *&frente, Nodo *&fin, int &n){
	Nodo *aux = frente;
	n = frente->n;
	if(colaVacia(frente)){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente;
	}
	delete aux;
}

/*
2 – Crear y cargar 4 vectores A, B, C y D. Con ellos cargar una cola de datos el
cual, luego se descargara en el vector D que contendrán los valores de A, B
y C
*/

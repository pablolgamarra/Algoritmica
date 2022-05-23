#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;
};

void cargarPila(Nodo *&, int);
void quitarPila(Nodo *&, int &);

main(){
	setlocale(LC_ALL, "spanish");
	int n,f=0,c=0, lf=6,lc=5;
	Nodo *Pila = NULL;
	int B[lf][lc];
	cout<<"Cargar las filas impares de la matriz, y el programa cargará las pares.\n";
	while(f<lf){
	    f++;
	  while(c<lc){
	      c++;
			if(f%2!=0){
				cout<<"Carga de Datos.\nPosicion ["<<f<<", "<<c<<"]: ";
				cin>>B[f][c];
				cargarPila(Pila,B[f][c]);
			}else{
				quitarPila(Pila,n);
				B[f][c]=n;
			}	
		}
		c=0;
	}
	f=0;
	system("cls");
	cout<<"La Matriz Obtenida es\n";
	while(f<lf){
		f++;
		while(c<lc){
	    	c++;
			if(c == (lc)){
				cout<<B[f][c]<<" |\n";
			}else{
				cout<<B[f][c]<<" | ";
			}	
		}
		c=0;
	}
	f=0;
	system("pause");
	return 0;
}

void cargarPila(Nodo *&Pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->n = n;
	nuevo_nodo->siguiente = Pila;
	Pila = nuevo_nodo;
}

void quitarPila(Nodo *&Pila, int &n){
	Nodo *aux = Pila;
	n = aux->n;
	Pila = aux->siguiente;
	delete aux;
}

/*
4) Crear y cargar una matriz B de orden 6x5. Llenar cada fila impar con el teclado
y las filas pares con los elementos invertidos de la fila anterior utilizando pilas.
Imprimir la matriz 
*/

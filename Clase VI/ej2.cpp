#include <iostream>
#include <windows.h>
#include <locale.h>
#include <string>
#include <time.h>

using namespace std;

struct Nodo{
	string Premio;
	int ganador;
	Nodo *siguiente;
};

string Premios[4]{"Iphone X", "PlayStation 4", "Pendrive de 1TB", "Pulsera Mi Band3"};

void cargarPila(Nodo *&, int);
void quitarPila(Nodo *&, int&, string &);
int numRandom(void);

main(){
	setlocale(LC_ALL, "spanish");
	srand(time(NULL));
	Nodo *Pila=NULL;
	cout<<"Programa para realizar un sorteo entre 200 boletas.\n";
	system("pause");
	for(int i=3; i>=0; i--){
		cargarPila(Pila, i);
	}
	system("cls");
	cout<<"Premios y Boletas:\n";
	while(Pila != NULL){
		int ganador;
		string premio;
		quitarPila(Pila, ganador, premio);
		cout<<"El n° de Boleta: "<<ganador<<". Se ganó: "<<premio<<"\n";
	}
	system("pause");
	return 0;
}

int numRandom(void){
	int num = rand() % (200 - 1) + 1;
    return num;
}

void cargarPila(Nodo *&Pila, int i){
	Nodo *nuevoNodo= new Nodo();
	nuevoNodo->Premio=Premios[i];
	nuevoNodo->ganador=numRandom();
	nuevoNodo->siguiente=Pila;
	Pila=nuevoNodo;
	return;
}

void quitarPila(Nodo *&Pila, int &ganador, string &premio){
	Nodo *aux = Pila;
	ganador=aux->ganador;
	premio=aux->Premio;
	Pila=aux->siguiente;
	delete aux;
	return;
}

/*
2) Crear un programa que permita hacer un sorteo entre 200 boletas vendidas
con los siguientes premios en el orden indicado:
- Primer Premio: un iphone X
- Segundo Premio: un PlayStation 4
- Tercer premio: Pendrive de 1TB
- Cuarto premio: Pulsera Mi Band3
Mostrar los premios del cuarto al primero utilizando pilas.
*/

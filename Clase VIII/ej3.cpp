#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	string nombre;
	int edad;
	Nodo *siguiente;
};

void cargaCola(Nodo *&, Nodo *&, string , int);
void quitarCola(Nodo *&, Nodo *&, string &, int &);
bool colaVacia(Nodo *);

main(){
	setlocale(LC_ALL, "spanish");
	
	Nodo *Frente = NULL, *Fin = NULL;
	string nombre;
	int edad;
	char op;
	
	do{
		cout<<"Cargue los datos.\n";
		fflush(stdin);
		cout<<"Nombre: ";
		getline(cin, nombre);
		fflush(stdin);
		cout<<"Edad: ";
		cin>>edad;
		cargaCola(Frente, Fin, nombre, edad);
		cout<<"¿Desea seguir ingresando datos? (S)/(N): ";
		cin>>op;
		if(op == 'N' || op == 'n'){
			cout<<"Ok...Se imprimirán los datos.\n";
			system("pause");
		}
	}while(op == 'S' || op == 's');
	
	system("cls");
	int menores=0, mayores=0;
	
	while(!colaVacia(Frente)){
		quitarCola(Frente, Fin, nombre, edad);
		if(edad < 18){
			menores++;
		}else{
			mayores++;
		}
	}

	cout<<"La cantidad de Mayores de edad que se cargó a la lista es: "<<mayores<<"\n";
	cout<<"La cantidad de Menores de edad que se cargó a la lista es: "<<menores<<"\n";
}

bool colaVacia(Nodo *Frente){
	if(Frente == NULL){
		return true;
	}else{
		return false;
	}
}

void cargaCola(Nodo *&Frente, Nodo *&Fin, string nombre, int edad){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->nombre = nombre;
	nuevoNodo->edad = edad;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(Frente)){
		Frente = nuevoNodo;
	}else{
		Fin->siguiente = nuevoNodo;
	}
	Fin = nuevoNodo;
	return;
}

void quitarCola(Nodo *&Frente, Nodo *&Fin, string &nombre, int &edad){
	Nodo *aux = Frente;
	nombre = Frente->nombre;
	edad = Frente->edad;
	if(colaVacia(Frente)){
		Frente = NULL;
		Fin == NULL;
	}else{
		Frente = aux->siguiente;
	}
	delete aux;
}


/*
3) Crear una lista que permita ingresar los datos de un conjunto de personas, teniendo en
cuenta los siguientes campos: nombre, edad. Imprimir la lista de las personas que
tengan la mayoría de edad y decir cuántas de las personas son menores de edad. 
*/

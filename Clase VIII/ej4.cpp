#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	string nombre;
	string comida;
	int precio;
	Nodo *siguiente;
};

void cargaCola(Nodo *&, Nodo *&, string, string, int);
void quitarCola(Nodo *&, Nodo *&, string &, string &, int &);
bool colaVacia(Nodo *);

main(){
	setlocale(LC_ALL, "spanish");
	
	Nodo *Frente = NULL, *Fin = NULL;
	string nombre, comida;
	int precio;
	char op;
	
	do{
		fflush(stdin);
		cout<<"Pedidos.\n";
		cout<<"Ingrese nombre del cliente: ";
		getline(cin, nombre);
		cout<<"Ingrese la comida que desea el cliente: ";
		getline(cin, comida);
		fflush(stdin);
		cout<<"Ingrese el precio del pedido: ";
		cin>>precio;
		cargaCola(Frente, Fin, nombre, comida, precio);
		cout<<"¿Desea seguir cargando pedidos? (S)/(N): ";
		cin>>op;
		if(op == 'N' || op == 'n'){
			cout<<"Ok...Se imprimira la lista de los pedidos.\n";
			system("pause");
		}
	}while(op == 'S' || op == 's');
	
	system("cls");
	cout<<"Pedidos Cargados:\n";
	
	while(!colaVacia(Frente)){
		quitarCola(Frente, Fin, nombre, comida, precio);
		cout<<"Nombre del Cliente: "<<nombre<<"\n";
		cout<<"Pedido: "<<comida<<"\n";
		cout<<"Precio a Pagar: "<<precio<<"\n";
		cout<<"-----------------------------------\n";
	}
	
	system("pause");
	return 0;
}

bool colaVacia(Nodo *Frente){
	if(Frente == NULL){
		return true;
	}else{
		return false;
	}
}

void cargaCola(Nodo *&Frente, Nodo *&Fin, string nombre, string comida, int precio){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->nombre = nombre;
	nuevoNodo->comida = comida;
	nuevoNodo->precio = precio;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(Frente)){
		Frente = nuevoNodo;
	}else{
		Fin->siguiente = nuevoNodo;
	}
	Fin = nuevoNodo;
	return;
}

void quitarCola(Nodo *&Frente, Nodo *&Fin, string &nombre, string &comida, int &precio){
	Nodo *aux = Frente;
	nombre = Frente->nombre;
	comida = Frente->comida;
	precio = Frente->precio;
	if(colaVacia(Frente)){
		Frente = NULL;
		Fin = NULL;
	}else{
		Frente = Frente->siguiente;
	}
	delete aux;
	return;
}

/*
4) Crear una lista de pedidos para un local de comida rápida, donde, cada cliente solo
podrá realizar un pedido por vez. Para ello, se debe anotar: nombre, comida, precio.
Imprimir la lista de pedidos. 
*/

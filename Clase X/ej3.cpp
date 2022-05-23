#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void cargarLista(Nodo *&, int);
void mostrarLista(Nodo *);
int cargarNumero(void);

main(){
	setlocale(LC_ALL, "spanish");
	
	Nodo *Lista = NULL;
	char op;
	do{
		system("cls");
		cout<<"Programa para cargar una lista en orden decreciente.\n";
		cargarLista(Lista, cargarNumero());
		cout<<"¿Desea seguir ingresando numeros a la lista?: (S/N)";
		cin>>op;
		if(op == 'n' || op == 'N'){
			cout<<"OK...Se imprimirá la lista con los números que se cargaron en ella.\n";
			system("pause");
		}
	}while(op == 's' || op == 'S');

	system("cls");
	cout<<"Lista Cargada en forma decreciente:\n";
	mostrarLista(Lista);

	system("pause");
	return 0;
}

void cargarLista(Nodo *&Lista, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	Nodo *aux1 = Lista;
	Nodo *aux2;
	while((aux1 != NULL) && (aux1->dato > n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;	
	}
	if(Lista == aux1){
		Lista = nuevoNodo;
	}else{
		aux2->siguiente = nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
}

void mostrarLista(Nodo *Lista){
	Nodo *actual = new Nodo();
	actual = Lista;
	while(actual != NULL){
		cout<<actual->dato<<"\n";
		actual = actual->siguiente;
	}
}

int cargarNumero(void){
	int n;
	cout<<"Ingrese un numero para cargarlo a la lista: ";
	cin>>n;
	return n;
}

/*
3 – Crear y cargar una lista simplemente enlazada en orden decreciente. Mostrar
los elementos de la lista.
*/

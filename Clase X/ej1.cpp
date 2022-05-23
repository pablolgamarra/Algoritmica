#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

int numerosPares(void);
void cargarLista(Nodo *&, int);
void mostrarLista(Nodo *);

main(){
	setlocale(LC_ALL, "spanish");
	Nodo *Lista = NULL;
	char op;
	do{
		system("cls");
		cout<<"Programa para cargar una lista.\n";
		cargarLista(Lista, numerosPares());
		cout<<"¿Desea seguir cargando numeros? ( S/N ): ";
		cin>>op;
		if(op == 'N' || op == 'n'){
			cout<<"OK...Se imprimirán los valores ingresados a la lista";
		}
	}while(op == 'S' || op == 's');
	
	system("cls");
	cout<<"Lista Cargada:\n";
	mostrarLista(Lista);
	system("pause");
}

void cargarLista(Nodo *&Lista, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	Nodo *aux1 = Lista;
	Nodo *aux2;
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

int numerosPares(){
	int n;
	cout<<"Ingrese un numero par: ";
	cin>>n;
	while(n % 2 != 0){
		cout<<"El numero ingresado no es un numero par. Vuelva a intentar.\n";
		cout<<"Ingrese un numero: ";
		cin>>n;	
	}
	return n;
}

/*
1 – Cargar una lista simplemente enlazada con números pares. Mostrar los
elementos cargados sin ordenar
*/

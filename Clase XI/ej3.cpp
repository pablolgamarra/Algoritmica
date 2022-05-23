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
void buscarNodo(Nodo *, int);
int cargarNumeros(void);

main(){
	setlocale(LC_ALL, "spanish");
	Nodo *Lista = NULL;
	char op;
	do{
		cout<<"Programa para buscar elementos en una lista.\n";
		cargarLista(Lista, cargarNumeros());
		cout<<"¿Desea ingresar más números? (S/N)";
		cin>>op;
		if(op == 'n' || op == 'N'){
			cout<<"Ok...Se dejara de cargar numeros a la lista.\n";
		}
	}while(op == 's' || op == 'S');
	
	int n;
	cout<<"Ingrese el numero que desea buscar en la lista y el programa mostrará la cantidad de veces que se repite el elemento.\n";
	cout<<"Numero a buscar: ";
	cin>>n;
	buscarNodo(Lista, n);
	system("pause");
	return 0;
}

void cargarLista(Nodo *&Lista, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	Nodo *aux1 = Lista;
	Nodo *aux2;
	while((aux1 != NULL)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(aux1 == Lista){
		Lista = nuevoNodo;
	}else{
		aux2->siguiente = nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
	return;
}

void mostrarLista(Nodo *Lista){
	Nodo *actual = new Nodo();
	actual = Lista;
	while(actual != NULL){
		cout<<actual->dato<<"\n";
		actual = actual->siguiente;
	}
	return;
}

void buscarNodo(Nodo *Lista, int n){
	int encontrado = 0;
	Nodo *actual = new Nodo();
	actual = Lista;
	while((actual != NULL)){
		if(actual->dato == n){
			encontrado++;
		}
		actual = actual->siguiente;
	}
	if(encontrado == 0){
		cout<<"No se ha encontrado el elemento "<<n<<" en la lista cargada.\n";
	}else{
		cout<<"Se ha encontrado el elemento "<<n<<". "<<encontrado<<" veces.\n";
	}
	return;
}

int cargarNumeros(void){
	int n;
	cout<<"Carga de Numeros a la lista.\n";
	cout<<"Ingrese un numero: ";
	cin>>n;
	return n;
}

/*
3 – Cargar una lista hasta que el usuario lo decida. Luego, ingresar un numero,
buscar en la lista y decir cuantas veces se encuentra repetido o si el mismo no
se encuentra en la lista .
*/

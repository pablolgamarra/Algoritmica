#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void cargarLista(Nodo *&, int);
void imprimirLista(Nodo *);
void buscarNodo(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&, int &);
int mostrarMenu(void);

main(){
	setlocale(LC_ALL, "spanish");
	Nodo *Lista = NULL;
	int n;
	bool deseoSalir = false;
	do{
		switch(mostrarMenu()){
			case 1:
				char op;
				do{
					system("cls");
					cout<<"Ingrese el número que desea cargar a la Lista: ";
					cin>>n;
					cargarLista(Lista, n);
					cout<<"¿Desea seguir cargando números a la lista? S/N: ";
					cin>>op;
				}while(op == 'S' || op == 's');
				system("pause");
				break;
			case 2:
				system("cls");
				if(Lista == NULL){
					cout<<"No se pueden imprimir elementos de la lista porque está vacía\n";
					break;
				}
				imprimirLista(Lista);
				system("pause");
				break;
			case 3:
				system("cls");
				if(Lista == NULL){
					cout<<"No se pueden buscar elementos en la lista porque está vacía\n";
					break;
				}
				cout<<"Ingrese el número que desea buscar en la lista: ";
				cin>>n;
				buscarNodo(Lista, n);
				system("pause");
				break;
			case 4:
				system("cls");
				if(Lista == NULL){
					cout<<"No se pueden eliminar elementos de la lista porque está vacía\n";
					break;
				}
				cout<<"Ingrese el numero que desea eliminar de la lista cargada: ";
				cin>>n;
				eliminarNodo(Lista, n);
				system("pause");
				break;
			case 5:
				system("cls");
				cout<<"Ok...Se eliminará la lista cargada.\n";
				if(Lista == NULL){
					cout<<"No se pueden eliminar elementos de la lista porque está vacía\n";
					break;
				}
				while(Lista != NULL){
					eliminarLista(Lista, n);
					cout<<"El elemento "<<n<<" ha sido eliminado\n";
					if(Lista == NULL){
						cout<<"La lista ha sido eliminada.\n";
					}
				}
				system("pause");
				break;
			case 6:
				system("cls");
				cout<<"Gracias por utilizar el programa :)\n";
				deseoSalir = true;
				system("pause");
				break;
			default:
				system("cls");
				cout<<"Ha ocurrido un error, vuelva a intentar";
				break;
		}
	}while(!deseoSalir);
	
	system("pause");
	return 0;
}

void cargarLista(Nodo *&Lista, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	Nodo *aux1 = Lista;
	Nodo *aux2;
	while((aux1 != NULL)/* && (aux1->dato < n)*/){
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

void imprimirLista(Nodo *Lista){
	Nodo *actual = new Nodo();
	actual = Lista;
	while(actual != NULL){
		cout<<actual->dato<<"\n";
		actual = actual->siguiente;
	}
	return;
}

void buscarNodo(Nodo *Lista, int n){
	bool encontrado = false;
	Nodo *actual = new Nodo();
	actual = Lista;
	while((actual != NULL) && (!encontrado)){
		if(actual->dato == n){
			encontrado = true;
		}else{
			actual = actual->siguiente;
		}
	}
	if(encontrado){
		cout<<"Se ha encontrado el numero "<<n<<" dentro de la lista.\n";
	}else{
		cout<<"No se ha encontrado el numero "<<n<<" dentro de la lista.\n";
	}
}

void eliminarNodo(Nodo *&Lista, int n){
	Nodo *auxBorrar;
	Nodo *anterior = NULL;
	auxBorrar = Lista;
	while((auxBorrar != NULL) && (auxBorrar->dato != n)){
		anterior = auxBorrar;
		auxBorrar = auxBorrar->siguiente;
	}
	if(auxBorrar == NULL){
		cout<<"El elemento no existe en la lista\n";	
	}else if(anterior == NULL){
		Lista = Lista->siguiente;
		delete auxBorrar;
		cout<<"El elemento "<<n<<" fue borrado correctamente de la lista.\n";
	}else{
		anterior->siguiente = auxBorrar->siguiente;
		delete auxBorrar;
		cout<<"El elemento "<<n<<" fue borrado correctamente de la lista.\n";
	}
}

void eliminarLista(Nodo *&Lista, int &n){
	Nodo *aux = Lista;
	n = aux->dato;
	Lista = aux->siguiente;
	delete aux;
}

int mostrarMenu(void){
	int op;
	system("cls");
	cout<<"Programa de Manejo de Listas\n";
	do{
		cout<<"Seleccione la opción que desea.\n";
		cout<<"1 - Cargar Lista\n";
		cout<<"2 - Imprimir la Lista Cargada\n";
		cout<<"3 - Buscar un elemento dentro de la lista\n";
		cout<<"4 - Eliminar un elemento de la lista\n";
		cout<<"5 - Eliminar la lista cargada\n";
		cout<<"6 - Salir del programa\n";
		cin>>op;
		if(op < 1 || op > 6){
			cout<<"El numero ingresado no está en el rango, vuelva a intentar.\n";
		}
	}while(op < 1 || op > 6);
}
/*
1 – Crear una aplicación que permita realizar todas las operaciones vistas hasta
el momento en listas enlazadas (insertar, mostrar, buscar, eliminar nodo,
eliminar todo). Utiliza un menú para poder interactuar con el usuario
*/

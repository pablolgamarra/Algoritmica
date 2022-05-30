//@Towel15

#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;
/*
Operaciones Básicas
Insertar
Recorrer (Mostrar)
Modificar
Buscar
Eliminar
*/

//Estructura de los Nodos. Un dato y dos punteros por ser lista enlazada
struct Nodo{
	int dato;
	Nodo *siguiente;
	Nodo *anterior;
};

//Prototipos de Función
int cargaNumero(void);
int opcionImpresion(void);
void cargarLista(Nodo *&, Nodo *&, int);
void mostrarLista(Nodo *, int);
int buscarNodo(Nodo *, int, int, bool &);
void modificarNodo(Nodo *&, int);
void eliminarNodo(Nodo *&, Nodo *&, int);

main(){
	Nodo *primero = NULL, *ultimo = NULL;
	char op;
	int opImp;
	do{
		setlocale(LC_ALL, "spanish");
		cout<<"Programa de Manejo de Listas Doblemente Enlazadas.\n";
		cargarLista(primero, ultimo, cargaNumero());
		cout<<"¿Desea seguir ingresando numeros a la lista?\n (S/N):";
		cin>>op;
		if(op == 'n' || op == 'N'){
			cout<<"Ok...Se mostrarán las opciones disponibles.\n";
		}
	}while(op == 's' || op == 'S');
	cout<<"Ingrese el numero que desea que se busque en la lista.\n";
	bool errorEnBusqueda[2] = {false};
	int buscado = cargaNumero();
	int posicionesBusqueda[2] = {buscarNodo(primero, buscado, 1, errorEnBusqueda[0]), buscarNodo(ultimo, buscado, 2, errorEnBusqueda[1])};
//	cout<<errorEnBusqueda[0]<<endl;
//	cout<<errorEnBusqueda[1]<<endl;
	if(errorEnBusqueda[0] || errorEnBusqueda[1]){
		cout<<"El numero "<<buscado<<" no se ha encontrado en la lista.\n";
	}
	if(posicionesBusqueda[0] < posicionesBusqueda[1] && !errorEnBusqueda[0] && !errorEnBusqueda[1]){
		cout<<"El numero "<<buscado<<"se encuentra más rápido recorriendo desde el primer al último elemento.\n";
	}else if(!errorEnBusqueda[0] && !errorEnBusqueda[1]){
		cout<<"El numero "<<buscado<<"se encuentra más rápido recorriendo desde el último al primer elemento.\n";
	}
	system("pause");
	return 0;
}

//Declaracion de Funciones
int cargaNumero(void){
	int n;
	cout<<"Ingrese un número: ";
	cin>>n;
	return n;
}

int opcionImpresion(void){
	int op;
	cout<<"¿Desea imprimir los elementos: \n1- Del primero al último \n2- Del último al primero?\n";
	cin>>op;
	return op;
}

void cargarLista(Nodo *&primero, Nodo *&ultimo, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	if(primero == NULL){
		primero=nuevoNodo;
		nuevoNodo->anterior=NULL;
		nuevoNodo->siguiente=NULL;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevoNodo;
		nuevoNodo->siguiente=NULL;
		nuevoNodo->anterior=ultimo;
		ultimo=nuevoNodo;
	}
	cout<<"Se cargo el número: "<<n<<" a la lista correctamente.\n";
}

void mostrarLista(Nodo *iniciador, int op){
	system("cls");
	Nodo *actual = new Nodo;
	actual = iniciador;
	switch (op){
		case 1:
			//La lista se recorre desde el primer elemento hasta el último
			if(actual != NULL){
				while(actual != NULL){
					cout<<actual->dato<<"\n";
					actual = actual->siguiente;
				}
			}else{
				cout<<"ERROR.La lista no está cargada con ningún dato.\n";
			}
			break;
		case 2:
			//La lista se recorre desde el último elemento hasta el primero
			if(actual != NULL){
				while(actual != NULL){
					cout<<actual->dato<<"\n";
					actual = actual->anterior;
				}
			}else{
				cout<<"ERROR.La lista no está cargada con ningún dato.\n";
			}
			break;
	}
}

int buscarNodo(Nodo *iniciador, int buscado, int opBusqueda, bool &errores){
	cout<<"Buscar en la Lista Cargada.\n";
	Nodo *actual = new Nodo();
	actual = iniciador;
	int posicion=0;
	bool encontrado = false;
	if(actual != NULL){
		switch(opBusqueda){
			case 1:
				while((actual != NULL) && !encontrado){
					if(actual->dato == buscado){
						encontrado = true;
					}else{
						actual = actual->siguiente;
						posicion++;
					}
				}
				if(!encontrado){
					errores = true;
				}/*else{
					cout<<"Se ha encontrado el elemento "<<buscado<<" en la lista\n";
				}*/
				break;
			case 2:
				while((actual != NULL) && !encontrado){
					if(actual->dato == buscado){
						encontrado = true;
					}else{
						actual = actual->anterior;
						posicion++;
					}
				}
				if(!encontrado){
					errores = true;
				}/*else{
					cout<<"Se ha encontrado el elemento "<<buscado<<" en la lista\n";
				}*/
				break;
			default:
				cout<<"ERROR.La opcion de orden de busqueda no está disponible";
		}

	}else{
		cout<<"ERROR.La lista no está cargada con ningún dato.\n";
	}
	return posicion;
}

void modificarNodo(Nodo *&primero, int modificable){
	Nodo *actual = new Nodo();
	bool encontrado = false;
	actual = primero;
	if(actual != NULL){
		while(actual != NULL && !encontrado){
			if(actual->dato == modificable){
				encontrado = true;
				actual->dato = cargaNumero();
			}else{
				actual = actual->siguiente;	
			}		
		}
		if(encontrado){
			cout<<"Se ha modificado el elemento "<<modificable<<" en la lista\n";
		}else{
			cout<<"No se ha encontrado el elemento "<<modificable<<" en la lista. Por lo que no se hizo ninguna modificación\n";
		}
	}else{
		cout<<"ERROR.La lista no está cargada con ningún dato.\n";
	}
}

void eliminarNodo(Nodo *&primero, Nodo *&ultimo, int eliminable){
	Nodo *actual = new Nodo();
	Nodo *anterior = NULL;
	Nodo *aux = new Nodo();
	bool encontrado = false;
	actual = primero;
	if(actual != NULL){
		while(actual != NULL && !encontrado){
			if(actual->dato == eliminable){
				if(actual == primero){
					aux = primero;
					primero= actual->siguiente;
					primero->anterior=NULL;
				}else if(actual == ultimo){
					aux = ultimo;
					anterior->siguiente = actual ->siguiente;
					ultimo = anterior;
				}else{
					aux = actual;
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}
				delete aux;
				encontrado = true;
			}else{
				anterior = actual;
				actual = actual->siguiente;	
			}		
		}
		if(encontrado){
			cout<<"Se ha eliminado el elemento "<<eliminable<<" en la lista\n";
		}else{
			cout<<"No se ha encontrado el elemento "<<eliminable<<" en la lista. Por lo que no se eliminó ningún dato\n";
		}
	}else{
		cout<<"ERROR.La lista no está cargada con ningún dato.\n";
	}
}
/*
Crear una lista doblemente enlazada, en donde se pueda, agregar, modificar, eliminar elementos
numéricos enteros
atendiendo que ninguno sea un valor repetido. 
Luego, ingresar un número cualquiera 
y 
decir si el número se encuentra primero en el recorrido de primero a ultimo o de
ultimo a primer elemento de la lista. 
En caso de no encontrarse el valor, indicar con un mensaje. 
*/




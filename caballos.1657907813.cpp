#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
//Configurar, Crear Apuestas, Correr, Encontrar al Ganador, Pagar Apuestas, Calcular el total pagado
using namespace std;

//Estructuras
struct Caballo{
	int idCaballo;
	string nombre;
	int puntaje;
	int porcentajeIncremento;
	Caballo *siguiente;
};

struct Jugador{
	int idJugador;
	string nombre;
	Jugador *siguiente;
};

//Variables Globales
int id = 0, cantCaballos = 0;
bool configurado = false;

//Funciones
int generarAleatorio(int, int);
bool cargaLista(Caballo *&, int, string, int, int);
bool cargaLista(Jugador *&, int, string);
void mostrarLista(Caballo *);
void mostrarLista(Caballo *, int);
void mostrarLista(Jugador *);
void mostrarNodo(Caballo *);
void mostrarNodo(Caballo *, int);
void mostrarNodo(Jugador *);
void configurar(Caballo *&);
void configuracionCaballos(Caballo *&);
void jugar(Caballo *&);
void conApuestas(Caballo *&caballos);
void sinApuestas();
int menuPrincipal();

main(){
	srand(unsigned(time(NULL)));
	setlocale(LC_ALL, "spanish");
	
	Caballo *caballos = NULL;
	
	int op;
	char salida;
	bool salir = false;
	
	do{
		system("cls");
		switch(menuPrincipal()){
			case 0:
				cout<<"¿Está seguro de que desea salir del juego? (S/N):"; cin>>salida;
				while((salida != 'S' && salida != 's')  && (salida != 'n' && salida != 'N')){
					cout<<"¿Está seguro de que desea salir del juego? (S/N):"; cin>>salida;
				}
				if(salida == 'S' || salida == 's'){
					salir = true;
				}
				break;
			case 1:
				if(!configurado){
					cout<<"Para poder jugar primero debe configurar los parámetros de los caballos en el menu 'Configuracion'.\n";
					Sleep(1000);
				}else{
					jugar(caballos);
				}
				break;
			case 2:
				configurar(caballos);
				break;
			default:
				break;
		}		
	}while(!salir);

}

int generarAleatorio(int ls, int li){
	return rand()%(ls - li) + li;
}

bool cargaLista(Caballo *&caballos, int id, string nombre, int puntaje, int porcentaje){
	Caballo *nuevoNodo = new Caballo();
	nuevoNodo->idCaballo = id;
	nuevoNodo->nombre = nombre;
	nuevoNodo->puntaje = puntaje;
	nuevoNodo->porcentajeIncremento = porcentaje;
	Caballo *aux1 = caballos;
	Caballo *aux2 = NULL;
	while(aux1 && aux1->idCaballo < id){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(caballos == aux1){
		caballos = nuevoNodo;
	}else{
		aux2->siguiente = nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
}

bool cargaLista(Jugador *&jugadores, int id, string nombre){
	Jugador *nuevoNodo = new Jugador();
	nuevoNodo->idJugador = id;
	nuevoNodo->nombre = nombre;
	Jugador *aux1 = jugadores;
	Jugador *aux2 = NULL;
	while(aux1 && aux1->idJugador < id){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(jugadores == aux1){
		jugadores = nuevoNodo;
	}else{
		aux2->siguiente = nuevoNodo;
	}
	nuevoNodo->siguiente = aux1;
}

void mostrarLista(Caballo *caballos, int banderaUsuario){
	Caballo *actual = caballos;
	if(actual){
		while(actual){
			mostrarNodo(actual,1);
			actual = actual->siguiente;
		}
	}else{
		cout<<"No hay caballos en la lista";
	}
}

void mostrarLista(Jugador *jugadores){
	Jugador *actual = jugadores;
	if(actual){
		while(actual){
			mostrarNodo(actual);
			actual = actual->siguiente;
		}
	}else{
		cout<<"No hay caballos en la lista";
	}
}

void mostrarNodo(Caballo *actual){
	cout<<"Id Caballo: "<<actual->idCaballo<<"\n";
	cout<<"Nombre: "<<actual->nombre<<"\n";
	cout<<"Puntaje: "<<actual->puntaje<<"\n";
	cout<<"Porcentaje de Ganancia: "<<actual->porcentajeIncremento<<"\n";
}

void mostrarNodo(Caballo *actual, int banderaUsuario){
	cout<<"Id Caballo: "<<actual->idCaballo<<"\n";
	cout<<"Nombre: "<<actual->nombre<<"\n";
}

void mostrarNodo(Jugador *actual){
	cout<<"Id del Jugador: "<<actual->idJugador<<"\n";
	cout<<"Nombre del Jugador: "<<actual->nombre<<"\n";
}

void configurar(Caballo *&caballos){
	bool volver = false;
	int op;
	
	do{
		system("cls");
		cout<<"Configuracion de los Caballos.\n";
		cout<<"Seleccione la opción que desee.\n";
		cout<<"1- Configurar Propiedades de los caballos.\n";
		cout<<"0- Volver al menú principal.\n";
		cout<<"Opcion: "; cin>>op;
		while(op < 0 || op > 1){
			cout<<"Seleccione la opción que desee.\n";
			cout<<"1- Configurar Propiedades de los caballos.\n";
			cout<<"0- Volver al menú principal.\n";
			cout<<"Opcion: "; cin>>op;
		}
		switch(op){
			case 0:
				cout<<"\nOk...Saliendo al menú principal.\n";
				volver = true;
				break;
			case 1:
				configuracionCaballos(caballos);
				configurado = true;
				break;
		}
	}while(!volver);
}

void configuracionCaballos(Caballo *&caballos){
	string nombre;
	int margen, puntaje = 0;
	
	system("cls");
	
	cout<<"Ingrese la cantidad de Caballos con los que desea jugar: ";cin>>cantCaballos;
	while(cantCaballos < 2){
		cout<<"¡Para poder jugar se necesitan al menos dos caballos.\n!";
		cout<<"Ingrese la cantidad de Caballos con los que desea jugar: ";cin>>cantCaballos;
	}
	
	for(int i=0; i<cantCaballos; i++){
		cout<<"Ingrese nombre para el caballo "<<i+1<<": ";cin>>nombre;
		cout<<"Ok...Se generará un margen de ganancia aleatorio para el caballo.\n";
		margen = generarAleatorio(100, 1);
		cargaLista(caballos, id, nombre, 0, margen) ? id++ : id = id;
	}
	configurado = true;
}

void jugar(Caballo *&caballos){
	int opcion;
	bool volver = false;
	
	do{
		system("cls");
		cout<<"Jugar.\n";
		cout<<"Seleccione el modo de juego:\n";
		cout<<"1- Jugar con Apuestas.\n";
		cout<<"2- Jugar sin Apuestas.\n";
		cout<<"0- Volver al menú principal.\n";
		cin>>opcion;
		while(opcion < 0 || opcion > 2){
			cout<<"Seleccione el modo de juego:\n";
			cout<<"1- Jugar con Apuestas.\n";
			cout<<"2- Jugar sin Apuestas.\n";
			cout<<"0- Volver al menú principal.\n";
			cin>>opcion;
		}
		switch(opcion){
			case 0:
				cout<<"\nOk...Saliendo al menú principal.\n";
				volver = true;
				break;
			case 1:
				conApuestas(caballos);
				break;
			case 2:
				break;
			default:
				break;
		}
	}while(!volver);
}

void conApuestas(Caballo *&caballos){
	int cantJugadores = 0, opcion;
	string nombre;
	char op;
	bool volver = false, terminar = false;
	
	Jugador *jugadores = NULL;
	
	do{
		cout<<"Jugar Con Apuestas.\n";
		cout<<"Seleccione la Opcion que desea:\n";
		cout<<"1- Editar Cantidad y Nombre de Jugadores.\n";
		cout<<"2- Ver todos los jugadores.\n";
		cout<<"3- Crear una Apuesta.\n";
		cout<<"4- Ver todas las Apuestas creadas.\n";
		cout<<"5- Ver las apuestas de un jugador.\n";
		cout<<"0- Salir al Menú Principal.\n";
		cin>>opcion;
		while(opcion < 0 || opcion > 5){
			cout<<"Jugar Con Apuestas.\n";
			cout<<"Seleccione la Opcion que desea:\n";
			cout<<"1- Editar Cantidad y Nombre de Jugadores.\n";
			cout<<"2- Ver todos los jugadores.\n";
			cout<<"3- Crear una Apuesta.\n";
			cout<<"4- Ver todas las Apuestas creadas.\n";
			cout<<"5- Ver las apuestas de un jugador.\n";
			cout<<"0- Salir al Menú Principal.\n";
			cin>>opcion;
		}
		switch(opcion){
			case 1:
				cout<<"Editar Cantidad y Nombre de Jugadores.\n";
				cout<<"Ingrese la cantidad de jugadores con la que desea jugar: ";cin>>cantJugadores;
				while(cantJugadores < 2){
					cout<<"Para poder jugar, deben haber al menos dos jugadares.\n";
					cout<<"Ingrese la cantidad de jugadores con la que desea jugar: ";cin>> cantJugadores;
				}
				
				for(int i=0; i<cantJugadores; i++){
					cout<<"Ingrese el nombre del Jugador "<<i+1<<": "; cin>>nombre;
					cargaLista(jugadores, id, nombre)? id++ : id = id;
				}
				
				break;
			case 2:
				cout<<"Todos los Jugadores:\n";
				mostrarLista(jugadores);
				break;
			case 3:
				do{
					cout<<"Crear una Apuesta.\n";
					cout<<"*Para crear una apuesta, debe conocer el id del jugador que desea apostar, el monto y el id del caballo por el que desea apostar.\n";
					cout<<"¿Desea consultar alguno de estos datos antes de seguir? (S/N)"; cin>>op;
					while((op != 'S' && op != 's') && (op != 'N' && op != 'n')){
						cout<<"¿Desea consultar alguno de estos datos? (S/N)"; cin>>op;
					}
					
					if(op == 's' || op == 'S'){
						do{
							cout<<"Seleccione la sección cuyos datos desea buscar:\n";
							cout<<"1- Jugadores.\n";
							cout<<"2- Caballos.\n";
							cout<<"0- Volver al menú anterior.\n";
							cin>>opcion;
							while(opcion < 0 || opcion > 2){
								cout<<"Seleccione la sección cuyos datos desea buscar:\n";
								cout<<"1- Jugadores.\n";
								cout<<"2- Caballos.\n";
								cout<<"0- Volver al menú anterior.\n";
								cin>>opcion;
							}
							switch(opcion){
								case 0:
									volver = true;
									break;
								case 1:
									cout<<"Todos los Jugadores:\n";
									mostrarLista(jugadores);
									break;
								case 2:
									cout<<"Todos los Caballos:\n";
									mostrarLista(caballos, 1);
									break;
							}
						}while(!volver);
						volver = false;
						
						
					}	
				}while(!terminar);
				
				break;
			case 4:
				break;
			case 5:
				break;
			case 0:
				cout<<"Está seguro de que desea volver al menú principal? (S/N): "; cin>>op;
				while((op != 'S' && op != 's') && (op != 'N' && op != 'n')){
					cout<<"Está seguro de que desea volver al menú principal? (S/N): "; cin>>op;
				}
				if(op != 'S' || op != 's'){
					cout<<"Ok...Volviendo al Menú Principal.\n";
					Sleep(1000);
				}
				break;
			default:
				break;
		}
	}while(!volver);
	
}
void sinApuestas(Caballo *&caballos){
	cout<<"Sin Apuestas.\n";
}
int menuPrincipal(){
	int op;
	cout<<"Seleccione opcion:\n";
	cout<<"1- Jugar.\n";
	cout<<"2- Configuración.\n";
	cout<<"0- Salir.\n";
	cout<<"Opción Seleccionada: ";
	cin>>op;
	while(op < 0 || op > 2){
		cout<<"Seleccione opcion:\n";
		cout<<"1- Jugar.\n";
		cout<<"2- Configuración.\n";
		cout<<"0- Salir.\n";
		cout<<"Opción Seleccionada: ";
		cin>>op;		
	}
	return op;
}





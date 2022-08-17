//@Towel15 - GITHUB

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct Nodo {
	int idJugador = 0;
	string nombre = "";
	int puntajes[50] {0};
	int puntajeTotal = 0;
	Nodo* siguiente = NULL;
	Nodo* anterior = NULL;
};

struct NodoTop {
	int idJugador = 0;
	int puntajeTotal = 0;
	NodoTop* siguiente = NULL;
	NodoTop* anterior = NULL;
};

int i = 0, puntajeGanador = 0;

int generarAleatorio(int, int);
string cargarNombre(int);
int lanzarDados(void);
void cargarLista(Nodo*& , Nodo*& , int, string , int );
void modificarPuntaje(Nodo*, int, int, int);
string buscarNombre(Nodo*, int);
void mostrarLista(Nodo*, int);
void mostrarRonda(Nodo* , int);
void mostrarJugador(Nodo*, int);
void cargarTop(NodoTop*&, NodoTop*&, Nodo*);
void ordenarTop(NodoTop*&);
void mostrarTop(NodoTop*, Nodo*);
void juego(Nodo*&, Nodo*&, int&, int&);
void buscarGanador(Nodo*);
int mostrarMenu(void);
void salirOSeguir(bool&, bool&);
void gotoxy(int, int);

int main(){
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "spanish");

	Nodo* primero  = NULL, *ultimo = NULL;
	NodoTop* topPrimero = NULL, * topUltimo = NULL;

	int cantJugadores = 0, cantRondas = 0;
	bool salir = false, jugar = true;

	do {
		if (jugar) {
			juego(primero, ultimo, cantRondas, cantJugadores);
			system("cls");
			buscarGanador(primero);
			jugar = false;
		}
		system("cls");
		buscarGanador(primero);
		switch (mostrarMenu()) {
			case 1:
				mostrarLista(primero, cantRondas);
				system("pause");
				break;
			case 2:
				mostrarRonda(primero, cantRondas);
				break;
			case 3:
				mostrarJugador(primero, cantRondas);
				break;
			case 4:
				cargarTop(topPrimero, topUltimo, primero);
				ordenarTop(topPrimero);
				mostrarTop(topPrimero, primero);
				break;
			case 5:
				salirOSeguir(salir, jugar);
				break;
		}
	} while (!salir);

	system("pause");
	return 0;
}

int generarAleatorio(int limiteSuperior, int limiteInferior) {
	return rand() % ((limiteSuperior - limiteInferior)) + 1;
}

string cargarNombre(int i) {
	string nombre;
	cout << "|Nombre del jugador " << i << ": ";
	gotoxy(47,5+i);
	cout << "|\n";
	gotoxy(25, 5+i);
	cin >> nombre;
	return nombre;
}

int lanzarDados(void) {
	int puntaje = 0;
	int x = 50;
	int y = 0;

	for (int i = 1; i <= 3; i++) {
		if (i != 1) {
			y = y - 5;
		}
		gotoxy(x, y);
		y++;
		cout << "+----------+\n";
		for (int j = 1; j <= 4;j++) {
			gotoxy(x, y);
			y++;
			cout << "|          |\n";
		}
		gotoxy(x, y);
		cout << "+----------+\n";
		x = x + 14;
	}

	x = 55;
	y = 3;
	for (int i = 0; i < 3; i++) {
		puntaje = puntaje + generarAleatorio(21, 1);
		gotoxy(x,y);
		cout << puntaje;
		x = x + 14;
	}

	return puntaje;
}

void cargarLista(Nodo*& primero, Nodo*& ultimo,int id ,string nombre, int puntaje) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->idJugador = id;
	nuevoNodo->nombre = nombre;
	nuevoNodo->puntajes[0] = nuevoNodo->puntajes[0] + puntaje;
	if (primero == NULL) {
		primero = nuevoNodo;
		nuevoNodo->anterior = NULL;
		nuevoNodo->siguiente = NULL;
		ultimo = primero;
	}
	else {
		ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = ultimo;
		nuevoNodo->siguiente = NULL;
		ultimo = nuevoNodo;
	}
}

void mostrarLista(Nodo* primero, int cantRondas) {
	system("cls");
	int x = 0, y = 1;
	
	Nodo* actual = new Nodo();
	actual = primero;
	if(actual){
		while (actual) {
			cout << "+----------------------------------------------+\n";
			cout << "|                                              |\n";
			cout << "+----------------------------------------------+\n";
			x = 1;
			gotoxy(x, y);
			cout << "Jugador: " << actual->nombre;
			x = 0;
			y = y + 2;
			gotoxy(x, y);
			for (int i = 1; i <= cantRondas; i++) {
				cout << "|                                              |\n";
				cout << "+----------------------------------------------+\n";
				x = 1;
				gotoxy(x, y);
				cout << "Ronda " << i << " Puntaje: " << actual->puntajes[i-1];
				y = y + 2;
			}
			actual = actual->siguiente;
		}
	}
}

void mostrarRonda(Nodo* primero, int cantRondas) {
	int rondaMostrar = 0;
	cout << "Ingrese la ronda cuyos puntajes desea mostrar: "; cin >> rondaMostrar;
	while (rondaMostrar > cantRondas) {
		cout << "Error. No se pueden mostrar puntajes de una ronda que no se jugó.\nVuelva a intentar.\n";
		cout << "Ingrese la ronda cuyos puntajes desea mostrar: "; cin >> rondaMostrar;
	}

	Nodo* actual = new Nodo();
	actual = primero;
	
	for (int i = 1; i <= cantRondas; i++) {
		cout << "+----------------+----------------+----------------+";
		cout << "|                |                |                |";
		cout << "+----------------+----------------+----------------";
	}

	system("cls");
	if (actual) {
		cout << "Ronda: " << rondaMostrar<<"\n";
		while (actual) {
			cout << "\tJugador: " << actual->nombre << "\n";
			cout << "\tPuntaje: " << actual->puntajes[rondaMostrar] << ".\n";
			actual = actual->siguiente;
		}
	}
}

void mostrarJugador(Nodo* primero, int cantRondas) {
	string jugadorMostrar = cargarNombre(1);

	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	system("cls");
	if (actual) {
		cout << "Jugador: " << jugadorMostrar<< "\n";
		while (actual && !encontrado) {
			if (actual->nombre == jugadorMostrar) {
				for (int i = 0; i < cantRondas; i++) {
					cout << "Ronda " << i + 1 << " Puntaje: " << actual->puntajes[i] << ".\n";
				}
				cout << "El Puntaje Total de " << actual->nombre << " es: " << actual->puntajeTotal << "\n";
				encontrado = true;
			}
			else {
				actual = actual->siguiente;
			}
		}
	}
	if (!encontrado) {
		cout << "No se ha encontrado a ningún jugador con ese nombre.\n";
	}
}

void cargarTop(NodoTop *&topPrimero, NodoTop *&topUltimo, Nodo* primero) {
	Nodo* actual = new Nodo();
	actual = primero;

	if (actual) {
		while (actual) {
			NodoTop* nuevoNodo = new NodoTop();
			nuevoNodo->idJugador = actual->idJugador;
			nuevoNodo->puntajeTotal = actual->puntajeTotal;
			if (topPrimero == NULL) {
				topPrimero = nuevoNodo;
				nuevoNodo->anterior = NULL;
				nuevoNodo->siguiente = NULL;
				topUltimo = topPrimero;
			}
			else {
				topUltimo->siguiente = nuevoNodo;
				nuevoNodo->anterior = topUltimo;
				nuevoNodo->siguiente = NULL;
				topUltimo = nuevoNodo;
			}
			actual = actual->siguiente;
		}
	}
}

void ordenarTop(NodoTop *&topPrimero) {
	NodoTop* actual = new NodoTop(), * aux = new NodoTop();
	actual = topPrimero;
	if (actual) {
		while (actual) {
			if (actual->siguiente) {
				if (actual->puntajeTotal < actual->siguiente->puntajeTotal) {
					aux = actual;
					
					actual->idJugador = actual->siguiente->idJugador;
					actual->puntajeTotal = actual->siguiente->puntajeTotal;

					actual->siguiente->idJugador = aux->idJugador;
					actual->siguiente->puntajeTotal = aux->puntajeTotal;
				}
				actual = actual->siguiente;
			}
			else {
				actual = actual->siguiente;
			}
		}
	}
}

void mostrarTop(NodoTop* topPrimero, Nodo *primero) {
	NodoTop* actual = new NodoTop();
	actual = topPrimero;

	if (actual) {
		while (actual) {
				cout << "Jugador: " << buscarNombre(primero, actual->idJugador) << "\n";
				cout << "Puntaje: " << actual->puntajeTotal << "\n";
			actual = actual->siguiente;
		}
	}
}

void modificarPuntaje(Nodo* primero, int id, int puntajeRonda, int rondaActual) {
	Nodo* actual = new Nodo();
	bool encontrado = false;
	actual = primero;
	if (actual != NULL) {
		while (actual != NULL && !encontrado) {
			if (actual->idJugador == id) {
				encontrado = true;
				actual->puntajes[(rondaActual-1)] = actual->puntajes[(rondaActual - 1)] + puntajeRonda;
				actual->puntajeTotal = actual->puntajeTotal + actual->puntajes[(rondaActual - 1)];
			}
			else {
				actual = actual->siguiente;
			}
		}
	}
	if (!encontrado) {
		cout << "No se ha encontrado a ese jugador.\n";
	}
}

string buscarNombre(Nodo* primero, int idJugador) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	if (actual) {
		while (actual && !encontrado) {
			if (actual->idJugador == idJugador) {
				encontrado = true;
				return actual->nombre;
			}
			else {
				actual = actual->siguiente;
			}
		}
	}
	if (!encontrado) {
		return "No hay nombre.";
	}
}

void juego(Nodo*&primero, Nodo*&ultimo, int& cantRondas, int& cantJugadores) {
	system("cls");
	cout << "+----------------------------------------------+\n";
	cout << "|";
	gotoxy(17, 1);
	cout << "JUEGO DEL DADO";
	gotoxy(47,1);
	cout << "|\n";
	cout << "+----------------------------------------------+\n";
	cout << "|Cantidad de rondas que desean jugar: "; 
	gotoxy(47, 3);
	cout << "|\n";
	gotoxy(40, 3);
	cin >> cantRondas;
	while (cantRondas <= 0 || cantRondas > 50) {
		cout << "El rango de rondas simulables es de 1 a 50.\nVuelva a intentar.\n";
		cout << "Ingrese la cantidad de rondas que desean jugar: "; cin >> cantRondas;
	}
	cout << "+----------------------------------------------+\n";
	cout << "|Cantidad de jugadores: ";
	gotoxy(47, 5);
	cout << "|\n";
	gotoxy(24, 5);
	cin >> cantJugadores;
	while (cantJugadores < 2) {
		cout << "Error. Deben haber al menos 2 jugadores!.\n";
		cout << "Ingrese la cantidad de jugadores: "; cin >> cantJugadores;
	}

	for (int i = 1; i <= cantJugadores; i++) {
		cargarLista(primero, ultimo, i, cargarNombre(i), 0);
	}

	for (int i = 1; i <= cantRondas; i++) {
		system("cls");
		cout << "+----------------------------------------------+\n";
		cout << "|                                              |\n";
		cout << "+----------------------------------------------+\n";
		gotoxy(1, 1);
		cout << "Ronda:                                    " << i;
		for (int j = 1; j <= cantJugadores; j++) {
			if (j == 1) {
				gotoxy(0,3*j);
			}
			else {
				gotoxy(0, (3 * j - (j - 1)));
			}
			cout << "|                                              |\n";
			cout << "+----------------------------------------------+\n";
		}
		for (int j = 1; j <= cantJugadores; j++) {
			if (j == 1) {
				gotoxy(1, 3 * j);
			}
			else {
				gotoxy(1, (3 * j - (j -1)));
			}
			cout << "Jugador " << j << " lanza los dados...";
			int puntajeRonda = 0;
			puntajeRonda = lanzarDados();
			Sleep(1000);
			modificarPuntaje(primero, j, puntajeRonda, i);
		}
	}
}

void buscarGanador(Nodo* primero) {
	Nodo* actual = new Nodo();
	actual = primero;
	if (actual != NULL) {
		while (actual != NULL) {
			if (i == 0) {
				puntajeGanador = actual->puntajeTotal;
				i++;
			}
			else if (actual->puntajeTotal > puntajeGanador) {
				puntajeGanador = actual->puntajeTotal;
				i++;
			}
			actual = actual->siguiente;
		}
	}
	gotoxy(55, 0);
	cout << "+----------------------------------------------+\n";
	gotoxy(55, 1);
	cout << "|El ganador es: " << buscarNombre(primero, (i));
	gotoxy(102, 1);
	cout << "|\n";
	gotoxy(55, 2);
	cout << "|Su puntaje es: " << puntajeGanador;
	gotoxy(102, 2);
	cout << "|\n";
	gotoxy(55, 3);
	cout << "+----------------------------------------------+\n";
}

int mostrarMenu(void) {
	int opcion;
	gotoxy(0,0);
	cout << "Seleccione la opción que desea ejecutar:\n";
	cout << "1- Ver Puntajes.\n";
	cout << "2- Consultar Puntajes por Ronda Específica.\n";
	cout << "3- Consultar Puntajes de un Jugador.\n";
	cout << "4- Consultar Top de Puntajes Finales.\n";
	cout << "5- Salir del Programa o Volver a Jugar.\n";
	cout << "Opción: "; cin >> opcion;
	while (opcion < 1 || opcion > 5) {
		cout << "Seleccione la opción que desea ejecutar: ";
		cout << "1- Ver Puntajes.\n";
		cout << "2- Consultar Puntajes por Ronda Específica.\n";
		cout << "3- Consultar Puntajes de un Jugador.\n";
		cout << "4- Consultar Top de Puntajes Finales.\n";
		cout << "5- Salir del Programa o Volver a Jugar.\n";
		cout << "Opción: "; cin >> opcion;
	}
	return opcion;
}

void salirOSeguir(bool&salir, bool&jugar) {
	int opcion = 0;
	cout << "Seleccione la opción que desea:\n";
	cout << "1- Salir.\n";
	cout << "2- Volver a Jugar.\n";
	cout << "Opción: "; cin >> opcion;
	while (opcion < 1 || opcion > 2) {
		cout << "Error. Debe seleccionar una de las opciones disponibles.\n";
		cout << "Seleccione la opción que desea:\n";
		cout << "1- Salir.\n";
		cout << "2- Volver a Jugar.\n";
		cout << "Opción: "; cin >> opcion;
	}
	if (opcion == 1) {
		salir = true;
		jugar = false;
	}
	else {
		jugar = true;
	}
}

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posCursor;
	posCursor.X = x;
	posCursor.Y = y;
	SetConsoleCursorPosition(hcon, posCursor);
}

/*
Crear un juego que permita simular el lanzamiento de 3 dados de 20 caras cada uno entre
cierta cantidad de participantes, para ello, tener en cuenta los siguientes puntos:
- Al iniciar el programa debe pedir los siguientes datos:
- Cantidad de rondas para el juego
- Cantidad de jugadores
- Nombres de cada participante (Como mínimo 2 participantes)
- El juego va a consistir en realizar los lanzamientos de cada participante de acuerdo a
la cantidad de rondas establecidas, siendo el ganador, aquel que sume más puntos en
todas las rondas.
Al culminar, el programa debe mostrar al ganador con el puntaje que ha obtenido, además del
siguiente menú para consultar los datos a continuación:
- Vista general de puntajes (donde aparecerán, el nro. de lanzamiento, nombre y puntaje
de todas las rondas)
- Consulta de puntajes obtenidos por ronda especifica (donde se debe ingresar el
número de ronda para visualizar el puntaje de cada lanzador en esa ronda especifica)
- Consulta de puntajes por jugador (donde ingresando el nombre del jugador se podrá
visualizar los lanzamientos realizados en todas las rondas).
- Consulta del top de puntajes finales (Donde se visualizará la tabla de resultados de
mayor a menor puntaje).
- Salir o Volver a Jugar.
*/
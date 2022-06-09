//@Towel15 - GITHUB

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <string>
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
void mostrarTop(Nodo*, int, int);
void buscarGanador(Nodo*);
int mostrarMenu(void);

int main(){
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "spanish");

	Nodo* primero = NULL, *ultimo = NULL;

	int cantJugadores = 0, cantRondas = 0;
	bool salir = false;

	cout << "Juego del Dado\n";
	cout << "Ingrese la cantidad de rondas que desean jugar: "; cin >> cantRondas;
	while (cantRondas <= 0 || cantRondas > 50){
		cout << "El rango de rondas simulables es de 1 a 50.\nVuelva a intentar.\n";
		cout << "Ingrese la cantidad de rondas que desean jugar: "; cin >> cantRondas;
	}	

	cout << "Ingrese la cantidad de jugadores: "; cin >> cantJugadores;
	while (cantJugadores < 2) {
		cout << "Error. Deben haber al menos 2 jugadores!.\n";
		cout << "Ingrese la cantidad de jugadores: "; cin >> cantJugadores;
	}
	
	for (int i = 1; i <= cantJugadores; i++) {
		cargarLista(primero, ultimo, i, cargarNombre(i), 0);
	}

	for (int i = 1; i <= cantRondas; i++) {
		system("cls");
		cout << "Ronda " << i << ".\n";
		for (int j = 1; j <= cantJugadores; j++) {
			cout << "Jugador " << j << " lanza los dados...\n";
			int puntajeRonda = 0;
			puntajeRonda = lanzarDados();
			modificarPuntaje(primero, j, puntajeRonda, i);
			cout << "El jugador " << buscarNombre(primero, j)<< " ha sumado: " << puntajeRonda << " puntos en esta ronda.\n";
		}
	}

	system("cls");
	buscarGanador(primero);
	switch (mostrarMenu()) {
		case 1:
			mostrarLista(primero, cantRondas);
			break;
		case 2:
			mostrarRonda(primero, cantRondas);
			break;
		case 3:
			mostrarJugador(primero, cantRondas);
			break;
		case 4:
			mostrarTop(primero, cantRondas, cantJugadores);
			break;
		case 5:
			break;
	}

	system("pause");
	return 0;
}

int generarAleatorio(int limiteSuperior, int limiteInferior) {
	return rand() % ((limiteSuperior - limiteInferior)) + 1;
}

string cargarNombre(int i) {
	string nombre;
	cout << "Ingrese nombre del jugador " << i << ": "; cin >> nombre;
	return nombre;
}

int lanzarDados(void) {
	int puntaje = 0;
	for (int i = 0; i < 3; i++) {
		puntaje = puntaje + generarAleatorio(21, 1);
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
	Nodo* actual = new Nodo();
	actual = primero;
	if(actual){
		while (actual) {
			cout << "Jugador: " << actual->nombre<<"\n";
			for (int i = 0; i < cantRondas; i++) {
				cout << "Ronda " << i+1 << " Puntaje: " << actual->puntajes[i] << ".\n";
			}
			cout << "El Puntaje Total de "<<actual->nombre<<" es: " << actual->puntajeTotal<<"\n";
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

void mostrarTop(Nodo* primero, int cantRondas, int cantJugadores) {
	cout << "Top Puntajes.\n";
	int i = 0;
	int topPuntajes[5] {0};
	bool ordenado = false;
	Nodo* actual = new Nodo();
	actual = primero;
	if (actual) {
		i = 0;
		do {
			actual = primero;
			while (actual) {
				if (actual->siguiente != NULL) {
					if (actual->puntajeTotal > actual->siguiente->puntajeTotal) {
						topPuntajes[i] = actual->siguiente->puntajeTotal;
						i++;
					}

				}
				//cout << "Jugador: " << actual->nombre << "\n";
				//cout << "El Puntaje Total de " << actual->nombre << " es: " << actual->puntajeTotal << "\n";
				actual = actual->siguiente;
			}
			for (int j = 0; j < cantJugadores; j++) {
				if (topPuntajes[j] > topPuntajes[j + 1]);
			}
		} while(!ordenado);
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
	cout << "El ganador es: " << buscarNombre(primero, (i))<<"\n";
	cout << "Su puntaje es: " << puntajeGanador << "\n";
}

int mostrarMenu(void) {
	int opcion;
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
//pablog14 - GITHUB

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int generarAleatorio(int, int);

struct Caballo {
	int idCaballo = 0;
	int margenGanancia = generarAleatorio(100, 1);
} *Caballos = new Caballo[5];

struct Apuesta {
	int idApuesta = 0;
	int idJugadorApuesta = 0;
	int idCaballoApuesta = 0;
	int montoApuesta = 0;
	Apuesta* siguiente = NULL;
};

struct Jugador {
	int idJugador = 0;
	string nombreJugador = "";
	int cantidadApuestas = 0;
};

void registrarApuesta(Caballo*, Jugador*, int, Apuesta*&);
void mostrarLista(Apuesta*);
void mostrarNodo(Apuesta*);
void cargarLista(Apuesta*&, int, int, int, int);
void consultarApuestasJugadores(Apuesta*);
void totalApuestas(Apuesta*);
void consultarApuestasCaballos(Apuesta*, Caballo*);
void pagadoPorApuestas(Apuesta*);

int idApuesta = 0;

int main() {
	setlocale(LC_ALL, "spanish");

	Apuesta *lista = NULL;
	char op = 'n';
	int opcion = 0, opcionSeleccionada = 0, cantJugadores = 0, jugadorActual = 0;
	bool salir = false, jugar = true;

	do {
		cout << "Simulador de Corrida de Caballos.\n";
		cout << "Ingrese la cantidad de jugadores: ";cin >> cantJugadores;
		Jugador *Jugadores = new Jugador[cantJugadores];

		do {
			cout << "¿Desea Apostar?(S/N): "; cin >> op;
			
			if (op == 's' || op == 'S') {
				cout << "Seleccione el jugador que desee:\n";
				for (int i = 0; i < cantJugadores; i++) {
					cout << i + 1 << "- Jugador " << i + 1 << ".\n";
					Jugadores[i].idJugador = i;
				}
				cout << "Jugador: ";cin >> jugadorActual;
				while (jugadorActual < 1 || jugadorActual > cantJugadores) {
					cout << "La opción seleccionada no se encuentra en el rango adminitido.\n";
					cout << "Jugador: ";cin >> jugadorActual;
				}
				registrarApuesta(Caballos, Jugadores, jugadorActual, lista);
			}
		} while (op == 's' || op == 'S');


		
		system("cls");
		cout << "Seleccione la opcion que desea ejecutar:\n";
		cout << "1- Vista general de apuestas\n";
		cout << "2- Consulta de apuestas por caballo\n";
		cout << "3- Consulta de apuesta por usuario\n";
		cout << "4- Vista de Resumen.\n";
		cout << "5- Salir del programa o Volver a Correr\n";
		cout << "Opción: ";cin >> opcion;
		while (opcion < 1 || opcion > 5) {
			cout << "Error.\nEl número ingresado no se encuentra en el rango permitido.\n";
			cout << "Seleccione la opcion que desea ejecutar:\n";
			cout << "1- Vista general de apuestas\n";
			cout << "2- Consulta de apuestas por caballo\n";
			cout << "3- Consulta de apuesta por usuario\n";
			cout << "4- Vista de Resumen.\n";
			cout << "5- Salir del programa o Volver a Correr\n";
			cout << "Opción: ";cin >> opcion;
		}
	
		switch (opcion) {
		case 1:
			mostrarLista(lista);
			break;
		case 2:
			consultarApuestasCaballos(lista, Caballos);
			break;
		case 3:
			consultarApuestasJugadores(lista);
			break;
		case 4:
			totalApuestas(lista);
			break;
		case 5:
			pagadoPorApuestas(lista);
			break;
		case 6:
			cout << "¿Desea Salir del Programa o Volver a Jugar?";
			cout << "1- Salir.\n";
			cout << "2- Volver a Jugar.\n";
			cout << "Opción Seleccionada: ";
			while (opcionSeleccionada < 1 || opcionSeleccionada > 2) {
				cout << "La opción seleccionada no se encuentra en el rango admitido.\n";
				cout << "¿Desea Salir del Programa o Volver a Jugar?";
				cout << "1- Salir.\n";
				cout << "2- Volver a Jugar.\n";
				cout << "Opción Seleccionada: ";
			}
			if (opcionSeleccionada == 1) {
				cout << "Gracias por utilizar el programa.\n";
				salir = true;
			}
			else {
				cout << "Ok...Se volvera a la pantalla del juego.\n";
				jugar = true;
			}
		default:
			cout << "Error General. Vuelva a intentar por favor.\n";
			break;
		}
	} while (!salir);
}

int generarAleatorio(int ls, int li) {
	return (rand() % (ls - li) + li);
}

void registrarApuesta(Caballo *Caballos, Jugador *Jugadores, int jugadorActual,Apuesta *&lista) {
	system("cls");
	int caballoSeleccionado = 0, montoApuesta = 0;
	string nombreJugador = "";
	
	cout << "Seleccione el caballo por el que desea apostar:\n";
	for (int i = 0; i < 5; i++) {
		cout << "Caballo " << i + 1 << ": ";
		Caballos[i].idCaballo = i;
		cout << "\tMargen de Ganancia: " << Caballos[i].margenGanancia<<"\n";
	}
	cout << "Caballo Seleccionado: ";cin >> caballoSeleccionado;
	while (caballoSeleccionado < 1 || caballoSeleccionado > 5) {
		cout << "El número ingresado no se encuentra en el rango permitido.\n";
		cout << "Caballo Seleccionado: ";cin >> caballoSeleccionado;
	}
	cin.ignore();
	cin.clear();

	cout << "Ingrese el Monto de la Apuesta: "; cin >> montoApuesta;
	while (montoApuesta <= 0) {
		cout << "Error.\nLa apuesta debe ser mayor a cero.\n";
		cout << "Ingrese el Monto de la Apuesta: "; cin >> montoApuesta;
	}

	cargarLista(lista, idApuesta, Jugadores[jugadorActual].idJugador, caballoSeleccionado, montoApuesta);
	idApuesta++;
}

void cargarLista(Apuesta*& lista, int idApuesta, int idJugador, int idCaballoApuesta, int montoApuesta) {
	Apuesta* nuevaApuesta = new Apuesta();
	Apuesta* aux1 = lista;
	Apuesta* aux2 = new Apuesta();
	nuevaApuesta->idApuesta = idApuesta;
	nuevaApuesta->idJugadorApuesta = idJugador;
	nuevaApuesta->idCaballoApuesta = idCaballoApuesta;
	nuevaApuesta->montoApuesta = montoApuesta;
	while (aux1) {
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if (aux1 == lista) {
		lista = nuevaApuesta;
	}
	else {
		aux2->siguiente = nuevaApuesta;
	}
	nuevaApuesta->siguiente = aux1;
}

void mostrarNodo(Apuesta* actual) {
	cout << "Apostador: " << actual->idJugadorApuesta << "\n";
	cout << "Caballo por el que apostó: " << Caballos[actual->idCaballoApuesta].idCaballo << "\n";
	cout << "Monto de la Apuesta: "<<actual->montoApuesta<<"\n";
	cout << "Multiplicador: " << Caballos[actual->idCaballoApuesta].margenGanancia << "\n";
	cout << "Monto Ganado: " << actual->montoApuesta * Caballos[actual->idCaballoApuesta].margenGanancia << "\n";
}

void mostrarLista(Apuesta *lista) {
	Apuesta* actual = lista;
	if (actual) {
		mostrarNodo(actual);
		actual = actual->siguiente;
	}else {
		cout << "La lista no se encuentra cargada con ningún registro. Ingrese al menos un registro y vuelva a intentarlo.\n";
	}
}

void consultarApuestasCaballos(Apuesta *lista, Caballo *Caballos) {
	//Apuestas por Caballo
	Apuesta* actual = lista;
	int i = 0, encontrados = 0;
	cout << "Consulta de Apuestas por Caballo.\n";
	if (actual) {
		do {
			while (actual) {
				cout << "Caballo: " << Caballos[i].idCaballo + 1 << "\n";
				if (actual->idCaballoApuesta == Caballos[i].idCaballo) {
					cout << "\tJugador: " << actual->idJugadorApuesta << "\n";
					cout << "\tApuesta: " << actual->montoApuesta << "\n";
					encontrados++;
				}
			}
			if (encontrados == 0) {
				cout << "El caballo no tiene apuestas\n";
			}
			actual = lista;
			encontrados = 0;
		} while (i < 5);
	}
	else {
		cout << "La lista no se encuentra cargada con ningún registro. Ingrese al menos un registro y vuelva a intentarlo.\n";
	}
}

void consultarApuestasJugadores(Apuesta* lista) {
	//Consulta de Apuestas por Jugador
	Apuesta* actual = lista;
	cout << "Consulta de Apuestas de Cada Jugador.\n";
	if (actual) {
		while (actual) {
			cout << "Jugador: " << actual->idJugadorApuesta << "\n";
			cout << "\tCaballo por el que Apostó: " << actual->idCaballoApuesta + 1 << "\n";
			cout << "\tMonto Apostado: " << actual->montoApuesta << "\n";
		}
	}else {
		cout << "La lista no se encuentra cargada con ningún registro. Ingrese al menos un registro y vuelva a intentarlo.\n";
	}
}

void totalApuestas(Apuesta *lista) {
	Apuesta* actual = lista;
	int montoTotal = 0;
	if (actual) {
		while (actual) {
			montoTotal = montoTotal + actual->montoApuesta;
			actual = actual->siguiente;
		}
	}else{
		cout << "La lista no se encuentra cargada con ningún registro. Ingrese al menos un registro y vuelva a intentarlo.\n";
	}
	cout << "El monto total recaudado con la corrida es: " << montoTotal << "\n";
}

void pagadoPorApuestas(Apuesta* lista) {
	Apuesta* actual = lista;
	int totalPagado = 0;
	if (actual) {
		while (actual) {
			totalPagado = totalPagado + actual->montoApuesta;
			actual = actual->siguiente;
		}
	}
	else {
		cout << "La lista no se encuentra cargada con ningún registro. Ingrese al menos un registro y vuelva a intentarlo.\n";
	}
}

/*
 Crear un juego que simule una corrida entre 5 caballos, donde se tendrán en cuenta los
siguientes puntos:
- En el programa se debe visualizar la pista y simular la corrida utilizando cualquier
carácter para representar a los caballos.
- El programa debe permitir realizar una lista de apuestas donde se deberá registrar el
nombre del jugador, nombre o número del caballo, monto a apostar.
- Cada caballo debe tener un margen de ganancia por apuesta, es decir, al iniciar el
programa se debe ingresar cuanto pagará cada caballo en caso de ganar.
Finalmente, al terminar la corrida, se debe mostrar al caballo ganador y el top de
posiciones de los caballos participantes. Además, un menú con los siguientes parámetros:
- Vista general de apuestas
- Consulta de apuestas por caballo
- Consulta de apuesta por usuario
- Vista de resumen, donde se deberá mostrar:
- Total, recaudado por la corrida
- Total, pagado en concepto de apuesta a ganadores
- Salir del programa o volver a correr
Consideraciones para el juego:
- Utilizar la función gotoxy para mostrar el lanzamiento de los datos y dar el efecto de un
lanzamiento real o de la corrida de caballos.
- Utilizar la función Sleep() para manejar la temporización del programa y dar un mejor
efecto al lanzamiento realizado o corrida. Ejemplo: Sleep(200);
- Se debe tener en cuenta que en el ejercicio se deberá usa más de una estructura en
forma independiente para cada entidad (jugador, puntajes, etc.)
- La creatividad de cada programador será valorada en el ejercicio.
*/
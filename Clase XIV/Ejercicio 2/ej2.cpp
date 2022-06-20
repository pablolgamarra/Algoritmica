//pablog14 - GITHUB

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

int generarAleatorio(int, int);

struct Caballo {
	int idCaballo = 0;
	int margenGanancia = generarAleatorio(100, 1);
	int posicionFinal = 0;
} *Caballos = new Caballo[5];

struct Apuesta {
	int idApuesta = 0;
	int idJugadorApuesta = 0;
	int idCaballoApuesta = 0;
	int montoApuesta = 0;
	bool apuestaGanada = false;
	Apuesta* siguiente = NULL;
};

struct Jugador {
	int idJugador = 0;
	string nombreJugador = "";
};

void gotoxy(int, int);
void corrida(Caballo *);
void buscarGanador(Caballo*);
void mostrarTop(Caballo*);
void registrarApuesta(Caballo*, Jugador*, int, Apuesta*&);
void mostrarLista(Apuesta*, Jugador*);
void mostrarNodo(Apuesta*, Jugador*);
void cargarLista(Apuesta*&, int, int, int, int);
void consultarApuestasJugadores(Apuesta*);
void totalApuestas(Apuesta*);
void consultarApuestasCaballos(Apuesta*, Caballo*);
void pagadoPorApuestas(Apuesta*);
int menu(void);
bool tieneNumero(string);
bool errorDeCarga(void);

int idApuesta = 0, idCaballoGanador;

int main() {
	setlocale(LC_ALL, "spanish");
	srand((unsigned) time(NULL));

	Apuesta *lista = NULL;
	char op = 'n';
	int opcion = 0, opcionSeleccionada = 0, cantJugadores = 0, jugadorActual = 0;
	bool salir = false, jugar = true;

	do {
		system("cls");
		cout << "Simulador de Corrida de Caballos.\n";
		do {
			cout << "Ingrese la cantidad de jugadores: ";cin >> cantJugadores;
		} while (errorDeCarga());
		Jugador *Jugadores = new Jugador[cantJugadores];

		for (int i = 0; i < cantJugadores; i++) {
			do {
				Jugadores[i].idJugador = i;
				cout << "Ingrese nombre del Jugador " << i + 1 << ": "; cin >> Jugadores[i].nombreJugador;
			} while (tieneNumero(Jugadores[i].nombreJugador) || errorDeCarga());
		}
		
		for (int i = 0; i < 5; i++) {
			Caballos[i].idCaballo = i;
		} 

		do {
			system("cls");
			do {
				cout << "¿Desea Apostar?(S/N): "; cin >> op;
			} while (errorDeCarga());
			
			if (op == 's' || op == 'S') {
				system("cls");
				cout << "Seleccione el jugador que desee:\n";
				for (int i = 0; i < cantJugadores; i++) {
					cout << i + 1 << " " << Jugadores[i].nombreJugador << ".\n";
				}
				do {
					cout << "Jugador: "; cin >> jugadorActual;
					while (jugadorActual < 1 || jugadorActual > cantJugadores) {
						cout << "La opción seleccionada no se encuentra en el rango adminitido.\n";
						cout << "Jugador: "; cin >> jugadorActual;
					}
				} while (errorDeCarga());

				registrarApuesta(Caballos, Jugadores, jugadorActual-1, lista);
			}
		} while (op == 's' || op == 'S');

		corrida(Caballos);
		mostrarTop(Caballos);
		system("pause");
	
		do {
			system("cls");
			jugar = false;
			switch (menu()) {
			case 1:
				if (lista) {
					mostrarLista(lista, Jugadores);
				} else {
					cout << "No se registró ninguna apuesta. Vuelva a jugar y reintente.\n";
				}
				break;
			case 2:
				if (lista) {
					consultarApuestasCaballos(lista, Caballos);
				} else {
					cout << "No se registró ninguna apuesta. Vuelva a jugar y reintente.\n";
				}
				break;
			case 3:
				if (lista) {
					consultarApuestasJugadores(lista);
				} else {
					cout << "No se registró ninguna apuesta. Vuelva a jugar y reintente.\n";
				}
				break;
			case 4:
				if (lista) {
					totalApuestas(lista);
					pagadoPorApuestas(lista);
				} else {
					cout << "No se registró ninguna apuesta. Vuelva a jugar y reintente.\n";
				}

				break;
			case 5:
				cout << "¿Desea Salir del Programa o Volver a Jugar?\n";
				cout << "1- Salir.\n";
				cout << "2- Volver a Jugar.\n";
				cout << "Opción Seleccionada: "; cin >> opcionSeleccionada;
				while (opcionSeleccionada < 1 || opcionSeleccionada > 2) {
					cout << "La opción seleccionada no se encuentra en el rango admitido.\n";
					cout << "¿Desea Salir del Programa o Volver a Jugar?\n";
					cout << "1- Salir.\n";
					cout << "2- Volver a Jugar.\n";
					cout << "Opción Seleccionada: "; cin >> opcionSeleccionada;
				}
				if (opcionSeleccionada == 1) {
					cout << "Gracias por utilizar el programa.\n";
					salir = true;
					jugar = true;
				}
				else {
					cout << "Ok...Se volvera a la pantalla del juego.\n";
					jugar = true;
				}
				break;
			default:
				cout << "Error General. Vuelva a intentar por favor.\n";
				break;
			}
			cout << "Presione una tecla para seguir...\n";
			_getch();
		} while (!salir && !jugar);
	} while (!salir);
}

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posCursor;
	posCursor.X = x;
	posCursor.Y = y;
	SetConsoleCursorPosition(hcon, posCursor);
}

int generarAleatorio(int ls, int li) {
	return (rand() % (ls - li) + li);
}

void corrida(Caballo* Caballos) {
	system("cls");
	cout << "Corrida...\n";
	cout << "+-------------------------------------------------+\n";
	cout << "|                                                 |\n";
	cout << "+-------------------------------------------------+\n";
	cout << "|                                                 |\n";
	cout << "+-------------------------------------------------+\n";
	cout << "|                                                 |\n";
	cout << "+-------------------------------------------------+\n";
	cout << "|                                                 |\n";
	cout << "+-------------------------------------------------+\n";
	cout << "|                                                 |\n";
	cout << "+-------------------------------------------------+\n";

	int x = 1, y = 2;

	for (int i = 0; i < 5; i++) {
		gotoxy(x, y);
		cout << i+1;
		y = y + 2;
	}

	cout << "\n\n";
	cout << "Presione una tecla para iniciar la corrida...\n";
	_getch();

	x = 1, y = 2;
	int n = 1;
	bool limiteAlcanzado = false;
	int posActual[5] = { 0,0,0,0,0 };

	do {
		n = generarAleatorio(5, 0);
		posActual[n] = posActual[n] + 1;
		switch (n) {
		case 0:
			y = 2;
			x = posActual[n];
			gotoxy(x, y);
			cout << " ";
			x++;
			gotoxy(x, y);
			cout << "1";
			Sleep(100);
			break;
		case 1:
			y = 4;
			x = posActual[n];
			gotoxy(x, y);
			cout << " ";
			x++;
			gotoxy(x, y);
			cout << "2";
			Sleep(100);
			break;
		case 2:
			y = 6;
			x = posActual[n];
			gotoxy(x, y);
			cout << " ";
			x++;
			gotoxy(x, y);
			cout << "3";
			Sleep(100);
			break;
		case 3:
			y = 8;
			x = posActual[n];
			gotoxy(x, y);
			cout << " ";
			x++;
			gotoxy(x, y);
			cout << "4";
			Sleep(100);
			break;
		case 4:
			y = 10;
			x = posActual[n];
			gotoxy(x, y);
			cout << " ";
			x++;
			gotoxy(x, y);
			cout << "5";
			Sleep(100);
			break;
		default:
			gotoxy(60, 0);
			cout << "ERROR EN ALEATORIO KPP..."<<n<<"\n";
			break;
		}
		if (posActual[n] == 49) {
			limiteAlcanzado = true;
		}
		Caballos[n].posicionFinal = posActual[n];
	} while (!limiteAlcanzado);

	gotoxy(0, 13);
	buscarGanador(Caballos);
	cout << "El Caballo: " << idCaballoGanador+1 << " ha ganado.\n";
	system("pause");
}

void buscarGanador(Caballo* Caballos) {
	int mayorPosicion = 0;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			mayorPosicion = Caballos[i].posicionFinal;
			idCaballoGanador = Caballos[i].idCaballo;
		} else if (Caballos[i].posicionFinal > mayorPosicion) {
			mayorPosicion = Caballos[i].posicionFinal;
			idCaballoGanador = Caballos[i].idCaballo;
		}
	}
}

void mostrarTop(Caballo* Caballos) {
	Caballo* aux = Caballos;
	Caballo* aux2 = new Caballo();
	bool desordenado = true;
	for (int i = 0; i <= 4; i++) {
		for (int i = 0; i <= 4; i++) {
			if (Caballos[i].posicionFinal < Caballos[i + 1].posicionFinal) {
				*aux2 = aux[i];
				aux[i] = aux[i + 1];
				aux[i + 1] = *aux2;
			}
		}
	}

	cout << "Top de Posiciones\n";
	for (int i = 0; i < 5; i++) {
		cout << "\tCaballo " << aux[i].idCaballo + 1 << "\n";
	}
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

	cargarLista(lista, idApuesta, Jugadores[jugadorActual].idJugador, caballoSeleccionado-1, montoApuesta);
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

void mostrarNodo(Apuesta* actual, Jugador* Jugadores) {
	cout << "Apostador: " << Jugadores[actual->idJugadorApuesta].nombreJugador << "\n";
	cout << "\tCaballo por el que apostó: " << actual->idCaballoApuesta + 1<< "\n";
	cout << "\tMonto de la Apuesta: "<<actual->montoApuesta<<"\n";
	cout << "\tMargen de Ganancia del Caballo: " << Caballos[actual->idCaballoApuesta].margenGanancia << "\n";
	if (actual->idCaballoApuesta == idCaballoGanador) {
		actual->apuestaGanada = true;
		cout << "\tLa Apuesta fue ganada.\n";
		cout << "\tMonto Ganado: " << actual->montoApuesta * Caballos[actual->idCaballoApuesta].margenGanancia << "\n";
	}
}

void mostrarLista(Apuesta* lista, Jugador* Jugadores) {
	Apuesta* actual = lista;
	if (actual) {
		cout << "Apuestas Registradas:\n";
		while (actual) {
			mostrarNodo(actual, Jugadores);
			actual = actual->siguiente;
		}
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
			cout << "Caballo: " << Caballos[i].idCaballo + 1 << "\n";
			while (actual) {
				if (actual->idCaballoApuesta == Caballos[i].idCaballo) {
					cout << "\tJugador: " << actual->idJugadorApuesta << "\n";
					cout << "\tApuesta: " << actual->montoApuesta << "\n";
					encontrados++;
				}
				actual = actual->siguiente;
			}
			if (encontrados == 0) {
				cout << "\tEl caballo no tiene apuestas\n";
			}
			actual = lista;
			encontrados = 0;
			i++;
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
			cout << "Jugador: " << actual->idJugadorApuesta + 1  << "\n";
			cout << "\tCaballo por el que Apostó: " << actual->idCaballoApuesta + 1 << "\n";
			cout << "\tMonto Apostado: " << actual->montoApuesta << "\n";
			actual = actual->siguiente;
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
			if (actual->apuestaGanada) {
				totalPagado = totalPagado + actual->montoApuesta * Caballos[actual->idCaballoApuesta].margenGanancia;
			}
			actual = actual->siguiente;
		}
		cout << "El total pagado en concepto de apuestas ganadas es: " << totalPagado << "\n";
	}
	else {
		cout << "La lista no se encuentra cargada con ningún registro. Ingrese al menos un registro y vuelva a intentarlo.\n";
	}
}

int menu(void) {
	int opcion;
	cout << "Seleccione la opcion que desea ejecutar:\n";
	cout << "1- Vista general de apuestas\n";
	cout << "2- Consulta de apuestas por caballo\n";
	cout << "3- Consulta de apuesta por usuario\n";
	cout << "4- Vista de Resumen.\n";
	cout << "5- Salir del programa o Volver a Correr\n";
	cout << "Opción: "; cin >> opcion;
	while (opcion < 1 || opcion > 5) {
		cout << "Error.\nEl número ingresado no se encuentra en el rango permitido.\n";
		cout << "Seleccione la opcion que desea ejecutar:\n";
		cout << "1- Vista general de apuestas\n";
		cout << "2- Consulta de apuestas por caballo\n";
		cout << "3- Consulta de apuesta por usuario\n";
		cout << "4- Vista de Resumen.\n";
		cout << "5- Salir del programa o Volver a Correr\n";
		cout << "Opción: "; cin >> opcion;
	}
	return opcion;
}

bool tieneNumero(string cadena) {
	for (char letra : cadena) {
		if (isalpha(letra) == 0) {
			cout << "Sólo se pueden ingresar caractéres del abecedario.\n";
			return true;
		}
		else {
			return false;
		}
	}
}

bool errorDeCarga(void) {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Ha ocurrido un error en la carga de datos.\n";
		return true;
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
//pablog14 - GITHUB

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int generarAleatorio(int, int);

struct Caballo {
	int idCaballo = 0;
	int margenGanancia = generarAleatorio(100, 1);
} *Caballos[5];

struct Apuesta {
	int idApuesta = 0;
	string nombreJugador = "";
	int idCaballoApuesta = 0;
	int montoApuesta = 0;
	Apuesta* siguiente = NULL;
};

int main() {
	Apuesta *primero = NULL;
	char op = 'n';

	cout << "Simulador de Corrida de Caballos.\n";
	do {
		cout << "¿Desea Apostar?(S/N): "; cin >> op;
		if (op == 's' || op == 'S') {
			registrarApuesta(Caballos);
		}
	} while (op == 's' || op == 'S');

}

int generarAleatorio(int ls, int li) {
	return (rand() % (ls - li) + li);
}

void registrarApuesta(Caballo **Caballos) {
	system("cls");
	cout << "Seleccione el caballo por el que desea apostar:\n";
	for(int i=0; i<5; i++){
		cout << "Caballo " << i + 1 << ": ";
		*(Caballos + i).idCaballo = i;
		cout << "\tMargen de Ganancia: " << Caballos[i].margenGanancia<<"\n";
	}
}

void cargarLista(Apuesta*& lista, int idApuesta, string nombreJugador, int idCaballoApuesta, int montoApuesta) {
	Apuesta* nuevaApuesta = new Apuesta();
	Apuesta* aux1 = lista;
	Apuesta* aux2 = new Apuesta();
	nuevaApuesta->idApuesta = idApuesta;
	nuevaApuesta->nombreJugador = nombreJugador;
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
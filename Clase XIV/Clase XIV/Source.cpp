#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <string>

using namespace std;


int generarAleatorio(int, int);


int main(){
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "spanish");

	int cantJugadores = 0, cantRondas = 0;


	cout << "Juego del Dado\n";
	cout << "Ingrese la cantidad de rondas que desean jugar: "; cin >> cantRondas;
	cout << "Ingrese la cantidad de jugadores: "; cin >> cantJugadores;
	while (cantJugadores < 2) {
		cout << "Error. Deben haber al menos 2 jugadores!.\n";
		cout << "Ingrese la cantidad de jugadores: "; cin >> cantJugadores;
	}
	string nombres[10];
	for (int i = 0; i < 10; i++) {
		cin.ignore()
	cout << "Ingrese Nombre del Participante " << i << ": "; getline(cin,nombres[i],'\n');
	}
	
	
	for (int i = 0; i <= 10; i++) {
		int caraDado = generarAleatorio(21, 1);
		cout<< caraDado<<"\n";
	}
	return 0;
}

int generarAleatorio(int limiteSuperior, int limiteInferior) {
	return rand() % ((limiteSuperior - limiteInferior)) + 1;
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
visualizar los lanzamientos realizados en todas las todas).
- Consulta del top de puntajes finales (Donde se visualizará la tabla de resultados de
mayor a menor puntaje).
- Salir o Volver a Jugar.
*/
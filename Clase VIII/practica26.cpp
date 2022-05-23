#include <iostream>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	srand(time(NULL));
	cout<<"Programa para calcular un alumno aleatoriamente"<<endl;
	system("pause");
	int pepito = (rand()%(180 - 151) + 151);
	cout<<"El alumno con id "<< pepito <<" es el seleccionado para representar a la escuela en el concurso artístico."<<endl;
	system("pause");
}

/*
Una escuela tiene 180 alumnos distruibuidos en seis grados (1, 2, 3, 4, 5, 6)	180 alumnos
														

151 al 180 Sexto Grado
		
		151 al 180 al azar

														
donde cada alumno posee un código que lo identifica en la institución.		codigo id

Estos son correlativos, comenzando desde el 1°, 			codigo de uno en uno
luego el 2° grado y así sucesivamente, 

en cada grado hay 30 alumnos/as, 				30 alumnos 

crea un pseudocodigo que permita seleccionar 
al azar 
un estudiante del 6 grado para asistir 				1 estudiante del 6to grado Al Azar

a un evento artístico en representacion de la escuela
*/


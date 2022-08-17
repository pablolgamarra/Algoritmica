#include <iostream>
#include <windows.h>

using namespace std;
int puntaje;  

void calcCalif(int puntaje){
	if(puntaje >= 0 && puntaje <= 12){
		cout<<"La calificacion es: '1'\n";
	}else if(puntaje >= 13 && puntaje <=14){
		cout<<"La calificacion es: '2'\n";
	}else if(puntaje >= 15 && puntaje <=16){
		cout<<"La calificacion es: '3'\n";		
	}else if(puntaje >= 17 && puntaje <=18){
		cout<<"La calificacion es: '4'\n";		
	}else if(puntaje >= 19 && puntaje <=20){
		cout<<"La calificacion es: '5'\n";
	}else{
		cout<<"Algo anda mal.\n";
	}
	return;
}

int main(){
	system("cls");
	cout<<"Ingrese el puntaje del alumno: ";
	cin>>puntaje;
	while(puntaje < 0 || puntaje > 20){
	system("cls");
	cout<<"Ingrese el puntaje del alumno: ";
	cin>>puntaje;
	}
	calcCalif(puntaje);
	system("pause");
	return 0;
}

/*Crear un procedimiento que posibilite determinar la calificación de un alumno teniendo en cuenta la
siguiente escala de puntajes:
0 - 12 = 1
13 - 14 = 2
15 - 16 = 3
17 - 18 = 4
19 - 20 = 5
*/

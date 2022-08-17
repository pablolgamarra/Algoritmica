#include <iostream>
#include <windows.h>

using namespace std;
int opcion=1,calificacion,promedio,sumaCalif=0,i=0;

int calcPromedio(int suma, int cant){
	promedio=suma/cant;
	return promedio;
}

int main(){
	cout<<"Calculadora de Promedio de Calificaciones.\n";
	while(opcion == 1){
		system("cls");
		cout<<"Ingrese calificacion: ";
		cin>>calificacion;
		sumaCalif=sumaCalif+calificacion;
		i++;
		calcPromedio(sumaCalif,i);
		cout<<"Desea seguir ingresando calificaciones? 1=Si 2=No\n";
		cin>>opcion;
		while (opcion < 1 || opcion > 2){
			cout<<"Desea seguir ingresando calificaciones? 1=Si 2=No\n";
			cin>>opcion;
		}
		
	}
	system("cls");
	cout<<"La cantidad de calificaciones fue: "<<i<<"\n";
	cout<<"El promedio es: "<<promedio<<"\n";
	system("pause");
	return 0; 
}

/*Crea una función que calcule el promedio de calificaciones de dos alumnos/as.
*/
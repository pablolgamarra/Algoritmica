//Crear un pseudocódigo que ingrese el nombre y la edad de los alumnos 
//del 3er curso de un colegio. 
//cantidad de alumnos
//
//Decir si
//entre ellos existe un alumno mayor o no
//si tiene 1 aunque sea, 18 años, si hay mayores.

#include <iostream>
#include <windows.h>

using namespace std;

main(){
	int cantAlumnos;
	cout<<"Ingresar cantidad de alumnos que hay en el 3er Curso: ";
	cin>>cantAlumnos;
	//Validacion
	while(cantAlumnos <= 0){
		cout<<"Error. Debe ingresar numeros positivos."<<endl;
		cout<<"Ingresar cantidad de alumnos que hay en el 3er Curso: ";
		cin>>cantAlumnos;		
	}
	//Recorrer la cantidad de alumnos / Carga de Datos
	int c=1;
	string nombre;
	int edad;
	int sw=0;
	while(c <= cantAlumnos){
		fflush(stdin);
		cout<<"Ingrese nombre del alumno: ";
		getline(cin, nombre);
		cout<<"Ingrese edad del alumno: ";
		cin>>edad;
		if(edad >= 18){
			sw=1;
		}
		c++;
	}
	system("pause");
	if(sw == 0){
		cout<<"No hay alumnos mayores de edad en el 3er Curso."<<endl;
	}else{
		cout<<"Hay alumnos mayores de edad en el 3er Curso."<<endl;
	}
	system("pause");
}


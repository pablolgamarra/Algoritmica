//@Towel15 - GITHUB
#include <iostream>
#include <windows.h>

using namespace std;

//Estructura de los Nodos
struct Nodo{
	int cedula;
	string nombre;
	string apellido;
	int curso;
	int materia;
	int calificacion;
	Nodo *siguiente;
	Nodo *anterior;
};

//Estructura de Materias
string Materias[5] = {"Algorítmica", "Matemática", "Contabilidad", "Administración", "Sistemas Operativos"};

//Declaracion de Funciones
void cargarLista(Nodo *&, Nodo *&, int, string, string, int, int, int);
void modificarNodo(Nodo *&, Nodo *&, int, string, string, int, int, int);
void eliminarNodo(Nodo *&, Nodo *&);

main(){
	setlocale(LC_ALL, "spanish");
	
}

void cargarLista(Nodo *&primero, Nodo *&ultimo, int cedula, string nombre, string apellido, int curso, int materia, int calificacion){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->cedula = cedula;
	nuevoNodo->nombre = nombre;
	nuevoNodo->apellido = apellido;
	nuevoNodo->curso = curso;
	nuevoNodo->materia = materia;
	nuevoNodo->calificacion	= calificacion;
	if(!primero){
		nuevoNodo->anterior = NULL;
		nuevoNodo->siguiente = NULL;
		primero = nuevoNodo;
		ultimo = nuevoNodo;
	}else{
		ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = ultimo;
		nuevoNodo->siguiente = NULL;
		ultimo = nuevoNodo;
	}
}

void modificarNodo(Nodo *&primero, Nodo *&ultimo, int cedula, string nombre, string apellido, int curso, int materia, int calificacion){
	Nodo *actual = new Nodo();
	actual = primero;
	bool modificable = false;
	if(primero){
		while(actual && !modificable){
			if(actual->cedula == cedula){
				modificable = true;
			}else{
				actual = actual -> siguiente
			}
		}
		actual->cedula = cedula;
		actual->nombre = nombre;
		actual->apellido = apellido;
		actual->curso = curso;
		actual->material = materia;
		actual->calificacion = calificacion;
	}else{
		cout<<"La lista no tiene elementos.\nCargue elementos en ella y luego vuelva a intentar.\n";
	}
}

void eliminarNodo(Nodo *&, Nodo *&){
	Nodo *actual = new Nodo();
	actual = primero;
	bool eliminable = false;
	if(actual != NULL){
		while(actual != NULL && !encontrado){
			if(actual->cedula == cedula){
				
			}
		}
	}else{
		cout<<"La lista no tiene elementos cargados.\n";
	}
}

/*
Crear un proceso que permita ingresar las calificaciones de la carrera de ing. En informática para
el periodo lectivo 2022.
Donde, cada registro de calificación debe contar con los siguientes datos:

- Cedula del Alumno, Nombre, Apellido, Curso, Materia, Calificación

La aplicación debe permitir realizar las operaciones básicas: Insertar, Modificar, Eliminar
registros y 

realizar las siguientes consultas:
- Mostrar los registros cargados
- Mostrar los registros cargados por curso
- Mostrar los registros cargados por materia
- Buscar los registros relacionados con un alumno
- Consultar la cantidad de alumnos con calificaciones (1, 2, 3, 4, 5)
- Consultar el promedio de las calificaciones por materia
- Consultar el promedio de calificaciones en forma global
- Consultar la lista de calificaciones por curso
- Consultar la lista de calificaciones por materia
- Decir cuántos aprobados y no aprobados existen por materia
Observación:
- Ningún registro puede estar repetido en la estructura (realizar validación)
- Utilizar la función gotoxy para presentar los datos en forma de tablas 
*/

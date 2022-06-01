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
}

//Estructura de Materias
string Materias[5] = {"Algor�tmica", "Matem�tica", "Contabilidad", "Administraci�n", "Sistemas Operativos"};

//Declaracion de Funciones
void cargarLista(Nodo *&, Nodo *&);

main(){
	
}

void cargarLista(Nodo *&, Nodo *&, int cedula, string nombre, string apellido, int curso, int materia, int calificacion){
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


/*
Crear un proceso que permita ingresar las calificaciones de la carrera de ing. En inform�tica para
el periodo lectivo 2022.
Donde, cada registro de calificaci�n debe contar con los siguientes datos:

- Cedula del Alumno, Nombre, Apellido, Curso, Materia, Calificaci�n

La aplicaci�n debe permitir realizar las operaciones b�sicas: Insertar, Modificar, Eliminar
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
- Decir cu�ntos aprobados y no aprobados existen por materia
Observaci�n:
- Ning�n registro puede estar repetido en la estructura (realizar validaci�n)
- Utilizar la funci�n gotoxy para presentar los datos en forma de tablas 
*/

// C++ Clase 13.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//@Towel15 - GITHUB

#include <iostream>
#include <ctype.h>
#include <windows.h>
#include <string>

using namespace std;

//Estructura de los Nodos
struct Nodo {
	int cedula;
	string nombre;
	string apellido;
	int curso;
	int materia;
	int calificacion;
	Nodo* siguiente;
	Nodo* anterior;
};

//Estructuras Invariables
string materias[5] = { "Algorítmica", "Matemática", "Contabilidad", "Administración", "Sistemas Operativos" };
string errores[6] = {
	"Error. La Lista no está cargada con ningún registro.\n Cargue datos a la lista y vuelva a intentarlo",
	"Algo ha salido mal, opción de menú no valida.\n",
	"Error. Deben ingresar datos numéricos enteros.\n",
	"Error. Debe ingresar al menos un número.\n",
	"Error. La opción seleccionada no está disponible.\n",
	"Error. La materia seleccionada no se encuentra en la lista.\n Vuelva a intentarlo.\n"
};

//Prototipos de Funciones
bool errorCarga(void);
bool tieneNum(string);
int cargaCedula(void);
string cargaNombreApellido(char);
int cargaCurso(void);
int cargaMateria(void);
int cargaCalificacion(void);
void cargarLista(Nodo*&, Nodo*&, int, string, string, int, int, int);
void modificarNodo(Nodo*&, Nodo*&, int, string, string, int, int, int);
void eliminarNodo(Nodo*&, Nodo*&);
int mostrarMenu(void);

//Método Main - Principal
main() {
	setlocale(LC_ALL, "spanish");
	bool salir = false;
	do {
		system("cls");
		switch (mostrarMenu()) {
		case 1:
			cargaCedula();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			salir = true;
			cout << "Gracias por utilizar el programa.\n";
			system("pause");
			break;
		default:
			cout << "Algo ha salido mal. Codigo de Error: " << errores[1] << "\n";
			break;
		}
	} while (!salir);
}

//Declaración de Funciones

bool errorCarga(void) {
	if (cin.fail()) {
		cin.clear();
		fflush(stdin);
		return true;
	}
	else {
		return false;
	}
}

bool tieneNum(string cadena) {
	for (char caracter : cadena) {
		if (isdigit(caracter) != 0) {
			return true;
		}
	}
	return false;
}

int cargaCedula(void) {
	int cedula;
	do {
		cout << "Ingrese número de cédula: ";
		cin >> cedula;
	} while (errorCarga() || cedula <= 0);
	cout << "Se ha registrado correctamente el número de cédula.\n";
	return cedula;
}

string cargaNombreApellido(char op) {
	string nombre, apellido;
	switch (op) {
	case 'n':
		do {
			cout << "Ingrese nombre: ";
			getline(cin, nombre);
		} while (!errorCarga() && !tieneNum(nombre));
	case 'a':
		do {
			cout << "Ingrese apellido: ";
			getline(cin, nombre);
		} while (!errorCarga() && !tieneNum(nombre));
	default:
		cout << errores[4] << "\n";
	}
}

int cargaCurso(void){
	int curso;
	cout << "Seleccione el curso (1 - 5): ";
	cin >> curso;
	return curso;
}

int cargaMateria(void) {
	int materia;
	cout << "Seleccione la materia cuya calificación desea registrar:\n";
	cout << "1- Algorítmica\n";
	cout << "2- Matemática\n";
	cout << "3- Contabilidad\n";
	cout << "4- Administración\n";
	cout << "5- Sistemas Operativos\n";
	cin >> materia;
	while (materia < 1 || materia > 5) {
		cout << errores[5];
	}
	return materia;
}

int cargaCalificacion(void) {
	int calificacion;
	cout << "Ingrese la calificacion de la materia: ";
	cin >> calificacion;
	return calificacion;
}

void cargarLista(Nodo*& primero, Nodo*& ultimo, int cedula, string nombre, string apellido, int curso, int materia, int calificacion) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->cedula = cedula;
	nuevoNodo->nombre = nombre;
	nuevoNodo->apellido = apellido;
	nuevoNodo->curso = curso;
	nuevoNodo->materia = materia;
	nuevoNodo->calificacion = calificacion;
	if (!primero) {
		nuevoNodo->anterior = NULL;
		nuevoNodo->siguiente = NULL;
		primero = nuevoNodo;
		ultimo = nuevoNodo;
	}
	else {
		ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = ultimo;
		nuevoNodo->siguiente = NULL;
		ultimo = nuevoNodo;
	}
}

void modificarNodo(Nodo*& primero, Nodo*& ultimo, int cedula, string nombre, string apellido, int curso, int materia, int calificacion) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool modificado = false;
	if (primero) {
		while (actual && !modificado) {
			if (actual->cedula == cedula) {
				actual->cedula = cedula;
				actual->nombre = nombre;
				actual->apellido = apellido;
				actual->curso = curso;
				actual->materia = materia;
				actual->calificacion = calificacion;
				modificado = true;
			}
			else {
				actual = actual->siguiente;
			}
		}
		if (modificado) {
			cout << "Se ha modificado el elemento correctamente.\n";
		}
		else {
			cout << "No se ha encontrado el elemento a modificar.\nVuelva a intentar...";
		}
	}
	else {
		cout << errores[0] << "\n";
	}
}

void eliminarNodo(Nodo*& primero, Nodo*& ultimo, int cedula) {
	Nodo* actual = new Nodo();
	Nodo* aux = new Nodo();
	Nodo* anterior = NULL;
	actual = primero;
	bool eliminado = false;
	if (actual != NULL) {
		while (actual != NULL && !eliminado) {
			if (actual->cedula == cedula) {
				if (actual == primero) {
					aux = actual;
					primero = actual->siguiente;
					primero->anterior = NULL;
				}
				else if (actual == ultimo) {
					aux = actual;
					ultimo = actual->anterior;
					ultimo->siguiente = NULL;
				}
				else {
					aux = actual;
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}
				delete aux;
				eliminado = true;
			}
			else {
				anterior = actual;
				actual = actual->siguiente;
			}
		}
		if (eliminado) {
			cout << "Se ha eliminado el nodo correctamente...";
		}
		else {
			cout << "No se ha encontrado el nodo a eliminar. No se ha modificado nada.\n";
		}
	}
	else {
		cout << errores[0] << "\n";
	}
}

int mostrarMenu(void) {
	int op;
	cout << "Seleccione la opción que desea realizar.\n";
	cout << "1- Cargar datos de un alumno.\n";
	cout << "2- Modificar los datos de un alumno.\n";
	cout << "3- Mostrar los registros cargados.\n";
	cout << "4- Mostrar los registros cargados por curso.\n";
	cout << "5- Mostrar los registros cargados por materia.\n";
	cout << "6- Buscar los registros relacionados con un alumno.\n";
	cout << "7- Consultar la cantidad de alumnos que tienen una calificacion.\n";
	cout << "8- Consultar el promedio de las calificaciones por materia.\n";
	cout << "9- Consultar el promedio de calificaciones en forma global.\n";
	cout << "10- Consultar la lista de calificaciones por curso.\n";
	cout << "11- Consultar la lista de calificaciones por materia.\n";
	cout << "12- Consultar la cantidad de aprobados y desaprobados que hay por materia.\n";
	cout << "13- Salir del Programa.\n";
	cin >> op;
	while (op < 1 || op > 13) {
		system("cls");
		cout << errores[1] << "\n";
		cout << "Seleccione la opción que desea realizar.\n";
		cout << "1- Cargar datos de un alumno.\n";
		cout << "2- Modificar los datos de un alumno.\n";
		cout << "3- Mostrar los registros cargados.\n";
		cout << "4- Mostrar los registros cargados por curso.\n";
		cout << "5- Mostrar los registros cargados por materia.\n";
		cout << "6- Buscar los registros relacionados con un alumno.\n";
		cout << "7- Consultar la cantidad de alumnos que tienen una calificacion.\n";
		cout << "8- Consultar el promedio de las calificaciones por materia.\n";
		cout << "9- Consultar el promedio de calificaciones en forma global.\n";
		cout << "10- Consultar la lista de calificaciones por curso.\n";
		cout << "11- Consultar la lista de calificaciones por materia.\n";
		cout << "12- Consultar la cantidad de aprobados y desaprobados que hay por materia.\n";
		cout << "13- Salir del Programa.\n";
		cin >> op;
	}
	return op;
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

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

//@Towel15 - GITHUB

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

//Estructura de los Nodos
struct Nodo {
	int cedula = 0;
	string nombre = "";
	string apellido = "";
	int curso = 0;
	int materia = 0;
	int calificacion = 0;
	Nodo* siguiente = NULL;
	Nodo* anterior = NULL;
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
void gotoxy(int, int);
bool errorCarga(void);
bool tieneNum(string);
int cargaCedula(void);
string cargaNombreApellido(char);
int cargaCurso(void);
int cargaMateria(void);
int cargaCalificacion(void);
void cargaDatos(Nodo*&, Nodo*&);
void modificarDatos(Nodo *&, Nodo *&);
int datoAModificar(void);
void cargaLista(Nodo*&, Nodo*&, int, string, string, int, int, int);
bool buscarNodo(Nodo*, int );
void modificarNodo(Nodo*&, Nodo*&, int, int);
void eliminarNodo(Nodo*&, Nodo*&);
void imprimirLista(Nodo*, char);
void imprimirNodo(Nodo* );
void imprimirBuscar(Nodo*, char, int);
int mostrarMenu(void);
void buscarAlumno(Nodo *, int);

//Método Main - Principal
int main() {
	setlocale(LC_ALL, "spanish");

	Nodo* primero = NULL, * ultimo = NULL;

	bool salir = false;
	do {
		system("cls");
		switch (mostrarMenu()) {
		case 1:
			cargaDatos(primero, ultimo);
			break;
		case 2:
			modificarDatos(primero, ultimo);
			break;
		case 3:
			imprimirLista(primero, 't');
			break;
		case 4:
			imprimirLista(primero, 'c');
			break;
		case 5:
			imprimirLista(primero, 'm');
			break;
		case 6:
			cout << "Ingrese el numero de cédula del alumno que desea buscar.\n";
			buscarAlumno(primero, cargaCedula());
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
	return 0;
}

//Declaración de Funciones

//Funciones que llaman a otras

void cargaDatos(Nodo*& primero, Nodo*& ultimo) {
	system("cls");
	cout << "Creacion de un Registro.\n";
	int cedula = cargaCedula();
	string nombre = cargaNombreApellido('n');
	string apellido = cargaNombreApellido('a');
	int curso = cargaCurso();
	int materia = cargaMateria();
	int calificacion = cargaCalificacion();
	cargaLista(primero, ultimo, cedula, nombre, apellido, curso, materia, calificacion);
	cout << "Se ha creado el registro correctamente.\n";
	Sleep(1000);
}

void modificarDatos(Nodo*& primero, Nodo*& ultimo) {
	system("cls");
	cout << "Modificación de un Registro.\n";
	cout << "Cargue el numero de cédula del alumno cuyo registro desea modificar.\n";
	int cedula = cargaCedula();
	if (buscarNodo(primero, cedula)) {
		modificarNodo(primero, ultimo, cedula, datoAModificar());
	}
	Sleep(1000);
}

void buscarImprimir(Nodo* iniciador, char opcion, int parametroBusqueda) {
	/*
	Esta función se encarga de buscar los alumnos que se precisen, dependiendo del parámetro de búsqueda que se
	le pasa
	*/
	Nodo* actual = new Nodo();
	actual = iniciador;
	int encontrado = 0;
	switch (opcion) {
	case 'c':
		if (actual != NULL) {
			while (actual != NULL) {
				if (actual->curso == parametroBusqueda) {
					cout << "Cedula: " << actual->cedula << "\n";
					cout << "Nombre: " << actual->cedula << "\n";
					cout << "Apellido: " << actual->cedula << "\n";
					cout << "Curso: " << actual->cedula << "\n";
					cout << "Materia: " << actual->cedula << "\n";
					cout << "Calificación: " << actual->cedula << "\n";
					encontrado++;
				}
				actual = actual->siguiente;
			}
			if (encontrado == 0) {
				cout << "No se encontró ningún registro del curso deseado. Por favor, vuelva a  intentar.\n";
			}
		}
		break;
	case 'm':
		if (actual != NULL) {
			while (actual != NULL) {
				if (actual->materia == parametroBusqueda) {
					cout << "Cedula: " << actual->cedula << "\n";
					cout << "Nombre: " << actual->cedula << "\n";
					cout << "Apellido: " << actual->cedula << "\n";
					cout << "Curso: " << actual->cedula << "\n";
					cout << "Materia: " << actual->cedula << "\n";
					cout << "Calificación: " << actual->cedula << "\n";
					encontrado++;
				}
				actual = actual->siguiente;
			}
			if (encontrado == 0) {
				cout << "No se encontró ningún registro del curso deseado. Por favor, vuelva a  intentar.\n";
			}
		}
		break;
	default:
		cout << errores[1];
	}
}

void buscarAlumno(Nodo* iniciador, int cedula) {
	if (buscarNodo(iniciador, cedula)) {
		Nodo* actual = new Nodo();
		actual = iniciador;
		while (actual != NULL) {
			if (actual->cedula == cedula) {
				cout << "Registros del Alumno " << actual->nombre << ", " << actual->apellido << "\n";
				imprimirNodo(actual);
			}
			actual = actual->siguiente;
		}
	}
}


void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(hcon, cursor);
}

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
	return cedula;
}

string cargaNombreApellido(char op) {
	string nombre, apellido;
	switch (op) {
	case 'n':
		do {
			cin.ignore();
			cout << "Ingrese nombre: ";
			getline(cin, nombre);
		} while (errorCarga() || tieneNum(nombre));
		return nombre;
		break;
	case 'a':
		do {
			cout << "Ingrese apellido: ";
			getline(cin, nombre);
		} while (errorCarga() || tieneNum(nombre));
		return nombre;
	break;
	default:
		cout << errores[4] << "\n";
		return nombre;
	}
}

int cargaCurso(void) {
	int curso;
	cout << "Seleccione el curso (1 - 5): ";
	cin >> curso;
	while (curso < 1 || curso > 5) {
		cout << errores[4];
		cout << "Seleccione el curso (1 - 5): ";
		cin >> curso;
	}
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
		cout << "Seleccione la materia cuya calificación desea registrar:\n";
		cout << "1- Algorítmica\n";
		cout << "2- Matemática\n";
		cout << "3- Contabilidad\n";
		cout << "4- Administración\n";
		cout << "5- Sistemas Operativos\n";
		cin >> materia;
	}
	return materia;
}

int cargaCalificacion(void) {
	int calificacion;
	cout << "Ingrese la calificacion de la materia: ";
	cin >> calificacion;
	return calificacion;
}



int datoAModificar(void) {
	int op;
	cout << "Seleccione el Dato que Desea Modificar:\n";
	cout << "1- Número de Cédula\n";
	cout << "2- Nombre\n";
	cout << "3- Apellido\n";
	cout << "4- Curso\n";
	cout << "5- Materia\n";
	cout << "6- Calificación\n";
	cin >> op;
	while(op < 1 || op > 6){
		cout << errores[4];
		cout << "Seleccione el Dato que Desea Modificar:\n";
		cout << "1- Número de Cédula\n";
		cout << "2- Nombre\n";
		cout << "3- Apellido\n";
		cout << "4- Curso\n";
		cout << "5- Materia\n";
		cout << "6- Calificación\n";
		cin >> op;
	}
	return op;
}



void cargaLista(Nodo*& primero, Nodo*& ultimo, int cedula, string nombre, string apellido, int curso, int materia, int calificacion) {
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

bool buscarNodo(Nodo* primero, int cedula) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool encontrado = false;
	if (primero) {
		while (actual && !encontrado) {
			if (actual->cedula == cedula) {
				encontrado = true;
			}
			else {
				actual = actual->siguiente;
			}
		}
		if (encontrado) {
			cout << "Se ha encontrado el registro.\n";
		}
		else {
			cout << "No se ha encontrado el registro correspondiente a ese número de cédula.\nVuelva a intentar...";
		}
	}
	else {
		cout << errores[0] << "\n";
	}
	return encontrado;
}

void modificarNodo(Nodo*& primero, Nodo*& ultimo, int cedula, int op) {
	Nodo* actual = new Nodo();
	actual = primero;
	bool modificado = false;
	if (primero) {
		while (actual && !modificado) {
			if (actual->cedula == cedula) {
				switch (op) {
				case 1:
					actual->cedula = cargaCedula();
					break;
				case 2:
					actual->nombre = cargaNombreApellido('n');
					break;
				case 3:
					actual->apellido = cargaNombreApellido('a');
					break;
				case 4:
					actual->curso = cargaCurso();
					break;
				case 5:
					actual->materia = cargaMateria();
					break;
				case 6:
					actual->calificacion = cargaCalificacion();
					break;
				}
				modificado = true;
			}
			else {
				actual = actual->siguiente;
			}
		}
		if (modificado) {
			cout << "Se ha modificado el registro correctamente.\n";
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

void imprimirNodo(Nodo* actual) {
	if (actual != NULL) {
		cout << "Cedula: "<<actual->cedula<<"\n";
		cout << "Nombre: " << actual->nombre<<"\n";
		cout << "Apellido: " << actual->apellido << "\n";
		cout << "Curso: " << actual->curso << "\n";
		cout << "Materia: " << actual->materia << "\n";
		cout << "Calificacion: " << actual->calificacion << "\n";
	}
}

void imprimirBuscar(Nodo*, char, int)
{
	cout << "Imprimir Buscar";
}



void imprimirLista(Nodo* iniciador, char opcion) {
	/*
	Esta funcioón es la que llama a las otras dependiendo de la necesidad de impresión de datos que se tenga,
	es una llamadora de funciones.
	*/
	Nodo* actual = new Nodo();
	actual = iniciador;
	if (actual != NULL) {
		switch (opcion) {
		case 't':
			while (actual != NULL) {
				cout << "Cedula: " << actual->cedula << "\n";
				cout << "Nombre: " << actual->cedula << "\n";
				cout << "Apellido: " << actual->cedula << "\n";
				cout << "Curso: " << actual->cedula << "\n";
				cout << "Materia: " << actual->cedula << "\n";
				cout << "Calificación: " << actual->cedula << "\n";
				actual = actual->siguiente;
			}
			break;
		case 'c':
			cout << "Imprimir los alumnos de un curso.\nIngrese el curso que desea buscar.\n";
			imprimirBuscar(iniciador, 'c', cargaCurso());
			break;
		case 'm':
			cout << "Imprimir los alumnos de una materia.\nIngrese la materia que desea buscar.\n";
			imprimirBuscar(iniciador, 'm', cargaMateria());
			break;
		}
	}
	else {
		cout << errores[0] << "\n";
	}
	system("pause");
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
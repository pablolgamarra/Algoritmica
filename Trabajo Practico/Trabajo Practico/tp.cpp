//TRABAJO PRÁCTICO
//PABLO GAMARRA
//ROCELY MASI
//INGRID ACOSTA

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

//Opciones del Menú
string menu[14]{
"1) Registrar Jornal.",
"2) Modificar Jornal.",
"3) Eliminar Jornal.",
"4) Consultar Jornal por código de Funcionario.",
"5) Mostrar Lista de Primero al Último con un resumen totalizado.",
"6) Mostrar Lista de Ultimo al Primero con un resumen totalizado.",
"7) Mostrar el funcionario con mayor y menor jornal.",
"8) Realizar Arreglo(Cobrar Jornales).",
"9) Consultar Jornal Cobrado, por Funcionario.",
"10) Consultar Jornal Cobrado, en forma totalizada.",
"11) Consultar Jornal pendiente, por Funcionario.",
"12) Consultar Jornal pendiente, en forma totalizada.",
"13) Cancelar Jornal Cobrado.",
"14) Salir o Regresar."
};

//Estructura del Funcionario
struct Nodo {
	int codigo = 0;
	string nombre = "";
	int horasTrabajadas = 0;
	int turno = 0;
	int tipoDia = 0;
	int jornalACobrar = 0;
	bool cobrado = false;
	Nodo* anterior = NULL;
	Nodo* siguiente = NULL;
};

//Prototipo de Funciones
void registrarJornal(Nodo*&, Nodo*&, int&);
bool cargarLista(Nodo*&, Nodo*&, int, string, int, int, int, int);
void modificarJornal(Nodo*&);
bool modificarLista(Nodo*&, int, int, int);
bool modificarLista(Nodo*&, int, int, int);
bool modificarLista(Nodo*&, int, string);
void eliminarJornal(Nodo*&, Nodo*&, int&);
bool eliminarNodo(Nodo*&, Nodo*&, int);
void mostrarJornal(Nodo*, int);
bool buscarNodo(Nodo*, int);
bool buscarNodo(Nodo*, int, bool);
bool buscarNodo(Nodo*, bool, int);
void mostrarNodo(Nodo*);
void mostrarLista(Nodo*);
void mostrarLista(Nodo*, char);
void jornalMayorMenor(Nodo*, int);
void realizarArreglo(Nodo*&);
void consultaCobrado(Nodo*, bool);
void consultaCobrado(Nodo*, bool, int, bool);
void cancelarCobrado(Nodo*&);
void mostrarMenu(void);
void mostrarMenu(int);

int main() {
	setlocale(LC_ALL, "spanish");
	Nodo* primero = NULL, * ultimo = NULL;
	int id = 0, op = 0;
	char opsalir = 'n';
	bool salir = false;
	do {
		do {
			system("cls");
			cout << "Sistema de Control de Jornales.\n";
			mostrarMenu();
			cout << "Seleccione la opcion que desea: ";
			cin >> op;
			while (op < 0 || op > 14) {
				mostrarMenu();
				cout << "Seleccione la opcion que desea: ";
				cin >> op;
			}
		} while (op < 1 && op > 14);
		system("cls");
		switch (op) {
		case 1:
				registrarJornal(primero, ultimo, id);
				system("pause");
				break;
		case 2:
				modificarJornal(primero);
				system("pause");
				break;
			case 3:
				eliminarJornal(primero, ultimo, id);
				system("pause");
				break;
			case 4:
				mostrarJornal(primero, id);
				system("pause");
				break;
			case 5:
				mostrarLista(primero);
				system("pause");
				break;
			case 6:
				mostrarLista(ultimo, 'u');
				system("pause");
				break;
			case 7:
				jornalMayorMenor(primero, id);
				system("pause");
				break;
			case 8:
				realizarArreglo(primero);
				system("pause");
				break;
			case 9:
				consultaCobrado(primero, true);
				system("pause");
				break;
			case 10:
				consultaCobrado(primero, true, id, true);
				system("pause");
				break;
			case 11:
				consultaCobrado(primero, false);
				system("pause");
				break;
			case 12:
				consultaCobrado(primero, true, id, false);
				system("pause");
				break;
			case 13:
				cancelarCobrado(primero);
				system("pause");
				break;
			case 14:
				cout << "¿Está seguro de que desea salir del programa?(S/N): ";
				cin >> opsalir;
				while ((opsalir == 'n' || opsalir == 'N') && (opsalir == 'S' || opsalir == 's')) {
					cout << "¿Está seguro de que desea salir del programa?(S/N): ";
					cin >> opsalir;
				}
				if (opsalir == 's' || opsalir == 'S') {
					salir = true;
					cout << "Ok...Se cerrará el programa.\n";
				}
				break;
		default:
			cout << "Algo ha salido mal. Por favor, vuelva a intentar.\n";
			break;
		}
	} while (!salir);
}

void registrarJornal(Nodo *&primero, Nodo *&ultimo, int &id) {
	string nombre = "";
	int horasTrabajadas = 0, turno = 0, tipoDia = 0, jornalACobrar = 0;

	cin.ignore();
	cin.clear();
	cout << "Registro de Jornales por Funcionario.\n";
	cout << "Ingrese el nombre del funcionario: ";
	getline(cin, nombre);


	cin.clear();
	cout << "Ingrese las horas trabajadas: ";
	cin >> horasTrabajadas;
	while (horasTrabajadas < 0) {
		cout << "No se pueden cargar números negativos.\nVuelva a intentar.\n";
		cout << "Ingrese las horas trabajadas: ";
		cin >> horasTrabajadas;
	}

	cin.clear();
	cout << "Seleccione el turno:\n"
		<< "1- Diurno.\n"
		<< "2- Nocturno.\n"
		<< "Turno: ";
	cin >> turno;
	while (turno < 1 || turno > 2) {
		cout << "Error. Debe seleccionar un turno adecuado.\n";
		cout << "Seleccione el turno:\n"
			<< "1- Diurno.\n"
			<< "2- Nocturno.\n"
			<< "Turno: ";
		cin >> turno;
	}

	cin.clear();
	cout << "Seleccione si es día laborable o festivo:\n"
		<< "1- Día Laborable.\n"
		<< "2- Día Festivo(Sábados, Domingos o Feriados).\n"
		<< "Ingrese Día: ";
	cin >> tipoDia;
	while (tipoDia < 1 || tipoDia > 2) {
		cout << "Error.\nEl tipo de día seleccionado no es válido.\n";
		cout << "Seleccione si es día laborable o festivo:"
			<< "1- Día Laborable.\n"
			<< "2- Día Festivo(Sábados, Domingos o Feriados).\n"
			<< "Ingrese Día: ";
		cin >> tipoDia;
	}

	if (tipoDia == 1) {
		//Dia Laborable
		if (turno == 1) {
			//Turno Diurno
			jornalACobrar = horasTrabajadas * 100000;
		}
		else {
			//Turno Nocturno
			jornalACobrar = horasTrabajadas * 135000;
		}
	}
	else {
		//Dia Festivo
		if (turno == 1) {
			//Turno Diurno
			jornalACobrar = horasTrabajadas * (100000 + (100000 * 0.1));
		}
		else {
			//Turno Nocturno
			jornalACobrar = horasTrabajadas * (135000 + (135000 * 0.15));
		}
	}

	if (cargarLista(primero, ultimo, id, nombre, horasTrabajadas, turno, tipoDia, jornalACobrar)) {
		id++;
		cout << "Se ha cargado el registro. ID del Funcionario: " << id << "\n";
	}
}

bool cargarLista(Nodo*& primero, Nodo*& ultimo, int id, string nombre, int horasTrabajadas, int turno, int tipoDia, int jornalACobrar) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->codigo = id;
	nuevoNodo->nombre = nombre;
	nuevoNodo->horasTrabajadas = horasTrabajadas;
	nuevoNodo->turno = turno;
	nuevoNodo->tipoDia = tipoDia;
	nuevoNodo->jornalACobrar = jornalACobrar;
	if (!primero) {
		primero = nuevoNodo;
		primero->anterior = NULL;
		primero->siguiente = NULL;
		ultimo = primero;
	}
	else {
		ultimo->siguiente = nuevoNodo;
		nuevoNodo->anterior = ultimo;
		nuevoNodo->siguiente = NULL;
		ultimo = nuevoNodo;
	}
	return true;
}

void modificarJornal(Nodo *&primero) {
	int op = 0;

	cin.clear();
	cout << "Seleccione el campo que desea modificar: \n"
		<< "1- Nombre del Funcionario.\n"
		<< "2- Horas Trabajadas.\n"
		<< "3- Turno del Jornal.\n"
		<< "4- Tipo de Día.\n"
		<< "5- Jornal Cobrado.\n"
		<< "6- Cancelar.\n"
		<< "Opción Deseada: ";
	cin >> op;
	while (op < 1 || op > 6) {
		cout << "Debe ingresar un número en el rango admitido.\n";
		cout << "Seleccione el campo que desea modificar: "
			<< "1- Nombre del Funcionario.\n"
			<< "2- Horas Trabajadas.\n"
			<< "3- Turno del Jornal.\n"
			<< "4- Tipo de Día.\n"
			<< "5- Estado de Cobro del Jornal.\n"
			<< "6- Cancelar.\n"
			<< "Opción Deseada: ";
		cin >> op;
	}
	if (op < 6) {
		int idBuscado, horasTrabajadas, turno, tipoDia, estadoCobro;
		string nombre;
		cin.ignore();
		cin.clear();
		cout << "Ingrese el código del funcionario cuyo registro desea modificar: ";
		cin >> idBuscado;
		switch (op) {
		case 1:
			cin.ignore();
			cin.clear();
			cout << "Ingrese el nuevo nombre del funcionario: ";
			getline(cin, nombre, '\n');
			modificarLista(primero, idBuscado, nombre) ? cout << "Se ha modificado el registro.\n" : cout << "No se ha modificado el registro existente.\n";
			break;
		case 2:
			cin.ignore();
			cin.clear();
			cout << "Ingrese las horas trabajadas del funcionario: ";
			cin >> horasTrabajadas;
			while (horasTrabajadas < 0) {
				cout << "No se pueden cargar números negativos.\nVuelva a intentar.\n";
				cout << "Ingrese las horas trabajadas: ";
				cin >> horasTrabajadas;
			}
			modificarLista(primero, idBuscado, 2, horasTrabajadas) ? cout << "Se ha modificado el registro.\n" : cout << "No se ha modificado el registro existente.\n";
			break;
		case 3:
			cin.ignore();
			cin.clear();
			cout << "Seleccione el turno de trabajo: "
				<< "1- Diurno.\n"
				<< "2- Nocturno.\n"
				<< "Turno: ";
			cin >> turno;
			while (turno < 1 || turno > 2) {
				cout << "Error. Debe seleccionar un turno adecuado.\n";
				cout << "Seleccione el turno:\n"
					<< "1- Diurno.\n"
					<< "2- Nocturno.\n"
					<< "Turno: ";
				cin >> turno;
			}
			modificarLista(primero, idBuscado, 3, turno) ? cout << "Se ha modificado el registro.\n" : cout << "No se ha modificado el registro existente.\n";
			break;
		case 4:
			cout << "Seleccione si es día laborable o festivo:\n"
				<< "1- Día Laborable.\n"
				<< "2- Día Festivo(Sábados, Domingos o Feriados).\n"
				<< "Ingrese Día: ";
			cin >> tipoDia;
			while (tipoDia < 1 || tipoDia > 2) {
				cout << "Error.\nEl tipo de día seleccionado no es válido.\n";
				cout << "Seleccione si es día laborable o festivo:"
					<< "1- Día Laborable.\n"
					<< "2- Día Festivo(Sábados, Domingos o Feriados).\n"
					<< "Ingrese Día: ";
				cin >> tipoDia;
			}
			modificarLista(primero, idBuscado, 4, tipoDia) ? cout << "Se ha modificado el registro.\n" : cout << "No se ha modificado el registro existente.\n";
			break;
		case 5:
			cout << "Seleccione si el jornal ya ha sido cobrado o no.\n"
				<< "1- Ya ha sido cobrado por el funcionario.\n"
				<< "2- Aún no ha sido cobrado por el funcionario.\n";
			cin >> estadoCobro;
			while (estadoCobro < 1 || estadoCobro > 2) {
				cout << "Error.\nDebe ingresar un número en el rango admitido.\n";
				cout << "Seleccione si el jornal ya ha sido cobrado o no.\n"
					<< "1- Ya ha sido cobrado por el funcionario.\n"
					<< "2- Aún no ha sido cobrado por el funcionario.\n";
				cin >> estadoCobro;
			}
			if (estadoCobro == 1) {
				modificarLista(primero, idBuscado, 5, true) ? cout << "Se ha modificado el registro.\n" : cout << "No se ha modificado el registro existente.\n";
			}
			else {
				modificarLista(primero, idBuscado, 5,false) ? cout << "Se ha modificado el registro.\n" : cout << "No se ha modificado el registro existente.\n";
			}
			break;
		default:
			cout << "Ha ocurrido un error en el proceso.\n";
		}
	}
	else {
		cout << "Ok...No se modificará ningún registro.\n";
	}
}

 bool modificarLista(Nodo *&primero, int id, int campoModificar, int dato) {
	Nodo* actual = primero;
	bool modificado = false;
	if (actual) {
		while (actual && !modificado) {
			if (actual->codigo == id) {
				modificado = true;
				switch (campoModificar) {
				case 2: actual->horasTrabajadas = dato;
					break;
				case 3: actual->turno = dato;
					break;
				case 4: actual->tipoDia = dato;
					break;
				}
			}
			actual = actual->siguiente;
		}
		return modificado;
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
	}
	return modificado;
}

bool modificarLista(Nodo*& primero, int id, string dato) {
	Nodo* actual = primero;
	bool modificado = false;
	if (actual) {
		while (actual && !modificado) {
			if (actual->codigo == id) {
				modificado = true;
				actual->nombre = dato;
			}
			actual = actual->siguiente;
		}
		return modificado;
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
		return false;
	}
	return modificado;
}

bool modificarLista(Nodo*& primero, int id, bool dato) {
	Nodo* actual = primero;
	bool modificado = false;
	if (actual) {
		while (actual && !modificado) {
			if (actual->codigo == id) {
				modificado = true;
				actual->cobrado = dato;
			}
			actual = actual->siguiente;
		}
		return modificado;
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
		return false;
	}
	return modificado;
}

void eliminarJornal(Nodo*& primero, Nodo*& ultimo, int &id) {
	int idBuscado;
	cout << "Ingrese el código del funcionario que desea eliminar:\n";
	cin >> idBuscado;
	if (eliminarNodo(primero, ultimo, idBuscado)) {
		cout << "Se ha eliminado el registro correctamente.\n";
		id--;
	}
	else {
		cout << "No se ha eliminado el nodo.\n";
	}
}

bool eliminarNodo(Nodo*& primero, Nodo*& ultimo, int idBuscado) {
	Nodo* actual = primero;
	Nodo* anterior = new Nodo();
	Nodo* aux;
	bool encontrado = false;
	if (actual) {
		while (actual && !encontrado) {
			if (actual->codigo == idBuscado) {
				if (actual == primero) {
					aux = primero;
					primero = actual->siguiente;
					primero->anterior = NULL;
				}
				else if (actual == ultimo) {
					aux = ultimo;
					anterior->siguiente = actual->siguiente;
					ultimo = anterior;
				}
				else {
					aux = actual;
					anterior->siguiente = actual->siguiente;
					anterior->siguiente->anterior = anterior;
				}
				delete aux;
				encontrado = true;
			}
			else {
				anterior = actual;
				actual = actual->siguiente;
			}
		}
		return encontrado;
	}
	else {
		cout << "La lista no tiene elementos cargados. Cargue al menos un registro y vuelva a intentar.\n";
		return false;
	}
	return encontrado;
}

void mostrarJornal(Nodo* primero, int id) {
	int idBuscado;
	cout << "Ingrese el código del funcionario cuyos jornales desea ver: ";
	cin >> idBuscado;
	while (idBuscado < 0 || idBuscado > id) {
		cout << "Error. El código ingresado es menor a cero o no existe ningún funcionario con ese código.\nVuelva a intentar.\n";
		cout << "Ingrese el código del funcionario cuyos jornales desea ver: ";
		cin >> idBuscado;
	}
	buscarNodo(primero, idBuscado);
}

bool buscarNodo(Nodo* primero, int idBuscado) {
	Nodo* actual = primero;
	bool encontrado = false;
	if (actual) {
		while (actual && !encontrado) {
			if (actual->codigo == idBuscado) {
				mostrarNodo(actual);
			}
			actual = actual->siguiente;
		}
		return encontrado;
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
		return false;
	}
	return false;
}

bool buscarNodo(Nodo* primero, int idBuscado, bool consultaCobrado) {
	Nodo* actual = primero;
	int encontrados = 0;
	if (actual) {
		while (actual) {
			if (actual->codigo == idBuscado && actual->cobrado == consultaCobrado) {
				mostrarNodo(actual);
				encontrados++;
			}
			actual = actual->siguiente;
		}
		if (encontrados == 0) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
		return false;
	}
	return false;
}

bool buscarNodo(Nodo* primero, bool consultaCobrado, int idMax) {
	//Consulta de Todos los funcionarios y que ya cobraron
	Nodo* actual = primero;
	int idActual = 0, encontrados = 0, i = 0;
	if (actual) {
		do {
			while (actual) {
				if (i == 0) {
					cout << "Funcionario: " << actual->nombre << "\n";
				}

				if (actual->codigo == idActual && actual->cobrado == consultaCobrado) {
					mostrarNodo(actual);
					encontrados++;
				}
				actual = actual->siguiente;
			}
			if (encontrados == 0) {
				cout << "Este funcionario no tiene jornales cobrados.\n";
			}
			else {
				cout << "Se encontraron " << encontrados << " jornales de este funcionario.\n";
			}
			idActual++;
			encontrados = 0;
			actual = primero;
		} while (idActual != idMax);
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
		return false;
	}
	return false;
}

void mostrarNodo(Nodo* actual) {
	cout << "==================================================\n";
	cout << "Nombre del Funcionario: " << actual->nombre << "\n";
	cout << "Horas Trabajadas: " << actual->horasTrabajadas << "\n";
	cout << "Turno : ";
	(actual->turno == 1) ? cout << "Diurno.\n" : cout << "Nocturno.\n";
	cout << "Tipo de Día: ";
	(actual->tipoDia == 1) ? cout << "Laborable.\n" : cout << "Festivo.\n";
	cout << "Cobrado: ";
	actual->cobrado ? cout << "Si.\n" : cout << "No.\n";
	cout << "Monto a Cobrar: " << actual->jornalACobrar << "\n";
	cout << "==================================================\n";
}

void mostrarLista(Nodo* primero) {
	Nodo* actual = primero;
	if (actual) {
		while (actual) {
			mostrarNodo(actual);
			actual = actual->siguiente;
		}
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
	}
}

void mostrarLista(Nodo* ultimo, char banderaUltimo) {
	Nodo* actual = ultimo;
	if (actual) {
		while (actual) {
			mostrarNodo(actual);
			actual = actual->anterior;
		}
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentarlo.\n";
	}
}

void jornalMayorMenor(Nodo* primero, int idMax) {
	Nodo* actual = primero;
	int i = 0, idMayor = 0, idMenor = 0, jornalMayor = 0, jornalMenor = 0;
	if (actual) {
		do {
			while (actual) {
				if (i == 0) {
					idMayor = actual->codigo;
					idMenor = actual->codigo;
					jornalMayor = actual->jornalACobrar;
					jornalMenor = actual->jornalACobrar;
				}
				else if (actual->jornalACobrar < jornalMenor) {
					idMenor = actual->codigo;
				}
				else if (actual->jornalACobrar > jornalMayor) {
					idMayor = actual->codigo;
				}
				actual = actual->siguiente;
				i++;
			}
		} while (i < idMax);
	}
	else {
		cout << "No se encuentran registros cargados.Ingrese al menos un registro y vuelva a intentar.\n";
	}
	cout << "El empleado con el jornal menor:\n";
	buscarNodo(primero, idMenor);
	cout << "El funcionario con el jornal mayor:\n";
	buscarNodo(primero, idMayor);
}

void realizarArreglo(Nodo*& primero) {
	Nodo* actual = primero;
	if (primero) {
		while (actual) {
			if (!actual->cobrado) {
				actual->cobrado = true;
				cout << "Jornal Pagado al funcionario: " << actual->nombre << "\n";
			}
			actual = actual->siguiente;
		}
	}
	else {
		cout << "No hay registros cargados. Cargue al menos uno y vuelva a intentar.\n";
	}
}

void consultaCobrado(Nodo* primero, bool cobrado) {
	int idBuscado;
	cout << "Ingrese el código del funcionario cuyos jornales cobrados desea buscar: ";
	cin >> idBuscado;
	while (idBuscado < 0) {
		cout << "Error. El código sólo puede ser positivo.\n";
		cout << "Ingrese el código del funcionario cuyos jornales desea buscar: ";
		cin >> idBuscado;
	}
	if (!buscarNodo(primero, idBuscado, cobrado)) {
		cout << "Vuelva a intentar por favor.\n";
	}
}

void consultaCobrado(Nodo* primero, bool total, int idMax, bool cobrado) {
	buscarNodo(primero,cobrado, idMax);
}

void cancelarCobrado(Nodo*& primero) {
	int idBuscado;
	cout << "Ingrese código del funcionario cuyo pago de jornal desea cancelar: ";
	cin >> idBuscado;
	while (idBuscado < 0) {
		cout << "Debe ingresar números positivos de id. Vuelva a intentar.\n";
		cout << "Ingrese código del funcionario cuyo pago de jornal desea cancelar: ";
		cin >> idBuscado;
	}
	cout << "Ok...Se buscaran los jornales del funcionario.\n";
	buscarNodo(primero, idBuscado) ? cout << "Seleccione el número del jornal que desea cancelar.\n" : cout << "No se han encontrado jornales para este funcionario.\n";
	
	modificarLista(primero, idBuscado, false);
}

void mostrarMenu(void) {
	for (int i = 0; i < 14;i++) {
		cout << menu[i] << "\n";
	}
}

void mostrarMenu(int limite) {
	for (int i = 0; i < limite;i++) {
		cout << menu[i] << "\n";
	}
}

#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int id;
	string nombre;
	Nodo *siguiente;
};

void cargarCola(Nodo *&, Nodo *&, int, string);
void quitarCola(Nodo *&, Nodo *&, int &, string &);
bool colaVacia(Nodo *);
void menu(int &, int &);

main(){
	setlocale(LC_ALL, "spanish");
	
	char op;
	int n, i=0;
	string nombre;
	
	Nodo *frente=NULL, *fin=NULL;
	
	system("cls");
	
	cout<<"Programa Consultorio Médico.\nCargar los pacientes que deben consultar\n";
//	menu(opcion, i);
	
	do{
		cout<<"Ingrese nombre del Paciente: ";
		getline(cin, nombre);
		fflush(stdin);
		cargarCola(frente, fin, i+1, nombre);
		i++;
		cout<<"¿Desea seguir ingresando pacientes? (S)/(N): ";
		cin>>op;
		fflush(stdin);
		if(op == 'N' || op == 'n'){
			cout<<"Ok...Se imprimira la lista de pacientes...";
		}
	}while(op == 'S' || op == 's');
	
	
	system("pause");
	system("cls");
	
	while(!colaVacia(frente)){
		quitarCola(frente, fin, i, nombre);
		cout<<"------------------------------\n";
		cout<<"Nombre Paciente: "<<nombre<<".\n";
		cout<<"Numero de Consulta: "<<i<<".\n";
		cout<<"------------------------------\n\n";
	}
	
	delete frente, fin;
	system("pause");
	return 0;
}

bool colaVacia(Nodo *frente){
	if(frente == NULL){
		return true;
	}else{
		return false;
	}
}

void cargarCola(Nodo *&frente, Nodo *&fin, int id, string nombre){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->id = id;
	nuevoNodo->nombre = nombre;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(frente)){
		frente = nuevoNodo;
	}else{
		fin->siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
	return;
}

void quitarCola(Nodo *&frente, Nodo *&fin, int &id, string &nombre){
	Nodo *aux = frente;
	id = frente->id;
	nombre = frente->nombre;
	if(colaVacia(frente)){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente;
	}
	delete aux;
	return;
}

//void switchOpciones(int opcion, int &i){
//	switch(opcion){
//		case 1:
//			string nombre;
//			cout<<"Ingrese nombre del paciente: ";
//			getline(cin, nombre);
//			cargarCola(frente, fin, i, nombre);
//			i++;
//		case 2:
//			string nombre;
//			quitarCola(frente, fin, i, nombre);
//			cout<<"El paciente a quien le corresponde el turno actualmente es:\n";
//			cout<<"\tId: "<<i<<"\n";
//			cout<<"\tNombre: "<<nombre<<"\n";
//		case 3:
//			cout<<"Gracias por usar el programa.\n";
//		default:
//	}
//}

//void menu(int &opcion, int &i){
//	cout<<"¿Que desea hacer?.\n";
//	cout<<"1- Cargar Datos de un Paciente.\n";
//	cout<<"2- Saber cuál es el Paciente que corresponde ahora.\n";
//	cout<<"3- Salir del Programa.\n";
//	cout<<"Opcion Seleccionada: ";
//	cin>>opcion;
//}

/*
4 – Crear una lista de recepción para un consultorio medico registrando el
nombre de los pacientes. Imprimir la lista de los pacientes y el nro que le
corresponde en la consulta
*/

#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	string nombre;
	int curso;
	int edad;
	Nodo *siguiente;
};

void cargaPila(Nodo *&, string, int, int);
void quitarPila(Nodo *&, string &, int &, int &);
bool pilaVacia(Nodo *);

main(){
	Nodo *Pila = NULL;
	char op;
	string nombre;
	int edad, curso;
	
	setlocale(LC_ALL, "spanish");
	
	do{
		system("cls");
		fflush(stdin);
		cout<<"Cargar datos de alumno.\n";
		cout<<"Ingrese nombre del alumno: ";
		getline(cin, nombre);
		cout<<"¿Cuál es el curso del alumno? (1-5): ";
		cin>>curso;
		while(curso < 1 || curso > 5){
			fflush(stdin);
			cout<<"¡Error!. Debe ingresar numeros en el rango permitido\n";
			cout<<"¿Cuál es el curso del alumno? (1-5): ";
			cin>>curso;
		}
		cout<<"Ingrese la edad del alumno: ";
		cin>>edad;
		fflush(stdin);
		cargaPila(Pila, nombre, curso, edad);
		cout<<"¿Desea Seguir Cargando Datos? (S)/(N): ";
		cin>>op;
		fflush(stdin);
		if(op == 'N' || op == 'n'){
			cout<<"Ok...Se imprimira la lista con los alumnos cargados.\n";
			system("pause");
		}
	}while(op == 'S' || op == 's');
	
	system("cls");
	
	while(!pilaVacia(Pila)){
		quitarPila(Pila, nombre, curso, edad);
		if(pilaVacia(Pila)){
			cout<<"Nombre: "<<nombre<<"\n";
			cout<<"Curso: "<<curso<<"\n";
			cout<<"Edad: "<<edad<<"\n";
			cout<<"\n-------------------------\n";
			cout<<"Fin de Cola.\n";
		}else{
			cout<<"Nombre: "<<nombre<<"\n";
			cout<<"Curso: "<<curso<<"\n";
			cout<<"Edad: "<<edad<<"\n";
			cout<<"-------------------------\n";
		}
	}
	
	system("pause");
	return 0;
}

bool pilaVacia(Nodo *Pila){
	if(Pila == NULL){
		return true;
	}else{
		return false;
	}
}

void cargaPila(Nodo *&Pila, string nombre, int curso, int edad){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->nombre = nombre;
	nuevoNodo->curso = curso;
	nuevoNodo->edad = edad;
	nuevoNodo->siguiente = Pila;
	Pila = nuevoNodo;
	return;  
}

void quitarPila(Nodo *&Pila, string &nombre, int &curso, int &edad){
	Nodo *aux = Pila;
	nombre= aux->nombre;
	curso= aux->curso;
	edad = aux->edad;
	Pila= aux->siguiente;
	delete aux;
	return;
}

/*
1) Crear un registro de datos cuyos campos serán: nombre, curso, edad. Los cuáles serán
almacenados en una pila. Imprimir la Pila cargada, en formato de tabla. 
*/

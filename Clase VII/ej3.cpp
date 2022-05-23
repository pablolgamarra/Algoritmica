#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

struct Nodo{
	int n;
	Nodo *siguiente;	
};

void cargaCola(Nodo *&, Nodo *&, int );
void quitarCola(Nodo *&, Nodo *&, int &);
bool colaVacia(Nodo *);
bool califNoValida(int);

main(){
	setlocale(LC_ALL, "spanish");
	
	Nodo *frente = NULL, *fin = NULL;
	string materia;
	int n;
	
	cout<<"Ingrese el nombre de la materia: ";
	getline(cin,materia);
	
	cout<<"Cargar los datos de 20 alumnos.\n";
	for(int i=0; i<20; i++){
		cout<<"Alumno "<<i+1<<".\n";
		cout<<"Calificacion: ";
		cin>>n;
		while(califNoValida(n)){
			cout<<"Error!. El rango de calificaciones para cargar es de 1 al 5.\n";
			cout<<"Vuelva a ingresar calificacion. Alumno "<<i+1<<": ";
			cin>>n;
		}
		cargaCola(frente, fin, n);
	}
	
	int i=0;
	
	system("cls");
	cout<<"Materia: "<<materia<<"\n";
	while(!colaVacia(frente)){
		quitarCola(frente, fin, n);
		cout<<"------------------------\n";
		cout<<"Alumno "<<i+1<<"\n";
		cout<<"Nota: "<<n<<"\n";
		cout<<"------------------------\n";
		i++;
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

void cargaCola(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->n = n;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(frente)){
		frente = nuevoNodo;
	}else{
		fin->siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
	cout<<"Se agrego el elemento "<<n<<" a la Cola.\n";
	return;
}

void quitarCola(Nodo *&frente, Nodo *&fin, int &n){
	Nodo *aux = frente;
	n = frente->n;
	if(colaVacia(frente)){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente->siguiente;
	}
	delete aux;
}

bool califNoValida(int n){
	if(n < 1 || n > 5){
		return true;
	}else{
		return false;
	}
}

/*
3 – Cargar una lista de 20 alumnos con sus calificaciones finales en una materia
cualquiera. Imprimir la lista de reprobados en el orden que se ha cargado.
Utiliza una cola para representar los datos.
*/

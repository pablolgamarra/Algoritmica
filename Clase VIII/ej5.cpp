#include <iostream>
#include <windows.h>
#include <locale.h>
#include <string.h>

using namespace std;

struct Nodo{
	string nombre;
	int materia;
	int puntaje;
	Nodo *siguiente;
};

string Materias[5]={
	"Algoritmica",
	"Matemática",
	"Contabilidad",
	"Sistema Operativo",
	"Taller"
};

void cargaCola(Nodo *&, Nodo *&, string, int, int);
void quitarCola(Nodo *&, Nodo *&, string &, int &, int &);
bool colaVacia(Nodo *&);
string cargaNombre(void);
int cargaMateria(void);
int cargaPuntaje(void);

main(){
	setlocale(LC_ALL, "spanish");
	Nodo *Frente = NULL, *Fin = NULL;
	string nombre;
	int materia, puntaje, cantidadEstudiantes[5] = {0};
	float promediosPorMateria[5] = {0}, promedioGeneral=0;
	char op;
	
	do{
		cout<<"Cargar Datos de Alumnos.\n";
		nombre = cargaNombre();
		materia = cargaMateria();
		puntaje = cargaPuntaje();
		cantidadEstudiantes[materia] = cantidadEstudiantes[materia] + 1;
		promediosPorMateria[materia] = ((promediosPorMateria[materia] + puntaje )/ cantidadEstudiantes[materia]);
		cargaCola(Frente, Fin, nombre, materia, puntaje);
		
		cout<<"¿Desea seguir ingresando datos? (S)/(N):";
		cin>>op;
		if(op == 'N' || op == 'n'){
			cout<<"Se imprimira la lista de con los alumnos cargados.\n";
			system("pause");
		}
	}while(op == 'S' || op == 's');

	system("cls");
	
	while(!colaVacia(Frente)){
		quitarCola(Frente, Fin, nombre, materia, puntaje);
		cout<<"Nombre del Alumno: "<<nombre<<"\n";
		cout<<"Materia: "<<Materias[materia]<<"\n";
		cout<<"Puntaje: "<<puntaje<<"\n";
		cout<<"----------------------------------\n";
	}
	
	cout<<"Promedio de Puntaje de Cada Materia.\n";
	for(int i=0; i<5; i++){
		cout<<"Materia: "<<Materias[i]<<"\tPromedio: "<<promediosPorMateria[i]<<"\n";
		promedioGeneral= promedioGeneral + promediosPorMateria[i];
	}
	
	cout<<"El promedio de puntaje entre todas las materias es: "<<promedioGeneral/5<<"\n";
	
	system("pause");
	return 0;
}

bool colaVacia(Nodo *&Frente){
	if(Frente == NULL){
		return true;
	}else{
		return false;
	}
}

void cargaCola(Nodo *&Frente, Nodo *&Fin, string nombre, int materia, int puntaje){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->nombre = nombre;
	nuevoNodo->materia = materia;
	nuevoNodo->puntaje = puntaje;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(Frente)){
		Frente = nuevoNodo;
	}else{
		Fin->siguiente = nuevoNodo;
	}
	Fin = nuevoNodo;
	return;
}

void quitarCola(Nodo *&Frente, Nodo *&Fin, string &nombre, int &materia, int &puntaje){
	Nodo *aux = Frente;
	nombre = aux->nombre;
	materia = aux->materia;
	puntaje = aux->puntaje;
	if(colaVacia(Frente)){
		Frente= NULL;
		Fin = NULL;
	}else{
		Frente = Frente->siguiente;
	}
	delete aux;
	return;
}

string cargaNombre(void){
	fflush(stdin);
	string nombre;
	cout<<"Ingrese Nombre del Alumno: ";
	getline(cin, nombre);
	while(nombre.length() <= 0){
		cout<<"¡Error! Debe ingresar el nombre del Alumno.\n";
		cout<<"Ingrese Nombre del Alumno: ";
		getline(cin, nombre);
	}
	fflush(stdin);
	return nombre;
}

int cargaMateria(void){
	fflush(stdin);
	int materia;
	cout<<"Seleccione Materia:\n";
	cout<<"1- Algoritmica\n";
	cout<<"2- Matemática\n";
	cout<<"3- Contabilidad\n";
	cout<<"4- Sistema Operativo\n";
	cout<<"5- Taller\n";
	cout<<"Materia (1-5): ";
	cin>>materia;
	while(materia < 1 || materia > 5){
		cout<<"¡Error! Debe seleccionar uno de los cursos que están en la lista.\n";
		cout<<"Seleccione Materia:\n";
		cout<<"1- Algoritmica\n";
		cout<<"2- Matemática\n";
		cout<<"3- Contabilidad\n";
		cout<<"4- Sistema Operativo\n";
		cout<<"5- Taller\n";
		cout<<"Materia (1-5): ";
		cin>>materia;		
	}
	fflush(stdin);
	return (materia - 1);
}

int cargaPuntaje(void){
	fflush(stdin);
	int puntaje;
	cout<<"Ingrese Puntaje: ";
	cin>>puntaje;
	while(puntaje < 0){
		cout<<"¡Error! Debe ingresar numeros positivos.\n";
		cout<<"Ingrese Puntaje: ";
		cin>>puntaje;		
	}
	fflush(stdin);
	return puntaje;
}

/*
5) Crear una lista de puntajes de un curso para varias materias donde los datos a registrar
son los siguientes: nombre, materia, puntaje. Mostrar la lista y el promedio de puntaje
de las materias, como también el promedio general entre todas las materias
*/

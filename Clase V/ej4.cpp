#include <iostream>
#include <windows.h>

using namespace std;

//Prototipado de funciones
void cargaFC(int &, int &);
void cargarMatriz(int **, int, int);
void mostrarMatriz(int **, int, int);
int sumaDP(int **, int, int);

main(){
	system("cls");
	int f, c;
	cargaFC(f, c);
	
	//Creacion de la Matriz Dinamica
	int **Matriz = new int *[f];
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			*(Matriz + j)= new int[c];		
		}
	}
	
	cargarMatriz(Matriz, f, c);
	
	system("cls");
	
	mostrarMatriz(Matriz, f, c);
	
	cout<<"La suma de los elementos de la Diagonal Principal es: "<<sumaDP(Matriz, f, c)<<"\n";
	
	//Eliminacion de la Matriz dinamica creada
	for (int i = 0; i < f; i++)
    {
        delete[] Matriz[i];
    }
	Matriz = NULL;
    delete[] Matriz;
	
	system("pause");
	return 0;
}

//Funciones
void cargaFC(int &f, int &c){
	//Toma los valores ingresados por el usuario para la cantidad de filas y columnas y los valida.
	cout<<"Ingrese la cantidad de filas que desea que tenga la matriz: ";
	cin>>f;
	while(f < 1){
		cout<<"Debe ingresar al menos una fila.\nVuelva a ingresar.\n";
		cout<<"Ingrese la cantidad de filas que desea que tenga la matriz: ";
		cin>>f;
	}
	cout<<"Ingrese la cantidad de columnas que desea que tenga la matriz: ";
	cin>>c;
	while(c < 1){
		cout<<"Debe ingresar al menos una columna.\nVuelva a ingresar.\n";
		cout<<"Ingrese la cantidad de columnas que desea que tenga la matriz: ";
		cin>>c;
	}
	return;
}

void cargarMatriz(int **Matriz, int f, int c){
	//Toma la Matriz creada, el limite de fila y el limite de columna y carga datos al interior de la estructura de datos
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<"Carga de Datos.\nPosicion: ( "<<i+1<<", "<<j+1<<" ): ";
			cin>>*(*( Matriz + i ) + j);
		}
	}
	return;
}

void mostrarMatriz(int **Matriz, int f, int c){
	//Toma una matriz cualquiera, el limite de fila y el limite de columna e imprime los datos cargados al interior de ella
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			if(j==0){
				cout<<"| " << *(*(Matriz + i) +j ) << " | ";
			}else if(j==(c-1)){
				cout<< *(*(Matriz + i) +j ) << " |\n";
			}else{
				cout<< *(*(Matriz + i) +j ) << " | ";
			}
		}
	}
	return;
}

int sumaDP(int **Matriz, int f, int c){
	//Devuelve la suma de los elementos de la diagonal principal
	int sumaDP=0;
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			if((i + j) == (c-1)){ //Diagonal Principal = (Indice de fila + Indice de Columna == Limite de Columna - 1).
				sumaDP= sumaDP + (*(*(Matriz + i) + j));
			}
		}
	}
	return sumaDP;
}


/*
4) Crear y cargar una matriz dinámica y con el siguiente menú de selección, desarrolla las rutinas para cada uno:
- cargarMatriz: se encargará de agregar elementos a la matriz dinámica.
- mostrarMatriz: se encargará de mostrar los elementos cargados en la matriz dinámica.
- sumaDP: se encargará de hallar la sumatoria de los elementos de la diagonal principal. 
*/

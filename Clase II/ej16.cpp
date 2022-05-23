#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int f, c;
	cout<<"Ingrese la cantidad de filas que tendra la matriz: ";
	cin>>f;
	while(f < 1){
		cout<<"Error!.\nDebe ingresar al menos una fila.\n";
		cout<<"Ingrese la cantidad de filas que tendra la matriz: ";
		cin>>f;
	}

	cout<<"Ingrese la cantidad de columnas que tendra la matriz: ";
	cin>>c;
	while(c < 1){
		cout<<"Error!.\nDebe ingresar al menos una fila.\n";
		cout<<"Ingrese la cantidad de filas que tendra la matriz: ";
		cin>>c;
	}
	
	//Carga de Elementos en el Vector
	int A[f][c], SF[f]{}, SC[c]{};
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<"Carga de Elementos.\n Posicion "<<i+1<<", "<<j+1<<": ";
			cin>>A[i][j];
			//Asignacion de Valores a los vectores de suma
			SF[i]= SF[i]+A[i][j];
			SC[j]= SC[j]+A[i][j];
		}
	}
	
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<f;i++){
		cout<<"| ";
		for(int j=0; j<c;j++){
			if(j == (c-1)){
				cout<<A[i][j]<<" |\n";
			}else
				cout<<A[i][j]<<" | ";
		}
	}
	
	cout<<"Vector con la sumatoria de las filas:\n";
	for(int i=0; i<f; i++){
		if(i==(f-1)){
			cout<<SF[i]<<" \n";
		}else{
			cout<<SF[i]<<" | ";
		}
	}
	
	cout<<"\nVector con la sumatoria de las columnas:\n";
	for(int i=0; i<c; i++){
		if(i==(f-1)){
			cout<<SC[i]<<" \n";
		}else{
			cout<<SC[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
Crear y cargar una matriz A y a su vez dos vectores SF (Sumatoria de Filas) y SC (Sumatoria de Columnas) los
cuales contendrán la sumatoria de filas y columnas correspondientes a la matriz A, como se muestra en la figura.
Imprimir las estructuras de datos. 
*/

#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int f, c;
	cout<<"Ingrese la cantidad de filas que desea que tenga la matriz: ";
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
	
	int M[f][c], perimetro=0;
	int P[f][c];
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<"Carga de Elementos.\nPosicion "<<i+1<<", "<<j+1<<": ";
			cin>>M[i][j];
			if(i==0 || j==0){
				P[i][j]=M[i][j];
				perimetro=perimetro+M[i][j];
			}else if(i==(f-1) || j==(c-1)){
				P[i][j]=M[i][j];
				perimetro=perimetro+M[i][j];
			}
		}
		system("cls");
	}
	
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<f; i++){
		cout<<"| ";
		for(int j=0; j<c; j++){
			if(j==(c-1)){
				cout<<M[i][j]<<" |\n";			
			}else{
				cout<<M[i][j]<<" | ";				
			}
		}
	}
	
	cout<<"Perimetro de la Matriz Cargada: "<<perimetro<<"\n";
	for(int i=0; i<f; i++){
		cout<<"| ";
		for(int j=0; j<c; j++){
			if(i==0 || j==0){
				cout<<P[i][j]<<" | ";
			}else if(i==(f-1) || j==(c-1)){
				cout<<P[i][j]<<" | ";
			}else{
				cout<<"   ";
			}
			if(j==(c-1)){
				cout<<"\n";				
			}
		}
	}

	system("pause");
	return 0;
}

/*
21) Crear y cargar una matriz M. Imprimir la matriz y el perímetro del mismo como se muestra en la figura.
*/

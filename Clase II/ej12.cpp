#include <iostream>
#include <windows.h>
using namespace std;

main(){
	system("cls");

	int n;
	cout<<"Ingrese cantidad de filas y columnas que tendra la matriz: ";
	cin>>n;
	//Validacion del input de cantidad de f y c
	while(n < 1){
		cout<<"Error!. Debe cargar al menos 1 fila y 1 columna.\n";
		cout<<"Ingrese cantidad de filas y columnas que tendra la matriz: ";
		cin>>n;
	}
	system("cls");

	int A[n][n], DP[n];
	
	//Carga de los Elementos dentro del vector
	for(int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			cout<<"Elemento "<<i+1<<", "<<j+1<<": ";
			cin>>A[i][j];
			if(i==j){
				DP[i]=A[i][j];
			}
		}
		system("cls");
	}
	
	system("cls");  
	
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<n;i++){
		cout<<"| ";
		for(int j=0; j<n; j++){
			if(j!=n-1){
				cout<<A[i][j]<<" | ";		
			}else{
				cout<<A[i][j];
			}
		}
		cout<<" |\n";
	}
	
	for(int i=0;i<n; i++){
		if(i==0){
			cout<<"\nVector con los elementos de la Diagonal Principal: ["<<DP[i]<<" | ";
		}else if(i==n-1){
			cout<<DP[i]<<"]\n";
		}else{
			cout<<DP[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
12) Crear y cargar una matriz A y un vector DP. Guardar los elementos de la diagonal principal de la matriz A en el
vector DP. Imprimir ambas estructuras de datos.
*/

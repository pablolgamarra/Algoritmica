#include <iostream>
#include <windows.h>

using namespace std;

bool multiplo3(int num){
	if(num % 3 == 0){
		return true;
	}
}

bool par(int num){
	if(num%2==0){
		return true;
	}
}

main(){
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
	
	int A[f][c], multiplos=0, pares=0, M3[c]{}, CP[f]{};
	
	//Carga de los Elementos en el Vector A
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<"Carga de Elementos. Elemento "<<i+1<<", "<<j+1<<": ";
			cin>>A[i][j];
			//Filtrado de los Elementos Pares
			if(A[i][j] % 2 == 0){
				CP[i]=CP[i]+1;
			}
			//Filtrado de los Multiplos de Tres y Mayores que Seis
			if(A[i][j] % 3 == 0 && A[i][j] > 6){
				M3[j]=M3[j]+1;
			}
		}
	}
	
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<f;i++){
		cout<<"| ";
		for(int j=0; j<c;j++){
			if(j == (c-1)){
				cout<<A[i][j]<<" |\n";
			}else{
				cout<<A[i][j]<<" | ";
			}
		}
	}
	
	cout<<"Vector con la cantidad de multiplos de 3, mayores que 6 de cada fila:\n";
	for(int i=0; i<c; i++){
		if(i==(f-1)){
			cout<<M3[i]<<" \n";
		}else{
			cout<<M3[i]<<" | ";
		}
	}
	
	cout<<"\nVector con la cantidad de pares de cada fila:\n";
	for(int i=0; i<f; i++){
		if(i==(f-1)){
			cout<<CP[i]<<" \n";
		}else{
			cout<<CP[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
17) Crear y cargar una matriz A y los vectores M3 y CP que tendrán 
M3 = Cantidad de múltiplos de 3 mayores que 6
y 
CP = Cantidad de elementos pares, todos de la matriz A. Imprimir las estructuras de datos.
*/

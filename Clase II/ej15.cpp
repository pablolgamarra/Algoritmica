#include <iostream>
#include <windows.h>

using namespace std;

bool esPrimo(int num){
	int divisibles=0;
	for(int x=1; x<=num; x++){
		if((num%x) == 0){
			divisibles++;
		}
	}
	if(divisibles == 2){
		return true;
	}else{
		return false;
	}
}

main(){
	int n;
	cout<<"Ingrese la cantidad de filas y columnas que desea que tenga la matriz: ";
	cin>>n;
	while(n < 1){
		cout<<"Error!. Debe ingresar al menos una fila y una columna.\nVuelva a cargar.\n";
		cout<<"Ingrese numero de filas y columnas que desea que tenga la matriz: ";
		cin>>n;
	}
		
	int G[n][n];
	bool P[n];
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			cout<<"Elemento "<<i+1<<", "<<j+1<<": ";
			cin>>G[i][j];
			if(esPrimo(G[i][j])){
				P[i]=true;
			}
		}
	}
	
	cout<<"Matriz Cargada.\n";
	for(int i=0; i<n;i++){
		cout<<"| ";
		for(int j=0; j<n;j++){
			if(j == (n-1)){
				cout<<G[i][j]<<" |\n";
			}else
				cout<<G[i][j]<<" | ";
		}
	}
	
	for(int i=0; i<n; i++){
		if(P[i]){
			cout<<"La fila "<<i+1<<" tiene numeros primos\n";
		}else{
			cout<<"La fila "<<i+1<<" no tiene ningun numero primo.\n";
		}
	}
	
	system("pause");
	return 0;
}

/*
15) Ingresar los elementos de una matriz G, decir independientemente en cuál de las filas fue ingresado números
primos. Imprimir las estructuras de datos. 
*/

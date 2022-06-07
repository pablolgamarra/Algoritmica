#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int n;
	cout<<"Ingrese la cantidad de filas y columnas desea que tenga la matriz: ";
	cin>>n;
    while(n < 1){
    	cout<<"Error!. Debe ingresar al menos una fila y una columna.\nVuelva a ingresar.";
    	cout<<"Ingrese la cantidad de filas y columnas que desea que tenga la matriz: ";
    	cin>>n;
	}
	
	int B[n][n], DS[n];
	//Carga de Datos en el Vector B
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"Carga de Datos.\nElemento "<<i+1<<", "<<j+1<<":";
			cin>>B[i][j];
			//Carga del Vector de la Diagonal Secundaria
			if((i+j) == (n-1)){
				DS[i] = B[i][j];
			}
		}
	}
	
	system("cls");
	cout<<"Matriz Cargada: \n";
	for(int i=0; i<n; i++){
		cout<<"| ";
		for(int j=0; j<n; j++){
			if(j==(n-1)){
				cout<<B[i][j]<<" ";
			}else{
				cout<<B[i][j]<<" | ";
			}
		}
		cout<<" |\n";
	}
	
	cout<<"Vector con los Elementos de la Diagonal Secundaria:\n";
	for(int i=0; i<n; i++){
		if(i==0){
			cout<<"| "<<DS[i]<<" | ";
		}else if(i==(n-1)){
			cout<<DS[i]<<" |\n";
		}else{
			cout<<DS[i]<<" | ";
		}
	}
	
	bool verificado = false;
	int aux=0;
	
	//Ordenamiento de Forma Ascendente del Vector de la diagonal secundaria
	while(!verificado){
		verificado=true;
		for(int i=0; i<(n-1);i++){
			if(DS[i]>DS[i+1]){
				verificado=false;
				aux=DS[i];
				DS[i]=DS[i+1];
				DS[i+1]=aux;
			}
		}
	}
	
	cout<<"Vector con los Elementos de la Diagonal Secundaria ordenados de forma ascendente:\n";
	for(int i=0; i<n; i++){
		if(i==0){
			cout<<"| "<<DS[i]<<" | ";
		}else if(i==(n-1)){
			cout<<DS[i]<<" |\n";
		}else{
			cout<<DS[i]<<" | ";
		}
	}
	
	verificado=false;

	//Ordenamiento de Forma Descendente del Vector de la diagonal secundaria	
	while(!verificado){
		verificado=true;
		for(int i=0; i<(n-1);i++){
			if(DS[i] < DS[i+1]){
				verificado=false;
				aux=DS[i];
				DS[i]=DS[i+1];
				DS[i+1]=aux;
			}
		}
	}
	
	cout<<"Vector con los Elementos de la Diagonal Secundaria ordenados de forma descendente:\n";
	for(int i=0; i<n; i++){
		if(i==0){
			cout<<"| "<<DS[i]<<" | ";
		}else if(i==(n-1)){
			cout<<DS[i]<<" |\n";
		}else{
			cout<<DS[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
20) Crear una matriz B y un vector DS. Cargar el vector DS con los elementos de las de datos (Imprimir el vect diagonal secundaria de la matriz.
Ordenar el vector en forma Ascendente y Descendente. Imprimir las estructuraor
antes y después de cada proceso de orden) 
*/

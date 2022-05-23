#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int n,m;
	cout<<"Cargue una matriz de dimension cualquiera.\n";
	cout<<"Ingrese numero de filas: ";
	cin>>n;
	while(n < 1){
		cout<<"Error!. Debe ingresar al menos una fila.\nVuelva a cargar.\n";
		cout<<"Ingrese numero de filas: ";
		cin>>n;
	}
	
	cout<<"Ingrese numero de columnas: ";
	cin>>m;
	while(m < 1){
		cout<<"Error!. Debe ingresar al menos una columna.\nVuelva a cargar.\n";
		cout<<"Ingrese numero de filas: ";
		cin>>m;
	}
	
	int A[n][m], MAYORES[m], MENORES[m];
	
	//Carga de Elementos
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"Carga Elemento Fila "<<i+1<<" Columna "<<j+1<<": ";
			cin>>A[i][j];
			//Filtrado de Mayores y Menores
			if(i==0){
				MAYORES[j]=A[i][j];
				MENORES[j]=A[i][j];
			}else if(A[i][j] > MAYORES[j]){
				MAYORES[j]=A[i][j];
			}else if(A[i][j] < MENORES[j]){
				MENORES[j]= A[i][j];
			}
		}
	}
	
	cout<<"Matriz Cargada\n";
	for(int i=0; i<n;i++){
		cout<<"| ";
		for(int j=0; j<m; j++){
			if(j!=m-1){
				cout<<A[i][j]<<" | ";		
			}else{
				cout<<A[i][j];
			}
		}
		cout<<" |\n";
	}
	
	for(int i=0;i<m; i++){
		if(i==0){
			cout<<"Vector con los elementos menores de cada columna: ["<<MENORES[i]<<" | ";
		}else if(i==m-1){
			cout<<MENORES[i]<<"]\n";
		}else{
			cout<<MENORES[i]<<" | ";
		}
	}
	
	for(int i=0;i<m; i++){
		if(i==0){
			cout<<"Vector con los elementos mayores de cada columna: ["<<MAYORES[i]<<" | ";
		}else if(i==m-1){
			cout<<MAYORES[i]<<"]\n";
		}else{
			cout<<MAYORES[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
14) Ingresar las dimensiones de una matriz M, Encontrar el mayor y menor elemento de cada columna. Imprimir las
estructuras de datos
*/

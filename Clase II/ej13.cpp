#include <iostream>

using namespace std;

main(){
	int n,m;
	cout<<"Cargue una matriz de dimension cualquiera.\n";
	cout<<"Ingrese numero de filas: ";
	cin>>n;
	cout<<"Ingrese numero de columnas: ";
	cin>>m;
	int A[n][m],MAYORES[n];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"Carga Elemento Fila "<<i+1<<" Columna "<<j+1<<": ";
			cin>>A[i][j];
			if(j==0){
				MAYORES[i]=A[i][j];
			}else if(A[i][j] > MAYORES[i]){
				MAYORES[i]=A[i][j];
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
	for(int i=0;i<n; i++){
		if(i==0){
			cout<<"Vector con los elementos mayores de cada fila: ["<<MAYORES[i]<<" | ";
		}else if(i==n-1){
			cout<<MAYORES[i]<<"]\n";
		}else{
			cout<<MAYORES[i]<<" | ";
		}
	}
}

/*
13) Ingresar las dimensiones de una matriz cualquiera. Encontrar el mayor y menor elemento de cada fila. Imprimir la
matriz. 
*/

#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int n;
	cout<<"Ingrese la cantidad de filas y columnas que desea que tenga la matriz: ";
	cin>>n;
    while(n < 1){
    	cout<<"Error!. Debe ingresar al menos una fila y una columna.\nVuelva a ingresar.";
    	cout<<"Ingrese la cantidad de filas y columnas que desea que tenga la matriz: ";
    	cin>>n;
	}
	
	int B[n][n], suma=0, mayor=0, menor=0, dosDigitos=0, divisibles=0;
	bool primo=false;
	
	//Carga de Datos en el Vector B
	for(int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			cout<<"Carga de Datos.\nElemento "<<i+1<<", "<<j+1<<": ";
			cin>>B[i][j];
			if(i==j){
				//Suma de los datos en el vector de sumas
				suma=suma+B[i][j];
				
				//Toma de Muestra para el mayor y el menor
				if(i==0){
					mayor=B[i][j];
					menor=B[i][j];
				}
				
				//Filtrado de los menores y mayores de la matriz
				if(B[i][j] < menor){
					menor=B[i][j];
				}
				if(B[i][j] > mayor){
					mayor=B[i][j];
				}
				
				//Filtrado de los numeros con mas de dos digitos
				if(B[i][j] > 99 || B[i][j] < (- 99)){
					dosDigitos++;
				}
				
				
				if(i==(n-1)){
					for(int x=1; x<=suma;x++){
						if(suma % x == 0){
							divisibles++;
						}
					}
				}
			}
		}
		system("cls");
	}
	
	if(divisibles > 2){
		primo=false;
	}else{
		primo=true;
	}
	
	system("cls");
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<n; i++){
		cout<<"| ";
		for(int j=0; j<n; j++){
			if(j != (n-1)){
				cout<<B[i][j]<<" | ";				
			}else{
				cout<<B[i][j];
			}
		}
		cout<<" |\n";
	}
	
	cout<<"Resumen sobre datos de la Diagonal Principal:\n";
	cout<<"Suma: "<<suma<<"\n";
	cout<<"Mayor Elemento: "<<mayor<<"\n";
	cout<<"Menor Elemento: "<<menor<<"\n";
	cout<<"Numeros con mas de Dos Digitos: "<<dosDigitos<<"\n";
	
	if(primo){
		cout<<"La Sumatoria es Primo?: Si\n";
	}else{
		cout<<"La Sumatoria es Primo?: No\n";		
	}
	
	system("pause");
	return 0;
}

/*
19) Cargar los elementos de una matriz B. realizar un resumen sobre los elementos de la diagonal principal según
se muestra en la figura. Imprimir la matriz y los datos hallados. 
-Suma elementos Diagonal Principal
-Mayor Elemento
-Menor Elemento
-Numeros con mas de 2 digitos
-La sumatoria es primo
*/

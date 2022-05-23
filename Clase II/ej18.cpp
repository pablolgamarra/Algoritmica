#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int n;
    cout<<"Ingrese la cantidad de filas y columnas que desea que tenga la matriz: ";
    cin>>n;
    while(n < 1){
    	cout<<"Error!. Debe ingresar al menos una fila y una columna.\nVuelva a ingresar.";
    	cout<<"Ingrese la cantidad de filas y columnas que desea que tenga la matriz: ";
    	cin>>n;
	}
	
    int A[n][n], MEN[n],MAY[n],x=0;
    float P[n]{0};
    
	for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cout<<"Carga de Datos.\nIngrese valor para posicion "<<i+1<<", "<<j+1<<": ";
            cin>>A[i][j];
            while(A[i][j] < 0 || A[i][j] > 10){
            	cout<<"Solo numeros positivos menores a 10. Vuelva a cargar: ";
            	cin>>A[i][j];
			}
			if(j==0){
				MEN[x]=A[i][j];            	
				MAY[x]=A[i][j];
			}else if(A[i][j]< MEN[x]){
				MEN[x]=A[i][j];
			}else if(A[i][j]>MAY[x]){
				MAY[x]=A[i][j];
			}
			P[j]=P[j] + A[i][j];
        }
        x++;
        system("cls");
    }

	system("cls");
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<n;i++){
		cout<<"| ";
		for(int j=0; j<n;j++){
			if(j == (n-1)){
				cout<<A[i][j]<<" |\n";
			}else{
				cout<<A[i][j]<<" | ";
			}
		}
	}
	
	cout<<"Vector con los elementos menores de cada fila.\n";
	for(int i=0; i<n; i++){
		if(i==(n-1)){
			cout<<MAY[i]<<" \n";
		}else{
			cout<<MAY[i]<<" | ";
		}
	}
	cout<<"\n";
	
	cout<<"Vector con los elementos mayores de cada fila.\n";
	for(int i=0; i<n; i++){
		if(i==(n-1)){
			cout<<MEN[i]<<" \n";
		}else{
			cout<<MEN[i]<<" | ";
		}
	}

	cout<<"\nVector con los promedios de cada columna.\n";
	for(int i=0; i<n; i++){
		if(i==(n-1)){
			cout<<P[i]/n<<" \n";
		}else{
			cout<<P[i]/n<<" | ";
		}
	}
	cout<<"\n";
	
	system("pause");	
    return 0;
}

/*
Cargar una matriz A con cualquier numero positivo menor a 10. Hallar el mayor, menor elemento 
de cada fila y el promedio de cada columna. (Considerar los vectores Men, May y P). 
*/

#include <iostream>

using namespace std;

main(){
	int n;
	cout<<"Ingrese la cantidad de elementos que tendra vector: ";
	cin>>n;
	int N[n];
	for(int i=0; i<n; i++){
		cout<<"Carga de Datos. Elemento "<<i+1<<": ";
		cin>>N[i];
		for(int j=0; j<i; j++){
			while(N[i] == N[j]){
				cout<<"No se pueden cargar dos elementos de igual valor.\n Volver a cargar posicion "<<i+1<<": ";
				cin>>N[i];
			}
		}
	}
	cout<<"Vector Cargado:\n";
	for(int i=0; i<n;i++){
		if(i == (n-1)){
			cout<<N[i]<<" |\n";
		}else
			cout<<N[i]<<" | ";
	}
	return 0;
}

//11) Crear y cargar un vector “N” donde ningún elemento sea repetido. Imprimir el vector. 

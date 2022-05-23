#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int n;
	cout<<"Ingrese la cantidad de elementos que quiere cargar: ";
	cin>>n;
	while(n < 1){
		cout<<"\e[0;31m Debe cargarse al menos un numero!.\nIngrese un valor diferente: ";
		cin>>n;
	}
	int N[n];
	bool verificado=false;
	for(int i=0; i<n; i++){
			cout<<"Carga de Datos.\n";
			cout<<"\e[0m Elemento: "<<i+1<<": ";
			cin>>N[i];
			do{
				verificado=true;
				for(int j=0; j<i;j++){
					while(N[i]==N[j]){
						cout<<"\e[0;31m No se puede ingresar el mismo numero dos veces!.\nIngrese un valor diferente: ";
						cin>>N[i];
						verificado=false;
					}
				}
			}while(!verificado);
	}
	cout<<"\e[0m";
	for(int i=0; i<n;i++){
		if(i==0){
			cout<<"Vector Cargado: ["<<N[i]<<" | ";
		}else if(i == n-1){
			cout<<N[i]<<"]\n";
		}else{
			cout<<N[i]<<" | ";
		}
	}
	system("pause");
	return 0;
}

/*
11) Crear y cargar un vector “N” donde ningún elemento sea repetido. Imprimir el vector. 
*/

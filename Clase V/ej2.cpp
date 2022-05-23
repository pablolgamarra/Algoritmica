#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int n;
	cout<<"Ingrese la cantidad de elementos que desea cargar: ";
	cin>>n;
	//Validacion del numero de elementos
	while(n < 1){
		cout<<"Error. Solo numeros positivos.\n";
		cout<<"Ingrese la cantidad de elementos que desea cargar: ";
		cin>>n;
	}
	
	int A[n], *puntero, menor;
	puntero= &A[0];
	
	for(int i=0; i<n; i++){
		cout<<"Carga de Datos. Posicion: "<<i+1<<": ";
		cin>>*(puntero + i);
		if(i==0){
			menor=*(puntero+i);
		}else if(*(puntero+i) < menor){
			menor=*(puntero + i);
		}
	}
	
	//Impresion del Vector Cargado
	for(int i=0; i<n; i++){
		if(i==0){
			cout<<"| "<<puntero[i]<<" | ";
		}else if(i == (n-1)){
			cout<<puntero[i]<<" |\n";
		}else{
			cout<<puntero[i] <<" | ";
		}
	}
	cout<<"El menor valor ingresado es: "<<menor<<"\n";
	puntero = NULL;
	system("pause");
}

/*
2) Rellenar un arreglo con “n” números, posteriormente utilizando punteros determinar el menor elemento del
arreglo. 
*/

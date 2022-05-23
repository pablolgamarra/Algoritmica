#include <iostream>
#include <windows.h>

using namespace std;

//Prototipado de las funciones usadas

void cargaArray(int *&, int);

int mayorElemento(int *&, int);

int menorElemento(int *&, int);

float valorPromedio(int *&, int);

void cantidadPar_Impar(int *&, int, int &, int &);

void imprimeArray(int *, int);

main(){
	system("cls");
	int n, pares=0, impares=0;
	cout<<"Ingrese la cantidad de elementos que desea que tenga el vector a cargar (Entre 10 y 50): ";
	cin>>n;
	
	//Validacion de elementos a cargar
	while(n < 10 || n > 50){
		system("cls");
		cout<<"Error, debe cargar entre 10 y 50 numeros en el vector.\nVuelva a cargar.\n";
		cout<<"Ingrese la cantidad de elementos que desea que tenga el vector a cargar: ";
		cin>>n;
	}
	
	int *N = new int[n];
	
	system("cls");
	cargaArray(N, n);

	system("cls");
	imprimeArray(N, n);
	cout<<"El mayor elemento del Vector cargado es: " << mayorElemento(N, n) << "\n";
	cout<<"El menor elemento del Vector cargado es: " << menorElemento(N, n) << "\n";
	cout<<"El valor promedio del Vector cargado es: " << valorPromedio(N, n) << "\n";
	cantidadPar_Impar(N, n, pares, impares);
	cout<<"La cantidad de pares en el Vector es: " << pares << "\n";
	cout<<"La cantidad de impares en el Vector es: " << impares << "\n";
	
	system("pause");
	return 0;
}

void cargaArray(int *&N, int n){
	for(int i=0; i<n; i++){
		cout<<"Carga de Datos.\n Ingrese valor para posicion "<<i+1<<": ";
		cin>>*(N + i);
	}
	return;
}

void imprimeArray(int *N, int n){
	for(int i=0; i<n; i++){
		if(i==0){
			cout<<"| "<< *(N + i) <<" | ";
		}else if(i == (n-1)){
			cout<< *(N + i) <<" |\n";
		}else{
			cout<< *(N + i) <<" | ";
		}
	}
	return;
}

int mayorElemento(int *&N, int n){
	int mayor;
	for(int i=0; i<n; i++){
		if(i == 0){
			mayor=*(N+i);
		}else if(mayor < *(N+i)){
			mayor=*(N+i);
		}
	}
	return mayor;
}

int menorElemento(int *&N, int n){
	int menor;
	for(int i=0; i<n; i++){
		if(i == 0){
			menor=*(N+i);
		}else if(menor > *(N+i)){
			menor=*(N+i);
		}
	}
	return menor;
}

float valorPromedio(int *&N, int n){
	float promedio=0;
	for(int i=0; i<n; i++){
		promedio = (promedio + *(N+i));	
	}
	return promedio / n;
}

void cantidadPar_Impar(int *&N , int n, int &pares, int &impares){
	for(int i=0; i<n; i++){
		if((*(N+i) % 2) == 0){
			pares++;
		}else{
			impares++;
		}
	}
	return;
}


/*
3) Crear un Array dinámico N (unidimensional) utilizando una función para obtener la cantidad de elementos en el
array, teniendo en cuenta que el número de elementos debe estar entre 10 y 50.
 Utilizar las siguientes rutinas para encontrar los siguientes valores.
mayorElemento( ) Se encargará de hallar el mayor elemento ingresado en el array
menorElemento() Se encargará de hallar el menor elemento ingresado en el array
valorPromedio() Encontrará el promedio de valores ingresados en el array
CantidadPar_Impar( ) Encontrará la cantidad de pares e impres ingresados en el array
imprimeArray( ) Se encargará de imprimir el array creado 
*/

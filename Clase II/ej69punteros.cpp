#include <iostream>

using namespace std;

main(){
	int f, c, *SFP=NULL, *SCP=NULL, **M=NULL;
	cout<<"Ingrese la cantidad de filas que tendra la matriz: ";
	cin>>f;
	cout<<"Ingrese la cantidad de columnas que tendra la matriz: ";
	cin>>c;
	for(int i=0; i<f; i++){
		M=new int*[c];
	}
	SFP= new int[f];
	SCP= new int [c];
	
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<"Carga de Elementos.\n Posicion "<<i+1<<", "<<j+1<<": ";
			cin>>A[i][j];
			*(SFP+i)= *(SFP+i) + *((M+i)+j);
			*(SFP+i)= *(SCP+j) + *((M+i)+j);
		}
	}
	cout<<"Matriz Cargada:\n";
	for(int i=0; i<f;i++){
		cout<<"| ";
		for(int j=0; j<c;j++){
			if(j == (c-1)){
				cout<<*((M+i)+j)<<" |\n";
			}else
				cout<<*((M+i)+j)<<" | ";
		}
	}
	cout<<"Vector con la sumatoria de las filas:\n";
	for(int i=0; i<f; i++){
		if(i==(f-1)){
			cout<<*(SFP+i)<<" \n";
		}else{
			cout<<*(SFP+i)<<" | ";
		}
	}
	cout<<"\n";
	cout<<"Vector con la sumatoria de las columnas:\n";
	for(int i=0; i<c; i++){
		if(i==(f-1)){
			cout<<*(SCP+i)<<" \n";
		}else{
			cout<<*(SCP+i)<<" | ";
		}
	}
	delete [] SFP;
	delete [] SCP;
	*SCP= NULL;
	*SFP= NULL;
	return 0;
}

/*
Crear y cargar una matriz A y a su vez dos vectores SF (Sumatoria de Filas) y SC (Sumatoria de Columnas) los
cuales contendrán la sumatoria de filas y columnas correspondientes a la matriz A, como se muestra en la figura.
Imprimir las estructuras de datos. 
*/

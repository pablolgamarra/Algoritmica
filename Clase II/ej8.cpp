#include <iostream>
#include <windows.h>

using namespace std;

main(){
	int V[10], aux=0;
	system("cls");
	
	cout<<"Cargar un vector de 10 elementos y el programa los desplazara a la izquierda.\n";
	
	//Carga del Vector 'V'
	for(int i=0; i<10; i++){
		cout<<"Elemento "<<i+1<<": ";
		cin>>V[i];
		system("cls");
	}
	aux=V[0];
	system("cls");
	
	for(int i=0; i<10; i++){
		if(i == 0){
			cout<<"Vector antes de desplazar los elementos: ["<<V[i]<<" | ";
			V[i]=V[i+1];
		}else if(i == 9){
			cout<<V[i]<<"]\n";
			V[i]=aux;
		}else{
			cout<<V[i]<<" | ";
			V[i]=V[i+1];
		}
	}
	
	for(int i=0; i<10; i++){
		if(i == 0){
			cout<<"Vector luego de desplazar los elementos: ["<<V[i]<<" | ";
		}else if(i == 9){
			cout<<V[i]<<"]\n";
		}else{
			cout<<V[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
8) Cargar un vector de 10 elementos y desplazar cíclicamente sus elementos un lugar hacia la izquierda. Imprimir el
vector antes y después de desplazar. 
*/

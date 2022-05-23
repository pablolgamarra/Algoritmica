#include <iostream>
#include <windows.h>

using namespace std;

main(){
	int A[10],B[5],C[5];
	system("cls");
	cout<<"Cargar un vector de 10 elementos.\n";
	
	//Carga del Vector 'A'
	for(int i=0; i<10; i++){
		cout<<"Elemento "<<i+1<<": ";
		cin>>A[i];
		system("cls");
	}
	
	//Contador para ordenar
	int j=5;
	
	//Carga de los vectores 'B' y 'C'
	for(int i=0; i<5; i++){	
		B[i]=A[i];
		C[i]=A[j];
		j++;
	}
	
	//Impresion en Pantalla
	for(int i=0; i<10; i++){
		if(i==0){
			cout<<"Vector A: ["<<A[i]<<" | ";			
		}else if(i == 9){
			cout<<A[i]<<"]\n";
		}else{
			cout<<A[i]<<" | ";
		}
	}
	
	for(int i=0; i<5; i++){
		if(i==0){
			cout<<"Vector B: ["<<B[i]<<" | ";			
		}else if(i == 4){
			cout<<B[i]<<"]\n";
		}else{
			cout<<B[i]<<" | ";
		}
	}
	
	for(int i=0; i<5; i++){
		if(i==0){
			cout<<"Vector C: ["<<C[i]<<" | ";			
		}else if(i == 4){
			cout<<C[i]<<"]\n";
		}else{
			cout<<C[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*9) Leer un vector de con 10 elementos. 
Luego pasar los primeros 5 elementos de dicho vector a otro nuevo vector B.
También pasar los últimos 5 elementos de este último a otro vector C. 
Imprime los 3 vectores.*/

#include <iostream>

using namespace std;

main(){
	int num,sumaPares=0;
	cout<<"Ingrese un numero mayor a 50: ";
	cin>>num;
	while(num <= 50){
		cout<<"El numero ingresado debe ser mayor a 50.\n";
		cout<<"Ingrese un numero mayor a 50: ";
		cin>>num;
	}
	for(int i=1; i<=num; i++){
		if(i != num){
			if(i % 2 != 0){
				cout<<i<<", ";
			}else{
				sumaPares=sumaPares+i;
			}			
		}else{
			if(i % 2 != 0){
				cout<<i<<"\n";
			}else{
				sumaPares=sumaPares+i;
			}
		}


	}
	cout<<"La suma de los numeros pares de la serie es: "<<sumaPares<<"\n";
}

/*
3) Ingresar un número mayor a 50. Generar una serie a partir de 1 hasta el número ingresado e imprimir solo los
números impares y calcular e imprimir la sumatoria de los números pares de la serie. 
*/

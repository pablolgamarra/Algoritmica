#include <iostream>

using namespace std;

main(){
	int cantNumeros, mayor, menor;
	cout<<"Ingrese la cantidad de numeros que desea ingresar: ";
	cin>>cantNumeros;
	int nums[cantNumeros];

	for(int i=0; i<cantNumeros; i++){
		cout<<"La cantidad de numeros ingresados hasta el momento es: "<<i+1<<"\n";
		cout<<"Ingrese numero: ";
		cin>>nums[i];
		if(i==0){
			menor=nums[i]; 
			mayor=nums[i];
		}else{
			if(nums[i] < menor){
				menor=nums[i];
			}
			if(nums[i]>mayor){
				mayor=nums[i];
			}
		}
	}
	cout<<"La cantidad de numeros ingresados en total es: "<<cantNumeros<<"\n";
	cout<<"El menor numero ingresado es: "<<menor<<"\n";
	cout<<"El mayor numero ingresado es: "<<mayor<<"\n";
	if(menor <= 0){
		cout<<"La tabla del menor numero no se puede hacer porque es negativo o igual a cero";
	}else{
		cout<<"Tabla de: "<<menor<<"\n";
		for(int i=1; i<=10;i++){
			cout<<menor<<" x "<<i<<" ="<<menor*i<<"\n";
		}
	}
}

/*
4) Ingresar tantos n�meros como se desee hasta un n�mero ingresado previamente. 
Indica cuantos n�meros fueron ingresados, adem�s encontrar el mayor y menor n�mero encontrado 
e imprimir la tabla de multiplicar del
menor, 
solo si este es un n�mero positivo, en caso de negativo, enviar un mensaje indicando �El n�mero es
negativo o igual a cero�.
*/

#include <iostream>

using namespace std;

main(){
	int num, aux=0;
	bool divisibles=false;
	cout<<"Ingrese un numero positivo: ";
	cin>>num;
	while(num <= 0){
		cout<<"Ingrese un numero positivo(Mayor a Cero): ";
		cin>>num;
	}
	for(int i=2; i<=num; i++){
		aux=num;
		while(aux>0){
			aux=aux-2;
		}
		if(aux==0){
			divisibles=true;
			break;
		}
	}
	if(divisibles){
		cout<<"El numero ingresado no es un numero primo.\n";
	}else{
		cout<<"El numero ingresado es un numero primo.\n";
	}

}

/*
5) Ingresar un número positivo. Decir si el mismo es o no primo con el método de sumas o restas
 sucesivas.
*/

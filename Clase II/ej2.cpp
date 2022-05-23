#include <iostream>

using namespace std;

main(){
	int num,aux=0;
	cout<<"Ingrese un numero: ";
	cin>>num;
	aux=num;
	while(aux>0){
		aux=aux-2;
	}
	if(aux==0){
		cout<<"El numero ingresado es par.\n";
	}else{
		cout<<"El numero ingresado es impar.\n";
	}
}

/*
2) Ingresar un número positivo. Decir si el mismo es o no par por el método de restas sucesivas. 
*/

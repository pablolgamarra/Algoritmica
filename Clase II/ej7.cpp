#include <iostream>

using namespace std;

main(){
	int n=0, divisibles=0;
	string op = "s";
	while(op != "n"){
		cout<<"Ingrese un numero para determinar si el mismo es primo: ";
		cin>>n;
		while(n<=0){
			cout<<"El numero ingresado debe ser positivo.\nVuelva a Ingresar: ";
			cin>>n;
		}
		for(int i=1; i<=n; i++){
			if(n % i == 0){
				divisibles++;
			}
		}
		if(divisibles > 2){
			cout<<"El numero ingresado no es un numero primo.\n";
		}else{
			cout<<"El numero ingresado es un numero primo.\n";
		}
		cout<<"Desea volver a ingresar (S/N): ";
		cin>>op;
	}
}

/*
7) Ingresar tantos números como se desee. Decir si fue ingresado o no un numero primo. 
*/

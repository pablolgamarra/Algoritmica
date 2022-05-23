#include <iostream>
#include <windows.h>

using namespace std;

//Prototipado de Funcion
int factorial(int );

main(){
	system("cls");
	int n;
	cout<<"Ingrese el numero del cual desea saber la factorial: ";
	cin>>n;
	cout<<n <<"!: "<<factorial(n)<<"\n";
	system("pause");
	return 0;
}

int factorial(int n){
	//Funcion Factorial Recursiva
	if(n==0){
		return 1;//La factorial de '0' siempre es '1'
	}else{
		return n * factorial((n - 1));//La recursividad se da acá, porque si no es el caso base se devuelve 'n' * factorial de el numero anterior
	}
}

/*
5) Ingresar un Numero y calcular su factorial en forma recursiva.
*/

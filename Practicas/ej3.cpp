//Imprimir los numeros pares que hay entre el 1 y el 100

#include <iostream>
#include <windows.h>

using namespace std;

main(){
	int c=1;
	cout<<"Programa para imprimir numeros pares"<<endl;
	system("pause");
	while(c <= 100){
		if(c % 2 == 0){
			cout<<c<<",";
		}
		c++;
	}
	cout<<endl;
	system("pause");
}

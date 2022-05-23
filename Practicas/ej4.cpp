//Imprimir Hola y Adios 10 veces de Forma alternativa

#include <iostream>
#include <windows.h>

using namespace std;

main(){
	int c=1;
	int sw = 0;
	cout<<"Programa para imprimir hola y adios de forma alternativa."<<endl;
	system("pause");
	while(c < 10){
		if(sw == 0){
			cout<<"Hola"<<endl;
			sw=1;
		}else{
			cout<<"Adios"<<endl;
			sw=0;
		}
		c++;
	}
	system("pause");
}



#include <iostream>

using namespace std;

main(){
	int n,suma=0;
	char op='n';
	while(op != 's'){
		cout<<"Ingrese un numero: ";
		cin>>n;
		suma=suma+n;
		cout<<"Desea salir? (S/N): ";
		cin>>op;
	}
	cout<<"La suma de numeros es: "<<suma;
	return 0;
}

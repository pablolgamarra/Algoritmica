#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int monto, resultado,resto;

int main(){
	system("cls");
	cout<<"Ingrese el monto:"<<endl;
	cin>>monto;
	
	resultado=monto/3;
	
	resto=monto%3;
	
	system("cls");
	cout<<"El monto ingresado es: " <<monto<<endl;
	cout<<"El monto que se lleva cada nino/a es: "<<resultado<<endl;
	cout<<"Lo que sobra es: " <<resto<<endl;
	
	system("pause");
	return 0;
}

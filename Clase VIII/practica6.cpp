#include <iostream>
#include <windows.h>

using namespace std;

main(){
	float meses;
	cout<<"Ingrese un valor en meses y el programa lo pasara a dias."<<endl;
	cout<<"Ingrese el valor en meses: ";
	cin>>meses;
	
	
	system("cls");
	cout<<"La cantidad meses ingresada fue: "<<meses<<endl;
	cout<<"La cantidad ingresada expresada en dias es: "<<meses*30<<endl;
	system("pause");
}

/*
Ingresar un valor en meses e indicarlo en dias

30 dias = 1 mes
60 dias = 2 meses

*/

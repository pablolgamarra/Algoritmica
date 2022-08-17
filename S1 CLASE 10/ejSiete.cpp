#include <iostream>
#include <windows.h>

using namespace std;

const double pi=3.141592;

float radio,area;

float calcArea(float radio){
	area=pi*(radio * radio);
	return area;
}

int main(){
	system("cls");
	cout<<"Ingrese el radio del circulo: ";
	cin>>radio;
	calcArea(radio);
	system("cls");
	cout<<"El area del circulo es: "<<area<<"\n";
	system("pause");
	return 0;	
}

/*7) Escribe una función en pseudocódigo que devuelva el área de un círculo dado su radio. Recuerda que
para calcular el área, la fórmula es ? * r2*/
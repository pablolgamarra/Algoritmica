#include <iostream>
#include <windows.h>

using namespace std;
int metodoPago;
float precio,totalPagar;

float calcTotal (int mp, float pr) {
	if(mp == 1){
		totalPagar=pr*0.75;
	}else{
		totalPagar=pr*0.90;
	}
	return totalPagar;
}

int main(){
	system("cls");
	cout<<"Ingrese el monto a pagar: ";
	cin>>precio;
	cout<<"Ingrese 1 si el pago es al contado. Ingrese 2 si el pago es en cuotas: ";
	cin>>metodoPago;
	while(metodoPago < 0 || metodoPago > 2){
		cout<<"Ingrese 1 si el pago es al contado. Ingrese 2 si el pago es en cuotas: ";
		cin>>metodoPago;
	}
	calcTotal(metodoPago,precio);
	system("cls");
	cout<<"El total a pagar es: "<<totalPagar<<endl;
	if(metodoPago == 1){
		cout<<"-----------------------------------\n";
		cout<<"Se aplico un descuento del 25%.\n";
	}else{
		cout<<"-----------------------------------\n";
		cout<<"Se aplico un descuento del 10%.\n"	;
	}	
	system("pause");
	return 0;
}


/*Crea una función que permita calcular el monto a pagar por un electrodom�stico considerando que el
pago por las compras se efectía al contado tiene 25% de descuento, caso contrario, solo tiene 10% de
descuento.*/

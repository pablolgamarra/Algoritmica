#include <iostream>
#include <windows.h>

using namespace std;
int sueldoNeto,sueldoBase,descuento,sobreSueldo;

int calcSueldoNeto(int sb, int d, int ss){
	sueldoNeto=(sueldoBase+sobreSueldo)-descuento;
	return sueldoNeto;
}

main(){
	cout<<"Calculadora de sueldo neto.\n";
	cout<<"Sueldo Base: ";
	cin>>sueldoBase;
	cout<<"Descuento: ";
	cin>>descuento;
	cout<<"Sobre Sueldo: ";
	cin>>sobreSueldo;
	calcSueldoNeto(sueldoBase,descuento,sobreSueldo);
	system("cls");
	cout<<"El sueldo neto es: "<<sueldoNeto<<".\n";
	system("pause");
	return 0;
}

/*Crea la función que posibilite calcular el sueldo neto a cobrar de un empleado, considerando el sueldo
base, descuento y sobre sueldo que es cargado en el programa principal. 
*/
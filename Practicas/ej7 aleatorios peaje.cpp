//Puesto de peaje registro diario de paso de vehiculos, 
//los cuales poseen un codigo que les identifica
//moto 1 = 5000
//autos/camionetas 2 = 15000
//omnibus 3 = 30000
//total acumulado por el paso de cada vehiculo
//monto total recaudado por el peaje
//Realizar el procedimiento hasta que el numero de vehiculo sea menor a 999

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

main(){
	srand(time(NULL));
	cout<<"Programa de Carga Peaje."<<endl;
	int contadorVehiculos = 0;
	int tipoVehiculo = 0;
	int acumMotos=0, acumAutos=0, acumOmnibus=0;
	//Bucle de Vehiculos que Pasan
	while(contadorVehiculos <= 999){
		tipoVehiculo = ((rand() % (3 - 1)) + 1);
		switch(tipoVehiculo){
			case 1:
				acumMotos = acumMotos + 5000;
				break;
			case 2:
				acumAutos = acumAutos + 15000;
				break;
			case 3:
				acumOmnibus = acumOmnibus + 30000;
				break;
			default:
				cout<<"Ha pasado un vehículo no identificado por el peaje."<<endl;
		}
		contadorVehiculos++;
	}
	int total = acumMotos + acumAutos + acumOmnibus;
	cout<<"El monto total que se cobro por motos es: "<<acumMotos<<endl;
	cout<<"El monto total que se cobro por autos/camionetas es: "<<acumAutos<<endl;
	cout<<"El monto total que se cobro por omnibus es: "<<acumOmnibus<<endl;
	cout<<"El total recaudado por el peaje es: "<<total<<endl;
}



//El departamento de meteorolog�a registra cada hora la temperatura del 
//ambiente expresado en grados cent�grados
//24 horas en un dia = 24 veces que se registra la temperatura
//while o for de 0  a 24
//(�C) adem�s de eso se registra tambi�n la hora correspondiente a dicha temperatura

//Realiza un algoritmo que permita calcular e imprimir:
//a) El promedio de temperatura del dia
//b) La mayor temperatura registrada en el dia
//c) La hora en que se registr� la menor temperatura

#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

main(){
	setlocale(LC_ALL, "spanish");
	int hora = 0, temp, horaMenorTemperatura;
	double promedioTemperatura=0, temperaturaMayor = 0, temperaturaMenor;
	while(hora <= 23){
		cout<<"Hora: "<<hora<<endl;
		cout<<"Ingrese la temperatura registrada: ";
		cin>>temp;
		promedioTemperatura= promedioTemperatura + temp;
		if(hora == 0){
			temperaturaMayor = temp;
		}else if(temperaturaMayor < temp){
			temperaturaMayor = temp;
		}
		if(hora == 0){
			temperaturaMenor = temp;
		}else if(temperaturaMenor > temp){
			temperaturaMenor = temp;
			horaMenorTemperatura = hora;
		}
		hora++;
	}
	cout<<"El promedio de temperatura que se registro en el d�a fue: "<<promedioTemperatura / 24 <<"�C"<<endl;
	cout<<"La mayor mayor temperatura registrada es: "<<temperaturaMayor<<"�C"<<endl;
	cout<<"La hora a la que se registro menor temperatura es: "<<horaMenorTemperatura<<" Hs."<<endl;
}


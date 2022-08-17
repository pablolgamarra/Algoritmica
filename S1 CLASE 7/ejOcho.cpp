#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int hora,temperatura,promedio=0,tempTotal=0,tempMayor,tempMenor,horaMenor;
    cout<<"Programa que registra la temperatura en C cada hora.\n";
    for(hora=0;hora<=24;hora++){
        if(hora == 0){
            cout<<"Ingrese la temperatura: ";
            cin>>temperatura;
            cout<<"\nHora: "<<hora;
            tempTotal=tempTotal+temperatura;
            tempMayor=temperatura;
            tempMenor=temperatura;
            horaMenor=hora;
        }else{
            system("cls");
            cout<<"Ingrese la temperatura: ";
            cin>>temperatura;
            cout<<"\nHora: "<<hora;
            tempTotal=tempTotal+temperatura;
        }
        if(temperatura < tempMenor){
            tempMenor=temperatura;
            horaMenor=hora;
        }else if(temperatura > tempMayor){
            tempMayor=temperatura;
        }
    }
    promedio=tempTotal/24;
    system("cls");
    cout<<"El promedio de la temperatura del dia es: "<<promedio<<" Grados C\n\n";
    cout<<"La mayor temperatura que se registro en el dia fue: "<<tempMayor<<" Grados C\n\n";
    cout<<"La hora en la que se registro la menor temperatura fue: "<<horaMenor<<" horas.\n\n";
    system("pause");
    return 0;
}

/*
El departamento de meteorología registra cada hora la temperatura del ambiente expreasado en grados centígrados
(°C) además de eso se registra también la hora correspondiente a chicha temperatura
Realiza un algoritmo que permita calcular e imprimir:
a) El promedio de temperatura del dia
b) La mayor temperatura registrada en el dia
c) La hora en que se registró la menor temperatura 
*/
#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int vehiculo,monto,montoMotos=0,montoAutos=0,montoPesados=0,contTotal=0,contMotos=0,contAutos=0,contPesados=0,op;
    cout<<"Programa Puesto de Peaje.\n";
    do{
        cout<<"1- Motos \n2-Autos/Camionetas\n3-Omnibus/Vehiculos Pesados\n";
        cout<<"Ingrese el tipo de vehiculo: ";
        cin>>vehiculo;
        //Validadacion Tipo de Vehiculo
        while(vehiculo < 1 || vehiculo > 3){
            system("cls");
            cout<<"ERROR. El tipo de vehiculo ingresado no es valido.\nVuelva a seleccionar.\n";
            cout<<"1- Motos \n2-Autos/Camionetas\n3-Omnibus/Vehiculos Pesados\n";
            cout<<"Ingrese el tipo de vehiculo:";
            cin>>vehiculo;
        }
        cout<<"Ingrese el monto a pagar: ";
        cin>>monto;
        switch (vehiculo){
        case 1:
            contMotos++;
            montoMotos=montoMotos+monto;
            break;
        case 2:
            contAutos++;
            montoAutos=montoAutos+monto;
            break;
        case 3:
            contPesados++;
            montoPesados=montoPesados+monto;
            break;
        default:
            cout<<"Algo salio mal pa.\n";
            break;
        }
        cout<<"Desea seguir ingresando datos?:\n1-Si.\t2-No.\t:";
        cin>>op;
        //Validacion Opciones
        while(op < 1 || op > 2){
            system("cls");
            cout<<"Desea seguir ingresando datos?:\n1-Si.\t2-No.\t:";
            cin>>op;
        }
    }while(op == 1);

    cout<<"EL Total de Vehiculos que pasaron por el puesto de peaje es "<<(contMotos+contAutos+contPesados)<<"\n";
    cout<<contMotos<<" Motos\n"<<contAutos<<" Vehiculos Livianos(Autos y Camionetas)\n"<<contPesados<<" Vehiculos Pesados(Omnibus y Camiones)\n";
    cout<<"El monto total recaudado es: "<<(montoMotos+montoAutos+montoPesados)<<" Guaranies.\n";
    system("pause");
    return 0;
}

/*
Un puesto de peaje registra diariamente el paso de vehículos, los cuales poseen un código que los identifica
(1 = motos; 2 = autos/camionetas; 3 = ómnibus/vehículos pesados) guardándose además el monto a pagar.
Crea un programa que permita calcular e imprimir:
a) El total acumulado por el paso de cada tipo de vehículo
b) La cantidad de veces que paso cada tipo de vehículo por el peaje
c) El monto total recaudado por el peaje
Realizar el procedimiento mientras el tipo de vehículo sea distinto de 999 
*/
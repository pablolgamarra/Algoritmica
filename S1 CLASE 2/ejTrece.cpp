#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int seleccion,totalIng,total,descuento;

    system("cls");

    cout<<"Ingrese el total de la venta: ";
    cin>>totalIng;

    cout<<"Presione '1' si el pago es en efectivo, presione '2' si el pago es con tarjeta de credito: ";
    cin>>seleccion;
//si paga en efectivo es 20%, si paga con tarjeta es 30%
    system("cls");

    switch (seleccion){
    
    case 1:
        total=totalIng*0.8;
        descuento=totalIng*0.2;

        cout<<"El total a pagar es: "<<total<<"\n\nEl descuento aplicado es del 20%. El total descontado es: "<<descuento<<endl;

        break;

    case 2:
        total=totalIng*0.7;
        descuento=totalIng*0.3;

        cout<<"El total a pagar es: "<<total<<"\n\nEl descuento aplicado es del 20%. El total descontado es: "<<descuento<<endl;
        break;
    default:
        cout<<"La opcion de pago seleccionada no es valida."<<endl;
        break;
    }

    system("pause");
}
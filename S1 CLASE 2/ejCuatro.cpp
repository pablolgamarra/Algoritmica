#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

main(){
    int cost,option,discount, costD;
    string course;

    system("cls");

    cout<<"Ingrese el nombre del curso: \n";
    cin>>course;

    cout<<"Ingrese el costo: ";
    cin>>cost;

    cout<<"Seleccione '1' si el pago es al contado y '2' si el pago no es al contado: ";
    cin>>option;

    system("cls");

    switch(option){
        case 1:
            discount=cost*0.2;
            costD= cost-discount;

            cout<<"-El monto total es: "<<cost<<"\n-El descuento es: "<<discount<<"\n-El total a pagar con descuento es: "<<costD<<endl;

        break;

        case 2:
            cout<<"El total a pagar es: "<<cost<<endl;

        break;

        default: 
            cout<<"La opcion ingresada no es valida\n";

    }

    system("pause");


}
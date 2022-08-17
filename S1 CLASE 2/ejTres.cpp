#include <iostream>
#include <windows.h>

using namespace std;

main (){
    int mt,s,seleccion, me;
    
    system("cls");

    cout<<"Ingrese el monto a pagar: "<<endl;
    cin>>mt;

    cout<<"Escriba '1' si el pago es netamente en efectivo y presione '2' si una parte del pago se hara con un cheque"<<endl;
    cin>>seleccion;
    
    switch(seleccion){
        case 1: 
            cout<<"El monto a pagar es: "<<mt<<endl;
        break;

        case 2: 
            cout<<"Ingrese el monto que se pagara en efectivo"<<endl;
            cin>>me;
        
            s=mt-me;

            cout<<"El monto a cobrar en cheque es de: "<<s<<endl;
        break;

        default: 
            cout<<"La selección no es válida"<<endl;
        break;
    }

    system("pause");

}
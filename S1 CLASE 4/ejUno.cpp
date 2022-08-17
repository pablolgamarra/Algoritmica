#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numAIngresar,contPares=0,contIngresados=0,numIngresado,contAux=0;

    system("cls");

    cout<<"\nIngrese la cantidad de numeros a ingresar: ";
    cin>>numAIngresar;
    system("cls");

    while(contIngresados<numAIngresar){
        contIngresados++;
        cout<<"\nIngrese numero: ";
        cin>>numIngresado;
        while(contAux<numIngresado){
            contAux=contAux+2;
        }
        if(contAux==numIngresado){
            contPares++;
        }
    }
    system("cls");
    cout<<"\n\nSe han ingresado: "<<contIngresados<<" \n\nDe los cuales: "<<contPares<<" son pares\n\n";
    system("pause");
}
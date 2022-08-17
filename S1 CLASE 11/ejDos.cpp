#include <iostream>
#include <windows.h>

using namespace std;
int moneda;
float cantidad;

void ConversionMoneda(int moneda, float cantidad){
    switch(moneda){
        case 1:
            cout<<"La cantidad ingresada en Dolares se convertira a Euros.\n";
            cout<<cantidad<<" Dolares. Equivalen a: "<<cantidad*0.75<<" Euros.\n";
            break;
        case 2:
            cout<<"La cantidad ingresada en Libras se convertira a Euros.\n";
            cout<<cantidad<<" Libras. Equivalen a: "<<cantidad*1.22<<" Euros.\n";
            break;
        case 3:
            cout<<"La cantidad ingresada en Yenes se convertira a Euros.\n";
            cout<<cantidad<<" Yenes. Equivalen a: "<<cantidad*0.009<<" Euros.\n";
            break;
        default:
            cout<<"La opcion seleccionada no es valida.\n";
            break;
    }
}

int main(){
    system("cls");
    cout<<"El programa convertira las monedas ingresadas a Euros\n";
    cout<<"Ingrese cantidad: ";
    cin>>cantidad;
    cout<<"Escriba ('1') si la cantidad ingresada es en Dolares ; ('2') si la cantidad es en Libras; ('3') si la cantidad ingresada es en Yenes: ";
    cin>>moneda;
    system("cls");
    ConversionMoneda(moneda, cantidad);
    system("pause");
    return 0;
}




/*
Escribe una función en pseudocódigo llamada ConversionMoneda (…) que permita convertir una
cantidad de dinero dada en dólares, libras o yenes a Euros. Estas son las equivalencias
aproximadas:
1 libra=1,22 euros
1 dolar=0,75 euros
1 yen=0.009 euros
*/
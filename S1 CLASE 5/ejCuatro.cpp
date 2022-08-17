#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int numIng, c=0;
    system("cls");
    cout<<"Tablas de Multiplicar. \n";
    cout<<"Ingrese un numero par menor a 20: ";
    cin>>numIng;
    while ((numIng%2!=0)||(numIng>=20)){
        cout<<"ERROR.\n Ingrese un numero par menor a 20: ";
        cin>>numIng;
    }
    system("cls");
    cout<<"Tabla de Multiplicar del: "<<numIng<<endl<<endl;
    while (c<=10){
        cout<<numIng<<"x"<<c<<"="<<numIng*c<<endl;
        c++;
    }
    system("pause");
    return 0;
}

/*Crear un programa que permita ingresar un número par menor a 20. Imprimir su tabla de multiplicar*/
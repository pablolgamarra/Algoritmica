#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int numUno,numDos,diferencia,mayor,menor;
    cout<<"Programa que muestra los numeros existentes entre dos numeros.\n";
    cout<<"Debe haber una diferencia de 20 unidades entre ambos numeros para que el programa funcione correctamente.\n";
    cout<<"Ingrese el primer numero: ";
    cin>>numUno;
    cout<<"Ingrese el segundo numero: ";
    cin>>numDos;
    diferencia=abs(numUno-numDos);
    while(diferencia <= 20){
        system("cls");
        cout<<"ERROR! Debe haber una diferencia de 20 unidades entre ambos numeros para que el program funcione correctamente.\n";
        cout<<"Ingrese el primer numero: ";
        cin>>numUno;
        cout<<"Ingrese el segundo numero: ";
        cin>>numDos;
        diferencia=abs(numUno-numDos);
    }
    system("cls");
    if(numUno < numDos){
        menor = numUno;
        mayor = numDos;
    }else{
        menor = numDos;
        mayor = numUno;
    }
    for(menor; menor <= mayor; menor++){
        if(menor == mayor){
            cout<<menor<<"\n";
        }else{
            cout<<menor<<", ";
        }
    }
    system("pause");
    return 0;
}

/*
Ingresar dos números distintos cuya diferencia entre ambos sea como mínimo de 20 unidades. Mostrar los
números existentes entre ambos. 
*/
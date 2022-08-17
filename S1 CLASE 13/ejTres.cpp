#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int num;
    system("cls");
    cout<<"Ingresar un numero y el programa imprimira los 10 numeros consecutivos a el.\n";
    cout<<"Ingrese numero: ";
    cin>>num;
    for(int i=num;i<=(num+10);i++){
        if(i==num+10){
            cout<<i<<"\n";
        }else{
            cout<<i<<", ";
        }
    }
    system("pause");
    return 0;
}

/*
Ingresar un número, mostrar los 10 números consecutivos a partir del número ingresado
*/

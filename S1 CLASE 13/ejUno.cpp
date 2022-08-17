#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int num;
    system("cls");
    cout<<"Ingrese un numero y el programa determinara si el mismo es un numero par o impar.\n";
    cout<<"Ingrese numero: ";
    cin>>num;
    system("cls");
    if(num%2==0){
        cout<<"El numero ingresado es un numero par.\n";
    }else{
        cout<<"El numero ingresado es un numero impar.\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar un numero y decir si es par o impar
*/
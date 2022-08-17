#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void cargarN(int &);

void invertir(int);

main(){
    int n;
    system("cls");
    cout<<"Programa que permite invertir el orden de un numero.\n"; 
    cargarN(n);
    cout<<"Numero Invertido: ";
    invertir(n);
    cout<<"\n";
    system("pause");
    return 0;
}

void cargarN(int &n){
    do{
        cout<<"Ingrese un numero con al menos dos digitos: ";
        cin>>n;
    }while(n<10);
    return;
}

void invertir(int n){
    cout<<n%10;
    if(n > 10) invertir (n/10);
}

/*
Ingrese un numero positivo con un mínimo de 2 cifras. Crear una función recursiva que
permita invertir el número
*/
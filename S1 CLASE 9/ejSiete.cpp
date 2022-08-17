#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num, aux=0, i=1,sw=0;
    cout<<"Programa que dice si el numero ingresado es o no primo.\n";
    cout<<"Ingrese un numero positivo: ";
    cin>>num;
    while(num < 0){
        cout<<"ERROR. Ingrese un numero positivo: ";
        cin>>num;
    }
    while((i<(num - 1)) && (sw == 0)){
        i++;
        while(aux<num){
            aux=aux+i;
        }
        if(aux == num){
            sw=1;
        }        
    }
    system("cls");
    if(sw == 0){
        cout<<"El numero ingresado: "<<num<<" es un numero primo.\n";
    }else{
        cout<<"El numero ingresado: "<<num<<" no es un numero primo.\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar un número positivo. Decir si el mismo es o no primo con el método de sumas sucesivas.
*/
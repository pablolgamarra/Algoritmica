#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num,sw=0,i;
    cout<<"Ingrese un numero positivo y el programa determinara si el mismo es o no un numero primo.\n";
    cout<<"Ingrese el valor: ";
    cin>>num;
    while(num<0){
        system("cls");
        cout<<"Error. \nEl valor ingresado debe ser positivo: ";
        cin>>num;
    }
    if(num == 1 || num== 0){
        sw=1;
    }
    for(i=2;i<num;i++){
        if ((num % i) == 0){
            sw=1;
            break;
        }else{
            sw=0;
        }
    }
    if(sw == 0){
        cout<<"El numero ingresado es un numero primo.\n";
    }else{
        cout<<"El numero ingresado no es un numero primo.\n";
    }  
    system("pause");
    return 0;
}

/*
Ingresar un número positivo cualquiera. Decir si el mismo es o no primo utilizando un switch.
*/
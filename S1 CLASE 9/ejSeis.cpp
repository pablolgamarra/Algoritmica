#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num, i, divisibles = 0;
    cout<<"Ingrese un numero y el programa determinara si el mismo es un numero primo.\n";
    cout<<"Ingrese un numero positivo: ";
    cin>>num;
    while(num < 0){
        system("cls");
        cout<<"ERROR!. Ingrese un numero positivo: ";
        cin>>num;
    }
    for(i = 1;i <= num; i++){
        if((num % i) == 0){
            divisibles++;
        }
    }
    system("cls");
    if(divisibles == 2){
        cout<<"El numero ingresado es un numero primo.\n";
    }else{
        cout<<"El numero ingresado es un numero primo.\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar un número positivo. Decir si el mismo es o no un numero primo. 
*/
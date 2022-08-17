#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num, sw=0, iUno=0, iDos=10;
    cout<<"Programa que imprime la tabla de un numero de forma alternativa.\n";
    cout<<"Ingrese un numero positivo menor que 10: ";
    cin>>num;
    while(num < 0 || num > 10){
        system("cls");
        cout<<"ERROR. Ingrese un numero positivo menor que 10: ";
        cin>>num;
    }
    system("cls");
    do{
        if(sw == 0){
            sw=1;
            cout<<num<<" X "<< iUno<<" = "<<num*iUno<<"\n";
            iUno++;
        }else{
            sw=0;
                cout<<num<<" X "<< iDos<<" = "<<num*iDos<<"\n"; 
            iDos--;
        }   
    }while(iUno <= 10 || iDos>=0);
    system("pause");
    return 0;
}

/*
Dado un número menor que 10. Hallar su tabla de multiplicar de forma por duplicado, es decir, empezando por el
cero y por el 10 de forma alternativa.
*/
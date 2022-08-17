#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng,contAux=0;
    system("cls");
    cout<<"\nIngrese un numero positivo: ";
    cin>>numIng;
    system("cls");
    while(numIng<0){
        cout<<"ERROR\nEl numero ingresado debe ser positivo.\nVuelva a ingresar: ";
        cin>>numIng;
    }
    while(numIng>contAux){
        contAux=contAux+2;
    }
    system("cls");
    if(contAux==numIng){
        cout<<"\nEl numero ingresado es Par\n";
    }else{
        cout<<"\nEl numero ingresado es Impar\n";
    }
    system("pause");
}
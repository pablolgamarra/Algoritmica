#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng,contAux;

    cout<<"\nIngrese un numero positivo: ";
    cin>>numIng;
    system("cls");
    while(numIng<0){
        cout<<"ERROR\nEl numero ingresado debe ser positivo.\nVuelva a ingresar: ";
        cin>>numIng;
    } 
    while(0<numIng){
        numIng=numIng-2;
    }
    if(numIng==0){
        cout<<"\nEl numero ingresado es Par.\n";
    }else{
        cout<<"\nEl numero ingresado es Impar.\n";
    }
}
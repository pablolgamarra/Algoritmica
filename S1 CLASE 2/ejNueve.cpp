#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int use,prize,extraPrize;

    system("cls");

    cout<<"Ingrese los minutos usados: ";
    cin>>use;

    if(use==1){
        prize= 500;
        cout<<"\n Se utilizaron: "<<use<<" minutos. \nEl total a pagar es : "<< prize<<endl;
    }if(use>1){
        system("cls");
        prize=(use*300)+500;
        cout<<"\nSe utilizaron: "<<use<<" minutos. \nEl total a pagar es : "<<prize<<endl;
    }if(use<1){
        system("cls");
        cout<<"El tiempo de uso ingresado no es valido"<<endl;
    }

    system("pause");
}
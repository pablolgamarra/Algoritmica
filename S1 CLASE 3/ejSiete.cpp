#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng, i=0,contPar=0,contImp=0;
    
    system("cls");
    
    cout<<"Ingrese un numero superior a 50: ";
    cin>>numIng;

    while (numIng<=50){
        cout<<"ERROR, el numero ingresado debe ser superior a 50.\nVuelva a ingresar el numero: ";
        cin>>numIng;
    }

    system("cls");

    while(i<numIng){
        if(i%2==0){
            i++;
            cout<<i<<", ";
            contImp++;
        }else{
            i++;
            cout<<i<<", ";
            contPar++;
        }
    }

    cout<<"\n";
    cout<<"\nLa cantidad de numeros pares es de: "<<contPar;
    cout<<"\nLa cantidad de numeros impares es de: "<<contImp;
    cout<<"\n\n";

    system("pause");
}
#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng, i=0;

    system("cls");

    cout<<"Ingrese un numero mayor que 20: ";
    cin>>numIng;

    while(numIng<=20){
        cout<<"Error, el numero ingresado debe ser mayor a 20. \nVuelva a ingresar el numero: ";
        cin>>numIng;
    }

    system("cls");
    while(i<numIng){
        i++;
        cout<<i<<", ";
    }

    cout<<endl;

    system("pause");

}
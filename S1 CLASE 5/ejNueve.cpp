#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int numIng,restoCero=0,i=1;
    cout<<"Ingrese un numero natural mayor que 1: ";
    cin>>numIng;
    while(numIng<=1){
        cout<<"ERROR!.\nEl numero ingresado debe ser natural y mayor a 1: ";
        cin>>numIng;
    }
    while(i<=numIng){
        if(numIng%i==0){
            restoCero++;
        }
        i++;
    }
    system("cls");
    if(restoCero==2){
        cout<<"\nEl numero ingresado es un numero primo.\n";
    }else{
        cout<<"\nEl numero ingresado no es primo.\n";
    }
    system("pause");
    return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;
int cantIng,i,j=0,numIng,contPar=0;
int main(){
    system("cls");
    cout<<"El programa determina la cantidad de numeros que se ingresan.\n";
    cout<<"Ingrese la cantidad de numeros que va a ingresar: ";
    cin>>cantIng;
    while(cantIng <= 0){
        cout<<"ERROR!. Ingrese numeros positivos: ";
        cin>>cantIng;
    }
    for(i=0;i<cantIng;i++){
        cout<<"Ingrese numero: ";
        cin>>numIng;
        while(numIng <= 0){
        cout<<"ERROR!. Ingrese numeros positivos: ";
        cin>>numIng;
        }
        while(j<numIng){
            j=j+2;
        }
        if(j == numIng){
            contPar++;
        }
        j=0;
    }
    system("cls");
    cout<<"Se ingresaron: "<<contPar<<" numeros pares.\n";
    system("pause");
    return 0;
}


/*
Ingresar tantos números hasta un número ingresado previamente. Decir cuántos números pares se han
ingresado mediante el método de sumas sucesivas. 
*/
#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    system("cls");
    int i, sw=0,sumaPares=0,sumaImpares=0;

    for(i=0;i<=1000;i++){
        if(sw==0){
            sumaPares=sumaPares+i;
            sw=1;
        }else{
            sumaImpares=sumaImpares+i;
            sw=0;
        }
    }
    system("cls");
    cout<<"La suma de los numeros Pares es: "<<sumaPares<<"\n";
    cout<<"La suma de los numeros Impares es: "<<sumaImpares<<"\n";
    return 0;
}

/*
Hacer un programa que calcule independientemente la suma de los pares y los impares de
los números entre 1 y 1000 utilizando un switch.
*/
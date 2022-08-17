#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    system("cls");
    int sw=0,i=0;
    string mensajeUno="Hola", mensajeDos="Adios";
    for(i=0;i<=10;i++){
        if(sw==0){
            cout<<mensajeUno<<"\n";
            sw=1;
        }else{
            cout<<mensajeDos<<"\n";
            sw=0;
        }
    }
    system("pause");
    return 0;
}
/*
Imprimir 10 veces, de una forma alternativa, Hola y Adiós. 
*/
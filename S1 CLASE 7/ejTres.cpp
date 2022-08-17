#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int i,sw=0,tabla=1;
    cout<<"Tablas de Multipicar Alternativas.\n";
    do{
        if(sw == 0){
            cout<<"Tabla de: "<<tabla<<"\n";        
            for(i=0;i<=10;i++){
                cout<<tabla<<" x "<<i<<" = "<<tabla*i<<"\n";
            }
            tabla++;
            sw=1;
        }else{
            sw=0;
            tabla++;
        }
    }while(tabla<=10);
    system("pause");
    return 0;
}

/*
Crear un programa que permita imprimir la tabla de multiplicar de los 10 primeros números en forma alternativa (de
menor a mayor en forma sucesiva
*/
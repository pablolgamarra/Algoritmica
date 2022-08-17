#include <iostream>
#include <conio.h>

using namespace std;

struct strings
{
    string texto;
    int largo;
}cadena[10];

main(){
    system("cls");
    //Presentacion de la funcion del programa
    cout<<"Programa para calcular la longitud de cadenas.\n";
    //Carga de Cadenas
    for(int i=0;i<10;i++){
        cout<<"Ingrese cadena "<<i+1<<": ";
        cin>>cadena[i].texto;
        cadena[i].largo=(cadena[i].texto).length();
    }
    //Impresion de las cadenas y sus largores
    system("cls");
    cout<<"=================================================\n";
    for(int i=0;i<10;i++){
        cout<<"Cadena "<<i+1<<": "<<cadena[i].texto<<"\n";
        cout<<"Longitud: "<<cadena[i].largo<<"\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar 10 datos de tipo cadena. Imprimir los datos ingresados y la longitud de
caracteres de los mismos. 
*/
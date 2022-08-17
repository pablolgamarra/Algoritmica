#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int f, c;
    cout<<"Programa que permite cargar y posteriormente imprimir una matriz.\n";
    cout<<"\nIngrese la cantidad de filas: ";
    cin>>f;
    cout<<"\nIngrese la cantidad de columnas: ";
    cin>>c;
    while(c>=f){
        system("cls");
        cout<<"ERROR!.\nLa cantidad de filas debe ser superior a la cantidad de columnas.\n";
        cout<<"\nIngrese la cantidad de filas: ";
        cin>>f;
        cout<<"\nIngrese la cantidad de columnas: ";
        cin>>c;
    }
    int M [f][c];
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc <= c; cc++){
            cout<<"Cargar dato.\nFila "<<cf<<" Columna "<<cc<<"\nValor: ";
            cin>>M[cf][cc];
        }
    system("cls");
    }
    cout<<"Se imprimira el vector cargado.\n";
    system("pause");
    system("cls");
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc <= c; cc++){
            if(cc == c){
                cout<<M[cf][cc]<<"\n";
            }else{
            cout<<M[cf][cc]<<" - ";
            }   
        }
    }
    system("pause");
}

/*
Ingresar las dimensiones de una matriz M tal que en el mismo la cantidad de
filas sea superior al de las columnas, imprimir la matriz cargada. 
*/
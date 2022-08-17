#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int f, c, sd=0;
    cout<<"Programa que halla e imprime la sumatoria de elementos en la diagonal principal('La matriz creada debe ser cuadrada.')\n";
    cout<<"\nIngrese la cantidad de filas: ";
    cin>>f;
    cout<<"\nIngrese la cantidad de columnas: ";
    cin>>c;
    while(f != c){
        cout<<"ERROR!.\nLa matriz debe ser cuadrada('Igual cantidad de filas que de columnas').\n";
        cout<<"\nIngrese la cantidad de filas: ";
        cin>>f;
        cout<<"\nIngrese la cantidad de columnas: ";
        cin>>c;
    }
    int B [f][c];
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc <= c; cc++){
            cout<<"Cargar dato.\nFila "<<cf<<" Columna "<<cc<<"\nValor: ";
            cin>>B[cf][cc];
            if(cf == cc){
                sd=sd+B [cf][cc];
            }
        }
    system("cls");
    }
    cout<<"Se imprimira el vector cargado.\n";
    system("pause");
    system("cls");
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc <= c; cc++){
            if(cc == c){
                cout<<B[cf][cc]<<"\n";
            }else{
            cout<<B[cf][cc]<<" - ";
            }   
        }
    }
    cout<<"La sumatoria de los elementos en la diagonal principal es: "<<sd<<"\n";
    system("pause");    
}

/*
Crear y cargar una matriz cuadrada. Hallar e imprimir la sumatoria de la
diagonal principal. Imprimir la matriz.
*/
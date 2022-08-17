#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int f, c, cp=0, ci=0, promP=0, promI=0;
    cout<<"Programa que permite cargar y posteriormente imprimir una matriz.\n";
    cout<<"\nIngrese la cantidad de filas: ";
    cin>>f;
    cout<<"\nIngrese la cantidad de columnas: ";
    cin>>c;
    int B [f][c];
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc <= c; cc++){
            cout<<"Cargar datos.\nFila "<<cf<<" Columna "<<cc<<"\nValor: ";
            cin>>B[cf][cc];
            if((B[cf][cc] %2 ) == 0 ){
                cp++;
                promP=promP+B[cf][cc];
            }else{
                promI=promI+B[cf][cc];
                ci++;
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
    cout<<"Cantidad de Pares: "<<cp<<endl;
    cout<<"Cantidad de Impares: "<<ci<<endl;
    cout<<"Promedio de Pares: "<<(promP/cp)<<"\n";
    cout<<"Promedio de Impares: "<<(promI/ci)<<"\n";
    system("pause");
}

/*
Crear y cargar una matriz B, analizar los elementos pares e impares cargados
e imprimir el promedio de los mismos. Imprimir la matriz.
*/
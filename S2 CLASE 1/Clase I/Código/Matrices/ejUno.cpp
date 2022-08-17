#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    cout<<"Programa en el que se carga una matriz 6*3 y luego se imprime la misma.\n";
    int A [6][3];
    system("cls");
    for(int cf=1; cf<=6; cf++){
        for(int cc=1; cc <= 3; cc++){
            cout<<"Cargar dato.\nFila "<<cf<<" Columna "<<cc<<"\nValor: ";
            cin>>A[cf][cc];
        }
    system("cls");
    }
    cout<<"Se imprimira el vector cargado.\n";
    system("pause");
    for(int cf=1; cf<=6; cf++){
        for(int cc=1; cc <= 3; cc++){
            if(cc == 3){
                cout<<A[cf][cc]<<"\n";
            }else{
            cout<<A[cf][cc]<<" - ";
            }   
        }
    }
    system("pause");
}

/*
Crear y cargar una matriz A de orden 6x3. Imprimir la matriz cargada.
*/

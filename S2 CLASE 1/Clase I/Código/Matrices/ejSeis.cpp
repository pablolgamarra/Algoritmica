#include <iostream>
#include <windows.h>

using namespace std;

int f, c;

void cargaDatos(int &f, int &c){
    cout<<"Ingrese la cantidad de filas que tendra la matriz:";
    cin>>f;
    while (f <= 0){
        cout<<"Debe ser un numero positivo.\n";
        cout<<"Ingrese la cantidad de filas que tendra la matriz:";
        cin>>f;
    }
    cout<<"Ingrese la cantidad de columnas que tendra la matriz:";
    cin>>c;
    while (c <= 0){
        cout<<"Debe ser un numero positivo.\n";
        cout<<"Ingrese la cantidad de columnas que tendra la matriz:";
        cin>>c;
    }    
}

int main(){
    system("cls");
    cout<<"Programa que encuentra el mayor y el menor numero de una matriz cualquiera.\n";
    cargaDatos(f, c);
    int A[f][c], May[c], Men[c];
    cout<<"Carga de Datos.\n";
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc<=c; cc++){
            cout<<"Fila: "<<cf<<" Columna: "<<cc<<"\nIngresar valor:";
            cin>>A[cf][cc];
            if(cf==1){
                May[cf]=A[cf][cc];
                Men[cf]=A[cf][cc];
            }else if(A[cf][cc] < Men[cc]){
                Men[cf]=A[cf][cc];
            }else if(A[cf][cc] > May[cc]){
                May[cf]=A[cf][cc];
            }
            system("cls");
        }
    }
    cout<<"Se imprimiran la matriz cargada y el vector con los elementos mayores y menores\n";
    system("pause");
    system("cls");
    cout<<"Matriz Cargada.\n";
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc<=c; cc++){
            if(cc == c){
                cout<<A[cf][cc]<<"\n";
            }else{
                cout<<A[cf][cc]<<"|";
            }
        }
    }
    cout<<"Mayores Ingresados en cada Fila: \n";
    for(int i=1; i<= c; i++){
        if(i == c){
            cout<<May[i]<<"\n";
        }else{
            cout<<May[i]<<" - ";
        }
    }
    cout<<"\n";
    cout<<"Menores Ingresados en cada Fila: \n";
    for(int i=1; i<= c; i++){
        if(i == c){
            cout<<May[i]<<"\n";
        }else{
            cout<<May[i]<<" - ";
        }    
    }
    system("pause");    
}
/*
Ingresar las dimensiones de una matriz cualquiera. Encontrar el mayor y
menor elemento de cada fila. Imprimir la matriz. 
*/
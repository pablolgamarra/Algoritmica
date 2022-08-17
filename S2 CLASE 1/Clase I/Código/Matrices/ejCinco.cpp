#include <iostream>
#include <windows.h>

using namespace std;

int f, c;

void cargaDatos(int &f, int &c){
    cout<<"Ingrese la cantidad de filas que tendra la matriz. (Debe ser una matriz cuadrada.):";
    cin>>f;
    while (f <= 0){
        cout<<"Debe ser un numero positivo.\n";
        cout<<"Ingrese la cantidad de filas que tendra la matriz. (Debe ser una matriz cuadrada.):";
        cin>>f;
    }
    cout<<"Ingrese la cantidad de columnas que tendra la matriz. (Debe ser una matriz cuadrada.):";
    cin>>c;
    while (c <= 0){
        cout<<"Debe ser un numero positivo.\n";
        cout<<"Ingrese la cantidad de columnas que tendra la matriz. (Debe ser una matriz cuadrada.):";
        cin>>c;
    }    
}


int main(){
    system("cls");
    cout<<"Programa que halla los valores de la diagonal principal de un matriz cargada.\n";
    cargaDatos(f, c);
    while(f != c){
        cout<<"Error!.\nDebe ser una matriz cuadrada.(Igual numero de filas que de columnas).\n";
        cargaDatos(f, c);
    }
    int A[f][c], DP[f];
    system("cls");
    cout<<"Carga de Datos.\n";
    for(int cf=1; cf<=f; cf++){
        for(int cc=1; cc<=c; cc++){
            cout<<"Fila: "<<cf<<" Columna: "<<cc<<"\nIngresar valor:";
            cin>>A[cf][cc];
            if(cf == cc){
                DP[cf]=A[cf][cc];
            }
            system("cls");
        }
    }
    cout<<"Se imprimiran la matriz cargada y el vector con los elementos de la diagonal principal.\n";
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
    cout<<"Vector con los elementos de la diagonal principal:\n";
    for(int i=1; i<=f; i++){
        if(i == f){
            cout<<DP[i]<<"\n";
        }else{
            cout<<DP[i]<<" | ";            
        }
    }    
    system("pause");

}

/*
Crear y cargar una matriz A y un vector DP. Guardar los elementos de la
diagonal principal de la matriz A en el vector DP. Imprimir ambas estructuras
de datos. 
*/
#include <iostream>
#include <windows.h>

using namespace std;

int f, c;

void cargaFC(int &f, int &c)
{
    cout << "Ingrese la cantidad de filas: ";
    cin >> f;
    while (f <= 0)
    {
        cout << "ERROR.\nDebe ingresarse un numero positivo mayor que cero.\n";
        cout << "Vuelva a ingresar cantidad de filas: ";
        cin >> f;
    }
    cout << "Ingrese la cantidad de columnas: ";
    cin >> c;
    while (c <= 0)
    {
        cout << "ERROR.\nDebe ingresarse un numero positivo mayor que cero.\n";
        cout << "Vuelva a ingresar cantidad de columnas: ";
        cin >> c;
    }
}

int main()
{
    system("cls");
    cout << "Programa para cargar una matriz y crear dos vectores con los elementos de las filas y de las columnas.\n";
    cargaFC(f, c);
    int A[f][c], F[f], C[c]={0}, sf = 0, sc = 0;
    for (int i = 1; i <= f; i++)
    {
        sf=0;
        for (int j = 1; j <= c; j++)
        {
            if(i==1){
                C[j]=0;
            }            
            cout << "Carga de Datos.\n";
            cout << "Fila: " << i << "\tColumna: " << j << "\n";
            cout << "Valor: ";
            cin >> A[i][j];
            sf = sf + A[i][j];
            C[j]=C[j]+A[i][j];
        }
        F[i]=sf;
    }
    system("cls");
    cout << "Matriz Cargada.\n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j == c){
                cout<<A[i][j]<<"\n";
            }
            else{
                cout<<A[i][j]<<" | ";
            }
        }
    }
    system("pause");
    cout<<"Suma De Filas: \n";
    for(int i=1;i<=f;i++){
        if(i==f){
            cout<<F[i]<<"\n";
        }else{
            cout<<F[i]<<" | ";
        }
    }
    cout<<"Suma de Columnas: \n";
    for(int i=1;i<=c;i++){
        if(i==c){
            cout<<C[i]<<"\n";
        }else{
            cout<<C[i]<<" | ";
        }
    }    
    system("pause");
    return 0;
}

/*
Crear y cargar una matriz A y a su vez dos vectores SF (Sumatoria de Filas) y SC (Sumatoria de Columnas) los
cuales contendrán la sumatoria de filas y columnas correspondientes a la matriz A, como se muestra en la
figura. Imprimir las estructuras de datos.
*/

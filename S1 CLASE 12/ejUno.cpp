#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int A[11];
    system("cls");
    cout << "Programa que permite cargar un vector y luego lo imprime.\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << "Ingresar valor para posicion " << i << ": ";
        cin >> A[i];
    }
    cout << A[10];
    system("cls");
    for (int i = 1; i <= 10; i++)
    {
        cout << "Valor de posicion " << i << ":  " << A[i] << "\n";
    }
    system("pause");
    return 0;
}

/*
Dimensionar un vector A con 10 elementos. Imprimir el vector cargado. 
*/
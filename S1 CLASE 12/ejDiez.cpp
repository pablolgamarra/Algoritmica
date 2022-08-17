#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int A[5], B[5];
    cout << "Cargar un vector con numeros pares, el programa pasara los datos a otro vector.\n";
    cout << "Cargar Vector: \n";
    for (int i = 1; i <= 5; i++)
    {
        cout << "Posicion " << i << " : ",
            cin >> A[i];
        while (A[i] % 2 != 0)
        {
            cout << "ERROR. Solo numeros pares.\nVuelva a ingresar: ";
            cin >> A[i];
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        B[i] = A[i];
    }
    system("cls");
    cout << "Vector Ingresado: \n";
    for (int i = 1; i <= 5; i++)
    {
        if (i == 5)
        {
            cout << A[i] << "\n";
        }
        else
        {
            cout << A[i] << " | ";
        }
    }
    cout << "Vector Copiado: \n";
    for (int i = 1; i <= 5; i++)
    {
        if (i == 5)
        {
            cout << B[i] << "\n";
        }
        else
        {
            cout << B[i] << " | ";
        }
    }
}

/*
Crea un pseudocódigo para cargar un vector de 5 elementos donde sus elementos sean solamente
pares y luego pasarlo a otro vector B. Imprimir ambos elementos. 
*/
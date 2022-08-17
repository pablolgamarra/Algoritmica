#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
        system("cls");
        int f, c;
        cout << "Cargue una matriz y el programa encontrara la cantidad de pares y los multiplos de 3 mayores a 6.\n";
        cout << "Cantidad de filas: ";
        cin >> f;
        while (f <= 0)
        {
            cout << "ERROR. La cantidad de filas debe ser positivas.\n";
            cout << "Vuelva a ingresar: ";
            cin >> f;
        }
        cout << "Ingrese la cantidad de columnas: ";
        cin >> c;
        while (c <= 0)
        {
            cout << "ERROR. La cantidad de columnas debe ser positivas.\n";
            cout << "Vuelva a ingresar: ";
            cin >> c;
        }
        int A[f][c], mayor, m3 = 0, cp = 0;
    if (f > c)
    {
        mayor = f;
    }
    else if (f < c)
    {
        mayor = c;
    }
    else
    {
        mayor = f;
    }
    int M3[mayor], CP[mayor];
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            system("cls");
            cout << "Carga de Datos.\n";
            cout << "Fila: " << i << "\tColumna: " << j << "\n";
            cout << "Valor: ";
            cin >> A[i][j];
            if ((A[i][j] % 2) == 0)
            {
                cp++;
                CP[cp]=A[i][j];
            }
            if (((A[i][j] % 3) == 0) && (A[i][j] > 6))
            {
                m3++;
                M3[m3]=A[i][j];
            }
        }
    }
    cout << "Matriz Cargada: \n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j == c)
            {
                cout << A[i][j] << "\n";
            }
            else
            {
                cout << A[i][j] << " | ";
            }
        }
    }
    if (cp <= 0)
    {
        cout << "No se ingresaron pares a la matriz.\n";
    }
    else
    {
        cout << "Vector de numeros pares ingresados: \n";
        for (int i = 1; i <= cp; i++)
        {
            if (i == cp)
            {
                cout << CP[i] << "\n";
            }
            else
            {
                cout << CP[i] << " | ";
            }
        }
    }
    if (m3 <= 0)
    {
        cout << "No se ingresaron multiplos de 3 mayores a 6 a la matriz.\n";
    }
    else
    {
        cout << "Vector de multiplos de 3 mayores a 6 ingresados: \n";
        for (int i = 1; i <= m3; i++)
        {
            if (i == m3)
            {
                cout << M3[i] << "\n";
            }
            else
            {
                cout << M3[i] << " | ";
            }
        }
    }
    system("pause");
    return 0;
}

/*
Crear y cargar una matriz A y los vectores M3 y CP que tendrán M3 = Cantidad de múltiplos de 3 mayores que
6 y CP = Cantidad de elementos pares, todos de la matriz A. Imprimir las estructuras de datos. 
*/
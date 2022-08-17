#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    system("cls");
    int n, num;
    cout << "Programa que carga un vector con numeros aleatorios.\n";
    cout << "Ingrese cantidad de elementos a generar: ";
    cin >> n;
    int M[n];
    cout << "Se creara el vector.\n";
    system("pause");
    for (int i = 1; i <= n; i++)
    {
        num = rand() % (100 - 10) + 10;
        M[i] = num;
    }
    cout << "Se creo el vector. Continuar para imprimir.\n";
    system("pause");
    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            cout << M[i] << "\n";
        }
        else
        {
            cout << M[i] << "|";
        }
    }
    system("pause");
    return 0;
}

/*
Crear y cargar un vector M con números al azar entre el 10 y 100. Decir cuántos elementos pares e impares
contiene el vector. Imprimir el vector. 
*/
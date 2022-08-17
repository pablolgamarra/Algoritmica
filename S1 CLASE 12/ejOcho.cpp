#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int V[6], suma = 0;
    cout << "Programa que permite cargar un vector de 5 elementos, para luego efectuar la sumatoria y el promedio de los datos cargados.\n";
    cout << "Carga de Datos: \n";
    for (int i = 1; i <= 5; i++)
    {
        cout << "Ingrese numero para posicion " << i << " : ";
        cin >> V[i];
        suma = suma + V[i];
    }
    system("cls");
    cout << "Vector Cargado: \n";
    for (int i = 1; i <= 5; i++)
    {
        if (i == 5)
        {
            cout << V[i] << "\n";
        }
        else
        {
            cout << V[i] << " | ";
        }
    }
    cout << "La suma de los elementos es: " << suma << "\n";
    cout << "El promedio es: " << suma / 5;
}

/*
Crear un pseudocódigo para cargar e imprimir un vector de 5 elementos y efectuar la sumatoria y el
promedio de elementos pares que se hayan cargado. 
*/
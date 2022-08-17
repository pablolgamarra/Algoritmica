#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    system("cls");
    int elementos, mayor, menor;
    cout << "Programa que permite ingresar la cantidad de elementos al azar que tendra un vector.\n";
    cout << "Ingrese la cantidad de elementos que desea que tenga el Vector: ";
    cin >> elementos;
    while ((elementos <= 0))
    {
        cout << "ERROR. El vector debe tener al menos un elemento: ";
        cin >> elementos;
    }
    int V[elementos];
    system("cls");
    for (int i = 1; i <= elementos; i++)
    {
        V[i] = rand() % (100 - 1) + 1;
        if (i == 1)
        {
            menor = V[i];
            mayor = V[i];
        }
        else if (V[i] > mayor)
        {
            mayor = V[i];
        }
        else if (V[i] < menor)
        {
            menor = V[i];
        }
    }
    for (int i = 1; i <= elementos; i++)
    {
        cout << "Posicion " << i << " : " << V[i] << "\n";
    }
    cout << "El menor numero generado es: " << menor << "\n";
    cout << "El mayor numero generado es: " << mayor << "\n";
    system("pause");
    return 0;
}

/*
Hacer un programa que permita crear un vector V, cargar con números al azar hasta 100. Imprimir el
vector, junto con el menor y mayor valor generado. 
*/
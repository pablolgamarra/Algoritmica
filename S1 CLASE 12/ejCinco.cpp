#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int elementos, contPares = 0, contImpares = 0;
    system("cls");
    cout << "Programa que permite crear un vector y cargarlo. Luego contar la cantidad de pares e impares.\n";
    cout << "Ingrese la cantidad de elementos: ";
    cin >> elementos;
    while (elementos < 20)
    {
        system("cls");
        cout << "ERROR. El vector debe tener como minimo 20 elementos.\n";
        cout << "Ingrese la cantidad de elementos: ";
        cin >> elementos;
    }
    int A[elementos];
    for (int i = 1; i <= elementos; i++)
    {
        system("cls");
        cout << "Posicion " << i << "\n";
        cout << "Ingrese elemento: ";
        cin >> A[i];
    }
    for (int i = 1; i <= elementos; i++)
    {
        if (A[i] % 2 == 0)
        {
            contPares++;
        }
        else
        {
            contImpares++;
        }
    }
    system("cls");
    cout << "Cantidad de Pares encontrados: " << contPares << "\n";
    cout << "Cantidad de Impares encontrados: " << contImpares << "\n";
    for (int i = 1; i <= elementos; i++)
    {
        cout << "Posicion " << i << " : " << A[i] << "\n";
    }
    system("pause");
    return 0;
}

/*
Hacer un programa que permita dimensionar un vector con no menos de 20 elementos.
Buscar e imprimir la cantidad de elementos pares e impares cargados. Imprimir el vector. 
*/
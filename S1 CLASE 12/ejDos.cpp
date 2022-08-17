#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    system("cls");
    srand((unsigned)time(NULL));
    int A[21], numRnd;
    cout << "Programa que crea un vector con 20 elementos aleatorios.\n";
    for (int i = 1; i <= 20; i++)
    {
        A[i] = rand() % 50 + 1;
    }

    for (int i = 1; i <= 20; i++)
    {
        cout << "Posicion " << i << " : " << A[i] << "\n";
    }
    system("pause");
    return 0;
}

/*
Crear y cargar un vector A con 20 elementos aleatorios hasta 50. Imprimir el vector
*/
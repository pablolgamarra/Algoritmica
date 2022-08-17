#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    system("cls");
    srand((unsigned)time(NULL));
    int elementos = (rand() % (100 - 20) + 20), N[elementos];
    cout << "El vector tendra: " << elementos << " elementos.\n";
    system("pause");
    system("cls");
    for (int i = 1; i <= elementos; i++)
    {
        N[i] = (rand() % (100 - 20) + 20);
    }
    for (int i = 1; i <= elementos; i++)
    {
        cout << "Posicion: " << i << ": " << N[i] << "\n";
    }
    system("pause");
    return 0;
}

/*
Crear y cagar un vector N con no menos de 20 elementos al azar entre el 20 y 100. Imprimir el vector. 
*/
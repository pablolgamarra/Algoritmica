#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void cuantToGen(int &);

int randomGenerator(int &);

void chargeArray(int *, int, int);

void printArray(int *, int);

main()
{
    int limit, n, *ptr;
    srand(time(NULL));
    system("cls");
    cout << "Programa para generar un vector con numeros aleatorios.\n";
    cuantToGen(limit);
    int M[limit];
    ptr = M;
    chargeArray(ptr, limit, n);
    cout << "Se imprimira el vector con los numeros creados.\n";
    system("pause");
    printArray(ptr, limit);
    system("pause");
    return 0;
}

void cuantToGen(int &limit)
{
    cout << "Ingrese la cantidad de numeros que desea que el programa genere: ";
    cin >> limit;
    while (limit <= 0)
    {
        cout << "Error. La cantidad a generar debe ser al menos uno.\n";
        cout << "Ingrese la cantidad de numeros que desea que el programa genere: ";
        cin >> limit;
    }
    return;
}

int randomGenerator(int &n)
{
    n = rand() % (100) + 0;
    return n;
}

void chargeArray(int *array, int limit, int n)
{
    int aux;
    bool verified = false;
    cout << "Carga de Datos.\n";
    for (int i = 0; i < limit; i++)
    {
        aux = randomGenerator(n);
        verified = false;
        do
        {
            if (i == 0)
            {
                verified = true;
                break;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    if (aux == (*(array + j)))
                    {
                        aux = randomGenerator(n);
                        verified = false;
                        break;
                    }
                    else
                    {
                        verified = true;
                    }
                }
            }
        } while (!verified);
        *(array + i) = aux;
    }
    return;
}

void printArray(int *array, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        if (i == (limit - 1))
        {
            cout << *(array + i) << "\n";
        }
        else
        {
            cout << *(array + i) << " || ";
        }
    }
    return;
}

/*
Crear un vector dinámico con “n” números aleatorios sin repetir ningún elemento. Imprimir el arrays
dinámico creado. 
*/
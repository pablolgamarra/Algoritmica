#include <iostream>
#include <windows.h>

using namespace std;

void ingNum(int &);

void binario(int);

main()
{
    int n;
    cout << "Programa para convertir un numero a binario mediante programacion recursiva.\n";
    system("cls");
    ingNum(n);
    binario(n);
    cout << "\n";
    system("pause");
}

void ingNum(int &n)
{
    do
    {
        cout << "Ingrese un numero positivo: ";
        cin >> n;
    } while (n <= 0);
    return;
}

void binario(int n)
{
    if (n > 1)
        binario(n / 2);
    cout << n % 2;
}

/*
Ingresar un número y mostrar su equivalente en binario usando una función recursiva 
*/
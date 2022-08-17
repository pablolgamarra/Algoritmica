#include <iostream>
#include <windows.h>

using namespace std;

void ingNum(int &);

int factorial(int);

main()
{
    system("cls");
    int n;
    cout << "Programa calculador de factorial por medio de la recursividad.\n";
    ingNum(n);
    system("cls");
    cout << "La factorial de " << n << " es: " << factorial(n) << "\n";
    system("pause");
    return 0;
}

void ingNum(int &n)
{
    cout << "Ingrese numero: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Error. Solo numeros positivos.\n";
        cout << "Ingrese numero: ";
        cin >> n;
    }
    return;
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
/*
Programar un algoritmo recursivo que calcule la factorial de un número. 
*/
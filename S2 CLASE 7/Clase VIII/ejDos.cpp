#include <iostream>
#include <windows.h>

using namespace std;

int multiplicacion(int);

main()
{
    system("cls");
    int i = 1;
    cout << "Programa para multiplicar numeros de forma recursiva.\n";
    int mult = multiplicacion(i);
    system("cls");
    cout << "El producto es: " << mult << "\n";
    system("pause");
}

int multiplicacion(int i)
{
    int n;
    cout << "Ingrese numero: ";
    cin >> n;
    if (i == 2)
    {
        return n;
    }
    else
    {
        return n * (multiplicacion(i + 1));
    }
}

/*
Calcular el producto de dos números de forma recursiva. Los números a multiplicar se leen por teclado.
*/

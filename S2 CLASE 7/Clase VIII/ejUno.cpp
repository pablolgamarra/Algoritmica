#include <iostream>
#include <windows.h>

using namespace std;

int suma(int);

main()
{
    int i = 1;
    cout << "Programa para sumar dos numeros de manera recursiva.\n";
    cout << suma(i) << endl;
    system("pause");
}

int suma(int i)
{
    int n;
    system("cls");
    cout << "Ingrese numero: ";
    cin >> n;
    if (i == 2)
    {
        return n;
    }
    else
    {
        return n + (suma(i + 1));
    }
}
/*
Calcular la suma de dos números de forma recursiva. Los números a sumar se leen por teclado
*/

/*

suma recursiva

n=lo que ingresa por teclado
i= cantidad de veces
suma

i!= 2 se ejecuta

suma=suma+n



*/
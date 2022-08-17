#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int n, div=0;
    cout << "Programa para calcular si un numero es primo o no y ademas señalar la posicion en memoria.\n";
    cout << "Ingrese numero: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            div++;
        }
    }
    if (div > 2)
    {
        cout << "El numero ingresado es un numero primo.\n";
    }
    else
    {
        cout << "El numero ingresado no es un numero primo.\n";
    }
    cout << "La posicion en memoria donde se guardo el numero es: " << &n << "\n";
    system("pause");
    return 0;
}

/* Determinar si un número es primo o no; con punteros y además indicar en qué posición
de memoria se guardó el número.  */
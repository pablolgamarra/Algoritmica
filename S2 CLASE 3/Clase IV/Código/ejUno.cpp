#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int n;
    cout << "Programa para calcular si un numero es par o impar y ademas señalar la posicion en memoria.\n";
    cout << "Ingrese numero: ";
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "El numero ingresado es par.\n";
    }
    else
    {
        cout << "El numero ingresado es impar\n";
    }
    cout << "La posicion en memoria es: " << &n << "\n";
    system("pause");
    return 0;
}

/* Comprobar si un número es par o impar, y señalar la posición de memoria donde se está
guardando el numero utilizando punteros */
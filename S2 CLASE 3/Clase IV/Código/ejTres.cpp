#include <iostream>
#include <windows.h>

using namespace std;

void intercambio(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int x, y;
    system("cls");
    cout << "Programa para intercambiar valor de variables.\n";
    cout << "Ingresar valor para primera variable: ";
    cin >> x;
    cout << "Ingresar valor para segunda variable: ";
    cin >> y;
    intercambio(&x, &y);
    cout << "Primer valor: " << x << endl;
    cout << "Segundo valor: " << y << endl;
    system("pause");
    return 0;
}

/* Ingresar dos números. Intercambiar sus valores utilizando punteros. */
#include <iostream>
#include <windows.h>

using namespace std;

void ingNum(int &);

int invertir(int, int);

main()
{
    system("cls");
    int n;
    ingNum(n);
    system("cls");
    cout << "Numero Invertido: " << invertir(n, 0) << "\n";
    system("pause");
    return 0;
}

void ingNum(int &n)
{
    cout << "Ingrese numero a invertir: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "ERROR!. Vuelva a ingresar.\n";
        cout << "Ingrese numero a invertir: ";
        cin >> n;
    }
    return;
}

int invertir(int num, int numInv)
{
    if (num > 0)
    {
        return invertir(num / 10, num % 10 + numInv * 10);
    }
    else
    {
        return numInv;
    }
}
/*
Ingresar un número y mostrar el número de forma invertida ejemplo 123 – 321
*/
#include <iostream>
#include <windows.h>

using namespace std;

void ingNum(int &, int &);

int potencia(int, int);

main()
{
    int num, exp;
    system("cls");
    cout << "Programa que permite calcular la potencia de un numero.\n";
    ingNum(num, exp);
    system("cls");
    cout << "Base: " << num << "\nExponente: " << exp << "\nPotencia: " << potencia(num, exp) << "\n";
    system("pause");
    return 0;
}

void ingNum(int &num, int &exp)
{
    do
    {
        cout << "Ingrese Base: ";
        cin >> num;
    } while (num <= 0);
    do
    {
        cout << "Ingrese Exponente: ",
            cin >> exp;
    } while (exp <= 0);
    return;
}

int potencia(int num, int exp)
{
    if (exp == 1)
    {
        return num;
    }
    else
    {
        return num * potencia(num, (exp - 1));
    }
}

/*
Determinar la potencia de un número con funciones recursivas 
*/

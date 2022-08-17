#include <iostream>
#include <windows.h>

using namespace std;
void ingNum(int &, int &);

int mcd(int, int);

main()
{
    int numUno, numDos;
    system("cls");
    cout << "Programa para hallar el Maximo Comun Divisor de Dos Numeros.\n";
    ingNum(numUno, numDos);
    system("cls");
    cout << "El Maximo Comun Divisor de " << numUno << " y " << numDos << " es " << mcd(numUno, numDos) << "\n";
    system("pause");
    return 0;
}

void ingNum(int &numUno, int &numDos)
{
    do
    {
        cout << "Ingrese primer numero, debe ser positivo: ";
        cin >> numUno;
    } while (numUno <= 0);
    do
    {
        cout << "Ingrese segundo numero, debe ser positivo: ";
        cin >> numDos;
    } while (numDos <= 0);
    return;
}

int mcd(int numUno, int numDos)
{
    if (numDos == 0)
    {
        return numUno;
    }
    else
    {
        return mcd(numDos, numUno % numDos);
    }
}
/*

Ingrese dos números positivos. Crear una función recursiva que permita hallar el MCD
de dichos números (MCD: máximo común divisor) 
*/
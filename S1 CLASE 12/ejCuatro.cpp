#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int elementos, i = 1;
    cout << "El programa creara un vector con la cantidad de elementos que indique. Los elementos deberan ser numeros pares mayores a 10.\n";
    cout << "Ingrese la cantidad de elementos: ";
    cin >> elementos;
    while (elementos < 1)
    {
        cout << "ERROR.\n Debe haber al menos un elemento: ";
        cin >> elementos;
    }
    int B[elementos];
    for (i = 1; i <= elementos; i++)
    {
        cout << "Ingrese elemento " << i << " : ";
        cin >> B[i];
        while ((B[i] % 2) != 0 || B[i] < 10)
        {
            cout << "ERROR!. Los elementos deben ser pares y mayores que 10.\n";
            cout << "Ingrese elemento: " << i << " : ";
            cin >> B[i];
        }
    }
    system("cls");
    for (i = 1; i <= elementos; i++)
    {
        cout << "Posicion: " << i << " = " << B[i] << "\n";
    }
    system("pause");
    return 0;
}

/*
Crear y cargar un vector B con números pares mayores que 10. Imprimir el vector. 
*/
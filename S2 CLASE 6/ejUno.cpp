#include <iostream>
#include <windows.h>

using namespace std;

void ingresarNum(int &, int &);

void impNumeros(int, int, int *);

void cargarArray(int, int, int *);

main()
{
    system("cls");
    int n1, n2;
    cout << "Programa que imprime los numeros existentes entre dos numeros.\n";
    ingresarNum(n1, n2);
    int serieNums[n2];
    int *array = serieNums;
    cargarArray(n1, n2, array);
    impNumeros(n1, n2, array);
    delete[] array;
    system("pause");
    return 0;
}

void ingresarNum(int &n1, int &n2)
{
    int aux;
    cout << "Ingrese valor para el primer numero: ";
    cin >> n1;
    cout << "Ingrese valor para el segundo numero: ";
    cin >> n2;
    //Comprobar si los numeros son iguales
    while (n1 == n2)
    {
        system("cls");
        cout << "Los numeros no pueden ser iguales!. Vuelva a ingresar valores\n";
        cout << "Ingrese valor para el primer numero: ";
        cin >> n1;
        cout << "Ingrese valor para el segundo numero: ";
        cin >> n2;
    }
    //Determinar cual numero es el mayor
    if (n1 > n2)
    {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    return;
}

void cargarArray(int n1, int n2, int *array)
{
    for (n1; n1 <= n2; n1++)
    {
        *(array + n1) = n1;
    }
}

void impNumeros(int n1, int n2, int *array)
{
    for (n1; n1 <= n2; n1++)
    {
        cout << *(array + n1) << "\n";
    }
    cout << "Posicion en Memoria de la Serie de Numeros: " << array << "\n";
    return;
}

/*
Ingresar dos números distintos. Imprimir la serie de números existentes entre ambos. Imprime a demás, la
ubicación en memoria de dicha serie de números. 
*/
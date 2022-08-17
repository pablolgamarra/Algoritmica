#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int f, c;
    cout << "Cargue una matriz y el programa hara un resumen de los elementos de la diagonal principal\n";
    cout << "Cantidad de filas: ";
    cin >> f;
    while (f <= 0)
    {
        cout << "ERROR. La cantidad de filas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> f;
    }
    cout << "Ingrese la cantidad de columnas: ";
    cin >> c;
    while (c <= 0)
    {
        cout << "ERROR. La cantidad de columnas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> c;
    }
    int B[f][c], suma = 0, may, men, masDos = 0;
    bool primo = false;
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            system("cls");
            cout << "Carga de Datos.\n";
            cout << "Fila: " << i << "\tColumna: " << j << "\n";
            cout << "Valor: ";
            cin >> B[i][j];
            if (i == 1 && j == 1)
            {
                may = B[i][j];
                men = B[i][j];
            }
            if (i == j)
            {
                suma = suma + B[i][j];
                if (B[i][j] < men)
                {
                    men = B[i][j];
                }
                else if (B[i][j] > may)
                {
                    may = B[i][j];
                }
                if (B[i][j] > 99 || B[i][j] < -99)
                {
                    masDos++;
                }
            }
        }
    }
    int div = 0;
    for (int i = 1; i <= suma; i++)
    {
        if ((suma % i) == 0)
        {
            div++;
        }
    }
    if (div <= 2)
    {
        primo = true;
    }
    else
    {
        primo = false;
    }
    system("cls");
    cout << "Matriz Cargada: \n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j == c)
            {
                cout << B[i][j] << "\n";
            }
            else
            {
                cout << B[i][j] << " | ";
            }
        }
    }
    cout << "Suma de elementos de la diagonal principal: " << suma << "\n";
    cout << "Mayor Elemento: " << may << "\n";
    cout << "Menor Elemento: " << men << "\n";
    cout << "Numeros con mas de dos elementos: " << masDos << "\n";
    if (primo)
    {
        cout << "La sumatoria es primo.\n";
    }
    else
    {
        cout << "La sumatoria es no es primo.\n";
    }
    system("pause");
    return 0;
}

/*
Cargar los elementos de una matriz B. realizar un resumen sobre los elementos de la diagonal principal según
se muestra en la figura. Imprimir la matriz y los datos hallados.
*/
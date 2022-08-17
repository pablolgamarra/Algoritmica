#include <iostream>
#include <windows.h>

using namespace std;

int f, c;

void cargaFC(int &f, int &c)
{
    cout << "Cantidad de filas: ";
    cin >> f;
    while (f <= 0)
    {
        cout << "ERROR. La cantidad de filas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> f;
    }
    cout << "Cantidad de columnas: ";
    cin >> c;
    while (c <= 0)
    {
        cout << "ERROR. La cantidad de columnas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> c;
    }
}

int main()
{
    system("cls");
    cout << "Cargue una matriz y el programa hallara la diagonal secundaria y la ordenara de manera ascendente y de manera descendente.\n";
    cargaFC(f, c);
    while (f != c)
    {
        cout << "La matriz debe ser cuadrada.\n";
        cargaFC(f, c);
    }
    int B[f][c], DS[f];
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            system("cls");
            cout << "Carga de Datos.\n";
            cout << "Fila: " << i << "\tColumna: " << j << "\n";
            cout << "Valor: ";
            cin >> B[i][j];
            if ((i + j) == (f + 1))
            {
                DS[i] = B[i][j];
            }
        }
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
    cout << "Vector Diagonal Secundaria: \n";
    for (int i = 1; i <= f; i++)
    {
        if (i == f)
        {
            cout << DS[i] << "\n";
        }
        else
        {
            cout << DS[i] << " | ";
        }
    }
    cout << "Vector Diagonal Secundaria ordenado de manera Ascendente: \n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j < f; j++)
        {
            if (DS[j] > DS[j + 1])
            {
                c = DS[j];
                DS[j] = DS[j + 1];
                DS[j + 1] = c;
            }
        }
    }
    for (int i = 1; i <= f; i++)
    {
        if (i == f)
        {
            cout << DS[i] << "\n";
        }
        else
        {
            cout << DS[i] << " | ";
        }
    }
    cout << "Vector Diagonal Secundaria ordenado de manera Descendente: \n";
    for (int i = f; i >= 1; i--)
    {
        for (int j = f; j > 1; j--)
        {
            if (DS[j] > DS[j - 1])
            {
                c = DS[j];
                DS[j] = DS[j - 1];
                DS[j - 1] = c;
            }
        }
    }
    for (int i = 1; i <= f; i++)
    {
        if (i == f)
        {
            cout << DS[i] << "\n";
        }
        else
        {
            cout << DS[i] << " | ";
        }
    }
    system("pause");
    return 0;
}

/*
Crear una matriz B y un vector DS. Cargar el vector DS con los elementos de la diagonal secundaria de la
matriz. Ordenar el vector en forma Ascendente y Descendente. Imprimir las estructuras de datos (Imprimir el
vector antes y después de cada proceso de orden) 
*/
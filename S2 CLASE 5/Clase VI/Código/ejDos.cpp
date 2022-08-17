#include <iostream>
#include <windows.h>

using namespace std;

void cargaFC(int &, int &);

void cargaMatriz(int **, int, int);

void mostrarMatriz(int **, int, int);

void promDP(int **, int, int);

void promDS(int **, int, int);

main(){
    int filas, columnas;
    system("cls");
    cout << "Cargue una matriz y el programa podra realizar diferentes funciones.\n";
    //Ingreso de Cantidad de Filas y Columnas
    cargaFC(filas, columnas);
    //Declaracion Matriz Dinámica
    int **matriz = new int *[filas];
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(matriz + j) = new int[columnas];
        }
    }
    //Funciones Requeridas
    cargaMatriz(matriz, filas, columnas);
    mostrarMatriz(matriz, filas, columnas);
    promDP(matriz, filas, columnas);
    promDS(matriz, filas, columnas);
    cout<<"Gracias por utilizar el programa.\n";
    //Liberación del Espacio de la Matriz Dinámica
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    system("pause");
    return 0;
}

void cargaFC(int &filas, int &columnas)
{
    cout << "Ingrese la cantidad de filas que tendra la Matriz: ";
    cin >> filas;
    cout << "Ingrese la cantidad de columnas que tendra la Matriz: ";
    cin >> columnas;
    while ((filas <= 0 || columnas <= 0) || (filas != columnas))
    {
        system("cls");
        cout << "Ha ocurrido un error. La cantidad de filas y/o columnas no puede ser negativa. La cantidad de filas y de columnas deben ser iguales.\n";
        cout << "Ingrese la cantidad de filas que tendra la Matriz: ";
        cin >> filas;
        cout << "Ingrese la cantidad de columnas que tendra la Matriz: ";
        cin >> columnas;
    }
}

void cargaMatriz(int **matriz, int filas, int columnas)
{
    system("cls");
    cout << "Carga de Datos.\n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingrese valor para posicion ( " << i << ", " << j << " ): ";
            cin >> *(*(matriz + i) + j);
        }
    }
}

void mostrarMatriz(int **matriz, int filas, int columnas)
{
    system("cls");
    cout << "Matriz Cargada: \n";
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (j == (columnas - 1))
            {
                cout << *(*(matriz + i) + j) << "\n";
            }
            else
            {
                cout << *(*(matriz + i) + j) << " | ";
            }
        }
    }
    system("pause");
}

void promDP(int **matriz, int filas, int columnas)
{
    float promedio=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                promedio = promedio + *(*(matriz + i) + j);
            }
        }
    }
    system("cls");
    cout << "El promedio de los elementos de la diagonal principal es: " << (promedio/filas) << "\n";
    system("pause");
}

void promDS(int **matriz, int filas, int columnas)
{
    float promedio=0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i + j == (columnas - 1))
            {
                if (((*(*(matriz + i) + j)) % 2) == 0)
                {
                    promedio = promedio + *(*(matriz + i) + j);
                }
            }
        }
    }
    system("cls");
    cout << "El promedio de los elementos de la diagonal secundaria es: " << (promedio/filas) << "\n";
    system("pause");
}


/*
Crear y cargar una matriz M. Imprimir la matriz junto con el promedio de elementos de
la diagonal principal y secundaria. 
*/
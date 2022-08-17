#include <iostream>
#include <windows.h>

using namespace std;

void rowsAndColumns(int &, int &);

void arrayCreator(int **, int, int);

void arrayValues(int **, int, int, int &);

void printArray(int **, int, int);

void printAnRow(int **, int, int);

void optionSelector(int &);

void menu(int, int **, int, int, int);

main()
{
    int rows, columns, higher, option;
    system("cls");
    cout << "Cargue una matriz dinamica y podra realizar acciones con ella.\n";
    //Carga de Cantidad de Datos
    rowsAndColumns(rows, columns);
    //Creacion de Array
    int **array = new int *[rows];
    arrayCreator(array, rows, columns);
    //Carga del Array
    arrayValues(array, rows, columns, higher);
    //Menu
    menu(option, array, rows, columns, higher);
    system("pause");
    return 0;
}

void rowsAndColumns(int &rows, int &columns)
{
    cout << "Ingrese la cantidad de filas que tendra la matriz: ";
    cin >> rows;
    while (rows <= 0)
    {
        system("cls");
        cout << "Debe haber al menos una fila.\nVolver a ingresar.\n";
        cout << "Ingrese la cantidad de filas que tendra la matriz: ";
        cin >> rows;
    }
    system("cls");
    cout << "Ingrese la cantidad de columnas que tendra la matriz: ";
    cin >> columns;
    while (columns <= 0)
    {
        system("cls");
        cout << "Debe haber al menos una columna.\nVolver a ingresar.\n";
        cout << "Ingrese la cantidad de columnas que tendra la matriz: ";
        cin >> columns;
    }
    return;
}

void arrayCreator(int **array, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(array + j) = new int[columns];
        }
    }
    return;
}

void arrayValues(int **array, int rows, int columns, int &higher)
{
    system("cls");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Carga de Datos.\n";
            cout << "Posicion: ( " << i << ", " << j << " ).\nValor: ";
            cin >> (*(*(array + i) + j));
            if ((i == 0) && (j == 0))
            {
                higher = *(*(array + i) + j);
            }
            else if ((*(*(array + i) + j)) > higher)
            {
                higher = *(*(array + i) + j);
            }
        }
    }
    return;
}

void printArray(int **array, int rows, int columns)
{
    system("cls");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j == (columns - 1))
            {
                cout << *(*(array + i) + j) << "\n";
            }
            else
            {
                cout << *(*(array + i) + j) << " || ";
            }
        }
    }
    system("pause");
    return;
}

void printAnRow(int **array, int rows, int columns)
{
    system("cls");
    int row2Print;
    cout << "Ingresa la fila que queres imprimir (0) hasta (" << (rows-1) << "): ";
    cin >> row2Print;
    while (row2Print < 0 || row2Print > rows)
    {
        cout << "Fila no valida!\n";
        cout << "Ingresa la fila que queres imprimir (0) hasta (" << rows << "): ";
        cin >> row2Print;
    }
    system("cls");
    for (int j = 0; j < columns; j++)
    {
        if (j == (columns - 1))
        {
            cout << (*(*(array + row2Print) + j)) << "\n";
        }
        else
        {
            cout << (*(*(array + row2Print) + j)) << " || ";
        }
    }
    system("pause");
    return;
}

void optionSelector(int &option)
{
    system("cls");
    cout << "Seleccione la accion que desea realizar.\n";
    cout << "1. Imprimir la Matriz.\n";
    cout << "2. Imprimir una sola fila.\n";
    cout << "3. Mostrar el mayor numero cargado a la Matriz.\n";
    cout << "4. Salir del Programa.\n";
    cin >> option;
    while (option < 1 || option > 4)
    {
        system("cls");
        cout << "La opcion ingresada no es valida. Vuelva a seleccionar.\n";
        cout << "1. Imprimir la Matriz.\n";
        cout << "2. Imprimir una sola fila.\n";
        cout << "3. Mostrar el mayor numero cargado a la Matriz.\n";
        cout << "4. Salir del Programa.\n";
        cin >> option;
    }
    return;
}

void menu(int option, int **array, int rows, int columns, int higher)
{
    do
    {
        optionSelector(option);
        switch (option)
        {
            case 1:
                printArray(array, rows, columns);
                break;
            case 2:
                printAnRow(array, rows, columns);
                break;
            case 3:
                system("cls");
                cout << "El mayor elemento ingresado es: " << higher << "\n";
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "Gracias por usar el programa.\n";
                break;
            default:
                cout << "Opcion seleccionada es inexistente.\n";
                break;
        }
        return;
    } while (option != 4);    
}

/*
Crear y cargar una matriz dinámica. Utiliza el siguiente menú para imprimir los siguientes datos:
1- Imprimir la Matriz
2- Imprimir una Fila determinada
3- Mayor elemento cargado en la matriz 
*/
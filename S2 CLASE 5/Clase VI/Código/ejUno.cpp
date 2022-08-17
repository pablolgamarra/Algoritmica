#include <iostream>
#include <windows.h>

using namespace std;

//Variables Globales
int filas, columnas, opcion;

//Prototipos
void cargaFC(int &, int &);

void cargaMatriz(int **, int, int);

void mostrarMatriz(int **, int, int);

void sumaDP(int **, int, int);

void cantPIP(int **, int, int);

void perimetroM(int **, int, int);

void seleccionOp(int &);

//Rutina Principal
main()
{
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
    //Carga de Datos/Matriz
    cargaMatriz(matriz, filas, columnas);
    //Menú
    do
    {
        seleccionOp(opcion);
        switch (opcion)
        {
        case 1:
            mostrarMatriz(matriz, filas, columnas);
            break;
        case 2:
            sumaDP(matriz, filas, columnas);
            break;
        case 3:
            cantPIP(matriz, filas, columnas);
            break;
        case 4:
            perimetroM(matriz, filas, columnas);
            break;
        case 5:
            cout << "Gracias por utilizar el programa.\n";
            break;
        default:
            cout<<"La opcion seleccionada no es valida.\n";
            break;
        }
    }while(opcion != 5);
    // //PRUEBAS DE FUNCIONES
    // sumaDP(matriz, filas, columnas);
    // cantPIP(matriz, filas, columnas);
    // perimetroM(matriz, filas, columnas);
    // //
    //Liberar espacio en memoria ocupado por la matriz
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    system("pause");
    return 0;
}

//Funciones
void cargaFC(int &filas, int &columnas)
{
    bool verificado = false;
    cout << "Ingrese la cantidad de filas que tendra la Matriz: ";
    cin >> filas;
    cout << "Ingrese la cantidad de columnas que tendra la Matriz: ";
    cin >> columnas;
    while ((filas <= 0 || columnas <= 0) || (filas != columnas))
    {
        verificado = false;
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

void sumaDP(int **matriz, int filas, int columnas)
{
    int suma = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                suma = suma + *(*(matriz + i) + j);
            }
        }
    }
    system("cls");
    cout << "La suma de los elementos de la diagonal principal es: " << suma << "\n";
    system("pause");
}

void cantPIP(int **matriz, int filas, int columnas)
{
    int cantPares = 0, cantImpares = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i + j == (columnas - 1))
            {
                if (((*(*(matriz + i) + j)) % 2) == 0)
                {
                    cantPares++;
                }
                else
                {
                    cantImpares++;
                }
            }
        }
    }
    system("cls");
    cout << "La cantidad de pares que se encuentran en la Diagonal Secundaria es: " << cantPares << "\n";
    cout << "La cantidad de impares que se encuentran en la Diagonal Secundaria es: " << cantImpares << "\n";
    system("pause");
}

void perimetroM(int **matriz, int filas, int columnas)
{
    int perimetro = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == 0)
            {
                perimetro = perimetro + (*(*(matriz + i) + j));
            }
            else if (i == (filas - 1))
            {
                perimetro = perimetro + (*(*(matriz + i) + j));
            }
            else if (j == 0 || j == (columnas - 1))
            {
                perimetro = perimetro + (*(*(matriz + i) + j));
            }
        }
    }
    system("cls");
    cout << "El Perimetro de la Matriz Cargada es: " << perimetro << "\n";
    system("pause");
}

void seleccionOp(int &opcion)
{
    system("cls");
    cout << "Seleccione una opcion.\n";
    cout << "1. Imprimir la matriz cargada.\n";
    cout << "2. Para imprimir la sumatoria de los elementos de la diagonal principal.\n";
    cout << "3. Para imprimir la cantidad de pares e impares de la diagonal secundaria.\n";
    cout << "4. Para imprimir la sumatoria de elementos del perimetro de la Matriz.\n";
    cout << "5. Para salir del programa.\n";
    cout << "Ingrese su seleccion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > 6)
    {
        system("cls");
        cout << "La opcion ingresada no es válida. Vuelva a ingresar seleccion.\n";
        cout << "1. Imprimir la matriz cargada.\n";
        cout << "2. Para imprimir la sumatoria de los elementos de la diagonal principal.\n";
        cout << "3. Para imprimir la cantidad de pares e impares de la diagonal secundaria.\n";
        cout << "4. Para imprimir la sumatoria de elementos del perimetro de la Matriz.\n";
        cout << "5. Para salir del programa.\n";
        cout << "Ingrese su seleccion: ";
        cin >> opcion;
    }
}

/*
Crear y cargar una matriz dinámica y con el siguiente menú de selección, desarrolla las
rutinas para cada uno:
- cargarMatriz: se encargará de agregar elementos a la matriz dinámica
- mostrarMatriz: se encargará de mostrar los elementos cargados en la matriz
dinámica.
- sumaDP: se encargará de hallar la sumatoria de los elementos de la diagonal
principal
- cantPIP: se encargará de hallar la cantidad de elementos pares e impares de la
diagonal secundaria.
- perimetroM: se encargará de mostrar el perímetro correspondiente a la matriz
cargada 
*/
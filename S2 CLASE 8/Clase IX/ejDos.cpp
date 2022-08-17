#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void cantElementos(int &);

void cargaDatos(int **, int);

void cargaMayor(int **, int, int *);

void cargaMenor(int **, int, int *);

void promedioColumnas(int **, int, int *);

void cargaDP(int **, int, int *);

void cargaDS(int **, int, int *);

void selectorOpcion(int &);

void menu(int &, int **, int, int *, int *, int *, int *, int *);

void funcUno(int **, int);

void funcDos(int *, int);

void funcTres(int *, int);

void funcCuatro(int *, int);

void funcCincoSeis(int *, int);

void funcSiete(int **, int *, int *, int);

void funcOcho(int *, int);

void funcNueve(int *, int);

void funcDiez(int *, int);

void funcOnce(int *, int);

void funcDoce(int *, int);

void funcTrece(int **, int);

bool esPrimo(int);

main()
{
    int n;
    system("cls");
    cout << "Cargue una matriz y el programa le permitira hacer diferentes funciones.\n";
    //El usuario ingresa la cantidad de filas y columnas que tendra la Matriz (Minimo 4)
    cantElementos(n);
    //Creacion de Matriz Principal y Vectores
    int **A = new int *[n], *MEN = new int[n], *MAY = new int[n], *P = new int[n], *DP = new int[n], *DS = new int[n], opcion;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            *(A + j) = new int[n];
        }
    }
    //Carga de Datos en la Matriz Principal
    cargaDatos(A, n);
    cout << "Sale de la Carga de Datos";
    //Menu de Funciones que se pueden realizar
    menu(opcion, A, n, MEN, MAY, P, DP, DS);
    getch();
    return 0;
}

void cantElementos(int &n)
{
    do
    {
        cout << "Ingrese la cantidad de filas y columnas que tendra la matriz (Minimo 4 ): ";
        cin >> n;
    } while (n < 4);
    return;
}

void cargaDatos(int **A, int limite)
{
    for (int i = 1; i <= limite; i++)
    {
        system("cls");
        for (int j = 1; j <= limite; j++)
        {
            cout << "Carga de Datos.\nPosicion (" << i << " , " << j << "): ";
            cin >> *(*(A + i) + j);
        }
    }
    return;
}

void cargaMenor(int **A, int limite, int *MEN)
{
    int menorDeFila;
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if (j == 1)
            {
                menorDeFila = *(*(A + i) + j);
            }
            else if ((*(*(A + i) + j)) < menorDeFila)
            {
                menorDeFila = *(*(A + i) + j);
            }
        }
        *(MEN + i) = menorDeFila;
    }
    return;
}

void cargaMayor(int **A, int limite, int *MAY)
{
    int mayorDeFila;
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if (j == 1)
            {
                mayorDeFila = *(*(A + i) + j);
            }
            else if (*(*(A + i) + j) > mayorDeFila)
            {
                mayorDeFila = *(*(A + i) + j);
            }
        }
        *(MAY + i) = mayorDeFila;
    }
    return;
}

void promedioColumnas(int **A, int limite, int *P)
{
    int auxProm = 0;
    for (int i = 1; i <= limite; i++)
    {
        auxProm = 0;
        for (int j = 1; j <= limite; j++)
        {
            auxProm = auxProm + (*(*(A + j) + i));
        }
        *(P + i) = (auxProm / limite);
    }
    return;
}

void cargaDP(int **A, int limite, int *DP)
{
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if (i == j)
            {
                *(DP + i) = *(*(A + i) + j);
            }
        }
    }
    return;
}

void cargaDS(int **A, int limite, int *DS)
{
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if ((i + j) == (limite + 1))
            {
                *(DS + j) = *(*(A + i) + j);
            }
        }
    }
    return;
}

void funcUno(int **A, int limite)
{
    // Mostrar la matriz junto con la dirección de memoria del primer y último elemento
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if (j != limite)
            {
                cout << *(*(A + i) + j) << " | ";
            }
            else
            {
                cout << *(*(A + i) + j) << " ";
            }
        }
        cout << "\n";
    }
    cout << "Posicion de Memoria del Primer Elemento: " << (*(A + 1) + 1) << "\n";
    cout << "Posicion de Memoria del Ultimo Elemento: " << (*(A + limite) + limite) << "\n";
    return;
}

void funcDos(int *MEN, int limite)
{
    //Mostrar el vector MEN, mostrando la posición de memoria de cada elemento
    for (int i = 1; i <= limite; i++)
    {
        cout << "Menor de la Fila " << i << ": " << *(MEN + i) << "\n";
        cout << "Posicion en Memoria: " << (MEN + i) << "\n";
    }
    return;
}

void funcTres(int *MAY, int limite)
{
    //Mostrar el vector MAY, mostrando la posición de memoria de cada elemento
    for (int i = 1; i <= limite; i++)
    {
        cout << "Mayor de la Fila " << i << ": " << *(MAY + i) << "\n";
        cout << "Posicion en Memoria: " << (MAY + i) << "\n";
    }
    return;
}

void funcCuatro(int *P, int limite)
{
    //Mostrar el vector P, mostrando la posición de memoria de cada elemento
    for (int i = 1; i <= limite; i++)
    {
        cout << "Promedio de la Columna " << i << ": " << *(P + i) << "\nPosicion en Memoria: " << (P + i) << "\n";
    }
    return;
}

void funcCincoSeis(int *Diagonal, int limite)
{
    //Mostrar el vector DP, mostrando la posición de memoria de cada elemento
    for (int i = 1; i <= limite; i++)
    {
        cout << "Posicion " << i << ", " << i << ". Corresponde al Elemento: " << *(Diagonal + i) << "\n";
        cout << "Posicion en Memoria: " << (Diagonal + i) << "\n";
    }
    return;
}

void funcSiete(int **A, int *DP, int *DS, int limite)
{
    //Intercambiar los elementos de la diagonal principal y secundaria. Imprimir la matriz
    // antes y después de intercambiar.
    cout << "Matriz antes de intercambiar las diagonales.\n";
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if (j != limite)
            {
                cout << *(*(A + i) + j) << " | ";
            }
            else
            {
                cout << *(*(A + i) + j) << " ";
            }
        }
        cout << "\n";
    }
    cout << "Matriz luego de intercambiar las diagonales.\n";
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            if (i != limite)
            {
                if (i == j)
                {
                    cout << *(DS + j) << " | ";
                }
                else if ((i + j) == (limite + 1))
                {
                    cout << *(DP + j) << " | ";
                }
                else
                {
                    cout << *(*(A + i) + j) << " | ";
                }
            }
            else
            {
                if (i == j)
                {
                    cout << *(DS + j) << "  ";
                }
                else if ((i + j) == (limite + 1))
                {
                    cout << *(DP + j) << "  ";
                }
                else
                {
                    cout << *(*(A + i) + j) << "  ";
                }
            }
        }
        cout << "\n";
    }
    return;
}

void funcOcho(int *MAY, int limite)
{
    //Ordenar el vector MAY en forma ascendente. Imprimir el vector antes y después de ordenar
    cout << "Vector con los Mayores Elementos de cada fila antes de ordenar.\n";
    for (int i = 1; i <= limite; i++)
    {
        cout << "Mayor de la Fila " << i << ": " << *(MAY + i) << "\n";
    }
    int mayArreglado[limite], aux;
    for (int i = 1; i <= limite; i++)
    {
        mayArreglado[i] = *(MAY + i);
    }
    for (int i = 1; i <= (limite - 1); i++)
    {
        for (int j = 1; j <= (limite - 1); j++)
        {
            if (mayArreglado[j] > mayArreglado[j + 1])
            {
                aux = mayArreglado[j];
                mayArreglado[j] = mayArreglado[j + 1];
                mayArreglado[j + 1] = aux;
            }
        }
    }
    cout << "Vector con los Mayores Elementos de cada fila ordenado.\n";
    for (int i = 1; i <= limite; i++)
    {
        if (i == limite)
        {
            cout << mayArreglado[i] << "\n";
        }
        else
        {
            cout << mayArreglado[i] << " | ";
        }
    }
    return;
}

void funcNueve(int *MEN, int limite)
{
    //Ordenar el vector MEN en forma descendente. Imprimir el vector antes y después de ordenar.
    cout << "Vector con los Menores Elementos de cada fila antes de ordenar.\n";
    for (int i = 1; i <= limite; i++)
    {
        cout << "Menor de la Fila " << i << ": " << *(MEN + i) << "\n";
    }
    int menArreglado[limite], aux;
    for (int i = 1; i <= limite; i++)
    {
        menArreglado[i] = *(MEN + i);
    }
    for (int i = 1; i <= (limite - 1); i++)
    {
        for (int j = 1; j <= (limite - 1); j++)
        {
            if (menArreglado[j] < menArreglado[j + 1])
            {
                aux = menArreglado[j];
                menArreglado[j] = menArreglado[j + 1];
                menArreglado[j + 1] = aux;
            }
        }
    }
    cout << "Vector con los Menores Elementos de cada fila ordenado.\n";
    for (int i = 1; i <= limite; i++)
    {
        if (i == limite)
        {
            cout << menArreglado[i] << "\n";
        }
        else
        {
            cout << menArreglado[i] << " | ";
        }
    }
    return;
}

void funcDiez(int *DP, int limite)
{
    //Mover cíclicamente a la derecha los elementos del vector DP
    int aux = *(DP + limite), MOV[limite], aux2, j = 1;
    cout << "Vector antes de ser Desplazado.\n";
    for (int i = 1; i <= limite; i++)
    {
        if (i == limite)
        {
            cout << *(DP + i) << "\n";
        }
        else
        {
            cout << *(DP + i) << " | ";
        }
    }
    for (int i = 1; i <= limite; i++)
    {
        if (i == 1)
        {
            MOV[i] = aux;
            aux = *(DP + j);
        }
        else
        {
            MOV[i] = aux;
            j++;
            aux = *(DP + j);
        }
    }
    cout << "Vector Desplazado.\n";
    for (int i = 1; i <= limite; i++)
    {
        if (i == limite)
        {
            cout << MOV[i] << "\n";
        }
        else
        {
            cout << MOV[i] << " | ";
        }
    }
    return;
}

void funcOnce(int *DS, int limite)
{
    // Invertir los elementos del vector del DS
    int INV[limite];
    cout << "Vector de la Diagonal Secundaria en Orden Original.\n";
    for (int i = 1; i <= limite; i++)
    {
        if (i == limite)
        {
            cout << *(DS + i) << "\n";
        }
        else
        {
            cout << *(DS + i) << " | ";
        }
    }
    int i = 1;
    for (int j = limite; j >= 1; j--)
    {
        INV[i] = *(DS + j);
        i++;
    }
    cout << "Vector de la Diagonal Secundaria en Orden Inverso:\n";
    for (int i = 1; i <= limite; i++)
    {
        if (i == limite)
        {
            cout << INV[i] << "\n";
        }
        else
        {
            cout << INV[i] << " | ";
        }
    }
    return;
}

void funcDoce(int *MAY, int limite)
{
    int ref, repetidos = 0, x = 0;
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            ref = *(MAY + i);
            if (*(MAY + j) == ref)
            {
                x++;
            }
        }
        if (x > 1)
        {
            repetidos++;
            x = 0;
        }
        else
        {
            x = 0;
        }
    }
    cout << "La cantidad de veces que se repite un numero en el vector de mayores de cada fila es: " << repetidos << "\n";
    return;
}

bool esPrimo(int n)
{
    bool esPrimo = false;
    int divisibles = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((n % i) == 0)
        {
            divisibles++;
        }
    }
    if (divisibles == 2)
    {
        esPrimo = true;
    }
    else
    {
        esPrimo = false;
    }
    return esPrimo;
}

void funcTrece(int **A, int limite)
{
    //Decir si en la matriz fue ingresado algún numero primo, y si los hubiere, mostrar la posición en memoria que este ocupa
    int ref = 0, cantPrimos = 0;
    for (int i = 1; i <= limite; i++)
    {
        for (int j = 1; j <= limite; j++)
        {
            ref = (*(*(A + i) + j));
            if ((esPrimo(ref)) == true)
            {
                cout << "Se encontro un numero primo. Posicion " << i << ", " << j << "\n";
                cout << "Posicion en Memoria: " << (*(A + i) + j) << "\n";
                cantPrimos++;
            }
        }
    }
    cout << "Se encontraron " << cantPrimos << " numeros primos.\n";
    return;
}

void selectorOpcion(int &opcion)
{
    do
    {
        cout << "Seleccione el numero correspondiente a la accion que desea ejecutar.\n";
        cout << "1.  Imprimir la Matriz junto con la direccion de memoria del primer y el ultimo elemento.\n";
        cout << "2.  Imprimir el Vector con los Menores elementos de cada fila junto con la direccion en memoria de cada elemento.\n";
        cout << "3.  Imprimir el Vector con los Mayores elementos de cada filas junto con la direccion en memoria de cada elemento.\n";
        cout << "4.  Imprimir el Vector que contiene el Promedio de los valores ingresados en cada columna junto con la direccion de memoria de cada elemento.\n";
        cout << "5.  Imprimir el Vector que contiene los elementos de la Diagonal Principal junto con la direccion en Memoria de Cada Elemento.\n";
        cout << "6.  Imprimir el Vector que contiene los elementos de la Diagonal Secundaria junto con la direccion en Memoria de Cada Elemento.\n";
        cout << "7.  Intercambiar los elementos de la Diagonal Principal y Secundaria.\n";
        cout << "8.  Ordenar el Vector que contiene los Mayores elementos de cada fila en forma ascendente.\n";
        cout << "9.  Ordenar el Vector que contiene los Menores elementos de cada fila en forma descendente.\n";
        cout << "10. Mover ciclicamente a la derecha los elementos del Vector que contiene los elementos de la Diagonal Principal.\n";
        cout << "11. Invertir los elementos del Vector que contiene los elementos de la Diagonal Secundaria.\n";
        cout << "12. Encontrar la cantidad de numeros que se repiten en el Vector de los Elementos Mayores.\n";
        cout << "13. Buscar numeros primos que se encuentran en Matriz e imprimir su direccion de memoria.\n";
        cout << "14. Salir o Regresar al menu principal\n";
        cin >> opcion;
    } while (opcion < 0 || opcion > 14);
    return;
}

void menu(int &opcion, int **A, int limite, int *MEN, int *MAY, int *P, int *DP, int *DS)
{
    do
    {
        selectorOpcion(opcion);
        switch (opcion)
        {
        case 1:
            funcUno(A, limite);
            break;
        case 2:
            cargaMenor(A, limite, MEN);
            funcDos(MEN, limite);
            break;
        case 3:
            cargaMayor(A, limite, MAY);
            funcTres(MAY, limite);
            break;
        case 4:
            promedioColumnas(A, limite, P);
            funcCuatro(P, limite);
            break;
        case 5:
            cargaDP(A, limite, DP);
            funcCincoSeis(DP, limite);
            break;
        case 6:
            cargaDS(A, limite, DS);
            funcCincoSeis(DS, limite);
            break;
        case 7:
            cargaDP(A, limite, DP);
            cargaDS(A, limite, DS);
            funcSiete(A, DP, DS, limite);
            break;
        case 8:
            cargaMayor(A, limite, MAY);
            funcOcho(MAY, limite);
            break;
        case 9:
            cargaMenor(A, limite, MEN);
            funcNueve(MEN, limite);
            break;
        case 10:
            cargaDP(A, limite, DP);
            funcDiez(DP, limite);
            break;
        case 11:
            cargaDS(A, limite, DS);
            funcOnce(DS, limite);
            break;
        case 12:
            cargaMayor(A, limite, MAY);
            funcDoce(MAY, limite);
            break;
        case 13:
            funcTrece(A, limite);
            break;
        case 14:
            cout << "Gracias por haber utilizado el programa.\n";
            break;
        }
        if (opcion != 14)
        {
            cout << "Presione una tecla para continuar.\n";
            getch();
        }
    } while (opcion != 14);
    return;
}

/*
Crear una matriz cuadrada “A” con un mínimo de 16 elementos. Cargar la matriz con
cualquier numero entero por el usuario, luego, crear los vectores: Realizar los siguientes
cálculos:
 MEN: donde se guardarán los menores elementos de cada fila
 MAY: donde se guardarán los mayores elementos de cada fila
 P: donde se guardará el promedio de elementos de cada columna
 DP: donde se almacenará los elementos de la diagonal principal de la matriz
 DS: donde se almacenará los elementos de la diagonal secundaria de la matriz.
Mostrar un menú de selección con las opciones necesarias para ver los siguientes
resultados:
1) Mostrar la matriz junto con la dirección de memoria del primer y último elemento
2) Mostrar el vector MEN, mostrando la posición de memoria de cada elemento
3) Mostrar el vector MAY, mostrando la posición de memoria de cada elemento
4) Mostrar el vector P, mostrando la posición de memoria de cada elemento
5) Mostrar el vector DP, mostrando la posición de memoria de cada elemento
6) Mostrar el vector DS, mostrando la posición de memoria de cada elemento
7) Intercambiar los elementos de la diagonal principal y secundaria. Imprimir la matriz
antes y después de intercambiar.
8) Ordenar el vector MAY en forma ascendente. Imprimir el vector antes y después de
ordenar 
9) Ordenar el vector MEN en forma descendente. Imprimir el vector antes y después de
ordenar.
10) Mover cíclicamente a la derecha los elementos del vector DP
11) Invertir los elementos del vector del DS
12) Decir cuántos números se encentran repetidos en el vector MAY
13) Decir si en la matriz fue ingresado algún numero primo, y si los hubiere, mostrar la
posición en memoria que este ocupa
14) Salir o Regresar al menú principal. 
*/
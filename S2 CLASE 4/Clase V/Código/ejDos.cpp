#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void ingNumero(int &);
void cargarArray(int *, int);
void seleccion(int &);
void moverDerecha(int *, int);
void moverIzquierda(int *, int);
void invertirArray(int *, int);
void ordenAscendente(int *, int);
void ordenDescendente(int *, int);
void mitadMitad(int *, int);
void imprimirArray(int *, int);

main()
{
    system("cls");
    int n, *array, opcion;
    cout << "Programa que realiza funciones determinadas con Arrays utilizando punteros.\n";
    ingNumero(n);
    array = new int[n];
    cargarArray(array, n);
    do
    {
        seleccion(opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Mover el array a la derecha.\n";
            moverDerecha(array, n);
            break;
        case 2:
            system("cls");
            cout << "Mover el array a la izquierda.\n";
            moverIzquierda(array, n);
            break;
        case 3:
            system("cls");
            cout << "Invertir el array.\n";
            invertirArray(array, n);
            break;
        case 4:
            system("cls");
            cout << "Ordenar el array de manera ascendente.\n";
            ordenAscendente(array, n);
            break;
        case 5:
            system("cls");
            cout << "Ordenar el array de manera descendente.\n";
            ordenDescendente(array, n);
            break;
        case 6:
            system("cls");
            cout << "Ordenar el array en mitades.\n";
            mitadMitad(array, n);
            break;
        case 7:
            system("cls");
            cout << "Imprimir el array cargado.\n";
            imprimirArray(array, n);
            break;
        case 8:
            system("cls");
            cout << "Gracias por utilizar el programa :)\n";
            break;
        default:
            system("cls");
            cout << "La opcion con la que se llego es invalida.\n";
            break;
        }
    } while (opcion != 8);
    system("pause");
    delete[] array;
    return 0;
}

void ingNumero(int &n)
{
    cout << "\nIngrese el limite (Debe ser un numero par positivo y menor a 100): ";
    cin >> n;
    while (n < 0 || n > 100 || (n % 2) != 0)
    {
        system("cls");
        cout << "ERROR. Debe ser un numero par positivo y menor a 100. Vuelva a ingresar limite: ";
        cin >> n;
    }
}

void cargarArray(int *array, int n)
{
    int aux, sw = 0;
    bool verificado = false;
    do
    {
        for (int i = 1; i <= n; i++)
        {
            verificado = false;
            cout << "Cargue valor para posicion: " << i << " : ";
            cin >> aux;
            while (!verificado)
            {
                for (int m = 1; m <= i; m++)
                {
                    if (aux == array[m])
                    {
                        sw = 1;
                        break;
                    }
                    else
                    {
                        sw = 0;
                    }
                }
                if (sw == 1)
                {
                    cout << "No pueden haber datos repetidos. Vuelva a ingresar dato de elemento " << i << ": ";
                    cin >> aux;
                    verificado = false;
                }
                else
                {
                    array[i] = aux;
                    verificado = true;
                }
            }
        }
    } while (!verificado);
}

void seleccion(int &opcion)
{
    cout << "Seleccione una opcion.\n";
    cout << "1. Mover ciclicamente los elementos del array a la derecha\n";
    cout << "2. Mover ciclicamente los elementos del array a la izquierda\n";
    cout << "3. Invertir los elementos del array\n";
    cout << "4. Ordenar los elementos del array en forma ascendente\n";
    cout << "5. Ordenar los elementos del array en forma descendente\n";
    cout << "6. Ordenar la primera mitad del array en forma ascendente y la segunda mitad en forma descendente\n";
    cout << "7. Imprimir el array cargado.\n";
    cout << "8. Salir del Programa.\n";
    cout << "Opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 7)
    {
        cout << "Seleccione una opcion.\n";
        cout << "1. Mover ciclicamente los elementos del array a la derecha\n";
        cout << "2. Mover ciclicamente los elementos del array a la izquierda\n";
        cout << "3. Invertir los elementos del array\n";
        cout << "4. Ordenar los elementos del array en forma ascendente\n";
        cout << "5. Ordenar los elementos del array en forma descendente\n";
        cout << "6. Ordenar la primera mitad del array en forma ascendente y la segunda mitad en forma descendente\n";
        cout << "7. Imprimir el array cargado.\n";
        cout << "8. Salir del Programa.\n";
        cout << "Opcion: ";
        cin >> opcion;
    }
}

void moverDerecha(int *array, int n)
{
    int aux = array[n];
    cout << "Array antes de moverlo: \n";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    cout << "Array desplazado a la derecha.\n";
    array[n] = array[1];
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
        {
            cout << aux << " | ";
        }
        if (i == (n - 1))
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    system("pause");
    return;
}

void moverIzquierda(int *array, int n)
{
    int aux = array[1];
    cout << "Array antes de moverlo: \n";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    array[n] = array[1];
    cout << "Array desplazado a la izquierda.\n";
    for (int i = n; i >= 1; i--)
    {
        if (i == 1)
        {
            cout << aux << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    system("pause");
    return;
}

void invertirArray(int *array, int n)
{
    int aux = array[1];
    cout << "Array antes de moverlo: \n";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    array[n] = array[1];
    cout << "Array invertido.\n";
    for (int i = n; i >= 1; i--)
    {
        if (i == 1)
        {
            cout << aux << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    system("pause");
    return;
    system("pause");
    return;
}

void ordenAscendente(int *array, int n)
{
    int aux;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((array[j]) > (array[j + 1]))
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    system("pause");
    return;
}

void ordenDescendente(int *array, int n)
{
    int aux;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((array[j]) < (array[j + 1]))
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    system("pause");
    return;
}

void mitadMitad(int *array, int n)
{
    int mitad = (n / 2), M1[mitad], M2[mitad], aux;
    for (int i = 1; i <= mitad; i++)
    {
        M1[i] = array[i];
    }
    for (int i = (mitad + 1); i <= n; i++)
    {
        M2[i] = array[i];
    }
    //Ordenamiento de M1
    for (int i = 1; i <= mitad; i++)
    {
        for (int j = 1; j < mitad; j++)
        {
            if ((M1[j]) < (M1[j + 1]))
            {
                aux = M1[j];
                M1[j] = M1[j + 1];
                M1[j + 1] = aux;
            }
        }
    }
    //Impresion de M1
    for (int i = 1; i <= mitad; i++)
    {
        if (i == mitad)
        {
            cout << M1[i] << "\n";
        }
        else
        {
            cout << M1[i] << " | ";
        }
    }
    //Ordenamiento de M2
    for (int i = (mitad + 1); i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((M2[j]) < (M2[j + 1]))
            {
                aux = M2[j];
                M2[j] = M2[j + 1];
                M2[j + 1] = aux;
            }
        }
    }
    //Impresion de M2
    for (int i = (mitad + 1); i <= n; i++)
    {
        if (i == n)
        {
            cout << M2[i] << "\n";
        }
        else
        {
            cout << M2[i] << " | ";
        }
    }
    system("pause");
    return;
}

void imprimirArray(int *array, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << array[i] << "\n";
        }
        else
        {
            cout << array[i] << " | ";
        }
    }
    system("pause");
    return;
}

/*

Crear un Array Dinámico numérico unidimensional “A” para ingresar en el datos no
repetidos (utiliza una función para la validación del mismo). Asegurarse de ingresar como
límite un numero par positivo menor que 100, luego, crear las siguientes rutinas según la
siguiente tabla:
moverDerecha( ) Se encargará de mover cíclicamente los elementos del array a la
derecha
moverIzquierda( ) Se encargará de mover cíclicamente los elementos del array a la
izquierda
InvertirArray( ) Se encargará de invertir los elementos del array
ordenAscendente( ) Se encargará de ordenar los elementos del array en forma
ascendente
ordenDescendente( ) Se encargará de ordenar los elementos del array en forma
descendente
MitadMitad( ) Esta rutina se encargará de ordenar la primera mitad del array
enforma ascendente y la segunda mitad en forma descendente 

*/
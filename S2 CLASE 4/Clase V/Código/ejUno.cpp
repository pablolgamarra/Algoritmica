#include <iostream>
#include <windows.h>

using namespace std;

void cantElementos(int &);

void seleccionOpcion(int &);

void cargaArray(int *, int);

void imprimeArray(int *, int);

void mayorElemento(int *, int);

void menorElemento(int *, int);

void valorPromedio(int *, int);

void cantidadPar_Impar(int *, int);

main()
{
    int elementos, *array, opcion;
    system("cls");
    cout << "Programa que permite cargar e imprimir un Array utilizando Punteros y Funciones.\n";
    cantElementos(elementos);
    array = new int[elementos];
    cargaArray(array, elementos);
    do
    {
        seleccionOpcion(opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            mayorElemento(array, elementos);
            break;
        case 2:
            menorElemento(array, elementos);
            break;
        case 3:
            valorPromedio(array, elementos);
            break;
        case 4:
            cantidadPar_Impar(array, elementos);
            break;
        case 5:
            imprimeArray(array, elementos);
            break;
        case 6:
            cout << "Gracias por utilizar el programa :).\n";
            break;
        default:
            cout << "No se ha encontrado una accion para la opcion seleccionada.\n";
            break;
        }
    } while (opcion != 6);
    system("pause");
    return 0;
}

void cantElementos(int &elementos)
{
    cout << "Ingrese la cantidad de elementos que tendra el array (Debe ser entre 10 y 50): ";
    cin >> elementos;
    while (elementos < 10 || elementos > 50)
    {
        system("cls");
        cout << "ERROR!. Debe ser entre 10 y 50: ";
        cin >> elementos;
    }
    return;
}

void cargaArray(int *array, int elementos)
{
    cout << "Carga de Datos.\n";
    for (int i = 1; i <= elementos; i++)
    {
        cout << "Ingrese valor para posicion ( " << i << " ) :";
        cin >> *array++;
    };
    return;
}

void imprimeArray(int *array, int elementos)
{
    system("cls");
    cout << "El Array cargado es: \n";
    for (int i = 1; i <= elementos; i++)
    {
        if (i == elementos)
        {
            cout << *array++ << "\n";
        }
        else
        {
            cout << *array++ << " | ";
        }
    }
    system("pause");
    return;
}

void seleccionOpcion(int &opcion)
{
    system("cls");
    cout << "Seleccione una opcion.\n";
    cout << "1. Hallar el mayor elemento ingresado en el array\n";
    cout << "2. Hallar el menor elemento ingresado en el array\n";
    cout << "3. Hallar promedio de valores ingresados en el array\n";
    cout << "4. Hallar la cantidad de pares e impares ingresados en el array\n";
    cout << "5. Imprimir el array creado\n";
    cout << "6. Salir del Programa\n";
    cout << "Opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 6)
    {
        system("cls");
        cout << "Seleccione una opcion.\n";
        cout << "1. Hallar el mayor elemento ingresado en el array\n";
        cout << "2. Hallar el menor elemento ingresado en el array\n";
        cout << "3. Hallar promedio de valores ingresados en el array\n";
        cout << "4. Hallar la cantidad de pares e impares ingresados en el array\n";
        cout << "5. Imprimir el array creado\n";
        cout << "6. Salir del Programa\n";
        cout << "Opcion: ";
        cin >> opcion;
    }
}

void mayorElemento(int *array, int elementos)
{
    int mayor = 0;
    for (int i = 1; i <= elementos; i++)
    {
        if (i == 1)
        {
            mayor = *array;
        }
        else if (*array > mayor)
        {
            mayor = *array;
        }
        array++;
    }
    cout << "El mayor numero ingresado al array es: " << mayor << "\n";
    system("pause");
    return;
}

void menorElemento(int *array, int elementos)
{
    int menor = 0;
    for (int i = 1; i <= elementos; i++)
    {
        if (i == 1)
        {
            menor = *array;
        }
        else if (*array < menor)
        {
            menor = *array;
        }
        array++;
    }
    cout << "El menor numero ingresado al array es: " << menor << "\n";
    system("pause");
    return;
}

void valorPromedio(int *array, int elementos)
{
    float promedio = 0;
    for (int i = 1; i <= elementos; i++)
    {
        promedio = promedio + *array;
        array++;
    }
    cout << "El valor promedio es: " << (promedio / elementos) << "\n";
    system("pause");
    return;
}

void cantidadPar_Impar(int *array, int elementos)
{
    int cantPar = 0, cantImpar = 0;
    for (int i = 1; i <= elementos; i++)
    {
        if (((*array) % 2) == 0)
        {
            cantPar++;
        }
        else
        {
            cantImpar++;
        }
        array++;
    }
    cout << "La cantidad de pares ingresados es: " << cantPar << "\n";
    cout << "La cantidad de impares ingresados es: " << cantImpar << "\n";
    system("pause");
    return;
}

/*

Crear un Array dinámico N (unidimensional) utilizando una función para obtener la
cantidad de elementos en el array, teniendo en cuenta que el número de elementos debe
estar entre 10 y 50. 

Utilizar las siguientes rutinas para encontrar los siguientes valores.
mayorElemento( ) Se encargará de hallar el mayor elemento ingresado en el array
menorElemento() Se encargará de hallar el menor elemento ingresado en el array
valorPromedio() Encontrará el promedio de valores ingresados en el array
CantidadPar_Impar( ) Encontrará la cantidad de pares e impres ingresados en el array
imprimeArray( ) Se encargará de imprimir el array creado 

*/
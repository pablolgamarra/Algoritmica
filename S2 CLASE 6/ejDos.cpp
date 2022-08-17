#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void limits(int &, int &);

void randomNumber(int &, int, int);

void pairNotPair(int);

void closeNoClose(bool &);

main()
{
    srand(time(NULL));
    int limI, limS, num;
    bool closer = false;
    system("cls");
    cout << "Programa que genera numeros aleatorios entre dos limites.\n";
    do
    {
        //Ingresar Limite Superior e Inferior
        limits(limI, limS);
        //Generador de numeros aleatoriosç
        randomNumber(num, limI, limS);
        //Comprobar si se quiere seguir ejecutando el programa
        closeNoClose(closer);
    } while (!closer);
    system("cls");
    cout << "Gracias por utilizar el programa.\n";
    system("pause");
    return 0;
}

void limits(int &limI, int &limS)
{
    cout << "Ingrese limite Inferior: ";
    cin >> limI;
    cout << "Ingrese limite Superior: ";
    cin >> limS;
    while (limI == limS)
    {
        system("cls");
        cout << "Los limites no pueden ser iguales!.\nVuelva a ingresar.\n";
        cout << "Ingrese limite Inferior: ";
        cin >> limI;
        cout << "Ingrese limite Superior: ";
        cin >> limS;
    }
    while (limS < limI)
    {
        system("cls");
        cout << "El Limite Superior no puede ser menor al Limite Inferior!\nVuelva a ingresar.\n";
        cout << "Ingrese limite Inferior: ";
        cin >> limI;
        cout << "Ingrese limite Superior: ";
        cin >> limS;
    }
    return;
}

void pairNotPair(int num)
{
    if ((num % 2) == 0)
    {
        cout << "El numero generado es par.\n";
    }
    else
    {
        cout << "El numero generado es impar.\n";
    }
    return;
}

void randomNumber(int &num, int limI, int limS)
{
    num = rand() % (limS - limI) + limI;
    system("cls");
    cout << "Numero Generado: " << num << "\tPosicion en memoria: " << &num << "\n";
    //Analizar si el numro generado es Par o Impar.
    pairNotPair(num);
    system("pause");
    return;
}

void closeNoClose(bool &closer)
{
    char option;
    cout << "Desea que el programa siga generando numeros aleatorios? (S) o (N): ";
    cin >> option;
    while ((option != 'S') && (option != 'N'))
    {
        cout << "Opcion no valida.\nVuelva a ingresar.\n";
        cout << "Desea que el programa siga generando numeros aleatorios? (S) o (N): ";
        cin >> option;
    }
    switch (option)
    {
    case 'S':
        closer = false;
        break;
    case 'N':
        closer = true;
        break;
    default:
        cout << "La opcion seleccionada no es valida.\n";
        break;
    }
    return;
}

/*
Generar “n” cantidad de números aleatorios establecidos entre Li: límite superior, Ls: límite superior. A cada
número aleatorio generado, mostrar su posición en memoria y además indica si los mismos son pares o
impares utilizando punteros. 
*/
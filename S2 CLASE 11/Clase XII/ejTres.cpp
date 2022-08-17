#include <iostream>
#include <windows.h>

//Espacios de Nombre
using namespace std;

//Prototipos de las funciones
void cargaCadena(string &);
void cadenaMinuscula(string &);
void cadenaMayuscula(string &);

//Funcion Principal
main()
{
    system("cls");
    string cadena;
    cout << "Programa que para convertir una cadena a mayusculas o a minusculas.\n";
    cargaCadena(cadena);
    //Impresion de la cadena original
    cout << "Cadena Original: " << cadena << "\n";
    //Se convierte la cadena a minusculas y se imprime
    cadenaMinuscula(cadena);
    cout << "Cadena Minuscula: " << cadena << "\n";
    //Se convierte la cadena a mayusculas y se imprime
    cadenaMayuscula(cadena);
    cout << "Cadena Mayuscula: " << cadena << "\n";
    system("pause");
    return 0;
}

//Funciones
void cargaCadena(string &cadena)
{
    cout << "Ingrese el texto que desea pasar a Mayusculas y minusculas: ";
    cin >> cadena;
    return;
}

void cadenaMinuscula(string &cadena)
{
    for (int i = 0; i < cadena.length(); i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
    return;
}

void cadenaMayuscula(string &cadena)
{
    for (int i = 0; i < cadena.length(); i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
    return;
}

/*
Ingresar una cadena, Imprimir la cadena original, además, la cadena en mayúsculas y
en minúsculas. 
*/
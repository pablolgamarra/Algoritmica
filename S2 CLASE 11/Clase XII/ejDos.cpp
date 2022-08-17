#include <iostream>

using namespace std;

struct strings
{
    string texto;
    int largor;
} cadena[2];

main()
{
    system("cls");
    int mayor, menor;
    bool iguales = false;
    //Presentacion del programa al usuario
    cout << "Programa para comparar dos cadenas.\n";
    //Carga de Datos a la Estructura
    for (int i = 0; i < 2; i++)
    {
        cout << "Ingrese cadena " << i + 1 << ": ";
        cin >> cadena[i].texto;
        cadena[i].largor = (cadena[i].texto).length();
        if (i != 0)
        {
            if (cadena[i].largor > cadena[i - 1].largor)
            {
                mayor = i;
                menor = i - 1;
            }
            else if (cadena[i].largor < cadena[(i - 1)].largor)
            {
                mayor = i - 1;
                menor = i;
            }
            else if (cadena[i].largor == cadena[i - 1].largor)
            {
                iguales = true;
            }
        }
    }
    //Impresion de las Cadenas
    system("cls");
    for (int i = 0; i < 2; i++)
    {
        cout << "Cadena " << i + 1 << ": " << cadena[i].texto << "\n\n";
    }
    //Impresion de cual es la mayor y la menor cadena.
    if (iguales)
    {
        cout << "La longitud de ambas cadenas es la misma\n";
    }
    else if (mayor == 0)
    {
        cout << "La cadena de mayor longitud es la cadena: 1\n";
        cout << "La cadena de menor longitud es la cadena: 2\n";
    }
    else if (mayor == 1)
    {
        cout << "La cadena de mayor longitud es la cadena: 2\n";
        cout << "La cadena de menor longitud es la cadena: 1\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar dos cadenas y comparar la longitud de los mismos, indicando cual es el de
mayor y menor longitud o si ambos son de longitudes iguales. 
*/
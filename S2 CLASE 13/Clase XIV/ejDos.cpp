#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

struct Premios
{
    int ganador;
    string premio;
    Premios *siguiente;
};

void cargaPremios(Premios *&pila, string premio)
{
    Premios *nuevoNumero = new Premios();
    nuevoNumero->ganador = ((rand() % 200 - 1) + 1);
    nuevoNumero->premio = premio;
    nuevoNumero->siguiente = pila;
    pila = nuevoNumero;
}

void descargarPila(Premios *&pila)
{
    Premios *aux = pila;
    cout << "El ganador de: " << pila->premio << " es el numero del boleta: " << pila->ganador << "\n";
    pila = aux->siguiente;
    delete aux;
}

main()
{
    int i = 1;
    string premio = "";
    Premios *pila = NULL;
    srand((unsigned)time(NULL));
    system("cls");
    cout << "Programa para hacer un sorteo entre 200 boletas.\n";
    while (i <= 4)
    {
        cout << "Ingrese premio " << i << ": ";
        getline(cin, premio);
        i++;
        cargaPremios(pila, premio);
    }
    cout << "Pulse una tecla para imprimir a los ganadores y sus respectivos premios.\n";
    getch();
    cout << "================================================\n";
    while (pila != NULL)
    {
        descargarPila(pila);
    }
    cout << "Presione una tecla para cerrar...\n";
    getch();
    return 0;
}

/*
Crear un programa que permita hacer un sorteo entre 200 boletas vendidas con los siguientes premios en el orden indicado:
- Primer Premio: un iphone X
- Segundo Premio: un PlayStation 4
- Tercer premio: Pendrive de 1TB
- Cuarto premio: Pulsera Mi Band3
Mostrar los premios del cuarto al primero utilizando pilas.
*/
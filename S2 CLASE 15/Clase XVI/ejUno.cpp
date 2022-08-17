#include <iostream>

using namespace std;

//Declaracion de Estructura
struct Nodo
{
    int dato;
    Nodo *siguiente;
};

//Prototipos de Funcion
void cargarCola(Nodo *&, Nodo *&, int);
void descargaCola(Nodo *&, Nodo *&, int &);
bool colaVacia(Nodo *);

//Funcion Principal
int main()
{
    int num;
    char seguir;
    Nodo *frente = NULL, *fin = NULL;
    cout << "Programa para agregar numeros a una cola" << endl;
    //Carga de los numeros que se desea agregar a la cola
    do
    {
        cout << "Ingrese un numero para agregar a la cola: ";
        cin >> num;
        while (!cin.good())
        {
            cout << "Ha ocurrido un error al cargar el numero. Asegurese de ingresar numeros enteros.\n";
            cout << "Ingrese un numero para agregar a la cola: ";
            cin >> num;
        }
        cargarCola(frente, fin, num);
        do
        {
            cout << "Desea seguir ingresando numeros?: [s/n]: ";
            cin >> seguir;
        } while (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');
    } while (seguir == 's' || seguir == 'S');
    cout << "Se imprimira la cola cargada.\n";
    //Impresion de la Cola
    while (frente != NULL)
    {
        descargaCola(frente, fin, num);
        if (frente != NULL)
        {
            cout << num << ", ";
        }
        else
        {
            cout << num << "\nFin de la Cola.\n";
        }
    }
    delete frente, fin;
    return 0;
}

//Funciones Utilizadas

bool colaVacia(Nodo *frente)
{
    if (frente == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void cargarCola(Nodo *&frente, Nodo *&fin, int n)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;
    if (colaVacia(frente))
    {
        frente = nuevoNodo;
    }
    else
    {
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;
    cout << "El numero: " << n << " se cargo correctamente.\n";
    return;
}

void descargaCola(Nodo *&frente, Nodo *&fin, int &n)
{
    n = frente->dato;
    Nodo *aux = frente;
    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->siguiente;
    }
    delete aux;
    return;
}

/*
Hacer un programa para agregar números enteros a una cola, hasta que el
usuario lo decida, después mostrar todos os números introducidos en la cola.
*/
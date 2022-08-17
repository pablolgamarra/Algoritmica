#include <iostream>

using namespace std;

//Declaracion de Estructura Utilizada
struct Nodo
{
    int dato;
    Nodo *siguiente;
};

//Prototipos de Funcion
void cargaCola(Nodo *&, Nodo *&, int);
void descargaCola(Nodo *&, Nodo *&, int &);
bool colaVacia(Nodo *);

//Funcion Principal
int main()
{
    int num = 0;
    //Creacion del "frente" y el "fin" de la cola
    Nodo *frente = NULL, *fin = NULL;
    cout << "Cargar 4 vectores, luego se creara un unico vector que contiene los datos de los 4.\n";
    //Creación y carga directa de los vectores.
    int A[5] = {1, 2, 3, 4, 5}, B[5] = {6, 7, 8, 9, 10}, C[5] = {12, 12, 13, 14, 15}, D[20] = {16, 17, 18, 19, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //Carga de los datos a la Cola Creada
    for (int j = 0; j < 5; j++)
    {
        cargaCola(frente, fin, A[j]);
    }
    for (int j = 0; j < 5; j++)
    {
        cargaCola(frente, fin, B[j]);
    }
    for (int j = 0; j < 5; j++)
    {
        cargaCola(frente, fin, C[j]);
    }
    //Descarga de los datos que se encuetran en la cola al vector D
    for (int j = 5; j < 20; j++)
    {
        descargaCola(frente, fin, num);
        D[j] = num;
    }
    //Impresion del Vector Deseado
    cout << "Se imprimira el vector que contiene a los elementos del resto.\n";
    for (int i = 0; i < 20; i++)
    {
        //Funcion Ternaria para imprimir los datos de manera mas ordenada
        (i != 19) ? cout << D[i] << " | " : cout << D[i] << "\n";

    }
    cout << "Gracias por usar el programa.\n";
}

void cargaCola(Nodo *&frente, Nodo *&fin, int num)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = num;
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
    cout << "Se cargo correctamente el dato: " << num << "\n";
    return;
}

void descargaCola(Nodo *&frente, Nodo *&fin, int &num)
{
    Nodo *aux = new Nodo();
    num = frente->dato;
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
}

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

/*
Crear y cargar 4 vectores A, B, C y D. Con ellos cargar una cola de datos el
cual, luego se descargara en el vector D que contendrán los valores de A, B
y C.
*/
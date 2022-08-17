#include <iostream>

using namespace std;

//Estructura Utilizada
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
    int calificacion, cantAlumnos = 20;
    Nodo *frente = NULL, *fin = NULL;
    cout << "Programa para cargar las calificaciones finales de Algoritmica.\n";
    //Carga de las calificaciones de los diferentes alumnos
    for (int i = 1; i <= cantAlumnos; i++)
    {
        cout << "Ingrese la calificacion de alumno " << i << ": ";
        cin >> calificacion;
        cargarCola(frente, fin, calificacion);
    }
    //Impresion de los Alumnos Reprobados 
    for (int i = 1; i <= cantAlumnos; i++)
    {
        descargaCola(frente, fin, calificacion);
        if (calificacion < 2)
        {
            cout << "El alumno " << i << " esta reprobado, con una calificacion de: " << calificacion << "\n";
        }
    }
    frente = NULL;
    fin = NULL;
    delete frente, fin;
    return 0;
}

//Funciones Utilizadas
void cargarCola(Nodo *&frente, Nodo *&fin, int num)
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
    cout << "La calificacion " << num << " se cargo correctamente.\n";
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
    return;
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

/*Cargar una lista de 20 alumnos con sus calificaciones finales en una materia
cualquiera. Imprimir la lista de reprobados en el orden que se ha cargado.
Utiliza una cola para representar los datos.*/
#include <iostream>

using namespace std;


//Declaracion de Estructura
struct Nodo
{
    int dato;
    string nombre;
    Nodo *siguiente;
};

//Prototipos de Funcion
void cargaCola(Nodo *&, Nodo *&, int, string);
void descargaCola(Nodo *&, Nodo *&, int &, string &);
bool colaVacia(Nodo *&);


//Funcion Principal
int main()
{
    int numero = 0;
    string nombre = "";
    char seguir = {'s'};
    Nodo *frente = NULL, *fin = NULL;
    cout << "Programa para cargar la lista de espera de un consultorio medico.\n";
    //Obtencion de los datos de los pacientes
    do
    {
        cin.ignore();
        cin.clear();
        cout << "Ingrese nombre del paciente: ";
        getline(cin, nombre);
        cout << "Ingrese numero que corresponde al paciente: ";
        cin >> numero;
        cargaCola(frente, fin, numero, nombre);
        //Comprobar y validar si se dese seguir cargando datos o no
        do
        {
            cout << "Desea seguir cargando datos? [s/n]: ";
            cin >> seguir;
            cin.ignore();
            cin.clear();
        } while (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');
    } while (seguir == 's' || seguir == 'S');
    //Impresion de la Cola Creada
    cout << "Lista de Espera: \n";
    while (frente != NULL)
    {
        descargaCola(frente, fin, numero, nombre);
        cout << "Numero Paciente: " << numero << "\n";
        cout << "Nombre: " << nombre << "\n";
    }
    delete frente, fin;
    return 0;
}

//Funciones Utilizadas
void cargaCola(Nodo *&frente, Nodo *&fin, int num, string nombre)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = num;
    nuevoNodo->nombre = nombre;
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
    return;
}

void descargaCola(Nodo *&frente, Nodo *&fin, int &num, string &nombre)
{
    Nodo *aux = new Nodo();
    num = frente->dato;
    nombre = frente->nombre;
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
bool colaVacia(Nodo *&frente)
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
Crear una lista de recepción para un consultorio medico registrando el
nombre de los pacientes. Imprimir la lista de los pacientes y el nro que le
corresponde en la consulta
*/
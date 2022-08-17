#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

struct Nodo{
    int numero;
    Nodo *siguiente;
};

struct Sorteo{
    int numero;
    string premio;
    Sorteo *siguiente;
};


void selecOpcion(int &);
void crearNodos(Nodo *, int );
void eliminarNodos(Nodo *&, int &);
void cargarElementosPila(Nodo *&);
void cargaNumero(int &);
void cargaPremios(Sorteo *&, string);
void descargaPremios(Sorteo *&);
void cargaString(string &);
void sorteo(Sorteo *&);
void cargaArray(int *, int);
void invertirArray(int *, int, Nodo *&);
void invertirVector(Nodo *&);
void cargaFilasImp(int **, int, int);
void cargaFilasPar(int **, int, int, Nodo *&);
void cargaMatriz(int **, Nodo *&);
void imprimeMatriz(int **);
void Matriz(Nodo *&);

int main(){ 
    Nodo *pila=NULL;
    Sorteo *cola=NULL;
    int opcion=0;
    selecOpcion(opcion);
    switch (opcion)
    {
        case 1:
            cargarElementosPila(pila);
        break;
        case 2:
            sorteo(cola);
        break;
        case 3:
            invertirVector(pila);
        break;
        case 4:
            Matriz(pila);
        break;
        // case 5:
        
        // break;
        default:
        cout<<"La opcion seleccionada no es valida o ha ocurrido un error.\n";
        break;
    }
    delete pila;
    delete cola;
}

void crearNodos(Nodo *pila, int num){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->numero=num;
    nuevoNodo->siguiente=pila;
    pila=nuevoNodo;
    return;
}

void eliminarNodos(Nodo *&pila, int &num){
    Nodo *aux=pila;
    num=pila->numero;
    pila=aux->siguiente;
    delete aux;
    return;
}

void selecOpcion(int &opcion){
    system("cls");
    do{
        cout<<"Seleccione una opcion: \n"
        <<"1. Almacenar numeros en forma de pila.\n"
        <<"2. Realizar un sorteo entre n boletas.\n"
        <<"3. Crear un Vector e Invertirlo usando pilas.\n"
        <<"4. Cargar una matriz n * n y cargarla de forma intercalada.\n"
        <<"5. Salir del Programa.\n"
        <<"Opcion: ";
        cin>>opcion;
    }while(opcion < 1 || opcion > 5);
    return;
}

void cargaNumero(int &num){
    do{
        cout<<"Ingrese un numero: ";
        cin>>num;
        while(!cin.good()){
            fflush(stdin);
            cin.clear();
            cin.ignore();
            cout<<"Ha ocurrido un error de carga.\n"
            <<"Vuelva a ingresar numero: ";
            cin>>num;
        }
    }while(!cin.good());
}

void seguir(char &cargar){
    do{
        cout<<"Desea seguir cargando numeros? [s/n]: ";
        cin>>cargar;
        if(cargar == 'S'){
            cargar='s';
        }else if(cargar == 'N'){
            cargar='n';
        }
    }while(cargar != 's' && cargar != 'n');
}

void cargarElementosPila(Nodo *&pila){
    int num=0;
    char op;
    cout<<"Opcion seleccionada: Almacenar numeros en forma de pila.\n";
    do{
        cargaNumero(num);
        crearNodos(pila, num);
        system("cls");
        seguir(op);  
    }while(op == 'S' || op == 's');
    cout<<"Numeros cargados.\n";
    while(pila != NULL){
        if(pila != NULL){
            eliminarNodos(pila,num);
            cout<<num<<", ";
        }else{
            eliminarNodos(pila,num);
            cout<<num<<"\n";
        }
    }
    return;
}

void cargaPremios(Sorteo *&cola, string premio, int n)
{
    Sorteo *nuevoNumero = new Sorteo();
    nuevoNumero->numero = ((rand() % n) + 1);
    nuevoNumero->premio = premio;
    nuevoNumero->siguiente = cola;
    cola = nuevoNumero;
}

void descargaPremios(Sorteo *&cola)
{
    Sorteo *aux = cola;
    cout << "El ganador de: " << cola->premio << " es el numero del boleta: " << cola->numero << "\n";
    cola= aux->siguiente;
    delete aux;
}

void cargaString(string &cadena){
    do{
        cin.ignore();
        cin.clear();
        cout<<"Premio: ";
        getline(cin, cadena);
        while(!cin.good()){
            cin.ignore();
            cin.clear();
            fflush(stdin);
            cout<<"Ha ocurrido un error en la carga. Vuelva a ingresar: ";
            getline(cin, cadena);
        }   
    }while(!cin.good());
}

void sorteo(Sorteo *&cola){
    srand((unsigned)time(NULL));
    int num=0, i=1;
    string premio;
    cout<<"Opcion Elegida: Realizar un sorteo.\n";
    cout<<"Ingrese la cantidad de boletas entre las que desea sortear.\n";
    do{
        cargaNumero(num);
    }while(num<1);
    while (i <= 4) 
    {
        cargaString(premio);
        cargaPremios(cola, premio, num);
        i++;
    }    

    while(cola != NULL){
        descargaPremios(cola);
    }
    return;
}

void cargaArray(int *Array, int limite)
{
    for (int i = 0; i < limite; i++)
    {
        cout << "Ingrese valor para posicion " << i + 1 << ": ";
        cin >> (*(Array + i));
    }
    return;
}

void invertirArray(int *Array, int contador, Nodo *&pila)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->numero = (*(Array + contador));
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    return;
}

void imprimeArray(int *Array, int limite)
{
    for (int i = 0; i < limite; i++)
    {
        if (i != (limite - 1))
        {
            cout << *(Array + i) << " | ";
        }
        else
        {
            cout << *(Array + i) << "\n";
        }
    }
}

void invertirVector(Nodo *&pila){
    int limite=0;
    cout<<"Opcion Elegida: Cargar un Vector e invertirlo mediante pilas.\n";
    do{
        cout<<"Ingrese el tamaño que tendra el vector (Debe ser superior a 1).\n";
        cargaNumero(limite);
    }while(limite <= 1);
    int A[limite],*Array=A;
    cargaArray(Array, limite);
    for(int i=0; i<limite; i++){
        invertirArray(Array, i, pila);
    }
    cout<<"Array Cargado: ";
    imprimeArray(Array, limite);
    for (int i = 0; i < limite; i++)
    {
        int j = 0;
        eliminarNodos(pila, j);
        if (i != (limite - 1))
        {
            cout << " " << limite << " | ";
        }
        else
        {
            cout << " " << limite << "\n";
        }
    }
    return;
}

void cargaPila(int **Matriz, int filas, int columnas, Nodo *&pila)
{
    cout << "Cargando Pila.\n";
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->numero = *(*(Matriz + filas) + columnas);
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    return;
}

void descargaPila(Nodo *&pila, int &x)
{
    cout << "Se descarga la pila.\n";
    Nodo *aux = pila;
    x = pila->numero;
    pila = aux->siguiente;
    delete aux;
    return;
}

void cargaMatriz(int **Matriz, Nodo *&pila)
{
    int x = 0;
    cout << "Cargar cada fila impar.\n";
    for (int i = 0; i < 6; i++)
    {
        system("cls");
        for (int j = 0; j < 5; j++)
        {
            if (((i + 1) % 2) != 0)
            {
                cout << "Carga Posicion (" << i + 1 << ", " << j + 1 << ")\n"
                     << "Valor: ";
                cin >> *(*(Matriz + i) + j);
                cargaPila(Matriz, i, j, pila);
            }
            else
            {
                cout << "Carga Posicion (" << i + 1 << ", " << j + 1 << ")(Fila Par.)\n";
                if(pila != NULL){
                    descargaPila(pila, x);  
                    if(pila == NULL){
                        cout<<"La pila se descargo completamemte.\n";
                    }
                }else{
                    cout<<"La pila esta vacia.\n";
                    descargaPila(pila, x);
                }
                cout << "Valor x= " << x << "\n";
                *(*(Matriz + i) + j) = x;
            }
        }
        cout << "Fila " << i << " completada.\n";
        getch();
    }
    return;
}

void imprimeMatriz(int **Matriz)
{
    cout << "Entra a imprime matriz.\n";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 4)
            {
                cout << *(*(Matriz + i) + j) << "\n";
            }
            else
            {
                cout << " " << *(*(Matriz + i) + j) << " | ";
            }
        }
    }
}
void Matriz(Nodo *&pila){
    int **M = new int *[6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            *(M + j) = new int[5];
        }
        cargaMatriz(M, pila);
        cout << "Hola";
        imprimeMatriz(M);
        for (int i = 0; i < 6; i++)
        {
            delete[] M[i];
        }
        delete[] M;
        delete pila;
        cout << "Presione una tecla para salir.\n";
        getch();
        return;
    }
}



/*
Hacer un programa que permita ejecutar un ejercicio de los hechos en la clase pasada
utilizando un menu.
*/
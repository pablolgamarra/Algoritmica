#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Nodo{
    int num;
    Nodo *siguiente;
};

void cargaPila(Nodo *&,int );

void descargaPila(Nodo *&, int &);

main(){
    char op;
    int n;
    Nodo *pila=NULL;
    do{
        cout<<"Ingrese numeros enteros y el programa los almacenara en forma de pila.\n";
        cout<<"Ingrese numero: ";
        cin>>n;
        while(!cin.good()){
            fflush(stdin);
            cin.clear();
            cout<<"Ha ocurrido un error en la carga.\n Vuelva a ingresar numero: ";
            cin>>n;
        }
        cargaPila(pila, n);
        cout<<"Desea seguir ingresando?: (s/n)";
        cin>>op;
        cin.ignore();
    }while(op == 's');
    cout<<"Se imprimira la pila cargada.\n";
    cout<<"Presione una tecla para comenzar";
    getch();
    while(pila != NULL){
        descargaPila(pila, n);
        if(pila != NULL){
            cout<<n<<", ";
        }else{
            cout<<n<<"\n";        
        }
        
    }
}

void cargaPila(Nodo *&pila,int n){
    Nodo *nuevoNodo= new Nodo();
    nuevoNodo->num= n;
    nuevoNodo->siguiente= pila;
    pila = nuevoNodo;
}

void descargaPila(Nodo *&pila,int &n){
    Nodo *aux= pila;
    n=aux->num;
    pila=aux->siguiente;
    delete aux;
}
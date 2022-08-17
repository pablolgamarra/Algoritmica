#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Array_Invertido{
    int elemento;
    Array_Invertido *siguiente;
};

void cantElementos(int &);

void cargaArray(int *, int);
void imprimeArray(int*A , int n){
    for(int i=0; i<n;i++){
        cout<<*(A+i)<<"\n";
    }
}
void invertirArray(int *,int , Array_Invertido *&);

void descargarPila(Array_Invertido *&);

main(){
    int n;
    cout<<"Programa para invertir un vector usando pilas.\n";
    cantElementos(n);
    int A[n], *Array=A;
    Array_Invertido *pila=NULL;
    cargaArray(A, n);
    invertirArray(A, n, pila);    
    for(int i=0; i<n; i++){
        if(i!=(n-1)){
            descargarPila(pila);
            cout<<" | ";
        }else{
            descargarPila(pila);
            cout<<" | \n";        
        }
        
    }
    system("pause");
    return 0;
}

void cantElementos(int &n){
    do{
        cout<<"Ingrese la cantidad de elementos que desea que tenga el vector: ";
        cin>>n;
        while(!cin.good()){
            fflush(stdin);
            cin.ignore();
            cin.clear();
            cout<<"Ha ocurrido un error en la carga.\nDebe ingresar valores numericos positivos.\n"
            <<"Vuelva a ingresar cantidad de elementos que tendra el vector: ";
            cin>>n;
        }
    }while(n<=0);
    return;
}

void cargaArray(int *Array, int limite){
    for(int i=0; i<limite; i++){
        cout<<"Ingrese valor para posicion "<<i+1<<": ";
        cin>>(*(Array+i));
    }
    return;
}

void invertirArray(int *Array, int contador,Array_Invertido *&pila){
    Array_Invertido *nuevo_nodo= new Array_Invertido();
    nuevo_nodo->elemento = (*(Array+contador));
    nuevo_nodo->siguiente=pila;
    pila=nuevo_nodo;
    return;
}

void descargarPila(Array_Invertido *&pila){
    Array_Invertido *aux= pila;
    cout<<aux->elemento;
    pila=aux->siguiente;
    delete aux;
    return;
}
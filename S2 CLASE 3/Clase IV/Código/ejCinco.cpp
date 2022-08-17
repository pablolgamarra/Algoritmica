#include <iostream>
#include <windows.h>

using namespace std;

void cantElementos(int &n){
    cout<<"Ingrese la cantidad de elementos que tendra el arreglo: ";
    cin>>n;
}

void cargaArray(int limite, int *Array,int &men){
    for(int i=1; i<=limite;i++){
        system("cls");
        cout<<"Carga de Datos.\n";
        cout<<"Ingrese valor para posicion "<<i<<" : ";
        cin>>*Array;
        if(i==1){
            men=*Array;
            cout<<men;
        }else if(*Array<men){
            men=*Array;
        }
        Array++;
    }
}

void imprimirArray(int limite, int *Array){
    for(int i=1; i<=limite;i++){
        if(i==limite){
            cout<<*Array++<<"\n";
        }else{
            cout<<*Array++<<" | ";
        }
    }
}



main(){
    system("cls");
    int n;
    cout<<"Programa que encuentra el menor numero ingresado a un Array.\n";
    cantElementos(n);
    int A[n], men=0;
    int *ptrA;
    ptrA=A;
    cargaArray(n,ptrA,men);
    imprimirArray(n,ptrA);
    cout<<"El menor valor ingresado es: "<<men<<"\n";
    system("pause");
    return 0;
}

/*
Rellenar un arreglo con “n” números, posteriormente utilizando punteros determinar el
menor elemento del arreglo.
*/
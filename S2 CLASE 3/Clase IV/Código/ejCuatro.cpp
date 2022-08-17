#include <iostream>
#include <windows.h>

using namespace std;

void cargarVector(int *array){
    for(int i=1; i<=10;i++){
        cout<<"Posicion: "<<i<<"\nValor: ";
        cin>>*array++;
    }
}

void imprimirVector(int *array){
    for(int i=1; i<=10;i++){
        if((*array%2)==0){
            cout<<"( Par ), Pos.Mem: "<<&(*array)<<" | ";
        }
        if(i==10){
            cout<<*array++<<"\n";
        }else{
            cout<<*array++<<" | ";
        }
    }
}

main(){
    system("cls");
    int A[10],*ptrM=A;
    cout<<"Cargue 10 elementos a un array y el programa determinara cuales son pares y la posicion en memoria  de los mismos.\n";
    cargarVector(ptrM);
    imprimirVector(ptrM);
    system("pause");
    return 0;
}

/*
Rellenar un array de 10 números, posteriormente utilizando punteros indicar cuales son
números pares y su posición en memoria. 
*/
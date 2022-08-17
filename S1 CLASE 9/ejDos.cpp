#include <iostream>
#include <windows.h>

using namespace std;

int num,i,suma=0;

int Par(int ,int num){
    if(i % 2 == 0){
        if(i == num || i == num-1){
            cout<<i<<"\n";
            suma=suma+i;
        }else{
            cout<<i<<", ";
            suma=suma+i;            
        }
    }
    return suma;
}
int main(){
    system("cls");
    cout<<"El programa imprime los numeros pares de una serie del 1 al numero ingresado y calcula la suma de los pares  .\n";
    cout<<"Ingrese un numero mayor a 50: ";
    cin>>num;
    while(num <= 50){
        system("cls");
        cout<<"ERROR! Solo numeros mayores a 50: ";
        cin>>num;
    }
    system("cls");
    for(i=1;i<=num;i++){
        Par(i,num);
    }
    cout<<"La suma de los numeros pares de la serie es: "<<suma<<"\n";
    system("pause");
    return 0;
}

/*
Ingresar un número mayor a 50. Generar una serie a partir de 1 hasta el número ingresado e imprimir solo los
números pares y calcular e imprimir la sumatoria de los números pares de la serie.
*/
#include <iostream>
#include <windows.h>

using namespace std;
int i, num, fact=1;

int factorial(int num){
    for(i=1; i <= num; i++){
        fact=fact*i;
    }
    return fact;
}
int main(){
    system("cls");
    cout<<"Programa que imprime la factorial de un numero.\n";
    cout<<"Ingrese un numero positivo.\n";
    cin>>num;
    system("cls");
    cout<<"La factorial de "<<num<< " es: "<<factorial(num)<<"\n";
    system("pause");
    return 0;
}

/*
Crear un subproceso que devuelva la factorial de un número.
*/
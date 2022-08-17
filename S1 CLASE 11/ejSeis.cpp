#include <iostream>
#include <windows.h>

using namespace std;
int num, i;
bool par=false;

bool EsPar(int num){
    if(num % 2 == 0){
        par=true;
    }
    return par;
}

int main(){
    system("cls");
    cout<<"El programa determinara si el numero ingresado es un numero par.\n";
    cout<<"Ingrese un numero: ";
    cin>>num;
    EsPar(num);
    if(par){
        cout<<"Verdadero\n";
    }else{
        cout<<"Falso.\n";
    }
    system("pause");
    return 0;
}

/*
Crea una función EsPar que devuelva el valor lógico "verdadero" o "falso" según si el número que
se indique como parámetro es par o no lo es.
*/
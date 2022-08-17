#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int num1,num2,aux;
    system("cls");
    cout<<"Intercambio de valores entre dos variables.\n";
    cout<<"Ingrese el primer numero: ";
    cin>>num1;
    cout<<"Ingrese el segundo numero: ";
    cin>>num2;
    system("cls");
    aux=num1;
    num1=num2;
    num2=aux;
    cout<<"Primer numero: "<<num1<<"\nSegundo numero: "<<num2<<"\n";
    system("pause");
    return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int num1,num2;
    system("cls");
    cout<<"Intercambio de Valores entre dos variables sin auxiliar.\n";
    cout<<"Ingrese el valor para a: ";
    cin>>num1;
    cout<<"Ingrese el valor para b: ";
    cin>>num2;
    system("cls");
    num1=num1+num2;
    num2=num1-num2;
    num1=num1-num2;
    cout<<"\nEl nuevo valor de a es: "<<num1<<"\nEl nuevo valor de b es: "<<num2<<endl;
    system("pause");
    return 0;
}
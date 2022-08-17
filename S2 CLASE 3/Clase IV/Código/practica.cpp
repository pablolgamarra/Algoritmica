#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int a, *puntero;
    system("cls");
    cout<<"Ingrese valor para 'a' :";
    cin>>a;
    puntero=&a;
    cout<<"A: "<<a<<endl;
    cout<<"Puntero: "<<*puntero<<endl;
    system("pause");
    return 0 ;
}


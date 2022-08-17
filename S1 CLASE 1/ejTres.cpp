#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int m,d;

int main(){
    system("cls");
 
    cout<<"Ingrese la cantidad de meses: "<<endl;
    cin>>m;

    d=m*30;

    cout<<"La cantidad de dias es: "<< d<<endl;

    system("pause");

    return 0;
}
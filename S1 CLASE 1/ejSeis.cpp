#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int n,r1,r2;

int main(){
    cout<<"Ingrese el numero que desea potenciar:" <<endl;
    cin>>n;

    r1=pow(n, 2);

    r2=pow(n, 3);

    system("cls");

    cout<<"El numero ingresado es: "<<n <<endl;
    cout<<"El cuadrado del numero es: "<< r1 <<endl;
    cout<<"El cubo del numero es: "<<r2 <<endl;

    system("pause");
    
    return 0;
}
#include <iostream> 
#include <cstdlib>
#include <windows.h>

using namespace std;

int p,d,pd;

int main(){
    system("cls");
    cout<<"Ingrese el precio del producto"<<endl;
    cin>>p;

    d=p*0.2;

    pd=p-d;

    system("cls");

    cout<<"El precio del producto sin el descuento es:"<<p<<endl;
    cout<<"El descuento de este producto es de:"<<d<<endl;
    cout<<" "<<endl;
    cout<<"El total a pagar es: "<<pd<<endl;

    system("pause");

    return 0;

}
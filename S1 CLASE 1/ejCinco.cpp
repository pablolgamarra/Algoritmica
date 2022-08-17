#include <iostream> 
#include <cstdlib>
#include <windows.h>

using namespace std;

int p,d,pd;

int main(){
    system("cls");
    cout<<"Ingrese el precio de la camisa"<<endl;
    cin>>p;

    d=p*0.1;

    pd=p-d;

    cout<<"El total a pagar es: "<<pd<<endl;

    system("pause");

    return 0;

}
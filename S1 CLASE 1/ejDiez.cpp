#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

string name;

int sb, d , ps, sn;

int main(){
    system("cls");
    cout<<"Ingrese su nombre"<<endl;
    cin>>name;
    cout<<" "<<endl;
    cout<<"Ingrese el sueldo base"<<endl;
    cin>>sb;
    cout<<" "<<endl;
    cout<<"Ingrese el monto a ser descontado"<<endl;
    cin>>d;
    cout<<" "<<endl;
    cout<<"Ingrese el plus salarial"<<endl;
    cin>>ps;


    sn= (sb+ps)-d;
    

    system("cls");
    cout<<" "<<endl;
    cout<<"El sueldo neto de: "<< name << " es de: "<< sn << " guaranies"<<endl;

    system("pause");
    return 0;
}

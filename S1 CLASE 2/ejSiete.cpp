#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

main(){
    string name;
    int type,prize, com;

    system("cls");

    cout<<"\n Ingrese el nombre del vendedor: ";
    cin>>name;
    
    cout<<"\n\n Ingrese el tipo del vehiculo |1| para autos y |2| para camionetas: ",
    cin>>type;

    cout<<"\n\n Ingrese el precio de venta: ";
    cin>>prize;

    system("cls");

    switch (type){
    case 1:
        com= prize*0.15;
        cout<<"La comision del vendedor "<<name<<" es de: "<<com<<endl;
        break;
    
    case 2:
        com=prize*0.25;
        cout<<"La comision del vendedor "<<name<<" es de: "<<com<<endl;
        break;

    default:
        cout<<"El tipo de vehiculo seleccionado no es valido"<<endl;
        break;
    }

    system("pause");

}
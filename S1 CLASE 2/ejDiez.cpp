#include <iostream>
#include <windows.h>

using namespace std;

main(){
    string name;
    int sueldoBase, cantHijos;

    system("cls");

    cout<<"Ingrese el nombre del trabajador: ";
    cin>>name;

    cout<<"\nIngrese la cantidad de hijos del trabajador: ";
    cin>>cantHijos;

    cout<<"\nIngrese el sueldo base del trabajador: ";
    cin>>sueldoBase;

    system("cls");

    if(cantHijos>2){
        sueldoBase=(sueldoBase*0.1)+sueldoBase;
    }
    cout<<"\nEl sueldo a cobrar por el trabajador "<<name<<" es de: "<<sueldoBase<<"\n"<<endl;

    system("pause");
}
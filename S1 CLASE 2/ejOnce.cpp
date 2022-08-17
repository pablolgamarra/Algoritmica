#include<iostream>
#include<windows.h>

using namespace std;

main(){
    string name;
    int sueldoBruto, sueldoNeto, descuento;

    system("cls");

    cout<<"Ingrese el nombre del empleado: ";
    cin>>name;

    cout<<"\nIngrese el sueldo del empleado: ";
    cin>>sueldoBruto;

    system("cls");

    if(sueldoBruto>700000){
        descuento=sueldoBruto*0.05;
        sueldoNeto=sueldoBruto-descuento;
    }else{
        descuento=0;
        sueldoNeto=sueldoBruto;
    }
    cout<<"\nNombre del trabajador: "<<name<<"\n\nDescuento: "<<descuento<<"\n\nSueldo a cobrar: "<<sueldoNeto<<"\n"<<endl;

    system("pause");

}
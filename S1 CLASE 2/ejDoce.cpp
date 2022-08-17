#include<iostream>
#include<windows.h>

using namespace std;

main(){
    string nombre;
    int peso, precio,oferta,total;

    system("cls");

    cout<<"Ingrese el nombre del producto: ";
    cin>>nombre;

    cout<<"\nIngrese el peso del producto en kg: ";
    cin>>peso;

    cout<<"\nIngrese el precio por kilogramo del producto: ";
    cin>>precio;

    system("cls");

    if(peso<=3){
        precio=precio;
        total=precio*peso;
    }else{
        oferta=precio*0.8;
        total=oferta*peso;
        cout<<"\nEste producto se encuentra en promocion!\n"<<"\n";
    }

    cout<<"Nombre del producto: "<<nombre<<"\n\nPeso: "<<peso<<"kg"<<"\n\nPrecio Unitario: "<<precio<<"\n\nTotal a pagar: "<<total<<endl;

    system("pause");

}
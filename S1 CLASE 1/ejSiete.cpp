#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int edad1,edad2,dif;

int main(){
    system("cls");
    cout<<"Ingrese la primera edad"<<endl;
    cin>>edad1;

    cout<<"Ingrese la segunda edad"<<endl;
    cin>>edad2;

    if(edad1>edad2){
        dif=edad1-edad2;
        system("cls");
        cout<<"La primera edad ingresada es:"<<edad1<<endl;
        cout<<"La segunda edad ingresada es:"<<edad2<<endl;
        cout<<"La diferencia de edades es de: " <<dif<<" anos"<<endl;
        system("pause");
        return 0;
    }if(edad1<edad2){
        dif=edad2-edad1;
        system("cls");
        cout<<"La primera edad ingresada es:"<<edad1<<endl;
        cout<<"La segunda edad ingresada es:"<<edad2<<endl;
        cout<<"La diferencia de edades es de: " <<dif<<" anos"<<endl;
        system("pause");
        return 0;
    }if(edad1=edad2){
        dif=0;
        system("cls");
        cout<<"La primera edad ingresada es:"<<edad1<<endl;
        cout<<"La segunda edad ingresada es:"<<edad2<<endl;
        cout<<"No hay diferencia de edades."<<endl;
        system("pause");
        return 0;
    }
    
    system("cls");
    cout<<"Hubo un error, vuelva a intentarlo"<<edad1<<endl;

    system("pause");

    return 0;

}
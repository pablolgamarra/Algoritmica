#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int num;
    system("cls");
    cout<<"Ingrese un numero y el programa imprimira a que dia de la semana corresponde.\n";
    cout<<"Ingrese numero: ";
    cin>>num;
    system("cls");
    switch(num){
        case 1:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Domingo.\n";
            break;
        case 2:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Lunes.\n";
            break;
        case 3:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Martes.\n";
            break;
        case 4:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Miercoles.\n";
            break;    
        case 5:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Jueves.\n";
            break;
        case 6:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Viernes.\n";
            break;
        case 7:
            cout<<"Numero ingresado: "<<num<<endl;
            cout<<"Corresponde al Dia: Sabado.\n";
            break;
        default:
            cout<<"El numero ingresado: "<<num<<" no es valido.\n";
            break;
    }
    system("pause");
    return 0;
}

/*
Ingresar un número que representa los días de la semana, indica a que día de la semana
corresponde el numero ingresado 
*/

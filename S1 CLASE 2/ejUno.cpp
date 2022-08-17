// Programa al que se ingresa un número y dependiendo del mismo, sew define el día de la semana que es

#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int dayn;

    system("cls");

    cout<<"Ingrese un numero del 1 al 7 segun de el dia: ";
    cin>>dayn;

    system("cls");

    switch (dayn)
    {
    case 1:

        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Domingo"<<endl;
        break;
    
    case 2:
        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Lunes"<<endl;
        break;

    case 3:
        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Martes"<<endl;
        break;
    
    case 4:
        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Miercoles"<<endl;
        break;

    case 5:
        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Jueves"<<endl;
        break;

    case 6:
        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Viernes"<<endl;
        break;

    case 7:
        cout<<"El numero ingresado fue: "<<dayn<<endl;
        cout<<"El dia equivalente al numero ingresado es: Sabado"<<endl;
        break;
    
    default: 
        cout<<"El numero ingresado no es valido"<<endl;
        break;
    }

    system("pause");
    
    return 0;
}

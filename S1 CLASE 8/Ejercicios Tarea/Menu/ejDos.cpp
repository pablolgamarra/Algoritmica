#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num;
    cout<<"Meses.\n";
    cout<<"Ingrese un numero que represente a un mes: ";
    cin>>num;
    switch(num){
        case 1:
            system("cls");
            cout<<"El numero ingresado corresponde a Enero\n";
            break;
        case 2:
            system("cls");
            cout<<"El numero ingresado corresponde a Febrero\n";
            break;
        case 3:
            system("cls");
            cout<<"El numero ingresado corresponde a Marzo\n";
            break;
        case 4:
            system("cls");
            cout<<"El numero ingresado corresponde a Abril\n";
            break;
        case 5:
            system("cls");
            cout<<"El numero ingresado corresponde a Mayo\n";
            break;
        case 6:
            system("cls");
            cout<<"El numero ingresado corresponde a Junio\n";
            break;
        case 7:
            system("cls");
            cout<<"El numero ingresado corresponde a Julio\n";
            break;
        case 8:
            system("cls");
            cout<<"El numero ingresado corresponde a Agosto\n";
            break;
        case 9:
            system("cls");
            cout<<"El numero ingresado corresponde a Septiembre\n";
            break;
        case 10:
            system("cls");
            cout<<"El numero ingresado corresponde a Octubre\n";
            break;
        case 11:
            system("cls");
            cout<<"El numero ingresado corresponde a Noviembre\n";
            break;
        case 12:
            system("cls");
            cout<<"El numero ingresado corresponde a Diciembre\n";
            break;
        default:
            system("cls");
            cout<<"El numero ingresado no corresponde a ningun mes.\n";
            break;
    }
    system("pause");
    return 0;
}

/*
Introducir un número que represente un mes del año. Imprimir el mes al que corresponde
utilizando la instrucción CASE. 
*/
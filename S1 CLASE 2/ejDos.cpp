// Programa que imprime un mes dependiendo del número elegido

#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int n;

    system("cls");

    cout<<"Ingrese un numero del '1' al '12' segun el mes que desee"<<endl;
    cin>>n;

    system("cls");

    switch (n)
    {
    case 1:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Enero"<<endl;
        break;
    
    case 2:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Febrero"<<endl;
        break;

    case 3:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Marzo"<<endl;
        break;

    case 4:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Abril"<<endl;
        break;

    case 5:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Mayo"<<endl;
        break;

    case 6:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Junio"<<endl;
        break;

    case 7:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Julio"<<endl;
        break;

    case 8:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Agosto"<<endl;
        break;

    case 9:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Septiembre"<<endl;
        break;

    case 10:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Octubre"<<endl;
        break;

    case 11:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Noviembre"<<endl;
        break;

    case 12:
        cout<<"El numero ingresado fue: "<<n<<endl;
        cout<<"El numero ingresado equivale al mes: Diciembre"<<endl;
        break;

    default:
        cout<<"El numero ingresado no es valido"<<endl;
        break;
    }

    system("pause");

}
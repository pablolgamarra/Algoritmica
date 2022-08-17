#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    float numUno, numDos;
    int opcion;
    cout<<"Calculadora Sencilla.\n";
    do{
        cout<<"Seleccione la opcion que quiere realizar: \n";
        cout<<"Menu de Opciones:\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir del Programa\n";
        cin>>opcion;
        switch (opcion){
            case 1:
                system("cls");
                cout<<"Opcion Elegida: Suma\n";
                cout<<"Ingrese el Valor del Primer Numero: ";
                cin>>numUno;
                cout<<"Ingrese el Valor del Segundo Numero: ";
                cin>>numDos;
                cout<<"El resultado es: "<<(numUno+numDos)<<"\n";
                system("pause");
                break;
            case 2:
                system("cls");
                cout<<"Opcion Elegida: Resta\n";                
                cout<<"Ingrese el Valor del Primer Numero: ";
                cin>>numUno;
                cout<<"Ingrese el Valor del Segundo Numero: ";
                cin>>numDos;
                cout<<"El resultado es: "<<(numUno-numDos)<<"\n";
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"Opcion Elegida: Multiplicacion\n";
                cout<<"Ingrese el Valor del Primer Numero: ";
                cin>>numUno;
                cout<<"Ingrese el Valor del Segundo Numero: ";
                cin>>numDos;
                cout<<"El resultado es: "<<(numUno*numDos)<<"\n";
                system("pause");
                break;
            case 4:
                system("cls");
                cout<<"Opcion Elegida: Division\n";
                cout<<"Ingrese el Valor del Primer Numero: ";
                cin>>numUno;
                cout<<"Ingrese el Valor del Segundo Numero: ";
                cin>>numDos;
                cout<<"El resultado es: "<<(numUno/numDos)<<"\n";
                system("pause");
                break;
            case 5:
                system("cls");
                cout<<"Opcion Elegida: Salir del Programa.\n";
                break;
            default:
                system("cls");
                cout<<"Se ha ingresado una opcion invalida.\n";
                break;
        }
    }while(opcion != 5);
    return 0;
}

/*
Introducir dos números por teclado y mediante un menú calcular su suma, resta, producto o
división. Ejemplo:
Menú de Opciones:
1. Suma
2. Resta
3. Multiplicación
4. División
5. Salir del Programa
Elige una opción:
*/
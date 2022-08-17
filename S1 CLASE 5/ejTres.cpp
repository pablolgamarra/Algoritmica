#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int cantAIngresar,contIngresados=0,numIngresado,promedio=0,contPares=0,contImpares=0,sumaPares=0,sumaImpares=0,sumaConts=0;
    system("cls");
    cout<<"Promedios de Pares e Impares\n";
    cout<<"Cual es la cantidad de numeros que va a ingresar?: ";
    cin>>cantAIngresar;
    system("cls");
    while(cantAIngresar>contIngresados){
        contIngresados++;
        cout<<"Ingrese numero: ";
        cin>>numIngresado;
        if(numIngresado%2==0){
            contPares++;
            sumaPares=sumaPares+numIngresado;
        }if(numIngresado%2!=0){
            contImpares++;
            sumaImpares=sumaImpares+numIngresado;
        }
    }
    sumaConts=contPares+contImpares;
    promedio=(sumaPares+sumaImpares)/sumaConts;
    cout<<"La cantidad de numeros ingresados fue: "<<contIngresados<<"\nEl promedio de los pares e impares ingresados encontrados es: "<<promedio<<"\n";
    system("pause");
    return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int numUno,numDos,menor,mayor,i,sw=0;
    cout<<"Ingrese dos numeros diferentes e inferiores a 50\n";
    cout<<"Ingrese el valor del primer numero: ";
    cin>>numUno;
    cout<<"Ingrese el valor del segundo numero: ";
    cin>>numDos;
    while(( (numUno>=50) || (numDos>=50) ) || (numUno==numDos)){
        cout<<"ERROR.\nIngrese dos numeros diferentes e inferiores a 50.\n";
        cout<<"Ingrese el valor del primer numero: ";
        cin>>numUno;
        cout<<"Ingrese el valor del segundo numero: ";
        cin>>numDos;
    }
    if(numUno<numDos){
        menor=numUno;
        mayor=numDos;
    }else if(numDos<numUno){
        menor=numDos;
        mayor=numUno;
    }
    do{
        if(sw==0){
            sw=1;
            cout<<menor<<", ";
            menor=menor+5;
        }else if(sw==1){
            sw=0;
            cout<<mayor<<", ";
            mayor=mayor-2;
        }
    }while(mayor>menor);
    system("pause");
    return 0;
}

/*
Introducir dos números inferiores a 50 por teclado. Al más pequeño aumentarlo de 5 en 5 y al
mayor disminuirlo de 2 en 2. Imprimir ambas series de números de una forma alternativa,
hasta que el menor supere al mayor.
*/
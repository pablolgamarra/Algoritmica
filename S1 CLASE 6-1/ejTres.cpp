#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int numUno,numDos,sw=0,i,contMultiplos=0,contImpresos=0,menor,mayor;
    cout<<"Ingresar dos numeros y el programa imprimira los multiplos de tres que hay entre esos numeros de manera alternativa\n\n";
    cout<<"Ingrese el valor del primer numero: ";
    cin>>numUno;
    cout<<"\nIngrese el valor del segundo numero: ";
    cin>>numDos;
    while(numUno==numDos){
        cout<<"ERROR. Los valores deben ser diferentes. ";
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
    system("cls");
    for(i=menor;i<=mayor;i++){
        if(((i % 3) == 0) && (sw==0)){
            cout<<i<<", ";
            sw=1;
            contMultiplos++;
            contImpresos++;
        }else if(((i % 3) == 0) && (sw==1)){
            sw=0;
            contMultiplos++;
        }
    }
    cout<<"\nEn la serie, se encontraron: "<<contMultiplos<<" Multiplos de 3. \n";
    cout<<"\nSe imprimieron: "<<contImpresos<<" numeros. \n";
    system("pause");
    return 0;
}

/*Imprimir los múltiplos de tres que hay entre dos números determinados de una forma
alternativa, es decir, uno sí y otro no. */
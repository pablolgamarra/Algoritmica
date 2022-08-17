#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    system("cls");
    int numUno,numDos,suma=0,sw=0,i,cantPares=0,menor,mayor;
    cout<<"Programa que imprime, suma y cuenta los numeros pares de manera alternativa entre dos numeros.\n";
    cout<<"\nIngrese el primer numero: ";
    cin>>numUno;
    cout<<"\nIngrese el segundo numero: ";
    cin>>numDos;
    while(numUno==numDos){
        system("cls");
        cout<<"ERROR!. \nLos numeros deben ser diferentes.";
        cout<<"\n\nIngrese el primer numero: ";
        cin>>numUno;
        cout<<"\n\nIngrese el segundo numero: ";
        cin>>numDos;
    }
    if(numUno<numDos){
        menor=numUno;
        mayor=numDos;
    }else{
        menor=numDos;
        mayor=numUno;
    }
    cout<<"\n\n";
    system("cls");
    for(i=menor;i<=mayor;i++){
        if((i % 2) == 0){
            if(sw==0){
                if((i==mayor) || (i==(mayor-1))){
                    cout<<i<<"\n";
                    cantPares++;
                    suma=suma+i;
                    sw=1;                    
                }else{
                    cout<<i<<", ";
                    cantPares++;
                    suma=suma+i;
                    sw=1;
                }
            }else{
                sw=0;
            }
        }
    }
    cout<<"\n";
    cout<<"La cantidad de pares es: "<<cantPares<<"\n\n";
    cout<<"La suma de los pares es: "<<suma<<"\n\n";
    system("pause");
    return 0;
}


/*
Hacer un programa que imprima, sume y cuente los números pares entre dos números
determinados de una forma alternativa. 
*/
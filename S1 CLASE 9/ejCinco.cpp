#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int cantIng, num, i = 0, j=0, mayor, menor;
    cout<<"El programa indica el mayor y el menor numero ingresados, imprime la tabla de multiplicar del menor en caso de que sea positivo.\n";
    cout<<"Cuantos numeros ingresara?: ";
    cin>>cantIng;
    while(i < cantIng){
        system("cls");
        cout<<"Ingrese numero: ";
        cin>>num;
        i++;
        if(i == 1){
            menor = num;
            mayor = num;
        }
        if(num < menor){
            menor= num;
        }
        if(num > mayor){
            mayor=num;
        }
    }
    system("cls");
    cout<<"Se ingresaron: "<<i<<" numeros\n";
    cout<<"Mayor numero ingresado: "<<mayor<<"\n";
    cout<<"Menor numero ingresado: "<<menor<<"\n";
    if(menor > 0){
            cout<<"Tabla del: "<<menor<<"\n";
        for(j; j<=10; j++){
            cout<<"\t"<<menor<<" x "<<j<<" = "<<menor*j<<"\n";
        }
    }else{
        cout<<"El menor numero ingresado es un numero negativo. No se puede imprimir su tabla\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar tantos números como se desee hasta un número ingresado previamente. Indica cuantos números
fueron ingresados, además encontrar el mayor y menor número encontrado e imprimir la tabla de multiplicar del
menor, solo si este es un número positivo, en caso de negativo, enviar un mensaje indicando “El número es
negativo o igual a cero”
*/
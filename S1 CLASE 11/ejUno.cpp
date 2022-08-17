#include <iostream>
#include <windows.h>

using namespace std;
//VARIABLES
int num=1, limite, divisible=0, i=1,j=0;
string opcion="S";

//FUNCIONES SECUNDARIAS
void primo(int limite){
    for(j=0; j<limite; j++){
        while(i <= num){
            if((num % i) == 0){
                divisible++;
            }
            i++;
        }
        if(divisible == 2){
            if((num == limite) || (num == (limite-1))){
                cout<<num<<".\n";
            }else{
                cout<<num<<", ";
            }
        }
        num++;
        divisible=0;
        i=1;        
    }
    return;
}

//FUNCION PRINCIPAL
int main(){
    system("cls");
    cout<<"Ingrese un numero y el programa imprimira en pantalla los numeros primos existentes entre el '1' y el numero ingresado.\n";
        cout<<"Ingrese un numero positivo mayor que '0': ",
        cin>>limite;
        while(limite <= 0){
            cout<<"Ingrese un numero positivo mayor que '0': ",
            cin>>limite;
        }
        primo(limite);
    system("pause");
    return 0;

}

/*
Escribe una función en pseudocódigo que devuelva si un número dado es primo o no. Para que un
número sea primo solo es divisible entre 1 y sí mismo (por ejemplo, 13, 17, 19…). Utilizando la
función, escribe un programa que escriba todos los números primos entre 1 y un
número leído desde el teclado
*/
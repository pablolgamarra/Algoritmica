#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num,divisible=0,sw=0,opcion,primos=0,i;
    cout<<"El programa determina si el numero ingresado es un numero primo.\n";
    do{
        cout<<"Ingrese un numero positivo: ";
        cin>>num;
        while(num<0){
            cout<<"\nERROR. Solo numeros positivos.\nVuelva a ingresar el numero: ";
            cin>>num;
        }
        for(i=1;i<=num;i++){
            if((num % i) == 0){
                divisible++;
            }
        }
        if(divisible == 2){
            sw=1;
        }else{
            sw=0;
        }
        divisible=0;
        if(sw == 1){
            primos++;
        }
        system("cls");
        cout<<"Desea seguir ingresando numeros ?\t'1'= Si\t'2' = No\n";
        cin>>opcion;
        system("cls");
        while(opcion < 1 || opcion > 2){
            system("cls");
            cout<<"Desea seguir ingresando numeros ?\t'1'= Si\t'2' = No\n";
            cin>>opcion;
            system("cls");
        }
    }while(opcion == 1);
    if(primos > 0){
        system("cls");
        cout<<"Se ingreso al menos un numero primo.\n";
    }else{
        system("cls");
        cout<<"No se ha ingresado ningun numero primo.\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar tantos números como se desee, decir si entre los números ingresados se encuentra algún numero primo.
*/
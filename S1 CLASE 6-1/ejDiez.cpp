#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num,sw=0,opcion=0,primo=0,i;
        cout<<"Ingrese cuantos numeros desee, el programa determinara si se ingreso algun numero primo\n\n";
    do{
        cout<<"Ingrese un numero positivo: ";
        cin>>num;
        while(num<0){
            cout<<"Ingrese un numero positivo: ";
            cin>>num;
        }
        if(num == 1 || num == 0){
            sw=1;
        }
        for(i=2;i<num;i++){
            if ((num % i) == 0){
                sw=1;
                break;
            }else{
                sw=0;
            }
        }
        if(sw == 1){
            primo=0;
        }else{
            primo=1;
        }
        system("cls");
        cout<<"Desea ingresar otro numero ? ('0'=Si.\t'1'=No.)\n";
        cin>>opcion;
        system("cls");
    }while(opcion == 0);
    system("cls");
    if(primo == 0){
        cout<<"No se ingreso ningun numero primo.\n";
    }else{
        cout<<"Se ingreso un numero primo.\n";
    }
    system("pause");
    return 0;
}

/*
Ingresar tantos números como se desee. Decir si fue ingresado o no un numero primo.
*/
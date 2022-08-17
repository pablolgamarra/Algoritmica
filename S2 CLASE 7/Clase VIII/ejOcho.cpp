#include <iostream>
#include <windows.h>

using namespace std;

void ingNum(int &);

int suma(int);

main(){
    int num;
    system("cls");
    cout<<"Programa para determinar la suma de los primeros 'x' numeros naturales.\n";
    ingNum(num);
    system("cls");
    cout<<"La suma de los primeros "<<num<<" numeros naturales es: "<<suma(num)<<"\n";
    system("pause");
    return 0;
}

void ingNum(int &num){
    do{
        cout<<"Ingrese cantidad de numeros que desea sumar: ";
        cin>>num;
    }while(num <= 0);
    return;
}

int suma(int num){
    if(num==1){
        return 1;
    }else{
        return num+suma((num-1));
    }
}

/*
Determinar la suma de los primeros "n" números naturales 
*/

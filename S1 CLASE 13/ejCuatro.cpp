#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
    srand((unsigned)time(NULL));
    int moneda= rand()%2+1;
    system("cls");
    cout<<"Programa que simula el lanzamiento de una moneda.\n";
    system("pause");
    system("cls");
    if(moneda==1){
        cout<<"Ha salido cara."<<endl;
    }else{
        cout<<"Ha salido cruz."<<endl;
    }
    system("pause");
    return 0;
}

/*
Crear un programa que simule el lanzamiento de una moneda
*/
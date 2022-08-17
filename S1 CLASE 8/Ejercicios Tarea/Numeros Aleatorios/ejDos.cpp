#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(NULL));
    system("cls");
    int i, ladoDado,contSeis=0;
    cout<<"Juego de Dados\n";
    for(i=0;i<=100;i++){
        ladoDado=rand()%6+1;
        cout<<"Dado: "<<ladoDado<<"\n";
        if(ladoDado == 6){
            contSeis++;
        }
    }
    cout<<"El lado con el numero seis salio: "<<contSeis<<" veces\n";
    system("pause");
    return 0;
}

/*
Simular cien tiradas de un dado y contar las veces que aparece el número 6. 
*/
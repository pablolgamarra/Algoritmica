#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
    system("cls");
    srand((unsigned)time(NULL));
    int moneda,contTiradas=0,cara=0,contCaras=0;
    cout<<"Lanzamiento de moneda al aire. El programa se detendra cuando salgan cara 3 veces seguidas\n";
    do{
        moneda=rand()%2+1;
        if(moneda == 1){
            cara=1;
            cout<<"Ha salido cara\n";
        }else{
            cara=0;
            contCaras=0;
            cout<<"Ha salido cruz\n";
        }
        if(cara == 1){
            contCaras++;
        }
        contTiradas++;
        system("pause");
        system("cls");
    }while(contCaras<3);
    system("cls");
    cout<<"Se realizaron "<<contTiradas<<" tiradas para que salga cara tres veces seguidas.\n";
    system("pause");
    return 0;
}

/*
Simular el lanzamiento de una moneda al aire y que pare cuando salgan 3 caras seguidas.
Imprimir el número de tiradas realizadas 
*/
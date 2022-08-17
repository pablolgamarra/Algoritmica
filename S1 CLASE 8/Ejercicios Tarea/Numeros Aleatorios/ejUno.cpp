#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main(){
    srand(time(NULL));
    int moneda;
    string opcion;
    cout<<"Juego de Cara o Cruz.";
    do{
        system("cls");
        moneda=rand()%2+1;
        if(moneda == 1){
            cout<<"Ha salido cara.\n";
        }else{
            cout<<"Ha salido cruz.\n";
        }
        cout<<"Desea seguir tirando monedas?. 'S' = Si / 'N' = No\n";
        cin>>opcion;
    }while(opcion == "S" || opcion == "s");
    return 0;
}

/*
Simular el lanzamiento de una moneda al aire e imprimir si ha salido cara o cruz. Repetir el
proceso tantas veces se desee. 
*/
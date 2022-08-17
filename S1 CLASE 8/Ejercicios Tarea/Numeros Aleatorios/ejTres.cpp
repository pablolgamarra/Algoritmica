#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
    srand((unsigned)time(NULL));
    int i,cantTiradas, dadoUno,dadoDos,contDiez=0;
    cout<<"Tiradas de Dos Dados (El programa cuenta las veces que entre ambos suman 10.)\n";
    cout<<"Ingrese la cantidad de tiradas que quiere realizar: ";
    cin>>cantTiradas;
    for(i=1;i<=cantTiradas;i++){
        system("cls");
        dadoUno=rand()%6+1;
        dadoDos=rand()%6+1;
        cout<<"Tirada: "<<i<<"\n";
        cout<<"Dado Uno: "<<dadoUno<<"\n";
        cout<<"Dado Dos: "<<dadoDos<<"\n";
        cout<<"------------------------------------------------\n";
        system("pause");
        if((dadoUno+dadoDos) == 10){
            contDiez++;
        }
    }
    system("cls");
    cout<<"Ambos dados sumaron '10' "<<contDiez<<" veces\n";
    system("pause");
    return 0;
}

/*
Simular cien tiradas de dos dados y contar las veces que entre los dos suman 10. 
*/
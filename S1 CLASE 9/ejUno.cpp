#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num, suma=0, numMayor,sw=0,i=0;
    string op;
    cout<<"Puede ingresar tantos numeros como desee.\nEl programa realizara la sumatoria e imprimira el mayor numero ingresado\n";
    do{
        if(i != 0){
            system("cls");
        }
        cout<<"Ingrese numero: ";
        cin>>num;
        suma=suma+num;
        if(i == 0){
            numMayor = num;
        }else if(num > numMayor){
            numMayor = num;
        }
        i++;
        cout<<"Desea seguir ingresando numeros?: (S)\t(N): ";
        cin>>op;
        if(op == "N" || op == "n"){
            sw = 1;
        }
    }while(sw == 0);
    system("cls");
    cout<<"Se ingresaron: "<<i<<" numeros.\n";
    cout<<"El mayor numero ingresado fue: "<<numMayor<<"\n";
    cout<<"La sumatoria de los numeros ingresados es: "<<suma<<"\n";
    system("pause");
    return 0;
}

/*
Ingresar tantos números como se desee. Imprimir la sumatoria de números y el mayor valor ingresado
*/
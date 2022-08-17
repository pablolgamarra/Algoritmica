#include <iostream>
#include <windows.h>
using namespace std;
main(){
    char seleccion;
    int suma=0,numIng=0,contNum=0,numMayor=0,numAnt=0;
    system("cls");
    do{
        numAnt=numIng;
        contNum++;
        cout<<"Ingrese numero: ";
        cin>>numIng;
        if(numIng>numAnt){
            numMayor=numIng;
            suma=suma+numIng;
        }else{
            suma=suma+numIng;
        }
        cout<<"Desea ingresar otro numero? S/N : ";
        cin>>seleccion;
    }while(seleccion=='s'||seleccion=='S');
    system("cls");
    cout<<"\nLa cantidad de numeros ingresados fue: "<<contNum<<endl;
    cout<<"\nLa suma es: "<<suma<<endl;
    cout<<"\nEl mayor numero ingresado fue: "<<numMayor<<endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng, i,suma=0;
    system("cls");
    cout<<"Ingrese un numero mayor a '50': ";
    cin>>numIng;
    while(numIng<=50){
        system("cls");
        cout<<"ERROR.\nIngrese un numero mayor a '50': ";
        cin>>numIng;
    }
    system("cls");
    cout<<"\n";
    for(i=1;i<=numIng;i++){
        if(i%2==0){
            suma=suma+i;
            cout<<i<<", ";
        }
    }
    cout<<"\n\nLa sumatoria de los numeros pares de la serie es: "<<suma<<endl;
    system("pause");
    return 0;
}
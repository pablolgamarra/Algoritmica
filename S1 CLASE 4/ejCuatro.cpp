#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng,limit,i=0;

    system("cls");
    cout<<"Ingrese un numero positivo menor que '5': ";
    cin>>numIng;
    system("cls");
    while(numIng>=5 || numIng<0){
        cout<<"ERROR!\nEl numero ingresado debe ser positivo y menor a '5'. \nVuelva a ingresar: ";
        cin>>numIng;
    }
    limit=numIng+20;
    for(numIng;numIng<=limit;i++){
        cout<<numIng<<", ";
        numIng++;
    }
    cout<<"\n";
    system("pause");
}
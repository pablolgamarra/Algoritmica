#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int numIng,i;
    system("cls");
    cout<<"Numero Par o Impar\n\n";
    cout<<"Ingrese numero: ";
    cin>>numIng;
    for(i=0;numIng>0;i++){
        numIng=numIng-2;
    }
    if(numIng==0){
        cout<<"\nEl numero ingresado es par\n\n";
    }else{
        cout<<"\nEl numero ingresado es impar\n\n";
    }
    system("pause");
    return 0;
}
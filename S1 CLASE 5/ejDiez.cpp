#include <iostream>
#include <windows.h>

using namespace std;
//divisible con otro numero 1=si 0=no, (true, false)
int main(){
    int numIng, i;
    bool comparador=true;
    system("cls");
    cout<<"Numeros Primos\n\n";
    cout<<"Ingrese un numero positivo: ";
    cin>>numIng;
    while(numIng<1){
        cout<<"Ingrese un numero positivo: ";
        cin>>numIng;
    }
    for(i=0;i<numIng;){
        i=i+2;
        if((numIng-(numIng/i)*i)==0){
            comparador=false;
        }
    }
    system("cls");
    if(comparador){
        cout<<"\nEl numero ingresado es un numero primo.\n\n";
    }else{
        cout<<"\nEl numero ingresado no es un numero primo\n\n";
    }
    system("pause");
    return 0;
}
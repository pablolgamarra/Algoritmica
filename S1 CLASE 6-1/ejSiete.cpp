#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int num,sw=0,iUno=0,iDos=10;
    cout<<"Ingrese un numero positivo menor que '10'\n";
    cin>>num;
    while(num<0 || num>10){
        cout<<"ERROR.\nIngrese un numero positivo menor que '10'\n";
        cin>>num;
    }
    system("cls");
    do{
        if(sw == 0){
        sw=1;
        cout<<num<<" x "<<iUno<<" = "<<num*iUno<<"\n";
        iUno++;
        }else if(sw == 1){
        sw=0;
        cout<<num<<" x "<<iDos<<" = "<<num*iDos<<"\n";
        iDos--;
        }
    }while(iUno <= 10 || iDos >= 0);
    system("pause");
    return 0;
}
/*
Dado un número menor que 10. Hallar su tabla de multiplicar de forma por duplicado, es decir,
empezando por el cero y por el 10 de forma alternativa. 
0   1   2   3   4   5   6   7   8   9   10

10  9   8   7   6   5   4   3   2   1   0

*/
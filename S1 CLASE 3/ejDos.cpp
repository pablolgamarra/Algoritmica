#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int n,i=0;
    
    system("cls");

    cout<<"Ingrese un numero: ";
    cin>>n;

    system("cls");

    while(i<n){
        i=i+2;
    }

    system("cls");

    if(i==n){
        cout<<"Numero ingresado: "<<n<<endl;
        cout<<"\nEl numero ingresado es un numero par.\n";
    }else{
        cout<<"Numero ingresado: "<<n<<endl;
        cout<<"\nEl numero ingresado es un numero impar.\n";
    }
}
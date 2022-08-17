#include <iostream>
#include <windows.h>
#include <wchar.h>

using namespace std;

main(){
    int n;

    system("cls");

    cout<<"Ingrese un numero: ";
    cin>>n;

    system("cls");
    if(n<0){
        cout<<"Numero negativo\n";
    }if(n>0){
        cout<<n+50<<endl;
    }

    system("pause");

}
#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int num,i;
    system("cls");
    cout<<"Ingrese un numero: ";
    cin>>num;
    while(num>=10||num<0){
        cout<<"ERROR. \nEl numero ingresado debe ser positivo y menor a 10: ";
        cin>>num;
    }
    system("cls");
    for(i=1;i<=10;i++){
        cout<<num<<" x "<<i<<" = "<<num*i<<"\n";
    }
    system("pause");
    return 0;
}
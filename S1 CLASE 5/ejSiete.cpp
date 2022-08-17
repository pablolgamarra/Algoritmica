#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int n, c;
    system("cls");
    cout<<"Tabla de Multiplicar de los 10 primeros numeros.\n\n";
    cout<<"Ingrese un numero positivo y menor o igual a 10: ";
    cin>>n;
    while(n<0||n>10){
        cout<<"ERROR. \n El numero ingresado debe ser positivo y menor o igual a 10: ";
        cin>>n;
    }
    cout<<"Tabla del: "<<n<<"\n";
    for(c=0;c<=10;c++){
        cout<<n<<" x "<<c<<" = "<<n*c<<"\n";
    }
    system("pause");
    return 0;
}
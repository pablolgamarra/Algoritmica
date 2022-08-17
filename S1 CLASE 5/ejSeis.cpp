#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numIng,c,fact=1,aux=1;
    system("cls");
    cout<<"Factoriales. \n\n";
    cout<<"Ingrese un numero positivo menor que 20: ";
    cin>>numIng;
    while(numIng>20||numIng<0){
        cout<<"ERROR. El numero ingresado debe ser positivo y menor a 20: ";
        cin>>numIng;
    }
    for(c=1;c<=numIng;c++){
        fact=c*fact;
    }
    system("cls");
    cout<<"La factorial de "<<numIng<<" es: "<<fact<<endl;
    system("pause");
    return 0;
}
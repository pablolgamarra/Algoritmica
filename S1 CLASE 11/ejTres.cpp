#include <iostream>
#include <windows.h>

using namespace std;
int num,cifras=1;
int main(){
    system("cls");
    cout<<"Ingrese un numero y el programa determinara la cifras que tiene\n";
    cout<<"Ingrese un numero mayor que '0': ";
    cin>>num;
    while (num < 0){
        cout<<"Ingrese un numero mayor que '0': ";
        cin>>num;
    }
    while(num/10>0){
        num=num/10;
        cifras++;
    }
    system("cls");
    cout<<"El numero tiene "<<cifras<<" cifras.\n";
    system("pause");
    return 0;
}

/*
Algoritmo que dado un número entero (este número no podrá ser menor o igual que 0), determine
el número de cifras que tiene. Por ejemplo, si introduzco un 253, me devuelva un 3. 
*/
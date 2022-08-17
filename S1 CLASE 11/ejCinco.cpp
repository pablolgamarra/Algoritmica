#include <iostream>
#include <windows.h>

using namespace std;
int numUno,numDos;

float rUno, rDos;

void EsMultiplo(int numUno, int numDos){
    rUno= numUno / numDos;
    rDos= numDos / numUno;
    if (rUno * numDos == numUno){
        cout<<"El primer numero es multiplo del segundo.\n";
    }else if(rDos * numUno == numDos){
        cout<<"El segundo numero es multiplo del primero.\n";
    }else{
        cout<<"Ninguno de los numeros es multiplo del otro.\n";
    }
    return;
}

int main(){
    cout<<"Ingrese dos numeros enteros y el programa determinara si uno es multiplo del otro.\n";
    cout<<"Ingrese primer numero: ";
    cin>>numUno;
    cout<<"Ingrese segundo numero: ";
    cin>>numDos;
    EsMultiplo(numUno, numDos);
    system("pause");
    return 0;
}

/*
Crea un programa que pida dos números enteros al usuario y diga si alguno de ellos es múltiplo
del otro. Crea una función EsMultiplo que te ayude a que el proceso principal sea legible. 
*/
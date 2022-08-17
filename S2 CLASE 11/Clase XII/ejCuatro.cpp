#include <iostream>
#include <windows.h>

using namespace std;

main(){
    system("cls");
    char cad1[40], cad2[40];
    cout<<"Programa que copia una cadena y la pega en otra.\n";
    cout<<"Ingrese la cadena que se copiara: ";
    cin>>cad1;
    strcpy(cad2, cad1);
    cout<<"Cadena Ingresada: "<<cad1<<"\n";
    cout<<"Cadena Copiada: "<<cad2<<"\n";
    system("pause");
    return 0;
}

/*
Ingresar una cadena en la variable cad1, copiar el contenido en cad2. Imprimir ambas
cadenas. 
*/
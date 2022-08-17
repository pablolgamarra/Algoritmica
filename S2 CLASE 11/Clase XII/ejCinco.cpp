#include <iostream>
#include <windows.h>

using namespace std;

main(){
    system("cls");
    string frase;
    int vocales=0;
    cout<<"Ingrese una frase y el programa calculara la cantidad de vocales que hay en las palabras.\n";
    cout<<"Ingrese frase: ";
    getline(cin, frase);
    for(char letra: frase){
        if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
            vocales++;
        }
    }
    system("cls");
    cout<<"La frase ingresada es: "<<frase<<"\n";
    cout<<"La cantidad de vocales que hay en la frase es: "<<vocales<<"\n";
    system("pause");
    return 0;
}

/*
Ingresar una frase. Indicar la cantidad de vocales existentes en la frase. 
*/
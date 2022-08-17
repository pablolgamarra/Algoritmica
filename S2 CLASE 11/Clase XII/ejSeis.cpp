#include <iostream>
#include <windows.h>

using namespace std;

void cortarFrase(char *, int);

main(){
    char *frase=NULL, cadena[50];
    int cantElementos;
    cout<<"Programa para cortar una frase.\n";
    cout<<"Ingrese frase: ";
    cin>>cadena;
    cantElementos=strlen(cadena);
    cout<<"cant: "<<cantElementos;
    frase = new char[cantElementos];
    cortarFrase(frase, cantElementos);
    cout<<"Frase Ingresada: "<<cadena<<"\n";
    return 0;
}

void cortarFrase(char *frase, int cantElementos){
    int desde, hasta;
    char fraseCortada[50];
    cout<<"Ingrese la posicion desde la cual desea cortar la frase: ";
    cin>>desde;
    while (desde < 0 || desde > cantElementos)
    {
        cout<<"ERROR. La posicion desde la cual se cortara debe ser mayor a cero.\n";
        cout<<"Ingrese la posicion desde la cual desea cortar la frase: ";
        cin>>desde;
    }
    cout<<"Ingrese la posicion hasta la cual desea cortar la frase: ";
    cin>>hasta;
    while (hasta < desde || hasta > cantElementos)
    {
        cout<<"ERROR. La posicion desde la cual se cortara debe ser mayor a cero.\n";
        cout<<"Ingrese la posicion hasta la cual desea cortar la frase: ";
        cin>>hasta;
    }    
    for(int i=desde; i < hasta; i++ ){
        strcat(fraseCortada, (frase+i));
    }
    cout<<"Fragmento Recortado: "<<fraseCortada<<"\n";
    return;
}

/*
Ingresar una frase. Crea un procedimiento que permita cortar la frase y guardar en otra
cadena, indicándole los parámetros desde y hasta. Ejemplo:
void CortarFrase(char *cadena, int nelementos, int desde, int hasta) 
*/
#include <iostream>
#include <windows.h>

using namespace std;

struct cadenas{
    string cadena;
    string cadenaMay="";
    string cadenaMin="";
    string cadenaCopy="";
}cadena, *ptrcadenas=&cadena;

void cadenaMinuscula(cadenas *);
void cadenaMayuscula(cadenas *);
void cadenaCopiar(cadenas *);

main(){
    cout<<"Programa para hacer manejo de cadenas.\n";
    cout<<"Ingrese cadena: ";
    getline(cin, ptrcadenas->cadena);
    cadenaMinuscula(ptrcadenas);
    cadenaMayuscula(ptrcadenas);
    cadenaCopiar(ptrcadenas);
    cout<<"Cadena Original: "<<ptrcadenas->cadena<<"\n";
    cout<<"Cadena en Minusculas: "<<ptrcadenas->cadenaMin<<"\n";
    cout<<"Cadena en Mayusculas: "<<ptrcadenas->cadenaMay<<"\n";
    cout<<"Cadena Copiada: "<<ptrcadenas->cadenaCopy<<"\n";
}

void cadenaMinuscula(struct cadenas *ptrcadenas)
{
    for (int i = 0; i < (ptrcadenas->cadena).length(); i++)
    {
        ptrcadenas->cadenaMin += tolower(ptrcadenas -> cadena[i]);
    }
    return;
}

void cadenaMayuscula(struct cadenas *ptrcadenas)
{
    for (int i = 0; i < (cadena.cadena).length(); i++)
    {
        ptrcadenas->cadenaMay += toupper(ptrcadenas -> cadena[i]);
    }
    return;
}

void cadenaCopiar(struct cadenas *ptrcadenas){
    ptrcadenas->cadenaCopy+=ptrcadenas->cadena;
    return;
}

/*
Crear la estructura Personas el cual contendrá los siguientes campos:
Cadena: donde se ingresara la cadena original
CadenaMay: donde la cadena original ingresada se convertirá en mayúsculas
CadenaMin: donde la cadena original se convertirá en minúsculas
CadenaCopy: donde la cadena original será copiada 
*/
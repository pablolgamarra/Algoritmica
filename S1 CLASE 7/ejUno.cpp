#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int pruebaUno,pruebaDos,pruebaTres,suma;
    cout<<"Calculadora de nota final.\n";
    cout<<"Ingrese el resultado de la primera prueba: ";
    cin>>pruebaUno;
    cout<<"Ingrese el resultado de la segunda prueba: ";
    cin>>pruebaDos;
    cout<<"Ingrese el resultado de la tercera prueba: ";
    cin>>pruebaTres;
    while(pruebaUno < 0 || pruebaUno >15){
        system("cls");
        cout<<"ERROR. El puntaje maximo de cada prueba es de 15.\n";
        cout<<"Ingrese el resultado de la primera prueba: ";
        cin>>pruebaUno;
    }
    while(pruebaDos < 0 || pruebaDos >15){
        system("cls");
        cout<<"ERROR. El puntaje maximo de cada prueba es de 15.\n";
        cout<<"Ingrese el resultado de la segunda prueba: ";
        cin>>pruebaDos;
    }
    while(pruebaTres < 0 || pruebaTres >15){
        system("cls");
        cout<<"ERROR. El puntaje maximo de cada prueba es de 15.\n";
        cout<<"Ingrese el resultado de la tercera prueba: ";
        cin>>pruebaTres;
    }
    suma=pruebaUno+pruebaDos+pruebaTres;
    if(suma == 0 || suma <= 25){
        cout<<"La calificacion obtenida es: 1.\n";
        cout<<"El puntaje total obtenido fue de: "<<suma<<" puntos.\n";
    }else if(suma == 26 || suma <= 30){
        cout<<"La calificacion obtenida es: 2.\n";
        cout<<"El puntaje total obtenido fue de: "<<suma<<" puntos.\n";
    }else if(suma == 31 || suma <= 35){
        cout<<"La calificacion obtenida es: 3.\n";
        cout<<"El puntaje total obtenido fue de: "<<suma<<" puntos.\n";
    }else if(suma == 36 || suma <= 40){
        cout<<"La calificacion obtenida es: 4.\n";
        cout<<"El puntaje total obtenido fue de: "<<suma<<" puntos.\n";
    }else if(suma == 41 || suma <= 45){
        cout<<"La calificacion obtenida es: 5.\n";
        cout<<"El puntaje total obtenido fue de: "<<suma<<" puntos.\n";
    }else{
        cout<<"Hubo un error pelotudo.\n";
        cout<<suma<<endl;
    }
    system("pause");
    return 0;
}

/*
Se tienen los resultados de tres pruebas de un alumno/a (Cada uno de 15 puntos – Validar los puntajes), lo cual una
vez totalizado servirá para determinar la calificación de la etapa basándose en la siguiente tabla para calificaciones.
0– 25 = 1
26– 30 = 2
31– 35 = 3
36– 40 = 4
41– 45 = 5 
*/
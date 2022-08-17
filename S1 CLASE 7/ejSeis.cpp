#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    string contrario;
    int gf=0,gc=0,gfTotal=0,gcTotal=0,puntos=0,i=1,promGoles;
    cout<<"Programa para determinar los puntos obtenidos en eliminatorias.\n";
    do{
    cout<<"Partido "<<i<<"\n";
    cout<<"Ingrese el contrincante: ";
    cin>>contrario;
    while(contrario == ""){
        cout<<"ERROR. Debe ingresarse el nombre del contrincante.\n";
        cout<<"Ingrese el contrincante: ";
        cin>>contrario;
    }
    cout<<"\nCuantos goles metio la Seleccion Paraguaya?: ";
    cin>>gf;
    while(gf < 0){
        cout<<"ERROR. Deben ingresarse datos positivos.\n";
        cout<<"Cuantos goles metio la Seleccion Paraguaya?: ";
        cin>>gf;
    }
    cout<<"\nCuantos goles metio el equipo contrario?: ";
    cin>>gc;
    while(gc < 0){
        cout<<"ERROR. Deben ingresarse datos positivos.\n";
        cout<<"Cuantos goles metio el equipo contrario?: ";
        cin>>gc;
    }
    gfTotal=gfTotal+gf;
    gcTotal=gcTotal+gc;
    if(gf > gc){
        puntos=puntos+3;
    }else if(gf == gc){
        puntos=puntos+1;
    }else if(gf < gc){
        puntos=puntos+0;
    }
    i++;
    }while(i<=3);
    promGoles=(gfTotal+gcTotal)/3;
    system("cls");
    cout<<"El puntaje obtenido en la primera fase fue: "<<puntos<<" pts.\n";
    cout<<"La Cantidad de goles que metio la Seleccion Paraguaya en la fase fue: "<<gfTotal<<" goles.\nLe hicieron "<<gcTotal<<" goles.\n";
    cout<<"El promedio de goles que metio la Seleccion Paraguaya en la fase es: "<<promGoles<<"\n";
    system("pause");
    return 0;
}

/*
El seleccionado de Paraguay disputa sus tres partidos de la primera fase de un torneo, donde se registran los datos:
Nro de partido, equipo contrincante, goles a favor, goles en contra.
Desarrolla un algoritmo que calcule e imprima:
a) El puntaje total obtenido al final de la primera fase (3 puntos si gana, 1 punto por empate, 0 si pierde)
b) La cantidad de goles que obtuvo y cuantos le hicieron
c) El promedio de goles en los tres partidos. 
*/
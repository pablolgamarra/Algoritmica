#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    string destino,selector;
    int numVuelo,escala=0,distanciaDestino;
    float tiempoEscala;
    cout<<"Programa Aerolinea Volando Bajito S.A\n";
    cout<<"Ingrese el Numero de Vuelo: ";
    cin>>numVuelo;
    while(numVuelo < 0){
        cout<<"ERROR.\nVuelva a ingresar el Numero de Vuelo: ";
        cin>>numVuelo;
    }
    cout<<"Ingrese el Nombre del Destino: ";
    cin>>destino;
    cout<<"Ingrese distancia al Destino: ";
    cin>>distanciaDestino;
    while(distanciaDestino <= 0){
        cout<<"ERROR.\nVuelva a ingresar distancia al Destino: ";
        cin>>distanciaDestino;
    }
    cout<<"El vuelo es con escala? (S=Si)\t(N=No): ";
    cin>>selector;
    while((selector != "S"  || selector != "s") && (selector != "N" || selector != "n")){
        cout<<"El vuelo es con escala? (S=Si)\t(N=No): ";
        cin>>selector;
    }
    if(selector == "S"  || selector == "s"){
        escala=0;
        cout<<"Ingrese el tiempo para recorrido de escala en horas: ";
        cin>>tiempoEscala;
        while(tiempoEscala < 0){
            cout<<"ERROR. El tiempo de escala debe ser en horas.\n";
            cout<<"Ingrese el tiempo para recorrido de escala en horas: ";
            cin>>tiempoEscala;
        }
    }else{
        escala=1;
    }
    
    system("pause");
    return 0;
}


/*
Una aerolínea registra diariamente los siguientes datos respecto a sus aeronaves: número de vuelo, destino, escala,
tiempo para recorrido de escala.
Calcula e imprime:
a) Los kilómetros totales para llegada a destino
b) El tiempo total del recorrido
c) La menor distancia registrada entre las escalas para cada vuelo
d) Emitir un mensaje si existe un vuelo sin escala (considera escala = 1, cuando es sin escala)
e) La condición para finalizar el programa es cuando el nro de vuelo es igual a 999 
*/
#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int cantAIngresar, contIngresados=0,numIngresado, numMayor=0, numMenor=0, c=0,numAnterior;
    system("cls");
    cout<<"Mayor y Menor Ingresados y Tabla de Multiplicar del Menor.\n";
    cout<<"Ingrese la cantidad de numeros que va a ingresar: ";
    cin>>cantAIngresar;
    system("cls");
    while (cantAIngresar>contIngresados){
        cout<<"Ingrese numero: ";
        cin>>numIngresado;
        if(contIngresados==0){
            numMayor=numIngresado;
            numMenor=numIngresado;
        }else{
            if (numIngresado>numMayor){
                numMayor=numIngresado;
            }else if(numIngresado<numMenor){
                numMenor=numIngresado;
            }
        }
        contIngresados++;
    }
    system("cls");
    cout<<"Se ingresaron "<<contIngresados<<" numeros.\n\n";
    cout<<"Menor Numero Ingresado: "<<numMenor<<"\n\n";
    cout<<"Mayor Numero Ingresado: "<<numMayor<<"\n\n";
    if(numMenor<=0){
        cout<<"La Tabla de Multiplicar no se puede imprimir.\n\nEl numero es negativo o igual a cero\n";
    }else{
        while (c<=10){
            cout<<numMenor<<"x"<<c<<"="<<numMenor*c<<endl;
            c++;
        }
    }
    system("pause");
    return 0;
}


/*Ingresar tantos números como se desee hasta un número ingresado previamente. Indica cuantos números fueron
ingresados, además encontrar el mayor y menor número encontrado e imprimir la tabla de multiplicar del menor, solo
si este es un número positivo, en caso de negativo, enviar un mensaje indicando “El número es negativo o igual a
cero”. */
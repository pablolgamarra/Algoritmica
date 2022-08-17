#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

//variables globales
int numUno, numDos,numAux=0,diferencia,seleccion,i=0,c=0,a=0,cantPares=0,sumaImpares=0,promedioImpares=0,cantImpares=0,primos=0,divisibles=0,fact=1,flag=0;

//funciones
int calcDiferencia(int numUno,int numDos){
    return abs(numUno-numDos);
}

//funcion principal
int main() {
    system("cls");
    cout<<"Deben ingresarse dos numeros distintos entre si y con una diferencia de 150 unidades entre si.\n";
    cout<<"\nIngrese el primer numero: ";
    cin>>numUno;
    cout<<"\nIngrese el segundo numero: ";
    cin>>numDos;
    diferencia=calcDiferencia(numUno,numDos);

    while (diferencia<=150){
        system("cls");
        cout<<"\nLos numeros ingresados deben ser distintos y la diferencia entre ambos debe ser de 150 numeros como minimo: \n";
        cout<<"\nVuelva a ingresar el primer numero: ";
        cin>>numUno;
        cout<<"\nVuelva a ingresar el segundo numero: ";
        cin>>numDos;
        diferencia=calcDiferencia(numUno,numDos);
    }

    system("cls");
    cout<<"Opciones: \n";
    cout<<"'1' : Mostrar los numeros existentes entre ambos.\n";
    cout<<"'2' : Mostrar la cantidad de pares entre los numeros ingresados.\n";
    cout<<"'3' : Mostrar el promedio de impares entre los numeros ingresados.\n";
    cout<<"'4' : Mostrar la cantidad de numeros primos existentes entre los numeros ingresados.\n";
    cout<<"'5' : Mostrar la factorial del primer numero primo hallado.\n";
    cout<<"'6' : Mostrar la tabla de multiplicar del ultimo numero primo hallado.\n";
    cout<<"'7' : Salir o Regresar al menu. \n";
    cout<<"\n\nIngrese opcion elegida: ";
    cin>>seleccion;

    switch (seleccion){
    case 1:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        for(i=numUno;i<=numDos;i++){
            if(i==numDos){
                cout<<i<<"\n";
            }else{
                cout<<i<<", ";

            }
        }
        break;

    case 2:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        for(i=numUno; i<numDos;i++){
        if(i % 2 == 0){
            cantPares++;
        }
        }
        cout<<"La cantidad de pares es: "<<cantPares<<"\n";
        break;
        
    case 3:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        for(i=numUno;i<=numDos;i++){
            if(i % 2 != 0){
                cantImpares++;
                sumaImpares=sumaImpares+i;
            }
        }
        promedioImpares=sumaImpares/cantImpares;
        cout<<"El promedio de Impares es: "<<promedioImpares<<"\n";
        break;

    case 4:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        for(i=numUno;i<=numDos;i++){
            for(c=1; c<=i;c++){
                if((i%c)==0){
                    divisibles++;
                }
            }
            if(divisibles==2){
                primos++;
            }
            divisibles=0;
        }
        cout<<"La cantidad de numeros primos es: "<<primos<<"\n";
        break;

    case 5:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        for(i=numUno;i<=numDos;i++){
            for(c=1; c<=i;c++){
                if((i%c)==0){
                    divisibles++;
                }
            }
            if(divisibles==2){
                primos++;
            }
            if(primos==1){
                for(a=1;a<=i;a++){
                    fact=a*fact;
                }
                break;
            }
            divisibles=0;
        }
        cout<<"El primer numero primo encontrado fue: "<<i<<"\n";
        cout<<"La factorial del primer numero primo encontrado es: "<<fact<<"\n";
        break;

    case 6:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        for(i=numUno;i<=numDos;i++){
            for(c=1; c<=i;c++){
                if((i%c)==0){
                    divisibles++;
                }
            }
            if(divisibles==2){
                primos=i;
            }
            divisibles=0;
        }
        for(c=0;c<=10;c++){
            cout<<primos<<" x "<<c<<" = "<<primos*c<<"\n";
        }
        break;

    case 7:
        system("cls");
        cout<<"Opcion elegida: "<<seleccion<<"\n";
        break;

    default:
        system("cls");
        cout<<"\nLa opcion seleccionada no es valida.";
        break;
    }
    system("pause");
    return 0;
}


/*
Dos numeros positivos diferentes cuya diferencia sea comop mínimo 150 numeros
Lista de Opciones:
1) Mostrar los números existentes entre ambos
2) Mostrar la cantidad de pares entre los números ingresados
3) Mostrar el promedio de impares entre los números ingresados
4) Mostrar la cantidad de números primos existentes entre los números ingresados
5) Mostrar la factorial del primer número primo hallado
6) Mostrar la tabla de multiplicar del ultimo numero primo hallado
7) Salir o Regresar al menú 
*/
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

void cantElementos(int &);

void cargarArray(int *, int);

void mayorElemento(int *, int);

void menorElemento(int *, int);

void valorPromedio(int *, int);

void cantidadPar_Impar(int *, int);

void imprimeArray(int *, int);

void selectorOpcion(int &);

void menu(int &, int *, int);

main(){
    int n, opcion;
    srand((unsigned)time(NULL));
    cout<<"Programa para crear un vector con numeros aleatorios en su interior.\n";
    cantElementos(n);
    int *N=new int[n];
    //Carga del Vector
    cargarArray(N, n);
    //Menu Selector
    do{
    menu(opcion, N, n);
    }while(opcion != 6);
    return 0;
}

void cantElementos(int &n){
    do{
        cout<<"Ingrese la cantidad de elementos que tendra el vector (10 en adelante): ";
        cin>>n;        
    }while(n < 10);
    return;
}

void cargarArray(int *N, int limite){
    cout<<"Se cargara el array con: "<<limite<<" Numeros Aleatorios.\n";
    for (int i=1; i<=limite; i++){
        *(N+i)=((rand()%100)+1);
    }
    cout<<"Array Cargado.\n";
    cout<<"Toque una tecla para seguir.\n";
    getch();                
    return;
}

void mayorElemento(int *N, int limite){
    int mayor=*(N+1);
    for(int i=2; i<=limite; i++){
        if(*(N+i) > mayor){
            mayor = *(N+i);
        }
    }
    cout<<"El Mayor Elemento es: "<<mayor<<"\n";
    return;
}

void menorElemento(int *N, int limite){
    int menor=*(N+1);
    for(int i=2; i<=limite; i++){
        if(*(N+i) < menor){
            menor = *(N+i);
        }
    }
    cout<<"El Menor Elemento es: "<<menor<<"\n";
    return;
}

void valorPromedio(int *N, int limite){
    float promedio=0;
    for(int i=1; i<=limite; i++){
        promedio= promedio + (*(N+i));
    }
    cout<<"El Valor Promedio es: "<<(promedio/limite)<<"\n";
    return;
}

void cantidadPar_Impar(int *N, int limite){
    int pares=0, impares=0;
    for(int i=1;i<=limite; i++){
        if((*(N+i)%2) == 0){
            pares++;
        }else{
            impares++;
        }
    }
    cout<<"Cantidad de Pares: "<<pares<<"\n";
    cout<<"Cantidad de Impares: "<<impares<<"\n";
    return;
}

void imprimeArray(int *N, int limite){
    for(int i=1; i<=limite; i++){
        if(i==limite){
            cout<<*(N+i)<<"\n";
        }else{
            cout<<*(N+i)<<" | ";
        }
    }
    return;
}

void selectorOpcion(int &opcion){
    do{
        cout<<"Seleccione la accion que desea realizar: \n";
        cout<<"1. Hallar el Mayor Elemento del Array.\n";
        cout<<"2. Hallar el Menor Elemento del Array.\n";
        cout<<"3. Hallar el Valor Promedio del Array.\n";
        cout<<"4. Hallar la Cantidad de Pares e Impares del Array.\n";
        cout<<"5. Imprimir Array Creado.\n";
        cout<<"6. Salir del Programa.\n";
        cin>>opcion;
    }while(opcion < 0 || opcion > 6);
    return;
}

void menu(int &opcion, int *N, int limite){
    selectorOpcion(opcion);
        switch(opcion){
            case 1:
                mayorElemento(N, limite);
                cout<<"Toque una tecla para seguir.\n";
                getch();                
                break;
            case 2:
                menorElemento(N, limite);
                cout<<"Toque una tecla para seguir.\n";
                getch();                
                break;
            case 3:
                valorPromedio(N, limite);
                cout<<"Toque una tecla para seguir.\n";
                getch();                
                break;
            case 4:
                cantidadPar_Impar(N, limite);
                cout<<"Toque una tecla para seguir.\n";
                getch();
                break;
            case 5:
                imprimeArray(N, limite);
                cout<<"Toque una tecla para seguir.\n";
                getch();
                break;
            default:
                cout<<"Gracias por usar el programa.\n";
                cout<<"Toque una tecla para seguir.\n";
                getch();                
                break;
    }
    return;
}
/*
Crear un Array dinámico N (unidimensional) utilizando una función para obtener la
cantidad de elementos en el array, donde, no se permitirá menos de 10 elementos. Cargar
el arrays con números aleatorios hasta 100. Luego, utiliza un menú para desplegar
opciones que ejecutarán las siguientes rutinas:
mayorElemento( ) Se encargará de hallar el mayor elemento ingresado en el array
menorElemento() Se encargará de hallar el menor elemento ingresado en el array
valorPromedio() Encontrará el promedio de valores ingresados en el array
CantidadPar_Impar( ) Encontrará la cantidad de pares e impres ingresados en el array
imprimeArray( ) Se encargará de imprimir el array creado 
*/
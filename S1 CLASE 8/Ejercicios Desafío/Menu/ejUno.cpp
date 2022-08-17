#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

//Variables Globales
int numUno,lado,altura,seleccion,opcion,ladoDado,ladoMoneda;

//Funciones
void cuadrado(){
    system("cls");
    cout<<"Ingrese el lado: ";
    cin>>lado;
    system("cls");
    cout<<"\n1. Calcular Perimetro\n";
    cout<<"2. Calcular Area\n";
    cin>>opcion;
    if (opcion == 1){
        //perimetro
        system("cls");
        cout<<"El perimetro es: "<<(lado*4)<<"\n";
        system("pause");
        return;
    }else{
        //area
        system("cls");
        cout<<"El area es: "<<(lado*lado)<<"\n";
        system("pause");
        return;
    }
}

void rectangulo(){
    system("cls");
    cout<<"Ingrese base: ";
    cin>>lado;
    cout<<"Ingrese altura: ";
    cin>>altura;    
    system("cls");
    cout<<"\n1. Calcular Perimetro\n";
    cout<<"2. Calcular Area\n";
    cin>>opcion;
    if (opcion == 1){
        //perimetro
        system("cls");
        cout<<"El perimetro es: "<<(lado*2)+(altura*2)<<"\n";
        system("pause");
        return;
    }else{
        //area
        system("cls");
        cout<<"El area es: "<<(lado*altura)<<"\n";
        system("pause");
        return;
    }
}

void creciente (){
    system("cls");
    cout<<"Ingrese un numero entre 20 y 30: ";
    cin>>numUno;
    system("cls");
    cout<<"1. Serie del 1 al numero ingresado\n";
    cout<<"2. Serie del numero ingresado al 100\n";
    cin>>opcion;
    system("cls");
    if(opcion == 1){
        //1 al num
        for(int i=1;i<=numUno;i++){
            if(i==numUno){
                cout<<i<<"\n";
            }else{
                cout<<i<<", ";
            }
        }
        system("pause");
        return;
    }else{
        //num al 100
        for(int i=numUno;i<=100;i++){
            if(i==100){
                cout<<i<<"\n";
            }else{
                cout<<i<<", ";
            }
        }
        system("pause");
        return;
    }
}

void decreciente(){
    system("cls");
    cout<<"Ingrese un numero entre 20 y 30: ";
    cin>>numUno;
    system("cls");
    cout<<"1. Serie del numero ingresado al 1\n";
    cout<<"2. Serie del 100 al numero ingresado\n";
    cin>>opcion;
    system("cls");
    if(opcion == 1){
        //num al 1
        for(int i=numUno;i>=1;i--){
            if(i==1){
                cout<<i<<"\n";
            }else{
                cout<<i<<", ";
            }
        }
        system("pause");
        return;
    }else{
        //100 al num
        for(int i=100;i>=numUno;i--){
            if(i==numUno){
                cout<<i<<"\n";
            }else{
                cout<<i<<", ";
            }
        }
        system("pause");
        return;
    }
}

void moneda(){
    system("cls");
    srand((unsigned)time(NULL));
    ladoMoneda=rand()%2+1;
    system("cls");
    if (ladoMoneda == 1){
        cout<<"Ha salido cara.\n";
        system("pause");
        return;
    }else{
        cout<<"Ha salido cruz.\n";
        system("pause");
        return;
    }
}

void dado(){
    system("cls");
    srand((unsigned)time(NULL));
    ladoDado=rand()%6+1;
    system("cls");
    cout<<"Ha Salido la cara: "<<ladoDado<<"\n";
    system("pause");
    return;
}

//Funcion Principal
int main(){
    do{
        system("cls");
        cout<<"Seleccione la accion que quiere realizar: \n";
        cout<<"1. Figuras\n";
        cout<<"2. Series\n";
        cout<<"3. Numeros Aleatorios\n";
        cout<<"4. Salir del Programa\n";
        cin>>seleccion;
        switch (seleccion){
            case 1:
                do{
                    system("cls");
                    cout<<"1. Cuadrado\n";
                    cout<<"2. Rectangulo\n";
                    cout<<"3. Salir al menu anterior.\n";
                    cin>>opcion;
                        switch (opcion){
                            case 1:
                                cuadrado();
                                break;
                            case 2:
                                rectangulo();
                                break;
                            case 3:
                                cout<<"Saliendo al menu anterior...\n";
                                break;
                            default:
                                cout<<"Se ha ingresado una opcion incorrecta.\n";
                                break;
                        }
                }while(opcion != 3);
                break;
            case 2:
                do{
                    system("cls");
                    cout<<"1. Creciente\n";
                    cout<<"2. Decreciente\n";
                    cout<<"3. Salir al menu anterior.\n";
                    cin>>opcion;
                    switch (opcion){
                        case 1:
                            creciente();
                            break;
                        case 2:
                            decreciente();
                            break;
                        case 3:
                            cout<<"Saliendo al menu anterior...\n";
                            break;                        
                        default:
                            cout<<"Se ha ingresado una opcion incorrecta.\n";
                            break;
                    }
                }while(opcion != 3);
                break;
            case 3:
                do{
                    system("cls");
                    cout<<"1. Simular el lanzamiento de una moneda y decir cual de las caras ha caído\n";
                    cout<<"2. Simular el lanzamiento de un dado. Imprimir el numero que ha caído\n";
                    cout<<"3. Regresar al menu anterior\n";
                    cin>>opcion;
                    switch (opcion){
                        case 1:
                            moneda();
                            break;
                        case 2:
                            dado();
                            break;
                        case 3:
                            cout<<"Saliendo al menu anterior...\n";
                            break;
                        default:
                            cout<<"Se ha ingresado una opcion incorrecta.\n";
                            break;                        
                    }
                }while(opcion != 3);
                break;
            case 4:
                system("cls");
                cout<<"Gracias por haber utilizado el programa :)\n";
                break;
            default:
                system("cls");
                cout<<"Se ingreso una opcion invalida.\n";
                break;
        }
    }while(seleccion != 4);
    return 0;
}

/*
Seleccionar los elementos del siguiente menú y realiza las opciones según se indica a
continuación:
1. Figuras
    1. Cuadrado
    Ingresar el lado de un cuadrado y calcular mediante las opciones:
        1. Perímetro
        2. Área
    2. Rectángulo
        Ingresar el lado de un cuadrado y calcular mediante las opciones:
        1. Perímetro
        2. Área
    3. Regresar al menú anterior
2. Series
    1. Creciente
        Ingresar un numero entre 20 y 30, a partir de este valor mostrar la serie de acuerdo
        a lo indicado en el menú:
        1. Serie del 1 al número ingresado
        2. Serie del número ingresado al 100
    2. Decreciente
        Ingresar un número entre 20 y 30, a partir de este valor mostrar la serie de acuerdo
        a lo indicado en el menú:
        1. Serie del número ingresado al 1
        2. Serie del 100 al número ingresado
    3. Regresar al menú anterior
3. Aleatorio    
    1. Simular el lanzamiento de una moneda y decir cuál de las caras ha caído
    2. Simular el lanzamiento de un dado. Imprimir el número que ha caído
    3. Regresar al menú anterior    
4. Salir del Programa 
*/
#include <iostream>
#include <windows.h>

using namespace std;
int main(){
    system("cls");
    int num, opcion, i;
    cout<<"Ingresar un numero entre 20 y 50.\n";
    cin>>num;
    while(num<20 || num>50){
        cout<<"ERROR.\nIngresar un numero entre 20 y 50.\n";
        cin>>num;
    }
    do{
        system("cls");
        cout<<"Seleccione la accion a realizar:\n1. Serie del 1 al numero ingresado\n2. Serie del numero ingresado al 100\n3. Serie del numero ingresado al 1\n4. Salir del programa\n";
        cout<<"Elige una opcion: ";
        cin>>opcion;
        system("cls");
        switch (opcion){
            case 1:
                for(i=1;i<=num;i++){
                    if(i == num){
                        cout<<i<<"\n";
                    }else{
                        cout<<i<<", ";
                    }
                }
                system("pause");
                break;
            case 2:
                for(i=num;i<=100;i++){
                    if(i == 100){
                        cout<<i<<"\n";
                    }else{
                        cout<<i<<", ";
                    }
                }
                system("pause");
                break;
            case 3:
                for(i=num;i>=1;i--){
                    if(i == 1){
                        cout<<i<<"\n";
                    }else{
                        cout<<i<<", ";
                    }
                }
                system("pause");
                break;
            case 4:
                cout<<"Gracias por usar el programa.\n";
                break;
        }   
    }while(opcion !=4);
    return 0;
}

/*
Ingresar un numero entre 20 y 50. A partir de esto, seleccionar los elementos del siguiente menú y
realiza las opciones indicadas:
1. Serie del 1 al número ingresado
2. Serie del número ingresado al 100
3. Serie del número ingresado al 1
4. Salir del programa
Elige una opción: 
*/
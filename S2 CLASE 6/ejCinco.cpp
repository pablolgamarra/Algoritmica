#include <iostream>
#include <windows.h>

using namespace std;

void elementsCty(int &);

void chargeArray(int *, int, int *, int &);

void printArray(int*, int);

void selectOption(int &);

void menu(int &, int*, int*, int*, int*, int, int, int, int);

main(){
    int nA, nB, nC, summatory=0, *A, *B, *C, *D, dCount=1, option;
    //Creacion de D
    D= new int[summatory];
    system("cls");
    cout<<"Cargar tres vectores. El programa cargada un cuarto vector con los elementos de los otros tres en forma ordenada.\n";
    //Carga de A
    cout<<"Vector A.\n";
    elementsCty(nA);
    summatory=summatory+nA;
    A= new int[nA];
    chargeArray(A, nA, D, dCount);
    //Carga de B
    system("cls");
    cout<<"Vector B.\n";
    elementsCty(nB);
    summatory=summatory+nB;
    B= new int[nB];
    chargeArray(B, nB, D, dCount);
    //Carga de C
    system("cls");
    cout<<"Vector C.\n";
    elementsCty(nC);
    summatory=summatory+nC;
    C= new int[nC];
    chargeArray(C, nC, D, dCount);
    //Menu de Opciones
    do{
        menu(option, A, B, C, D, nA, nB, nC, summatory);
    }while(option != 6);
    system("pause");
    return 0; 
}

void elementsCty(int &n){
    cout<<"Ingrese la cantidad de elementos que tendra el vector: ";
    cin>>n;
    while(n<=0){
        cout<<"Debe tener al menos un elemento.\n";
        cout<<"Ingrese la cantidad de elementos que tendra el vector: ";
        cin>>n;
    }
    return;
}

void chargeArray(int *array, int limit, int *D, int &dCount){
    system("cls");
    for(int i=1; i<=limit; i++){
        cout<<"Carga de Datos. Posicion ("<<i<<").\n";
        cout<<"Valor: ";
        cin>>*(array+i);
        *(D+dCount)=*(array+i);
        dCount++;
    }
    return;
}

void printArray(int *array, int limit){
    for(int i=1; i<=limit; i++){
        if(i==limit){
            cout<<*(array+i)<<"\n";
        }else{
            cout<<*(array+i)<<" || ";
        }
    }
    system("pause");
    return;
}

void selectOption(int &option){ 
    system("cls");
    cout<<"Seleccione la accion que desea realizar.\n";
    cout<<"1. Imprimir vector 'A'.\n";
    cout<<"2. Imprimir vector 'B'.\n";
    cout<<"3. Imprimir vector 'C'.\n";
    cout<<"4. Imprimir vector 'D'.\n";
    cout<<"5. Imprimir todos los vectores'.\n";
    cout<<"6. Salir del Programa.\n";
    cout<<"Opcion: ";
    cin>>option;
    while(option < 1 || option > 6){
        system("cls");
        cout<<"Seleccione una opcion valida!\n";
        cout<<"Seleccione la accion que desea realizar.\n";
        cout<<"1. Imprimir vector 'A'.\n";
        cout<<"2. Imprimir vector 'B'.\n";
        cout<<"3. Imprimir vector 'C'.\n";
        cout<<"4. Imprimir vector 'D'.\n";
        cout<<"5. Imprimir todos los vectores'.\n";
        cout<<"6. Salir del Programa.\n";
        cout<<"Opcion: ";
        cin>>option;
    }
    return;
}

void menu(int &option, int *A, int*B, int *C, int *D, int nA, int nB, int nC, int summatory){
    selectOption(option);
    system("cls");
    switch(option){
        case 1:
        printArray(A, nA);
        break;
        case 2:
        printArray(B, nB);
        break;
        case 3: 
        printArray(C, nC);
        break;
        case 4:
        printArray(D, summatory);
        break;
        case 5:
        cout<<"Vector 'A'.\n";
        printArray(A, nA);
        cout<<"Vector 'B'.\n";
        printArray(B, nB);
        cout<<"Vector 'C'.\n";
        printArray(C, nC);
        cout<<"Vector 'D'.\n";
        printArray(D, summatory);
        break;
        case 6:
        cout<<"Gracias por usar el programa.\n";
        break;
    }
    return;
}
/*
Crear los vectores dinámicos A, B, C, y D, cargar los vectores A, B, C y con los mismos elementos cargar en
forma ordenada el vector D. Utiliza un menú para imprimir los siguientes datos:
1- Imprimir vector A
2- Imprimir vector B
3- Imprimir Vector C
4- Imprimir Vector D
5- Imprimir Todos los Vectores 
*/
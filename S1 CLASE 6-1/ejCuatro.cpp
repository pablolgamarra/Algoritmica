#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int cantAlumnos,edad,i,mayores=0,sw=0;
    string nombre="";
    cout<<"Ingrese la cantidad de alumnos del Tercer Curso: ";
    cin>>cantAlumnos;
    while(cantAlumnos<0){
        cout<<"Ingrese la cantidad de alumnos del Tercer Curso: ";
        cin>>cantAlumnos;
    }
    for(i=1;i<=cantAlumnos;i++){
        system("cls");
        cout<<"Ingrese el nombre del "<<i<<" alumno: ";
        cin>>nombre;
        cout<<"Ingrese la edad del mismo: ";
        cin>>edad;
        if(edad>=18){
            sw=1;
            mayores++;
        }
    }
    if(sw==1){
        cout<<"Existen "<<mayores<<" alumnos mayores de edad.\n";
    }else{
        cout<<"No existen alumnos mayores de edad. \n";
    }
    system("pause");
    return 0;
}

/*Crea un pseudocódigo que ingrese el nombre y la edad de los alumnos del 3er curso de un
colegio. Decir si entre ellos existe un alumno mayor de edad. */
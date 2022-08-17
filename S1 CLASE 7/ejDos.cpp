#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    string nombre="";
    int calif,suma=0,i,promedio,sw=0;
    cout<<"Ingrese las calificaciones de un alumno y el programa determinara si el mismo aprobo el curso.\n";
    cout<<"Ingrese el nombre del alumno: ";
    cin>>nombre;
    for(i=1;i<=10;i++){
        system("cls");
        cout<<"Ingrese la calificacion de la "<<i<<" materia. \n";
        cin>>calif;
        while(calif<0 || calif>5){
            cout<<"ERROR. Las calificaciones deben ser numeros enteros positivos entre 1 y 5.\n";
            cout<<"Ingrese la calificacion de la "<<i<<" materia. \n";
            cin>>calif;
        }
        suma=suma+calif;
    }
    promedio=suma/10;
    if(promedio == 1){
        sw=1;
    }else if (promedio>=2 ){
        sw=0;
    }
    if(sw == 1){
        system("cls");
        cout<<"El alumno: "<<nombre<<" no aprobo el curso.\nSu promedio de calificaciones es: "<<promedio<<"\n";
    }else{
        system("cls");
        cout<<"El alumno: "<<nombre<<" aprobo el curso.\nSu promedio de calificaciones es: "<<promedio<<"\n";
    }
    system("pause");
    return 0;
}

/*
Se desea cargar las calificaciones de un alumno en las 10 materias que asiste en su curso. Donde, se registra el
nombre del alumno, la materia y calificación correspondiente. Se desea saber:
- El promedio de calificaciones
- Si el alumno aprobó o reprobó el curso (utiliza un sw para verificar dicho proceso) 
*/
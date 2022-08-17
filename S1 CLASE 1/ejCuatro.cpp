#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int c1,c2 ,c3,prom;

int main(){
    system("cls");

    cout<<"Ingrese la primera calificacion :" << endl;
    cin>>c1;

    cout<<"Ingrese la segunda calificacion: "<< endl;
    cin>>c2;

    cout<<"Ingrese la tercera calificacion: "<< endl;
    cin>>c3;

    prom= (c1+c2+c3)/3;

    cout<<"Las Calificaciones ingresadas fueron: " << c1 << ", " << c2 << ", " << c3 << " y el promedio es: " << prom << endl;

    system("pause");

    return 0;

}
#include <iostream>
#include <conio.h>

using namespace std;

void cantPersonas(int &);

main(){
    int n;
    cantPersonas(n);
    struct Personas
    {
        int cedula;
        string nombre;
        string apellido;
        string direccion;
        int edad;
    }Persona[n];
    cout<<"Programa para cargar los datos de "<<n<<" personas.\n";
    for(int i=0; i<n;i++){
        cout<<"Ingrese los datos de Persona "<<i+1<<"\n";
        cout<<"Ingrese Numero de Cedula: ";
        cin>>Persona[i].cedula;
        cout<<"Ingrese Nombre: ";
        cin>>Persona[i].nombre;
        cout<<"Ingrese Apellido: ";
        cin>>Persona[i].apellido;
        cout<<"Ingrese Direccion: ";
        cin>>Persona[i].direccion;
        cout<<"Ingrese Edad: ";
        cin>>Persona[i].edad;       
    }
    cout<<"Presione una tecla para Imprimir la estructura Cargada...\n";
    getch();
    for(int i=0; i<n;i++){
        cout<<"***********************************************\n";
        cout<<"Persona "<<i+1<<"\n";
        cout<<"Numero de Cedula: "<<Persona[i].cedula<<"\n";
        cout<<"Nombre: "<<Persona[i].nombre<<"\n";
        cout<<"Apellido: "<<Persona[i].apellido<<"\n";
        cout<<"Direccion: "<<Persona[i].direccion<<"\n";
        cout<<"Edad: "<<Persona[i].edad<<"\n";       
    }
    getch();
    return 0;
}

void cantPersonas(int &n){
    do{
        cout<<"Ingrese la cantidad de personas cuyos datos desea cargar: ";
        cin>>n;    
    }while(n<=0);    
}

/*
Crear la estructura Personas con “n” elementos, cuyos campos serán los siguientes:
Cedula Nombre Apellido Direccion Edad
Imprimir la estructura cargada y decir cuántos de los cargados fueron mayores y
menores de edad.
*/
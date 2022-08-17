#include <iostream>
#include <windows.h>

using namespace std;

bool errorCarga(void);
bool tieneNum(string);
void cantPersonas(int &);

struct Personas{
    int cedula;
    string nombre;
    string apellido;
    string direccion;
    int edad;
};


main(){
    int n, menores=0;
    system("cls");
    cout<<"Programa para cargar datos de personas y analizar cuales de los cargados fueron de menores de edad.\n";
    cantPersonas(n);
    Personas persona[n];
    for(int i=0; i<n;i++){
        system("cls");
        cout<<"Carga de Datos. Persona "<<i+1<<"\n";
        cout<<"Numero de Cedula: ";
        cin>>persona[i].cedula;
        while(errorCarga() || persona[i].cedula<=0){
            if(persona[i].cedula<=0){
                cout<<"Ha ocurrido un error, el numero de cedula ingresado no es valido. Vuelva a cargar!.\n";
            }
            if(errorCarga()){
                cout<<"Ha ocurrido un error en la carga. Vuelva a cargar!.\n";
            }
            cout<<"Numero de Cedula: ";
            cin>>persona[i].cedula;
            fflush(stdin);
        }
        cout<<"Nombre: ";
        getline(cin, persona[i].nombre);
        while(errorCarga() || tieneNum(persona[i].nombre) || persona[i].nombre == ""){
            cout<<"El nombre ingresado no es valido. Vuelva a cargar!.\n";
            cout<<"Nombre: ";
            getline(cin, persona[i].nombre);        
            fflush(stdin);
        }
        cout<<"Apellido: ";
        getline(cin, persona[i].apellido);
        while(errorCarga() || tieneNum(persona[i].nombre) ||persona[i].apellido == ""){
            cout<<"El apellido ingresado no es valido. Vuelva a cargar!.\n";
            cout<<"Apellido: ";
            getline(cin, persona[i].apellido);        
            fflush(stdin);
        }
        cout<<"Direccion: ";
        getline(cin, persona[i].direccion);
        while(persona[i].direccion == ""){
            cout<<"La direccion cargada no es valida. Vuelva a cargar!.\n";
            cout<<"Direccion: ";
            getline(cin, persona[i].direccion);        
            fflush(stdin);
        }
        cout<<"Edad: ";
        cin>>persona[i].edad;
        while(errorCarga() || persona[i].edad<=0 || persona[i].edad >=150){
            cout<<"Ha ocurrido un error en la carga. Vuelva a cargar!.\n";
            cout<<"Nombre: ";
            cin>>persona[i].edad;        
            fflush(stdin);
        }
        if(persona[i].edad < 18){
            menores++;
        }
    }
    cout<<"Datos Cargados:\n";
    for(int i=0; i<n;i++){
        cout<<"Persona "<<i+1<<"\n";
        cout<<"Cedula: "<<persona[i].cedula<<"\n";
        cout<<"Nombre: "<<persona[i].nombre<<"\n";
        cout<<"Apellido: "<<persona[i].apellido<<"\n";
        cout<<"Direccion: "<<persona[i].direccion<<"\n";
        cout<<"Edad: "<<persona[i].edad<<"\n";
        cout<<"========================================\n";
    }
    cout<<"Se ingresaron los datos de: "<<menores<<" personas menores de edad.\n";
    system("pause");
    return 0;
}


bool errorCarga(void)
{
    bool error = false;
    if (cin.fail())
    {
        cin.clear();
        fflush(stdin);
        error = true;
    }
    else
    {
        error = false;
    }
    return error;
}

bool tieneNum(string cadena)
{
    for (char letra : cadena)
    {
        if (isdigit(letra) != 0)
        {
            return true;
        }
    }
    return false;
}

void cantPersonas(int &n){
    do{
    cout<<"Ingrese la cantidad de personas cuyos datos va a cargar: ";
    cin>>n;
    while(errorCarga()){
        cout<<"Ha ocurrido un error en la carga. Vuelva a ingresar dato: ";
        cin>>n;
    }
    }while(n<=0);
}

/*
Crear la estructura Personas con “n” elementos, cuyos campos serán los siguientes:
Cedula Nombre Apellido Direccion Edad
Imprimir la estructura cargada y decir cuántos de los cargados fueron mayores y
menores de edad.
*/
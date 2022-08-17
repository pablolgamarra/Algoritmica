#include <iostream>
#include <windows.h>

using namespace std;

bool errorCarga(void);
bool tieneNum(string);


struct Personas{
    int cedula;
    string nombre;
    string apellido;
    string direccion;
    int edad;
}persona[10];


main(){
    cout<<"Programa para cargar datos de 10 personas.\n";
    for(int i=0; i<10;i++){
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
        cout<<"\nApellido: ";
        getline(cin, persona[i].apellido);
        while(errorCarga() || tieneNum(persona[i].nombre) ||persona[i].apellido == ""){
            cout<<"El apellido ingresado no es valido. Vuelva a cargar!.\n";
            cout<<"Apellido: ";
            getline(cin, persona[i].apellido);        
            fflush(stdin);
        }
        cout<<"\nDireccion: ";
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
    }
    cout<<"Datos Cargados:\n";
    for(int i=0; i<10;i++){
        cout<<"Persona "<<i+1<<"\n";
        cout<<"Cedula: "<<persona[i].cedula;
        cout<<"Nombre: "<<persona[i].nombre;
        cout<<"Apellido: "<<persona[i].apellido;
        cout<<"Direccion: "<<persona[i].direccion;
        cout<<"Edad: "<<persona[i].edad;
    }
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

/*
Crear la estructura Personas con 10 elementos cuyos campos serán los siguientes:
Cedula Nombre Apellido Direccion Edad
Imprimir la estructura cargada
*/

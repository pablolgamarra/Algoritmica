//Inclusión de Bibliotecas
#include <iostream>
#include <windows.h>

//Declaracion de espacios de nombres
using namespace std;

//Declaración de Estructura usada
struct Usuarios
{
    string nombre = "";
    string apellido = "";
    int cedula = 0;
    int edad = 0;
    char genero = {'M'};
};

//Prototipos de Funciones Usadas
string convertirMayus(string);
void cargaEstructura(Usuarios *, int, int &, int &);
void seleccionOpcion(int &);
void menoresMayores(int, int);
void mostrarGenero(Usuarios *);
void menu(Usuarios *, int, int, int, int);

//Funcion Principal
int main()
{
    //Declaracion de Variables Utilizadas
    int cant = 0, opcion = 0, cantMayores = 0, cantMenores = 0;
    system("cls");
    cout << "Programa para cargar datos de usuario.\n";
    cout << "Ingrese la cantidad de usuarios: ";
    cin >> cant;
    //Asignacion de Estructuras de Datos
    Usuarios usuarios[cant], *usuario = usuarios;
    //Carga de los Datos
    cargaEstructura(usuario, cant, cantMayores, cantMenores);
    //Mostrar Menu y Ejecutar la opcion seleccionada
    menu(usuario, opcion, cantMenores, cantMayores, cant);
    system("pause");
    return 0;
}

string convertirMayus(string cadena)
{
    string frase = "";
    for (int i=0; i<cadena.length(); i++)
    {
        frase+=toupper(cadena[i]);
    }
    return frase;
}

void cargaEstructura(Usuarios *usuario, int cant, int &cantMayores, int &cantMenores)
{
    for (int i = 0; i < cant; i++)
    {
        system("cls");
        cout << "Carga de Datos.\nUsuario " << i + 1 << ".\n";
        //Carga y Validación de Numero de Cedula
        do
        {
            cout << "Ingrese el numero de cedula: ";
            cin >> usuario[i].cedula;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore();
                cout << "Ha ocurrido un error en la carga.\nVuelva a cargar.\n";
                cout << "Ingrese numero de cedula: ";
                cin >> usuario[i].cedula;
            }
            while (usuario[i].cedula <= 0)
            {
                cin.clear();
                cin.ignore();
                cout << "Error.El numero de cedula no debe tener signos.";
                cout << "Vuelva a cargar.\nIngrese numero de cedula: ";
                cin >> usuario[i].cedula;
            }
        } while (!cin.good());
        //Carga y Validación de Nombre
        do
        {
            cin.clear();
            cout << "Ingrese el nombre: ";
            getline(cin, usuario[i].nombre);
            cin.ignore();
            while (!cin.good())
            {
                cout << "Ha ocurrido un error en la carga.\n";
                cout << "Vuelva a ingresar nombre: ";
                getline(cin, usuario[i].nombre);
                cin.ignore();
                cin.clear();
            }
            // while (usuario[i].nombre.length() <= 0)
            // {
            //     cout << "Se debe ingresar un nombre valido.\n";
            //     cout << "Vuelva a ingresar nombre: ";
            //     getline(cin, usuario[i].nombre);
            //     cin.ignore();
            // }
        } while (!cin.good());
        usuario[i].nombre=convertirMayus(usuario[i].nombre);
        //Carga y Validación de Apellido
        do
        {
            cin.clear();
            cout << "Ingrese el apellido: ";
            getline(cin, usuario[i].apellido);
            cin.ignore();
            while (!cin.good())
            {
                cout << "Ha ocurrido un error en la carga.\n";
                cout << "Vuelva a ingresar apellido: ";
                getline(cin, usuario[i].apellido);
                cin.ignore();
                cin.clear();
            }
            // while (usuario[i].apellido.length() <= 0)
            // {
            //     cout << "Se debe ingresar un apellido valido.\n";
            //     cout << "Vuelva a ingresar apellido: ";
            //     getline(cin, usuario[i].apellido);
            //     cin.ignore();
            //     cin.clear();
            // }
        } while (!cin.good());
        usuario[i].apellido=convertirMayus(usuario[i].apellido);
        //Carga y Validación de Edad
        do
        {
            cout << "Ingrese edad: ";
            cin >> usuario[i].edad;
            cin.ignore();
            while (!cin.good())
            {
                cin.clear();
                cin.ignore();
                cout << "Ha ocurrido un error en la carga.\nVuelva a cargar.\n";
                cout << "Ingrese edad: ";
                cin >> usuario[i].edad;
            }                
            while (usuario[i].edad <= 0)
            {
                cin.clear();
                cin.ignore();
                cout << "Error.La edad cargada no debe tener signos.";
                cout << "Vuelva a cargar.\nIngrese edad: ";
                cin >> usuario[i].edad;
            }
        } while (!cin.good());
        //Obtencion de los Menores y Mayores de Edad
        if (usuario[i].edad < 18)
        {
            ++cantMenores;
        }
        else
        {
            ++cantMayores;
        }
        //Carga y Validación de Genero
        do
        {
            cin.clear();
            cin.ignore();
            cout << "Ingrese Genero[M/F]: ";
            cin >> usuario[i].genero;
            if (usuario[i].genero == 'M')
            {
                usuario[i].genero = 'm';
            }
            else if (usuario[i].genero == 'F')
            {
                usuario[i].genero = 'f';
            }
            while (!cin.good())
            {
                cout << "Ha ocurrido un error en la carga.\n";
                cout << "Vuelva a ingresar Genero [M/F]: ";
                cin >> usuario[i].genero;
            }
            while (usuario[i].genero != 'M' && usuario[i].genero != 'F' && usuario[i].genero != 'm' && usuario[i].genero != 'f')
            {
                cout << "El valor ingresado no es valido.\n";
                cout << "Ingrese Género[M/F]: ";
                cin >> usuario[i].genero;
            }
            if (usuario[i].genero == 'M')
            {
                usuario[i].genero = 'm';
            }
            else if (usuario[i].genero == 'F')
            {
                usuario[i].genero = 'f';
            }
        } while (!cin.good());
    }
    return;
}

void seleccionOpcion(int &opcion)
{
    //Seleccion y Validacion de la Opcion
    do
    {
        system("cls");
        cout << "Seleccione el numero que corresponde a la accion que desea realizar.\n";
        cout << "1- Mostrar la estructura cargada\n";
        cout << "2- Mostrar la lista por género, ya sea (F o M)\n";
        cout << "3- Cantidad de Mayores y menores de Edad\n";
        cout << "4- Salir del Programa\n";
        cin >> opcion;
        while (!cin.good())
        {
            system("cls");
            cout << "Ha ocurrido un error en la carga.\n";
            cout << "Vuelva a seleccionar opcion.\n";
            cout << "1- Mostrar la estructura cargada\n";
            cout << "2- Mostrar la lista por género, ya sea (F o M)\n";
            cout << "3- Cantidad de Mayores y menores de Edad\n";
            cout << "4- Salir del Programa\n";
            cin >> opcion;
        }
    } while (opcion < 1 || opcion > 4);
    return;
}

void mostrarEstructura(Usuarios *usuario, int cant)
{
    //Impresion en consola de la estructura cargada
    system("cls");
    cout << "Se mostrara la estructura cargada.\n";
    for (int i = 0; i < cant; i++)
    {
        cout << "Nombre: " << usuario[i].nombre << "\n";
        cout << "Apellido: " << usuario[i].apellido << "\n";
        cout << "Numero de Cedula: " << usuario[i].cedula << "\n";
        cout << "Edad: " << usuario[i].edad << "\n";
        cout << "Genero: " << usuario[i].genero << "\n";
    }
    return;
}

void mostrarGenero(Usuarios *usuario, int cant)
{
    system("cls");
    char genero;
    //Obtencion del Genero que se desea filtrar
    do
    {
        cout << "Seleccione el genero por el que desea clasificar la lista [F/M]: ";
        cin >> genero;
    } while (genero != 'f' && genero != 'm' && genero != 'F' && genero != 'M');
    //Impresion de los Datos de acuerdo a la filtración
    for (int i = 0; i < cant; i++)
    {
        if (usuario[i].genero == genero)
        {
            system("cls");
            cout << "Nombre: " << usuario[i].nombre << "\n";
            cout << "Apellido: " << usuario[i].apellido << "\n";
            cout << "Numero de Cedula: " << usuario[i].cedula << "\n";
            cout << "Edad: " << usuario[i].edad << "\n";
            cout << "Genero: " << usuario[i].genero << "\n";
        }
    }
    return;
}

void menoresMayores(int menores, int mayores)
{
    system("cls");
    cout << "La cantidad total de usuarios cargados es: " << menores + mayores << "\n";
    cout << "De estos.\n"
         << menores << "Son menores.\n"
         << mayores << "Son mayores.\n";
    return;
}

void menu(Usuarios *usuario, int opcion, int cantMenores, int cantMayores, int cant)
{
    do
    {
        //Seleccion de la Opcion a ejecutarse
        seleccionOpcion(opcion);
        //Ejecucion de la Alternativa Seleccionada
        switch (opcion)
        {
        case 1:
            mostrarEstructura(usuario, cant);
            break;
        case 2:
            mostrarGenero(usuario, cant);
            break;
        case 3:
            menoresMayores(cantMenores, cantMayores);
            break;
        case 4:
            cout << "Gracias por usar el programa.\n";
            break;
        default:
            cout << "La opcion seleccionada no es valida.\n";
            break;
        }
        system("pause");
    } while (opcion != 4);
    return;
}
/*
Crear un programa que permita almacenar los datos principales de un usuario cualquiera en
una estructura estática. Los datos a almacenar son los siguientes:
- Cedula
- Nombre
- Apellido
- Edad
- Género (M = Masculino y F = Femenino)
Luego, mostrar el siguiente menú para realizar las siguientes consultas:
1 – Mostrar la estructura cargada
2 – Mostrar la lista por género, ya sea (F o M)
3 – Cantidad de Mayores y menores de Edad
4 – Salir del Programa 

Para tener en cuenta: los nombres y apellidos, deben ser almacenados en mayúsculas,
por lo tanto, si el usuario escribe en minúsculas, el programa debe encargarse de
transformar en mayúsculas antes de guardar los datos 
*/
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void pausar(void);
bool tieneNum(string);
bool errorCarga(void);
void cantDatos(int &);
void cargaAlumnos(int, struct Alumnos *);
void mostrarEstructura(int n, struct Alumnos *);
void cantAlumnos(int n, struct Alumnos *);
void cantMF(int n, struct Alumnos *);
void cantMenores(int n, struct Alumnos *);
void promedioEdades(int n, struct Alumnos *);
bool saliroSeguir(bool &);
void selectorOpcion(int &);
void menu(int, int &, struct Alumnos *);

struct Alumnos
{
    int cedula;
    string nombre;
    string apellido;
    int genero;
    int edad;
    int carrera;
} alumnos, *ptrAlumnos = &alumnos;

main()
{
    int n, opcion = 0;
    system("cls");
    cout << "Programa de Control de Estudiantes Universitarios.\n";
    cantDatos(n);
    cargaAlumnos(n, ptrAlumnos);
    menu(n, opcion, ptrAlumnos);
    ptrAlumnos = NULL;
    delete ptrAlumnos;
    return 0;
}

void pausar(){
    cout<<"Presione una tecla para seguir.\n";
    getch();
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

void cantDatos(int &n)
{
    do
    {
        cout << "Ingrese la cantidad de alumnos que cargara: ";
        cin >> n;
        while (errorCarga())
        {
            cout << "Ha ocurrido un error en la carga de datos.\n";
            cout << "Se debe ingresar un dato numerico entero.\n";
            cout << "Vuelva a ingresar cantidad de alumnos a cargar: ";
            cin >> n;
        }
        while (n <= 0)
        {
            cout << "Error!. Debe ingresar un numero mayor a cero.\n";
            cout << "Vuelva a ingresar cantidad de alumnos a cargar: ";
            cin >> n;
        }
    } while (errorCarga());
    return;
}

void cargaAlumnos(int n, struct Alumnos *ptrAlumnos)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Carga de Datos. Alumno " << i + 1 << "\n";
        cout << "Numero de Cedula: ";
        cin >> ptrAlumnos->cedula;
        do
        {
            while (errorCarga())
            {
                cout << "Deben ingresarse numeros enteros. Vuelva a cargar.\n";
                cout << "Numero de Cedula: ";
                cin >> ptrAlumnos->cedula;
            }
            while (ptrAlumnos->cedula <= 0)
            {
                cout << "Deben ingresarse numeros mayores a '0'.Vuelva a cargar.\n";
                cout << "Numero de Cedula: ";
                cin >> ptrAlumnos->cedula;
            }
        } while (errorCarga());
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, ptrAlumnos->nombre);
        while (tieneNum(ptrAlumnos->nombre) || errorCarga())
        {
            cout << "Debe ingresarse una cadena sin numeros. Vuelva a ingresar.\n";
            cout << "Nombre: ";
            getline(cin, ptrAlumnos->nombre);
        }
        cout << "Apellido: ";
        cin.ignore();
        getline(cin, ptrAlumnos->apellido);
        while (tieneNum(ptrAlumnos->apellido) || errorCarga())
        {
            cout << "Debe ingresarse una cadena sin numeros. Vuelva a ingresar.\n";
            cout << "Apellido: ";
            getline(cin, ptrAlumnos->apellido);
        }
        cout << "\nGenero 1-Femenino  2-Masculino \n";
        cout << "Genero: ";
        cin >> ptrAlumnos->genero;
        do{
            while (errorCarga())
            {
                cout << "Deben ingresarse numeros enteros. Vuelva a cargar.\n";
                cout << "Genero 1-Femenino  2-Masculino \n";
                cout << "Genero: ";
                cin >> ptrAlumnos->genero;
            }
            while (ptrAlumnos->genero < 1 || ptrAlumnos->genero > 2)
            {
                cout << "Deben ingresarse numeros en el rango permitido. Vuelva a cargar.\n";
                cout << "Genero 1-Femenino  2-Masculino \n";
                cout << "Genero: ";
                cin >> ptrAlumnos->genero;
            }
        }while(errorCarga());
        cout << "Edad: ";
        cin >> ptrAlumnos->edad;
        do
        {
            while (errorCarga())
            {
                cout << "Deben ingresarse numeros enteros. Vuelva a cargar.\n";
                cout << "Edad: ";
                cin >> ptrAlumnos->edad;
            }
            while (ptrAlumnos->edad <= 0)
            {
                cout << "Deben ingresarse numeros mayores a '0'.Vuelva a cargar.\n";
                cout << "Edad: ";
                cin >> ptrAlumnos->edad;
            }
        } while (errorCarga());
        cout << "Carreras 1- Informatica. 2- Administracion. 3- Contabilidad. 4- Medicina\n";
        cout << "Carerra: ";
        cin >> ptrAlumnos->carrera;
        do{
            while (errorCarga())
            {
                cout << "Deben ingresarse numeros enteros. Vuelva a cargar.\n";
        cout << "Carreras 1- Informatica. 2- Administracion. 3- Contabilidad. 4- Medicina\n";
        cout << "Carerra: ";
                cin >> ptrAlumnos->genero;
            }
            while (ptrAlumnos->carrera < 1 || ptrAlumnos->carrera > 4)
            {
                cout << "Deben ingresarse numeros en el rango permitido. Vuelva a cargar.\n";
        cout << "Carreras 1- Informatica. 2- Administracion. 3- Contabilidad. 4- Medicina\n";
        cout << "Carerra: ";
                cin >> ptrAlumnos->carrera;
            }
        }while(errorCarga());
    }
}

void selectorOpcion(int &opcion)
{
    do
    {
        cout << "Seleccione el numero que corresponde a la acción que quiere realizar.\n";
        cout << "1. Mostrar la estructura cargada\n";
        cout << "2. Cantidad de alumnos que estudian las diferentes carreras\n";
        cout << "3. Cantidad de alumnos Masculinos y Femeninos\n";
        cout << "4. Cantidad de Alumnos menores de edad que estudian Informatica\n";
        cout << "5. Promedio de edades de los alumnos en las distintas carreras\n";
        cout << "6. Salir o Regresar al Menu\n";
        cout << "Opcion Seleccionada: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 6);
}

void mostrarEstructura(int n, struct Alumnos *ptrAlumnos)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Alumno " << i + 1 << "\n";
        cout << "Numero de Cedula: " << ptrAlumnos->cedula << "\n";
        cout << "Nombre: " << ptrAlumnos->nombre << "\n";
        cout << "Apellido: " << ptrAlumnos->apellido << "\n";
        cout << "Genero: ";
        ptrAlumnos->genero == 1 ? cout << "Femenino\n" : cout << "Masculino\n";
        cout << "Edad: " << ptrAlumnos->edad << "\n";
        cout << "Carerra: ";
        switch ((ptrAlumnos->carrera))
        {
        case 1:
            cout << "Informatica\n";
            break;
        case 2:
            cout << "Contabilidad\n";
            break;
        case 3:
            cout << "Administracion\n";
            break;
        case 4:
            cout << "Medicina\n";
            break;
        default:
            cout << "La carrera que se cargo no es valida o no existe.\n";
            break;
        }
    }
}

void cantAlumnos(int n, struct Alumnos *ptrAlumnos)
{
    int cantAlumnos[4] = {0, 0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        switch (ptrAlumnos->carrera)
        {
        case 1:
            cantAlumnos[0] = cantAlumnos[0] + 1;
            break;
        case 2:
            cantAlumnos[1] = cantAlumnos[1] + 1;
            break;
        case 3:
            cantAlumnos[2] = cantAlumnos[2] + 1;
            break;
        case 4:
            cantAlumnos[3] = cantAlumnos[3] + 1;
            break;
        default:
            cout << "La carrera que se cargo no es valida o no existe.\n";
            break;
        }
    }
    cout << "Hay " << n << " alumnos en total. De los cuales: \n";
    cout << cantAlumnos[0] << " estudian Informatica.\n";
    cout << cantAlumnos[1] << " estudian Administracion.\n";
    cout << cantAlumnos[2] << " estudian Contabilidad.\n";
    cout << cantAlumnos[3] << " estudian Medicina.\n";
}

void cantMF(int n, struct Alumnos *ptrAlumnos)
{
    int cantMF[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        ((ptrAlumnos->genero) == 1) ? cantMF[0] = cantMF[0] + 1 : cantMF[1] = cantMF[1]+1;
    }
    cout << "Hay: " << n << " alumnos en total. De los cuales: \n";
    cout << cantMF[0] << " son de genero Femenino\n";
    cout << cantMF[1] << " son de genero Masculino\n";
}

void cantMenores(int n, struct Alumnos *ptrAlumnos)
{
    int cantMenores = 0;
    for (int i = 0; i < n; i++)
    {
        ((ptrAlumnos->edad) < 18) ? cantMenores++ : cantMenores = cantMenores;
    }
    cout << "Hay " << n << " alumnos. De los cuales:\n"
         << cantMenores << " son menores de edad.\n";
}

bool saliroSeguir(bool &salir)
{
    int op = 1;
    cout << "1- Salir del Programa.\n";
    cout << "2- Regresar al Menu.\n";
    cout << "Seleccion: ";
    cin >> op;
    op == 1 ? salir = true: salir = false;
}

void promedioEdades(int n, struct Alumnos *ptrAlumnos)
{
    int promedioEdades = 0;
    for (int i = 0; i < n; i++)
    {
        promedioEdades += ptrAlumnos->edad;
    }
    cout << "La edad promedio de los alumnos de la Facultad es: " << (promedioEdades / n) << "\n";
}

void menu(int n, int &opcion, struct Alumnos *ptrAlumnos)
{
    bool salir = false;
    do
    {
        system("cls");
        selectorOpcion(opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            cout << "Opcion Seleccionada: " << opcion << "\n";
            mostrarEstructura(n, ptrAlumnos);
            pausar();
            break;
        case 2:
            cout << "Opcion Seleccionada: " << opcion << "\n";
            cantAlumnos(n, ptrAlumnos);
            pausar();
            break;
        case 3:
            cout << "Opcion Seleccionada: " << opcion << "\n";
            cantMF(n, ptrAlumnos);
            pausar();
            break;
        case 4:
            cout << "Opcion Seleccionada: " << opcion << "\n";
            cantMenores(n, ptrAlumnos);
            pausar();
            break;
        case 5:
            cout << "Opcion Seleccionada: " << opcion << "\n";
            promedioEdades(n, ptrAlumnos);
            pausar();
            break;
        case 6:
            cout << "Opcion Seleccionada: " << opcion << "\n";
            saliroSeguir(salir);
            if(salir) cout<<"Gracias por usar el programa.\n";
            break;
        }
    } while (!salir);
}

/*
Crear la estructura Alumnos con “n” elementos. Cuyos campos son:
Cédula  Nombre  Apellido    Genero  Edad    Carrera
Dónde: - Genero se representará con los datos: 1- Femenino, 2 - Masculino
- Curso se representará con los datos: 1 – Informatica, 2 – Administracion, 3 – Contabilidad, 4 – Medicina
Crear un programa que permita seleccionar los elementos del siguiente menú:
- Opción 1: Mostrar la estructura cargada
- Opción 2: Cantidad de alumnos que estudian las diferentes carreras
- Opción 3: Cantidad de alumnos Masculinos y Femeninos
- Opción 4: Cantidad de Alumnos menores de edad que estudian Informatica
- Opción 5: Promedio de edades de los alumnos en las distintas carreras.
- Opción 6: 1 – Salir, 2 – Volver al menú.
  Asegurarse de validar todas las opciones de ingreso.
*/
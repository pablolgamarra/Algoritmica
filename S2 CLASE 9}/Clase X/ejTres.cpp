#include <iostream>
#include <conio.h>

using namespace std;

void cantElementos(int &);

void seleccionOp(int &);

main()
{
    int n, opcion, op_salida, cant_alumnos[4]{0, 0, 0, 0}, cant_MYF[2]{0, 0}, cantMenores = 0, promedio_Edades[4]{0, 0, 0, 0};
    bool salir = false;
    cantElementos(n);
    struct Alumnos
    {
        int cedula;
        string nombre;
        string apellido;
        int genero;
        int edad;
        int carrera;
    } alumno[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Carga de Datos.\nAlumno " << i + 1 << ".\n";
        do
        {
            cout << "Ingrese Numero de Cedula: ";
            cin >> alumno[i].cedula;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "El dato ingresado debe ser un numero entero.\n";
                cout << "Vuelva a ingresar: ";
                cin >> alumno[i].cedula;
            }
        } while (alumno[i].cedula <= 0);
        do
        {
            cout << "Ingrese Nombre: ";
            cin >> alumno[i].nombre;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "El dato ingresado debe ser una cadena de caracteres.\n";
                cout << "Vuelva a ingresar: ";
                cin >> alumno[i].nombre;
            }
        } while (((alumno[i].nombre).length()) <= 2);
        do
        {
            cout << "Ingrese Apellido: ";
            cin >> alumno[i].apellido;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "El dato ingresado debe ser una cadena de caracteres.\n";
                cout << "Vuelva a ingresar: ";
                cin >> alumno[i].apellido;
            }
        } while ((alumno[i].apellido.length()) < 4);
        do
        {
            cout << "Ingrese Genero: (1)-Masculino (2)-Femenino : ";
            cin >> alumno[i].genero;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "El dato ingresado debe ser un numero entero.\n";
                cout << "Vuelva a ingresar: ";
                cin >> alumno[i].genero;
            }
            cant_MYF[(alumno[i].genero) - 1] = cant_MYF[(alumno[i].genero) - 1] + 1;
        } while (alumno[i].genero <= 0 || alumno[i].genero > 2);
        do
        {
            cout << "Ingrese edad:";
            cin >> alumno[i].edad;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "El dato ingresado debe ser un numero entero.\n";
                cout << "Vuelva a ingresar: ";
                cin >> alumno[i].edad;
            }
            if (alumno[i].edad < 18)
            {
                cantMenores++;
            }
        } while (alumno[i].edad <= 0);
        do
        {
            cout << "Ingrese la carrera: (1)-Informatica (2)-Administracion (3)-Contabilidad (4)- Medicina : ";
            cin >> alumno[i].carrera;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "El dato ingresado debe ser un numero entero.\n";
                cout << "Vuelva a ingresar: ";
                cin >> alumno[i].carrera;
            }
            cant_alumnos[(alumno[i].carrera) - 1] = cant_alumnos[(alumno[i].carrera) - 1] + 1;
            promedio_Edades[alumno[i].carrera - 1] = promedio_Edades[alumno[i].carrera - 1] + alumno[i].edad;
        } while (alumno[i].carrera <= 0 || alumno[i].carrera > 4);
    }
    do
    {
        seleccionOp(opcion);
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << "Alumno " << i + 1 << "\n";
                cout << "Cedula: " << alumno[i].cedula << "\n";
                cout << "Nombre: " << alumno[i].nombre << "\n";
                cout << "Apellido: " << alumno[i].apellido << "\n";
                cout << "Genero: " << alumno[i].genero << "\n";
                cout << "Carrera: " << alumno[i].carrera << "\n";
            }
            opcion = 6;
            cout << "Presione una tecla para continuar..\n";
            getch();
            break;
        case 2:
            cout << "Cantidad de Alumnos que estudian las diferentes Carreras\n";
            cout << "El total de alumnos es: " << n << "\n";
            cout << "El total de alumnos de Informatica es: " << cant_alumnos[0] << "\n";
            cout << "El total de alumnos de Administracion es: " << cant_alumnos[1] << "\n";
            cout << "El total de alumnos de Contabilidad es: " << cant_alumnos[2] << "\n";
            cout << "El total de alumnos de Medicina es: " << cant_alumnos[3] << "\n";
            opcion = 6;
            cout << "Presione una tecla para continuar..\n";
            getch();
            break;
        case 3:
            cout << "Cantidad de Estudiantes Femeninos y Masculinos.\n";
            cout << "Estudiantes Masculinos: " << cant_MYF[0] << "\n";
            cout << "Estudiantes Femeninos: " << cant_MYF[1] << "\n";
            opcion = 6;
            cout << "Presione una tecla para continuar..\n";
            getch();
            break;
        case 4:
            cout << "Cantidad de Menores de Edad que estudian Informatica.\n";
            cout << "Hay " << cantMenores << " persona(s) que son menor(es) de edad y estudian informatica.\n";
            break;
            opcion = 6;
            cout << "Presione una tecla para continuar..\n";
            getch();
        case 5:
            cout << "Promedio de las edades de los alumnos de las distintas carreras.\n";
            cout << promedio_Edades[0] / cant_alumnos[0] << " es la edad promedio de los estudiantes de informatica.\n";
            cout << promedio_Edades[1] / cant_alumnos[1] << " es la edad promedio de los estudiantes de administración.\n";
            cout << promedio_Edades[2] / cant_alumnos[2] << " es la edad promedio de los estudiantes de contabilidad.\n";
            cout << promedio_Edades[3] / cant_alumnos[3] << " es la edad promedio de los estudiantes de medicina.\n";
            break;
            opcion = 6;
            cout << "Presione una tecla para continuar..\n";
            getch();
        case 6:
            do
            {
                cout << "Presione (1) para salir del programa o Presione (2) para volver al menu.\n";
                cin >> op_salida;
            } while (op_salida < 1 || op_salida > 2);
            if (op_salida == 1)
            {
                salir = true;
            }
            break;
        default:
            cout << "La opcion seleccionada no es valida.\n";
            opcion = 6;
            cout << "Presione una tecla para continuar..\n";
            getch();
        }
    } while (!salir);
}

void cantElementos(int &n)
{
    do
    {
        cout << "Ingrese la cantidad de personas cuya informacion desea cargar: ";
        cin >> n;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "El dato ingresado debe ser un numero entero.\n";
            cout << "Vuelva a ingresar: ";
            cin >> n;
        }
    } while (n <= 0);
}

void seleccionOp(int &opcion)
{
    do
    {
        cout << "Seleccione el numero correspondiente a la accion que desea realizar: ";
        cout << "1. Mostrar la estructura cargada.\n";
        cout << "2. Cantidad de alumnos que estudian las diferentes carreras.\n";
        cout << "3. Cantidad de Alumnos Masculinos y Femeninos.\n";
        cout << "4. Cantidad de Alumnos Menores de edad que estudian informatica.\n";
        cout << "5. Promedio de edades de los alumnos de las distintas carreras.\n";
        cout << "6. Salir o regresar al menu.\n";
        cin >> opcion;
    } while (opcion <= 0 || opcion > 6);
}

/*
Crear la estructura Alumnos con “n” elementos. Cuyos campos son:
Cedula Nombre Apellido Genero Edad Carrera
Dónde: - Genero se representará con los datos: 1- Femenino, 2 - Masculino
- Curso se representará con los datos: 1 – Informatica, 2 – Administracion, 3 – Contabilidad, 4 – Medicina
Crear un programa que permita seleccionar los elementos del siguiente menú:
- Opción 1: Mostrar la estructura cargada
- Opción 2: Cantidad de alumnos que estudian las diferentes carreras
- Opción 3: Cantidad de alumnos Masculinos y Femeninos
- Opción 4: Cantidad de Alumnos menores de edad que estudian Informatica
- Opción 5: Promedio de edades de los alumnos en las distintas carreras. - Opción 6: 1 – Salir, 2 – Volver al menú. 
Asegurarse de validar todas las opciones de ingreso.
Cedula Nombre Apellido Genero Edad Carrera
*/
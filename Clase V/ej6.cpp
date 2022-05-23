#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string>


using namespace std;

struct Alumno{
	int cedula;
	string nombre;
	string apellido;
	int curso;
	int parcial1;
	int parcial2;
	int trabajoPractico;
	int calificacion;
};

void gotoxy(int ,int);
int cantidadDatos(int &);
void cargaDatos(int , Alumno *);
void impresionDatos(int , Alumno *);
bool errorCarga(void);
bool tieneNumero(string);
int calcularNota(int, int, int);
void mostrarMenu(int &);
void ejecutarOpcion(int, Alumno *, int);
void interruptorFiltros(int &, int &, int &);
void filtrador(int, Alumno *, int);

main(){
	system("cls");
	int n, opcion;
	cantidadDatos(n);
	
	//Declaracion del array alumno, con 'n' miembros. Tambien se utiliza un puntero que apunte a ese array
	Alumno alumno[n], *alumnos;
	alumnos=&alumno[0];	
	
	cargaDatos(n, alumnos);
	
	do{
		mostrarMenu(opcion);
		ejecutarOpcion(n, alumnos, opcion);		
	}while(opcion !=4);
	
	system("pause");
	return 0;
}

bool errorCarga(void){
    bool error = false;
    if (cin.fail()){
        cin.clear();
        fflush(stdin);
        return true;
    }
    else{
        return false;
    }
}

bool tieneNumero(string cadena){
	int i=0;
	while(cadena[i]){
		if(isdigit(cadena[i]) == true){
            fflush(stdin);
			return true;
		}
		i++;
	}
	return false;
}

int cantidadDatos(int &n){
	cout<<"Ingrese la cantidad de alumnos cuyos datos desea cargar: ";
	cin>>n;
	do{
		while(errorCarga()){
			cout<<"Error. Debe ingresar numeros.\n";
			cout<<"Ingrese la cantidad de alumnos cuyos datos desea cargar: ";
			cin>>n;
		}
		while(n < 1){
			cout<<"Debe cargar al menos un elemento.\nVuelva a cargar.\n";
			cout<<"Ingrese la cantidad de alumnos cuyos datos desea cargar: ";
			cin>>n;
			while(errorCarga()){
				cout<<"Error. Debe ingresar numeros.\n";
				cout<<"Ingrese la cantidad de alumnos cuyos datos desea cargar: ";
				cin>>n;
			}			
		}	
	}while(errorCarga());
}

void cargaDatos(int n, Alumno *alumnos){
	for(int i=0; i<n; i++){
		system("cls");
		cout<<"+------------------------------------------------+\n";
		cout<<"| Carga de Datos  ";
		gotoxy(37,1);
		cout<<"  Alumno: "<<i+1<<" |\n";
		cout<<"+------------------------------------------------+\n";
		cout<<"|Numero de Cedula: ";
		gotoxy(49,3);
		cout<<"|";
		gotoxy(19,3);
		cin>>(alumnos + i)->cedula;
		while(errorCarga()){
			cout<<"Ocurrio un error en la carga. Recuerde que solo puede cargar numeros enteros. Vuelva a ingresar.\r";
			cout<<"Numero de Cedula: ";
			cin>>(alumnos + i)->cedula;
		}
		while(((alumnos + i)->cedula) < 0){
			cout<<"Error. Solo puede cargarse numeros positivos.\nVuelva a ingresar.\n";
			cout<<"Numero de Cedula: ";
			cin>>(alumnos + i)->cedula;
			
			while(errorCarga()){
			cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
			cout<<"Numero de Cedula: ";
			cin>>(alumnos + i)->cedula;
			}
		}
		cout<<"+------------------------------------------------+\n";
		cout<<"|Nombre: ";
		gotoxy(49,5);
		cout<<"|";
		gotoxy(9,5);
		cin>>(alumnos + i)->nombre;
		while(tieneNumero((alumnos + i)->nombre)){
			cout<<"Ocurrio un error en la carga. Recuerde que no puede cargar numeros. Vuelva a ingresar.";
			cout<<"Nombre: ";
			cin>>(alumnos + i)->nombre;
		}
		while(((alumnos + i)->nombre).empty()){
			cout<<"No puede dejar vacio ningun espacio del formulario.\nVuelva a Ingresar.\n";
			cout<<"Nombre: ";
			cin>>(alumnos + i)->nombre;
			while(tieneNumero((alumnos + i)->nombre)){
				cout<<"Ocurrio un error en la carga. Recuerde que no puede cargar numeros. Vuelva a ingresar.";
				cout<<"Nombre: ";
				cin>>(alumnos + i)->nombre;
			}
		}
		cout<<"+------------------------------------------------+\n";
		cout<<"|Apellido: ";
		gotoxy(49,7);
		cout<<"|";
		gotoxy(10,7);
		cin>>(alumnos + i)->apellido;
		while(tieneNumero((alumnos + i)->apellido)){
			cout<<"Ocurrio un error en la carga. Recuerde que no puede cargar numeros. Vuelva a ingresar.";
			cout<<"Apellido: ";
			cin>>(alumnos + i)->apellido;
		}
		while(((alumnos + i)->apellido).empty()){
			cout<<"No puede dejar vacio ningun espacio del formulario.\nVuelva a Ingresar.\n";
			cout<<"Apellido: ";
			cin>>(alumnos + i)->apellido;
			while(tieneNumero((alumnos + i)->apellido)){
				cout<<"Ocurrio un error en la carga. Recuerde que no puede cargar numeros. Vuelva a ingresar.";
				cout<<"Apellido: ";
				cin>>(alumnos + i)->apellido;
			}
		}
		cout<<"+------------------------------------------------+\n";
		cout<<"|Curso (1 - 5): ";
		gotoxy(49,9);
		cout<<"|";
		gotoxy(15,9);
		cin>>(alumnos + i)->curso;
		while(errorCarga()){
			cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
			cout<<"Curso (1 - 5): ";
			cin>>(alumnos + i)->curso;
		}
		while(((alumnos+ i) -> curso) > 5  || ((alumnos+ i) -> curso) <  1){
			cout<<"Solo se pueden ingresar numeros que se encuentran en el rango permitido.\nVuelva a ingresar.\n";
			cout<<"Curso (1 - 5): ";
			cin>>(alumnos + i)->curso;
			while(errorCarga()){
				cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
				cout<<"Curso (1 - 5): ";
				cin>>(alumnos + i)->curso;				
			}
		}
		cout<<"+------------------------------------------------+\n";
		cout<<"|Puntos conseguidos 1er Parcial (0 - 15): ";
		gotoxy(49,11);
		cout<<"|";
		gotoxy(41,11);
		cin>>(alumnos + i)->parcial1;
		while(errorCarga()){
			cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
			cout<<"Puntos conseguidos 1er Parcial (0 - 15): ";
			cin>>(alumnos + i)->parcial1;	
		}
		while(((alumnos + i)->parcial1) > 15  || ((alumnos + i)->parcial1) < 0){
			cout<<"Solo se pueden ingresar numeros que se encuentran en el rango permitido.\nVuelva a ingresar.\n";
			cout<<"Puntos conseguidos 1er Parcial (0 - 15): ";
			cin>>(alumnos + i)->parcial1;
			while(errorCarga()){
				cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
				cout<<"Puntos conseguidos 1er Parcial (0 - 15): ";
				cin>>(alumnos + i)->parcial1;				
			}
		}
		cout<<"+------------------------------------------------+\n";
		cout<<"|Puntos conseguidos 2do Parcial (0 - 15): ";
		gotoxy(49,13);
		cout<<"|";
		gotoxy(41,13);
		cin>>(alumnos + i)->parcial2;
		while(errorCarga()){
			cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
			cout<<"Puntos conseguidos 2do Parcial (0 - 15): ";
			cin>>(alumnos + i)->parcial2;
		}
		while(((alumnos + i)->parcial2) > 15  || ((alumnos + i)->parcial2) < 0){
			cout<<"Solo se pueden ingresar numeros que se encuentran en el rango permitido.\nVuelva a ingresar.\n";
			cout<<"Puntos conseguidos 2do Parcial (0 - 15): ";
			cin>>(alumnos + i)->parcial2;
			while(errorCarga()){
				cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
				cout<<"Puntos conseguidos 2do Parcial (0 - 15): ";
				cin>>(alumnos + i)->parcial2;				
			}
		}
		cout<<"+------------------------------------------------+\n";
		cout<<"|Puntos de Trabajo Practico (0 - 10): ";
		gotoxy(49,15);
		cout<<"|";
		gotoxy(37,15);
		cin>>(alumnos + i)->trabajoPractico;
		while(errorCarga()){
			cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
			cout<<"Puntos de Trabajo Practico: (0 - 10)";
			cin>>(alumnos + i)->trabajoPractico;
		}
		while(((alumnos + i)->trabajoPractico) > 10  || ((alumnos + i)->trabajoPractico) < 1){
			cout<<"Solo se pueden ingresar numeros que se encuentran en el rango permitido.\nVuelva a ingresar.\n";
			cout<<"Puntos de Trabajo Practico: (0 - 10)";
			cin>>(alumnos + i)->trabajoPractico;
			while(errorCarga()){
				cout<<"Ha ocurrido un error en la carga. Recuerde que sólo puede cargar numeros enteros.\nVuelva a ingresar.\n";
				cout<<"Puntos de Trabajo Practico: (0 - 10)";
				cin>>(alumnos + i)->trabajoPractico;				
			}
		}
		(alumnos + i) -> calificacion = calcularNota(((alumnos + i) -> parcial1), ((alumnos + i) -> parcial2), ((alumnos + i) -> trabajoPractico));
	}
	return;
}

void impresionDatos(int n, Alumno *alumnos){
	system("cls");
	for(int i=0; i<n; i++){
		int y=(i+3);
		if(i==0){
			cout<<"+----------------------------------------------------------------------------------------------------------------------+\n";
			cout<<"| Alumno |   C.I   |   Nombre    |   Apellido   |   Curso    |   Parcial 1   |   Parcial 2   |   T.Practico   |  Nota  |\n";
		}else{
			y=(i+(i+3));
		}
		cout<<"+--------+---------+-------------+--------------+------------+---------------+---------------+----------------+--------+\n";
		cout<<"|"
			<<i+1;
		gotoxy(9, y);
		cout<<"|"
			<<(alumnos + i)->cedula;
		gotoxy(19, y);
		cout<<"|"
			<<(alumnos + i)->nombre;
		gotoxy(33, y);
		cout<<"|"
			<<(alumnos + i)->apellido;
		gotoxy(48, y);
		cout<<"|"
			<<(alumnos + i)->curso;
		gotoxy(61, y);
		cout<<"|"
			<<(alumnos + i)->parcial1;
		gotoxy(77, y);
		cout<<"|"
			<<(alumnos + i)->parcial2;
		gotoxy(93, y);
		cout<<"|"
			<<(alumnos + i)->trabajoPractico;
		gotoxy(110, y);
		cout<<"|"
			<<(alumnos + i) ->calificacion;
		gotoxy(119, y);
		cout
			<<"|\n";
		if(i == (n-1)){
			cout<<"+--------+---------+-------------+--------------+------------+---------------+---------------+----------------+--------+\n";
		}
		
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Numero de Cedula: ";
//		gotoxy(49,3);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Nombre: "
//		gotoxy(49,5);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Apellido: "
//		gotoxy(49,7);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Curso: "
//		gotoxy(49,9);
//		cout<<"|\n";		
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Puntos conseguidos 1er Parcial: "
//		gotoxy(49,9);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Puntos conseguidos 2do Parcial: "
//		gotoxy(49,11);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Puntos de Trabajo Practico: "
//		gotoxy(49,13);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Nota: "
//		gotoxy(49,15);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
		
		
		//---------------------------------------------------------------------
		
		
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Alumno: "<<i+1;
//		gotoxy(49,1);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Numero de Cedula: "<<(alumnos + i)->cedula;
//		gotoxy(49,3);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Nombre: "<<(alumnos + i)->nombre;
//		gotoxy(49,5);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Apellido: "<<(alumnos + i)->apellido;
//		gotoxy(49,7);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Curso: "<<(alumnos + i)->curso;
//		gotoxy(49,9);
//		cout<<"|\n";		
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Puntos conseguidos 1er Parcial: "<<(alumnos + i)->parcial1;
//		gotoxy(49,9);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Puntos conseguidos 2do Parcial: "<<(alumnos + i)->parcial2;
//		gotoxy(49,11);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Puntos de Trabajo Practico: "<<(alumnos + i)->trabajoPractico;
//		gotoxy(49,13);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
//		cout<<"|Nota: "<<(alumnos + i) ->calificacion;
//		gotoxy(49,15);
//		cout<<"|\n";
//		cout<<"+------------------------------------------------+\n";
	}
	system("pause");
	return;
}

int calcularNota(int parcial1, int parcial2, int tp){
	int puntaje= parcial1 + parcial2 + tp;
	if(puntaje >= 0 && puntaje <=27){
		return 1;
	}else if(puntaje >= 28 && puntaje <=30){
		return 2;
	}else if(puntaje >= 31 && puntaje <=34){
		return 3;
	}else if(puntaje >= 35 && puntaje <=37){
		return 4;
	}else if(puntaje >= 38 && puntaje <=40){
		return 5;
	}
}

void mostrarMenu(int &opcion){
	system("cls");
	cout<<"Opciones Disponibles: \n";
	cout<<"Opcion 1: Mostrar los datos ingresados en forma de tabla.\n";
	cout<<"Opcion 2: Ingresar un curso y filtrar la lista por el curso ingresado.\n";
	cout<<"Opcion 3: Ingresar la cedula de identidad de un alumno, y filtrar los datos del mismo.\n";
	cout<<"Opcion 4: Salir del Programa.\n";
	cout<<"Opcion Seleccionada (1 - 4): ";
	cin>>opcion;
	while(opcion < 1 || opcion > 4){
		cout<<"Error!. Solo puede escoger opciones que estén disponibles.\n";
		cout<<"Opciones Disponibles: \n";
		cout<<"Opcion 1: Mostrar los datos ingresados en forma de tabla.\n";
		cout<<"Opcion 2: Ingresar un curso y filtrar la lista por el curso ingresado.\n";
		cout<<"Opcion 3: Ingresar la cedula de identidad de un alumno, y filtrar los datos del mismo.\n";
		cout<<"Opcion 4: Salir del Programa.\n";
		cout<<"Opcion Seleccionada (1 - 4): ";
		cin>>opcion;
	}
	return;
}

void ejecutarOpcion(int n, Alumno *alumnos, int opcion){
	switch(opcion){
		case 1:
			impresionDatos(n, alumnos);
			break;
		case 2:
			filtrador(n, alumnos, 1);
			break;
		case 3:
			filtrador(n, alumnos, 2);
			break;
		case 4:
			cout<<"Gracias por utilizar el programa.\n";
			break;
		default:
			cout<<"Ha ocurrido un error. Vuelva a intentarlo.\n";
			break;
	}
}

void interruptorFiltros(int &filtro, int &curso, int &cedula){
	switch(filtro){
		case 1:
			cout<<"Seleccione Curso para Filtrar (1 - 5): ";
			cin>>curso;
			
			while(errorCarga()){
				cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
				cout<<"Curso (1 - 5): ";
				cin>>curso;
			}
			
			while(curso > 5  || curso <  1){
				cout<<"Solo se pueden ingresar numeros que se encuentran en el rango permitido.\nVuelva a ingresar.\n";
				cout<<"Curso (1 - 5): ";
				cin>>curso;
				while(errorCarga()){
					cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
					cout<<"Curso (1 - 5): ";
					cin>>curso;
				}
			}
			break;
		case 2:
			cout<<"Ingrese el Numero de Cedula del Alumno cuyos datos necesita: ";
			cin>>cedula;
			while(errorCarga()){
				cout<<"Ocurrio un error en la carga. Recuerde que solo puede cargar numeros enteros. Vuelva a ingresar.\n";
				cout<<"Numero de Cedula: ";
				cin>>cedula;
			}
			while(cedula < 0){
				cout<<"Error. Solo puede cargarse numeros positivos.\nVuelva a ingresar.\n";
				cout<<"Numero de Cedula: ";
				cin>>cedula;
				
				while(errorCarga()){
					cout<<"Ha ocurrido un error en la carga. Recuerde que solo puede cargar numeros enteros.\nVuelva a ingresar.\n";
					cout<<"Numero de Cedula: ";
					cin>>cedula;
				}
			}
			break;
		default:
			cout<<"Ha ocurrido un error. Vuelva a intentar por favor.\n";
			break;
	}
}

void filtrador(int n, Alumno *alumnos, int filtro){
	int curso, cedula;
	bool existe=false;
	interruptorFiltros(filtro, curso, cedula);
	switch(filtro){
		case 1:
			system("cls");
			for(int i=0; i<n; i++){
				int y=(i+3);
				if((alumnos + i)->curso == curso){
					existe=true;
					cout<<"+----------------------------------------------------------------------------------------------------------------------+\n";
					cout<<"| Alumno |   C.I   |   Nombre    |   Apellido   |   Curso    |   Parcial 1   |   Parcial 2   |   T.Practico   |  Nota  |\n";
					cout<<"+--------+---------+-------------+--------------+------------+---------------+---------------+----------------+--------+\n";
					cout<<"|"
						<<i+1;
					gotoxy(9, y);
					cout<<"|"
						<<(alumnos + i)->cedula;
					gotoxy(19, y);
					cout<<"|"
						<<(alumnos + i)->nombre;
					gotoxy(33, y);
					cout<<"|"
						<<(alumnos + i)->apellido;
					gotoxy(48, y);
					cout<<"|"
						<<(alumnos + i)->curso;
					gotoxy(61, y);
					cout<<"|"
						<<(alumnos + i)->parcial1;
					gotoxy(77, y);
					cout<<"|"
						<<(alumnos + i)->parcial2;
					gotoxy(93, y);
					cout<<"|"
						<<(alumnos + i)->trabajoPractico;
					gotoxy(110, y);
					cout<<"|"
						<<(alumnos + i) ->calificacion;
					gotoxy(119, y);
					cout
					<<"|\n";
					cout<<"+--------+---------+-------------+--------------+------------+---------------+---------------+----------------+--------+\n";
					y=(i+(i+3));
				}
			}
			if(!existe){
				cout<<"No se han encontrado alumnos de ese curso entre los datos.\n";
			}
			system("pause");
			break;
		case 2:
			system("cls");
			for(int i=0; i<n; i++){
				int y=(i+3);
				if(((alumnos + i)->cedula) == cedula){
					existe=true;
					cout<<"+----------------------------------------------------------------------------------------------------------------------+\n";
					cout<<"| Alumno |   C.I   |   Nombre    |   Apellido   |   Curso    |   Parcial 1   |   Parcial 2   |   T.Practico   |  Nota  |\n";
					cout<<"+--------+---------+-------------+--------------+------------+---------------+---------------+----------------+--------+\n";
					cout<<"|"
						<<i+1;
					gotoxy(9, y);
					cout<<"|"
						<<(alumnos + i)->cedula;
					gotoxy(19, y);
					cout<<"|"
						<<(alumnos + i)->nombre;
					gotoxy(33, y);
					cout<<"|"
						<<(alumnos + i)->apellido;
					gotoxy(48, y);
					cout<<"|"
						<<(alumnos + i)->curso;
					gotoxy(61, y);
					cout<<"|"
						<<(alumnos + i)->parcial1;
					gotoxy(77, y);
					cout<<"|"
						<<(alumnos + i)->parcial2;
					gotoxy(93, y);
					cout<<"|"
						<<(alumnos + i)->trabajoPractico;
					gotoxy(110, y);
					cout<<"|"
						<<(alumnos + i) ->calificacion;
					gotoxy(119, y);
					cout
					<<"|\n";
					cout<<"+--------+---------+-------------+--------------+------------+---------------+---------------+----------------+--------+\n";
					y=(i+(i+3));
				}
			}
			if(!existe){
				cout<<"No se han encontrado alumnos de ese curso entre los datos.\n";
			}			
			system("pause");
			break;
		default:
			cout<<"Ha ocurrido un error.\nVuelva a intentarlo.\n";
	}
}

void gotoxy(int x, int y){
	HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
}




/*
6) Crear una estructura que permita cargar los siguientes registros para la materia de Algorítmica: cedula, nombre
y apellido, curso, parcial 1, parcial 2, trabajo practico, donde se debe prestar atención a los siguientes detalles:
- Los datos ingresados deben ser validados, es decir, en campos numéricos no deben ser permitidos datos
alfanuméricos y viceversa.
- Las parciales deben tener valores en los rangos de 0 a 15 puntos.
- El trabajo practico debe tener un rango de 0 a 10 puntos.
- La calificación dependerá del total de puntos el cual es laendo en cuenta la siguiente escala.
Calificación 	Desde 		Hasta sumatoria entre las parciales y el trabajo
practico. A su vez, la calificación deberá ser calculado teni
1 					0 			27
2 					28 			30
3 					31 			34
4 					35 			37
5 					38 			40 

A partir de los datos ingresados, mostrar los siguientes resultados
- Opción 1: Mostrar los datos ingresados en forma de tabla
- Opción 2: Ingresar un curso y filtrar la lista por el curso ingresado
- Opción 3: Ingresar la cedula de identidad de un alumno, y filtrar los datos del mismo
- Opción 4: Salir del Programa 
*/

//@Towel15 - GITHUB
#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

//Estructura de los Nodos
struct Nodo{
	double temperatura;
	int ciudad;
	int hora;
	Nodo *siguiente;
	Nodo *anterior;
};

//Prototipo de Funcion
int cargaCiudad(void);
int cargaHora(void);
double cargaTemp(void);
void cargarLista(Nodo *&, Nodo *&, int, int, double);
bool ciudadYHoraRepetida(Nodo *, int, int);
void mostrarLista(Nodo *);
int mostrarMenu(void);
void registrarTemperatura(int &, int &, double &, Nodo *&, Nodo *&, int &, int &);
void consultaTemperaturasHora(Nodo *, char);
void ciudadTempMayor(int, int);
void consultaTodosDatos(Nodo *);
void consultaPorCiudad(Nodo *, int);

//Estructura de Nombre de las Ciudades Cargadas
string ciudades[4] = {"Ciudad del Este", "Hernandarias", "Pdte. Franco", "Minga Guazú"};
int cantPorCiudad[4] = {0, 0, 0, 0}, cantPorHora[24] = {0}, i=0;

//Funcion Principal
main(){
	Nodo *primero = NULL, *ultimo = NULL;
	int ciudad, hora, ciudadMayorTemp, tempMayor;
	double temperatura;
	bool salir = false;
	setlocale(LC_ALL, "spanish");
	do{
		system("cls");
		cout<<"Programa para registrar la temperatura.\n";
		switch(mostrarMenu()){
			case 1:
				system("cls");
				cout<<"Registrar Temperatura.\n";
				registrarTemperatura(ciudad, hora, temperatura, primero, ultimo, tempMayor,ciudadMayorTemp);
				break;
			case 2:
				system("cls");
				cout<<"Consulta de Temperaturas por Hora en Forma Ascendente.\n";
				consultaTemperaturasHora(primero, 'a');
				system("pause");
				break;
			case 3:
				system("cls");
				cout<<"Consulta de Temperaturas por Hora en Forma Descendente.\n";
				consultaTemperaturasHora(primero, 'd');
				system("pause");
				break;
			case 4:
				system("cls");
				cout<<"Consulta de Temperaturas Registradas por Ciudad\n";
				cout<<"Seleccione la Ciudad cuyas temperaturas desea imprimir.\n";
				ciudad = cargaCiudad();
				consultaPorCiudad(primero, ciudad);
				system("pause");
				break;
			case 5:
				system("cls");
				cout<<"Imprimir la Ciudad que Registró Mayor Temperatura en el Día\n";
				ciudadTempMayor(tempMayor, ciudadMayorTemp);
				system("pause");
				break;
			case 6:
				system("cls");
				consultaTodosDatos(primero);
				system("pause");
				break;
			case 7:
				system("cls");
				cout<<"Gracias por utilizar el programa.\n";
				system("pause");
				salir = true;
				break;
			default:
				cout<<"Ha ocurrido un error. La opción seleccionada no está disponible   .\n";
				break;
		}
	}while(!salir);
}

//Declaracion de Funciones

int cargaCiudad(void){
	int n;
	cout<<"Seleccione la ciudad:\n";
	cout<<"1- Ciudad Del Este\n";
	cout<<"2- Hernandarias\n";
	cout<<"3- Pte. Franco\n";
	cout<<"4- Minga Guazú\n";
	cout<<"Ciudad: ";
	cin>>n;
	while(n < 1 || n > 4){
		cout<<"El numero ingresado no corresponde a ninguna ciudad.\nVuelva a ingresar.\n";
		cout<<"Seleccione la ciudad:\n";
		cout<<"1- Ciudad Del Este\n";
		cout<<"2- Hernandarias\n";
		cout<<"3- Pte. Franco\n";
		cout<<"4- Minga Guazú\n";
		cout<<"Ciudad: ";
		cin>>n;
	}
	cantPorCiudad[n-1] = cantPorCiudad[n-1] + 1;
	return n;
}

int cargaHora(void){
	int n;
	cout<<"Ingrese la hora (0-24): ";
	cin>>n;
	while(n < 0 || n > 24){
		cout<<"Error. Debe ingresar un numero entre 0 y 24.\n.Vuelva a cargar.\n";
		cout<<"Ingrese la hora (0-24): ";
		cin>>n;
	}
	return n;
}

double cargaTemp(void){
	double n;
	cout<<"Ingrese Temperatura Registrada: ";
	cin>>n;
	return n;
}

void registrarTemperatura(int &ciudad, int &hora, double &temperatura, Nodo *&primero, Nodo *&ultimo, int &tempMayor ,int &ciudadTempMayor){
	ciudad = cargaCiudad();
	hora = cargaHora();
	temperatura = cargaTemp();
	if(primero != NULL){
		while(ciudadYHoraRepetida(primero, ciudad, hora)){
			ciudad = cargaCiudad();
			hora = cargaHora();
			temperatura = cargaTemp();
		}
		cargarLista(primero, ultimo, ciudad, hora, temperatura);		
	}else{ 
		cargarLista(primero, ultimo, ciudad, hora, temperatura);
	}
	if(i==0){
		tempMayor=temperatura;
		ciudadTempMayor=ciudad;
	}else if(temperatura > tempMayor){
		tempMayor=temperatura;
		ciudadTempMayor=ciudad;
	}
	i++;
	system("cls");
	cout<<"Se registró la temperatura correctamente.\n";
	system("pause");
}

void cargarLista(Nodo *&primero, Nodo *& ultimo, int ciudad, int hora, double temperatura){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->ciudad = ciudad;
	nuevoNodo->hora = hora;
	nuevoNodo->temperatura = temperatura;
	if(primero == NULL){
		primero=nuevoNodo;
		nuevoNodo->anterior = NULL;
		nuevoNodo->siguiente = NULL;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevoNodo;
		nuevoNodo->siguiente=NULL;
		nuevoNodo->anterior=ultimo;
		ultimo=nuevoNodo;
	}
}

void ordenar(Nodo *&primero, Nodo *&ultimo){
	Nodo *actual = new Nodo();
	Nodo *anterior = NULL;
	Nodo *aux = new Nodo();
	actual = primero;
	if(primero != NULL){
		while(actual != NULL){
			if(actual->hora > actual->siguiente->hora && actual != ultimo){
				if(actual == primero){
					aux = primero;
					primero = actual->siguiente;
					primero->anterior=NULL;
					actual->siguiente = aux;
					actual->anterior = primero;
				}else{
					aux=actual;	
				}
			}else{
				actual = actual->siguiente;
			}
		}
	}else{
		cout<<"La lista no está cargada con ningún elemento.\n";
	}
}

bool ciudadYHoraRepetida(Nodo *iniciador, int ciudad, int hora){
	Nodo *actual=iniciador;
	bool encontrado = false;
	if(actual != NULL){
		while(actual != NULL && !encontrado){
			if(actual->ciudad == ciudad && actual->hora == hora){
				encontrado=true;		
			}else{
				actual = actual->siguiente;
			}
		}
		if(encontrado){
			cout<<"No se puede registrar la temperatura de una ciudad dos veces.\nVuelva a cargar.\n";
			return true;
		}else{
			return false;
		}
	}else{
		cout<<"La lista está vacía.\n";
		return false;
	}
}

void mostrarLista(Nodo *iniciador){
	Nodo *actual = new Nodo();
	actual = iniciador;
	if(actual != NULL){
		while(actual != NULL){
			cout<<"Ciudad: "<<ciudades[(actual->ciudad)-1]<<"\n";
			cout<<"Hora: "<<actual->hora<<"\n";
			cout<<"Temperatura Registrada: "<<actual->temperatura<<"ºC\n";
			actual = actual->siguiente;
		}
	}else{
		cout<<"La lista no tiene elementos cargados dentro.\n";
	}
}

int mostrarMenu(void){
	int op;
	cout<<"Menú de Opciones:\n";
	cout<<"1- Registrar Temperatura\n";
	cout<<"2- Consulta de temperaturas por hora en forma ascendente\n";
	cout<<"3- Consulta de temperaturas por hora en forma descendente\n";
	cout<<"4- Consulta de temperaturas registradas por ciudad\n";
	cout<<"5- La ciudad que registro mayor temperatura en el día\n";
	cout<<"6- Mostrar todos los datos de temperaturas y ciudades cargados.\n";
	cout<<"7- Salir del Programa\n";
	cout<<"Ingrese la opcion que desea: ";
	cin>>op;
	while(op < 1 || op > 7){
		cout<<"ERROR.\n El número seleccionado no se encuentra en el rango de opciones disponibles.\n";
		cout<<"Menú de Opciones:\n";
		cout<<"1- Registrar Temperatura\n";
		cout<<"2- Consulta de temperaturas por hora en forma ascendente\n";
		cout<<"3- Consulta de temperaturas por hora en forma descendente\n";
		cout<<"4- Consulta de temperaturas registradas por ciudad\n";
		cout<<"5- La ciudad que registro mayor temperatura en el día\n";
		cout<<"6- Mostrar todos los datos de temperaturas y ciudades cargados.\n";
		cout<<"7- Salir del Programa\n";
		cout<<"Ingrese la opcion que desea: ";
		cin>>op;
	}
	return op;
}

void consultaTemperaturasHora(Nodo *primero, char op){
	Nodo *actual = new Nodo();
	int ciudadActual = 0;
	switch(op){
		case 'a':
			actual = primero;  
			if(actual != NULL){
				int horaActual=0;
				do{
					actual=primero;
					while(actual != NULL){
						if(actual->hora == horaActual){
							cout<<"Hora: "<<actual->hora<<"\n";
							cout<<"\tTemperatura: "<<actual->temperatura<<"ºC\n";
							cout<<"\tCiudad: "<<ciudades[(actual->ciudad) - 1]<<"\n";
						}
						actual = actual->siguiente;
					}
					horaActual++;
				}while(horaActual <= 24);
			}else{
				cout<<"La lista no contiene datos.\nPara imprimirlos, primero debe cargar datos en ella.\n";
			}
			break;
		case 'd':
			actual = primero;  
			if(actual != NULL){
				int horaActual=24;
				do{
					actual=primero;
					while(actual != NULL){
						if(actual->hora == horaActual){
							cout<<"Hora: "<<actual->hora<<"\n";
							cout<<"\tTemperatura: "<<actual->temperatura<<"ºC\n";
							cout<<"\tCiudad: "<<ciudades[(actual->ciudad) - 1]<<"\n";
						}
						actual = actual->siguiente;
					}
					horaActual--;
				}while(horaActual >= 0);
			}else{
				cout<<"La lista no contiene datos.\nPara imprimirlos, primero debe cargar datos en ella.\n";
			}
			break;
		default:
			cout<<"La opcion de Impresion No Está Disponible.\n";
			break;
	}
}

void consultaPorCiudad(Nodo *primero, int ciudad){
	Nodo *actual = new Nodo();
	actual = primero;
	int encontrado = 0;
	if(actual != NULL){
		while(actual != NULL){
			if(actual->ciudad == ciudad){
				cout<<"Ciudad: "<<ciudades[(actual->ciudad)-1]<<"\n";
				cout<<"\tHora: "<<actual->hora<<"\n";
				cout<<"\tTemperatura Registrada: "<<actual->temperatura<<"ºC\n";
				encontrado++;
			}
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			cout<<"La ciudad seleccionada no tiene ninguna temperatura registrada.\n";
		}
	}else{
		cout<<"La lista no está cargada con ningún elemento.\n";
	}
}

void consultaTodosDatos(Nodo *primero){ 
	Nodo *actual = new Nodo();
	actual = primero;  
	int ciudadActual = 0;
	if(actual != NULL){
		do{
			if(cantPorCiudad[ciudadActual] == 0){
				ciudadActual++;
			}else{
				actual=primero;
				while (actual != NULL){
					if(actual->ciudad == ciudadActual+1){
						cout<<"Ciudad: "<<ciudades[(actual->ciudad)-1]<<"\n";
						cout<<"\tHora: "<<actual->hora<<"\n";
						cout<<"\tTemperatura Registrada: "<<actual->temperatura<<"ºC\n";
					}
					actual = actual->siguiente;
				}
				ciudadActual++;
			}
		}while(ciudadActual < 4);
	}else{
		cout<<"La lista no contiene datos.\nPara imprimirlos, primero debe cargar datos en ella.\n";
	}
}

void ciudadTempMayor(int tempMayor, int ciudadMayorTemp){
	cout<<"La ciudad que registró la mayor temperatura en el día fue: "<<ciudades[(ciudadMayorTemp-1)]<<"\n";
	cout<<"La temperatura más alta que se registró en el día fue: "<<tempMayor<<"ºC\n";
}
/*
Crear un programa que permita registrar las temperaturas en °C durante el día,
de 4 ciudades,
en donde los datos a registrar son los siguientes:
- Temperatura
- Ciudad (1 = Ciudad del este, 2 = Hernandarias, 3 = Pte Franco, 4 = Minga Guasu)
- Hora (Horario 24hs)
Permitir el ingreso de datos en una lista doblemente enlazada 
y la consulta de los mismos a través del siguiente menú:
1) Registrar Temperatura *
2) Consulta de temperaturas por hora en forma ascendente*
3) Consulta de temperaturas por hora en forma descendente*
4) Consulta de temperaturas registradas por ciudad *
5) La ciudad que registro mayor temperatura en el día

Observación:
- Realiza las validaciones para el horario de 24hs *
y el código de las ciudades (1,2,3,4)
- en las consultas mostrar el nombre de la ciudad teniendo en cuenta su código (1,2,3,4) *
*/

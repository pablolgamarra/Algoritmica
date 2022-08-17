//Un usuario selecciona una opcion de un menú

#include <iostream>
#include <windows.h>

using namespace std;

main(){
	int opcion;
	cout<<"1-Imprimir Hola Mundo en Pantalla"<<endl;	
	cout<<"2-Imprimir 2+2 en Pantalla"<<endl;
	cout<<"3-Imprimir una ecuacion en pantalla"<<endl;
	cin>>opcion;
//	if(opcion == 1){
//		cout<<"Hola Mundo";	
//	}else if(opcion == 2){
//		cout<<"4";
//	}else if(opcion == 3){
//		cout<<"x2+bx+c";
//	}
	
	switch(opcion){
		case 1:
			cout<<"Hola Mundo";
			break;
		case 2:
			cout<<"4";
			break;
		case 3:
			cout<<"x2+bx+c";
			break;
		default:
			cout<<"La opcion seleccionada no está disponible";
			break;
	}
}



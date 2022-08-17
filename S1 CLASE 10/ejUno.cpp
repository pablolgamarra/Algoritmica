#include <iostream>
#include <windows.h>

using namespace std;

int costo,comision;

int comisionGimnasia(int costo){
	comision=costo*0.3;
	return comision;
}

int comisionElectro(int costo){
	comision=costo*0.2;
	return comision;
}	

int main(){
	system("cls");
	int producto;
	cout<<"Ingrese '1' Si el producto vendido es un Equipo de Gimnasia. Ingrese '2' si es un Electrodomestico): ";
	cin>>producto;
	while(producto < 1 || producto > 2){
		system("cls");
		cout<<"Ingrese '1' Si el producto vendido es un Equipo de Gimnasia. Ingrese '2' si es un Electrodomestico): ";
		cin>>producto;
	}
	cout<<"Ingrese el Precio del Producto: ";
	cin>>costo;
	system("cls");
	switch(producto){
		case 1:
			cout<<"Equipo Gimnasia.\n";
			comisionGimnasia(costo);
			cout<<"La Comision es: "<<comision<<endl;
			break;
		case 2:
			cout<<"Electrodomestico.\n";
			comisionElectro(costo);
			cout<<"La Comision es: "<<comision<<endl;
			break;
		default:
			cout<<"El producto ingresado no es valido.\n";
			break;
	}
	system("pause");	
	return 0;
}


/*
Crea un procedimiento que realice el cálculo de comisión de vendedores de acuerdo al tipo de producto
que haya vendido (equipo de gimnasia=30%, electrodoméstico=20%). 
*/

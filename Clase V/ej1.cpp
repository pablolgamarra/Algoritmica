#include <iostream>
#include <windows.h>

using namespace std;

main(){
	system("cls");
	int n;
	cout<<"Ingrese un numero: ";
	cin>>n;
	if(n%2==0){
		cout<<"El numero ingresado: "<<n<<", es un numero par.\n";
	}else{
		cout<<"El numero ingresado: "<<n<<", es un numero impar.\n";
	}
	cout<<"La posicion de memoria del numero ingresado es: "<<&n<<"\n";
	system("pause");
}


/*1) Comprobar si un n�mero es par o impar, y se�alar la posici�n de memoria donde se est� guardando el numero
utilizando punteros. */

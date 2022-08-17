#include <iostream>
#include <windows.h>

using namespace std;

int estadoCivil;

void mostEstCivil(int estadoCivil){
	system("cls");
	switch(estadoCivil){
		case 1:
			cout<<"Estado Civil: Soltero(a).\n";
			break;
		case 2:
			cout<<"Estado Civil: Casado(a).\n";
			break;
		case 3:
			cout<<"Estado Civil: Separado(a).\n";
			break;		
		case 4:
			cout<<"Estado Civil: Viudo(a).\n";
			break;
		default:
			cout<<"Error. Algo anda mal.";
			break;
	}
}

int main(){
	system("cls");
	cout<<"Ingrese un numero y el programa determinara a que estado civil corresponde ese numero.\n";
	cout<<"Ingresar estado civil\n (1-4) :";
	cin>>estadoCivil;
	while(estadoCivil < 1 || estadoCivil > 4){
		system("cls");
		cout<<"Volver a ingresar el dato: ";
		cin>>estadoCivil;
	}
	mostEstCivil(estadoCivil);
	system("pause");
	return 0;
}

/*Crea un procedimiento que permita chequear que los valores v�lidos para un c�digo de estado civil sea
solo 1 = soltero/a 2 = casado/a 3 = separado/a 4 = viudo/a.
*/


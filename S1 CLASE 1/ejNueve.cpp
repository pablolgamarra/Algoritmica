#include <iostream>
#include <cstdlib>
#include <windows.h>


using namespace std;


int l,p,a;


int main(){
	system("cls");
	cout<<"Ingrese la medida del lado del terreno"<<endl;
	cin>>l;
	
	p=l*4;
	
	a=l*l;
	
    system("cls");

	cout<<"El lado del terreno es: "<<l<<" metros"<<endl;
	cout<<"El perimetro del terreno es: "<<p <<" metros"<<endl;
	cout<<"El area del terreno es:" <<a <<" metros"<<endl;
	
	
	system("pause");

	return 0;
}


#include <iostream>
#include <cstdlib>
#include <windows.h>


using namespace std;


int l,p,a;


int main(){
	system("cls")
	cout<<"Ingrese el lado"<<endl;
	cin>>l;
	
	p=l*4;
	
	a=l*l;
	
	cout<<"El lado que ingreso es:"<<l<<endl;
	cout<<"El perimetro es: "<<p <<endl;
	cout<<"El area es:" <<a <<endl;
	
	
	system("pause");

	return 0;
}


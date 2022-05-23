#include <iostream>

using namespace std;

main()
{
	//ESTRUCTURAS DE CONTROL
//	1
//	2
//	3
//			4
//	5				7
//	6				8
	
//	1 = 1 ? si verdadero
//	1 = 2 ? no falso
//	 =  < >
	//OPERADORES
//	+ Suma  		num1 + num2
//	- Resta			num1 - num2
//	* Multiplicacion	num2 * num1
//	/ Division		num1 / num2
//	
//	&&	AND			verdadero && falso  = falso
//	
//	||	OR			falso || falso  = falso
//	
//	==	EQUALS		verdadero == falso  = falso
//	
//	!	NOT			!falso = verdadero

	int numero1;
	int numero2;
	
	cout<<"Ingrese primer numero: ";
	cin>>numero1;
	
	cout<<"Ingrese segundo numero: ";
	cin>>numero2;

	
	
	if ( numero1 == numero2 )
	{
		cout<<"Los numeros ingresados son iguales";
	}else
	{
		cout<<"Los numeros ingresados son diferentes";
	}


}

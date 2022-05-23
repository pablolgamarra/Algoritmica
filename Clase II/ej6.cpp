#include <iostream>

using namespace std;

main(){
	int n,sw=0, j=1, i=10, x=1;
	cout<<"Ingrese un numero positivo menor que '10': ";
	cin>>n;
	
	while(n<=0 || n>10){
		cout<<"Deben ingresarse numeros positivos menores que '10': ";
		cin>>n; 
	}
	
	while(x <= 10){
		if(sw==0){
			sw=1;
			cout<<n<<" x "<<j<<"= "<<n*j<<"\n";
			j++;
		}else{
			sw=0;
			cout<<n<<" x "<<i<<"= "<<n*i<<"\n";
			i--;
		}
		x++;
	}
}

/*
6) Dado un número menor que 10. Hallar su tabla de multiplicar de forma 
por duplicado, es decir, empezando por el
cero y por el 10 de forma alternativa. 
*/

#include <iostream>

using namespace std;

main(){
	int n;
	system("cls");
	cout<<"Ingrese la cantidad de elementos que tendra B (No menos de 50): ";
	cin>>n;
	while(n<50){
		cout<<"Deben ingresarse al menos 50 elementos: ";
		cin>>n;
	}
	int B[n], cantMayores20=0;
	
	//Carga del Vector B
	for(int i=0; i<n; i++){
		cout<<"Elemento "<<i+1<<": ";
		cin>>B[i];
		if(B[i] >= 20){
			cantMayores20++;
		}
	}
	
	int N[cantMayores20], j=0, aux=0, sw=0;
	
	//Impresion del Vector B y Carga del vector que contiene a los elementos mayores que 20
	for(int i=0; i<n;i++){
		if(i==0){
			cout<<"Vector Cargado sin ordenar: ["<<B[i]<<" | ";
		}else if(i==(n-1)){
			cout<<B[i]<<"]\n";
		}else{
			cout<<B[i]<<" | ";
		}
		if(B[i] >= 20){
			N[j]=B[i];
			j++;
		}
	}
	
	bool verificado = false;
	
	//Ordenamiento del Vector 'B'
	while(!verificado){
		verificado=true;
		for(int i=0; i<(n-1);i++){
			if(B[i]>B[i+1]){
				verificado=false;
				aux=B[i];
				B[i]=B[i+1];
				B[i+1]=aux;
			}
		}
	}
	
	//Impresion en Pantalla de los Vectores
	for(int i=0; i<n;i++){
		if(i==0){
			cout<<"Vector Cargado Ordenado de Forma Ascendente ["<<B[i]<<" | ";
		}else if(i==(n-1)){
			cout<<B[i]<<"]\n";
		}else{
			cout<<B[i]<<" | ";
		}
	}
	
	for(int i=0; i<cantMayores20;i++){
		if(i==0){
			cout<<"Vector con elementos mayores a 20: ["<<N[i]<<" | ";
		}else if(i==(cantMayores20-1)){
			cout<<N[i]<<"]\n";
		}else{
			cout<<N[i]<<" | ";
		}
	}
	
	system("pause");
	return 0;
}

/*
10) Crear y cargar un vector B con no menos de 50 elementos, 
además, crear un vector N que tendrá los elementos
de B mayores que 20. 
Ordenar los elementos del vector B en forma creciente 
por el método bandera. 
Imprimir ambos vectores. 
*/

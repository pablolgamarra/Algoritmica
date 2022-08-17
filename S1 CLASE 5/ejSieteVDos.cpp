#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int n=1,c,contMult=1;
    system("cls");
    cout<<"\nTablas de Multiplicar de los 10 primeros numeros. \n\n";
    do
        //con el for se imprime la tabla de cada numero (n)
        //el if sirve para que cada evz que cambie de numero, imprima la tabla de que numero es
        for(c=0;n<=10;c++){
            if(n==1&&c==0){
                cout<<" \n";
            }else if(c==1){
                cout<<"Tabla del: "<<n<<"\n";
                cout<<n<<" x "<<c<<" = "<<n*c<<endl;
            }else{
                cout<<n<<" x "<<c<<" = "<<n*c<<endl;
            }
        //con este, cuando llega a n*c=10, para el for, es decir, cuando el numero se multiplica por 10 se aplica el if
        //con contMult lo que hago es contar cuantas veces cambia el valor de n
        if(c==10){
        contMult++;
        c=0;
        n++;
        cout<<"\n";
        }
        }
        //con contMult controlo hasta que numero se va a hacer la multiplicacion
    while(contMult<=10);
    system("pause");
    return 0;
}
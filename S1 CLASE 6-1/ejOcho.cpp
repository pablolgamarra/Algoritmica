#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    system("cls");
    int numUno,numDos,diferencia=0,menor, mayor,auxMenor,auxMayor,sw=0,i,contPares=0,contImpares=0;
    cout<<"Ingrese dos numeros diferentes y cuya diferencia sea de al menos 100 unidades.\n";
    cout<<"Ingrese el valor del primer numero: ";
    cin>>numUno;
    cout<<"Ingrese el valor del segundo numero: ";
    cin>>numDos;
    diferencia=abs(numUno - numDos);
    while(diferencia < 100){
        cout<<"ERROR. Los numeros deben ser diferentes y la diferencia entre ellos debe ser de al menos 100 unidades.\n";
        cout<<"Ingrese el valor del primer numero: ";
        cin>>numUno;
        cout<<"Ingrese el valor del segundo numero: ";
        cin>>numDos;
        diferencia=abs(numUno - numDos);
    }
    if(numUno<numDos){
        menor=numUno;
        mayor=numDos;
        auxMenor=menor;
        auxMayor=mayor;
    }else if(numDos<numUno){
        menor=numDos;
        mayor=numUno;
        auxMenor=menor;
        auxMayor=mayor;
    }
    while(menor<=auxMayor || mayor>=auxMenor){
        if(sw==0){
            sw=1;
            cout<<menor<<", ";
            if(((menor % 2) == 0) && (menor != 0)){
                contPares++;
            }else if(((menor % 2) != 0) && (menor != 0)){
                contImpares++;
            }
            menor++;
        }else if(sw==1){
            sw=0;
            cout<<mayor<<", ";
            if(((mayor % 2) == 0) && (mayor != 0)){
                contPares++;
            }else if(((mayor % 2) != 0) && (mayor != 0)){
                contImpares++;
            }
            mayor--;    
        }
    }
    cout<<"\n\n";
    cout<<"La cantidad de numeros pares es: "<<contPares<<"\nLa cantidad de numeros impares es: "<<contImpares<<"\n\n";
    system("pause");
    return 0;
}

/*Ingresar dos números distintos cuya diferencia entre ambos sea como mínimo de 100
unidades. Imprimir la serie existente entre ambos en forma alternativa, es decir, del menos a
mayor en forma alternativa. Imprimir la cantidad de pares e impares hallados en el proceso. 
*/
#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int numAIng,numIng,i=0,mayor,menor,numAnt=0;
    system("cls");
    cout<<"Ingrese la cantidad de numeros que va a ingresar: ";
    cin>>numAIng;
    system("cls");
    while(i<numAIng){
        cout<<"Ingrese numero: ";
        cin>>numIng;
        i++;
        if(numIng>numAnt){
            mayor=numIng;
        }if(numIng<=numAnt){
            menor=numIng;
        }
        numAnt=numIng;
    }
    system("cls");
    cout<<"\nLa cantidad de numeros ingresados fue: "<<i<<"\n\nEl mayor numero ingresado fue: "<<mayor<<"\n\nEl menor numero ingresado fue: "<<menor<<endl;
    system("pause");
    return 0;
}
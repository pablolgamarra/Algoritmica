#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int i=0;
// tiene que dividir con mod 2 y si sale 0 entonces sumarle 1 porque es multiplo de 2, 
// si sale algo que no es 0, entonces sumarle 1
   
    system("cls");

    while(i<=199){
        cout<<i<<", ";
        if(i%2==0){
            i=i+1;
        }else{
            i=i+2;
        }
    }

    cout<<"\n\n";

    system("pause");
}
#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int i=0;

    system("cls");

    while(i<=200){
        cout<<i<<", ";
        i= i+2;
    }
    cout<<"\n\n";

    system("pause");
}
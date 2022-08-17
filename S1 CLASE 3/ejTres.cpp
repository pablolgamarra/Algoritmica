#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int i=10;

    system("cls");

    while(i>=0){
        cout<<i<<", ";
        i=i-1;
    }
    cout<<"\n\n";

    system("pause");
}
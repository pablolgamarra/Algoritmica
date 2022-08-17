#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

main(){
    string name;
    int sueldo, he,sueldohe,sueldont;

    system("cls");

    cout<<"Ingrese el nombre del trabajador: ";
    cin>>name;

    cout<<"Ingrese el sueldo del trabajador: ";
    cin>>sueldo;

    cout<<"Ingrese las horas extra trabajadas: ";
    cin>>he;

    system("cls");

    if(he>30){

        sueldohe=he*35000;
        sueldont= sueldo + sueldohe;

        cout<<"\nEl sueldo neto de: "<<name<<". Es de: "<<sueldont<<"\nTrabajo en total: "<<he<<" horas extra.\n";

    }if(he<=30){
        sueldohe=he*25000;
        sueldont= sueldo + sueldohe;

        cout<<"\nEl sueldo neto de: "<<name<<". Es de: "<<sueldont<<"\nTrabajo en total: "<<he<<" horas extra.\n";

    }
    
    system("pause");
}
#include <iostream>
#include <windows.h>

using namespace std;

main(){
    int charge, option;

    system("cls");

    cout<<"Ingrese el valor de la recarga: ";
    cin>>charge;

    cout<<"Puede elegir un premio por su recarga!\n";

    cout<<" - Opcion 1: Te duplicamos tu saldo\n - Opcion 2: Tienes 3 Gb para navegar en internet\n - Opcion 3: Whatsapp y Facebook gratis por una semana \n - Opcion 4: Esta noche cuentas con saldo ilimitado\n - Opcion 5: Minutos libres por una semana\n";
    
    cout<<"Escriba un numero segun el regalo que prefiere: \n";
    cin>>option;

    system("cls");

    switch (option)
    {
    case 1:
        cout<<"Tu saldo ha sido duplicado!. Tienes acreditado "<<charge*2<<" de saldo\n";

        break;
    
    case 2:
        cout<<"Tienes Acreditado: "<< charge<< ".Elegiste la opción 2 Se te han acreditado 3Gb de Internet para navegar!\n";

        break;

    case 3:
        cout<<"Tienes Acreditado: " << charge<<". Elegiste la opcion 3. Se ha acreditado el premio de Whatsapp y Facebook gratis por una semana!\n";

        break;

    case 4: 
        cout<<"Tienes Acreditado: " << charge<<". Elegiste la opcion 4. Esta noche cuentas con saldo ilimitado\n";

        break;

    case 5: 
        cout<<"Tienes Acreditado: " << charge<<". Elegiste la opcion 5. Tienes minutos libres por una semana!\n";

        break;
    
    default:
        cout<<"Tienes Acreditado: "<<charge<<". No has seleccionado una Opcion valida\n";
        
        break;
    }

    system("pause");
}
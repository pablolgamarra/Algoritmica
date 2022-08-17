#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int B[11], aux;
    cout << "Cargue un vector y el programa imprimira el mismo pero con los elementos despazados un lugar hacia la izquierda.\n";
    cout << "Cargue el Vector: \n";
    for (int i = 1; i <= 10; i++)
    {
        cout << "Posicion " << i << " : ";
        cin >> B[i];
    }
    aux = B[1];
    system("cls");
    cout << "Vector cargado: \n";
    for (int i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            cout << B[i] << "\n";
        }
        else
        {
            cout << B[i] << " | ";
        }
    }
    cout << "\nVector Desplazado a la izquierda.\n";
    for (int i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            cout << B[1] << "\n";
        }
        else
        {
            cout << B[i + 1] << " | ";
        }
    }
    system("pause");
    return 0;
}

/*
Cargar un vector de 10 elementos y desplazar cíclicamente sus elementos un lugar hacia la
izquierda. Imprimir el vector antes y después de desplazar. 
*/
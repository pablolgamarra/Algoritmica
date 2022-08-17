#include <iostream>
#include <windows.h>

using namespace std;

int n, aux, sw = 0;

void cargaFC(int &n)
{
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "ERROR.\nDebe ingresarse un numero positivo mayor que cero.\n";
        cout << "Vuelva a ingresar cantidad de elementos: ";
        cin >> n;
    }
}

int main()
{
    system("cls");
    cout << "Programa que permite cargar un vector, en el cual no se puede ingresar el mismo elemento mas de una vez.\n";
    cargaFC(n);
    int N[n];
    bool verificado = false;
    do
    {
        for (int i = 1; i <= n; i++)
        {
            verificado = false;
            cout << "Carga de Datos.\n";
            cout << "Elemento " << i << "\n";
            cout << "Valor: ";
            cin >> aux;
            while (!verificado)
            {
                for (int m = 1; m <= i; m++)
                {
                    if (aux == N[m])
                    {
                        sw = 1;
                        break;
                    }
                    else
                    {
                        sw = 0;
                    }
                }
                if (sw == 1)
                {
                    cout << "No pueden haber datos repetidos. Vuelva a ingresar dato de elemento " << i << ": ";
                    cin >> aux;
                    verificado = false;
                }
                else
                {
                    N[i] = aux;
                    verificado = true;
                }
            }
        }
    } while (!verificado);
    cout << "Matriz cargada:\n";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cout << N[i] << "\n";
        }
        else
        {
            cout << N[i] << " | ";
        }
    }
    system("pause");
    return 0;
}

/*
1) Crear y cargar un vector N cuyos elementos no deben estar repetidos. Imprimir el vector. 
*/

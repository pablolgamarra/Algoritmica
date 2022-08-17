#include <iostream>
#include <windows.h>

using namespace std;

int f, c;

void cargaFC(int &f, int &c)
{
    cout << "Ingrese la cantidad de filas: ";
    cin >> f;
    while (f <= 0)
    {
        cout << "ERROR.\nDebe ingresarse un numero positivo mayor que cero.\n";
        cout << "Vuelva a ingresar cantidad de filas: ";
        cin >> f;
    }
    cout << "Ingrese la cantidad de columnas: ";
    cin >> c;
    while (c <= 0)
    {
        cout << "ERROR.\nDebe ingresarse un numero positivo mayor que cero.\n";
        cout << "Vuelva a ingresar cantidad de columnas: ";
        cin >> c;
    }
}
/*
bool comprobacion(){
    for(int m=1;m<=f;m++){
        for(int n=1;n<=c;n++){

        }
    }
}
*/
int main()
{
    system("cls");
    cout << "Programa que permite cargar una matriz, los elementos de la misma no deben estar repetidos.\n";
    cargaFC(f, c);
    system("cls");
    int N[f][c], aux, sw = 0;
    bool verificado = false;
    for (int i = 1; i <= f; i++)
    {
        do
        {
            for (int j = 1; j <= c; j++)
            {
                verificado = false;
                cout << "Carga de Datos.\n";
                cout << "Fila: " << i << "\tColumna: " << j << "\n";
                cout << "Valor: ";
                cin >> aux;
                while (!verificado)
                {
                    for (int m = 1; m <= i; m++)
                    {
                        for (int n = 1; n < j; n++)
                        {
                            if (aux == N[m][n])
                            {
                                sw = 1;
                                break;
                            }
                            else
                            {
                                sw = 0;
                            }
                        }
                    }
                    if (sw == 1)
                    {
                        cout << "No pueden haber datos repetidos. Vuelva a ingresar dato de fila " << i << "\tcolumna " << j << ": ";
                        cin >> aux;
                        verificado = false;
                    }
                    else
                    {
                        N[i][j] = aux;
                        verificado = true;
                    }
                }
            }
        } while (!verificado);
    }
    cout << "Impresion de la matriz cargada: \n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j == c)
            {
                cout << N[i][j] << "\n";
            }
            else
            {
                cout << N[i][j] << " | ";
            }
        }
    }
    system("pause");
    return 0;
}

/*
1) Crear y cargar un vector N cuyos elementos no deben estar repetidos. Imprimir el vector. 
*/
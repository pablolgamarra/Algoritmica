#include <iostream>
#include <windows.h>

using namespace std;

int f, c;

void cargaFC(int &f, int &c)
{
    cout << "Cantidad de filas: ";
    cin >> f;
    while (f <= 0)
    {
        cout << "ERROR. La cantidad de filas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> f;
    }
    cout << "Cantidad de columnas: ";
    cin >> c;
    while (c <= 0)
    {
        cout << "ERROR. La cantidad de columnas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> c;
    }
}


int main(){
    system("cls");
    cout<<"Programa que imprime el perimetro de una matriz.\n";
    cargaFC(f, c);
    int M[f][c], perimetro=0;
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            system("cls");
            cout << "Carga de Datos.\n";
            cout << "Fila: " << i << "\tColumna: " << j << "\n";
            cout << "Valor: ";
            cin >> M[i][j];
        }
    }        
    system("cls");
    cout << "Matriz Cargada: \n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j == c)
            {
                cout << M[i][j] << "\n";
            }
            else
            {
                cout << M[i][j] << " | ";
            }
        }
    }
    cout << "Perimetro de la Matriz Cargada: \n";
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if(i==1 || j==1 || j==c || i==f){
                perimetro=perimetro+M[i][j];
                if (j == c)
                {
                    cout << M[i][j] << "\n";
                }
                else
                {
                    cout << M[i][j] << " | ";
                }
            }else{
                cout<<"   |";
            }
        }
    }
    cout<<"Perimetro de la Matriz: "<<perimetro<<"\n";
    system("pause");
    return 0;
}

/*
Crear y cargar una matriz M. Imprimir la matriz y el perímetro del mismo como se muestra en la figura.
*/
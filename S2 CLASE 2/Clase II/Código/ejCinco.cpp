#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int f, c;
    cout << "Cargue una matriz con numeros positivos mayores a 10 y el programa hallara el mayor y el menor elemento de cada fila, ademas hallara el promedio de cada columna.\n";
    cout << "Cantidad de filas: ";
    cin >> f;
    while (f <= 0)
    {
        cout << "ERROR. La cantidad de filas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> f;
    }
    cout << "Ingrese la cantidad de columnas: ";
    cin >> c;
    while (c <= 0)
    {
        cout << "ERROR. La cantidad de columnas debe ser positivas.\n";
        cout << "Vuelva a ingresar: ";
        cin >> c;
    }
    int A[f][c], MEN[f], MAY[f], men, may;
    float P[c];
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if(i==1){
                P[j]=0;
            }
            system("cls");
            cout << "Carga de Datos.\n";
            cout << "Fila: " << i << "\tColumna: " << j << "\n";
            cout << "Valor: ";
            cin >> A[i][j];
            while ((A[i][j] < 0) || A[i][j] > 10)
            {
                cout << "ERROR. Deben ingresarse numeros positivos menores a 10.Volver a ingresar dato!\n";
                cout << "Fila: " << i << "\tColumna: " << j << "\n";
                cout << "Valor: ";
                cin >> A[i][j];
            }
            P[j] = P[j] + A[i][j];
            if (j == 1)
            {
                men = A[i][j];
                may = A[i][j];
            }
            if (A[i][j] > may)
            {
                may = A[i][j];
            }
            else if (A[i][j] < men)
            {
                men = A[i][j];
            }
            MEN[i] = men;
            MAY[i] = may;
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
                cout << A[i][j] << "\n";
            }
            else
            {
                cout << A[i][j] << " | ";
            }
        }
    }
    cout << "Vector de Mayores de Cada Fila: \n";
    for (int i = 1; i <= f; i++)
    {
        cout << " | " << MAY[i] << " | \n";
    }
    cout << "Vector de Menores de Cada Fila: \n";
    for (int i = 1; i <= f; i++)
    {
        cout << " | " << MEN[i] << " | \n";
    }
    cout<<"Vector de Promedios de Cada Columna: \n";
    for (int i = 1; i <= c; i++)
    {
        if (i == c)
        {
            cout << (P[i])/f << "\n";
        }
        else
        {
            cout << (P[i])/f << " | ";
        }
    }
    system("pause");
    return 0;
}
/*
Cargar una matriz A con cualquier número positivo menor a 10. Hallar el mayor, menor elemento de cada fila y
el promedio de cada columna. (Considerar los vectores Men, May y P) 
*/
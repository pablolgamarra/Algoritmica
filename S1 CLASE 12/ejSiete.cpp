#include <iostream>
#include <windows.h>

using namespace std;

int iA, iB, iC, iS, elementosA, elementosB, elementosC, elementosS;

int main()
{
    system("cls");
    cout << "El programa crea un Vector S apartir de los vectores A, B y C.\n";
    cout << "Ingrese la cantidad de elementos que tendra el vector 'A': ";
    cin >> elementosA;
    while (elementosA <= 0)
    {
        cout << "ERROR. Cada vector debe tener al menos un elemento.\n";
        cout << "Ingrese la cantidad de elementos que tendra el vector 'A': ";
        cin >> elementosA;
    }
    system("cls");
    cout << "Ingrese la cantidad de elementos que tendra el vector 'B': ";
    cin >> elementosB;
    while (elementosB <= 0)
    {
        cout << "ERROR. Cada vector debe tener al menos un elemento.\n";
        cout << "Ingrese la cantidad de elementos que tendra el vector 'A': ";
        cin >> elementosB;
    }
    system("cls");
    cout << "Ingrese la cantidad de elementos que tendra el vector 'C': ";
    cin >> elementosC;
    while (elementosC <= 0)
    {
        cout << "ERROR. Cada vector debe tener al menos un elemento.\n";
        cout << "Ingrese la cantidad de elementos que tendra el vector 'A': ";
        cin >> elementosC;
    }
    elementosS = elementosA + elementosB + elementosC;
    int A[elementosA], B[elementosB], C[elementosC], S[elementosS];
    system("cls");
    // Vector A
    cout << "Carga de Elementos. Vector A.\n";
    for (int iA = 1; iA <= elementosA; iA++)
    {
        cout << "Ingrese elemento para posicion " << iA << " : ";
        cin >> A[iA];
        S[iA] = A[iA];
    }
    //Vector B
    system("cls");
    cout << "Carga de Elementos. Vector B.\n";
    for (int iB = 1; iB <= elementosB; iB++)
    {
        cout << "Ingrese elemento para posicion " << iB << " : ";
        cin >> B[iB];
        S[elementosA + iB] = B[iB];
    }
    //Vector C
    system("cls");
    cout << "Carga de Elementos. Vector C.\n";
    for (int iC = 1; iC <= elementosC; iC++)
    {
        cout << "Ingrese elemento para posicion " << iC << " : ";
        cin >> C[iC];
        S[elementosA + elementosB + iC] = C[iC];
    }
    //Vector S
    system("cls");
    cout << "Se cargaran los datos de los vectores anteriores al Vector 'S'\n";
    system("pause");
    system("cls");
    cout << "Vector 'A': ";
    for (int iA = 1; iA <= elementosA; iA++)
    {
        if (iA != elementosA)
        {
            cout << A[iA] << " | ";
        }
        else
        {
            cout << A[iA] << "\n";
        }
    }
    cout << "Vector 'B': ";
    for (int iB = 1; iB <= elementosB; iB++)
    {
        if (iB != elementosB)
        {
            cout << B[iB] << " | ";
        }
        else
        {
            cout << B[iB] << "\n";
        }
    }
    cout << "Vector 'C': ";
    for (int iC = 1; iC <= elementosC; iC++)
    {
        if (iC != elementosC)
        {
            cout << C[iC] << " | ";
        }
        else
        {
            cout << C[iC] << "\n";
        }
    }
    cout << "Vector 'S': ";
    for (int iS = 1; iS <= elementosS; iS++)
    {
        if (iS != elementosS)
        {
            cout << S[iS] << " | ";
        }
        else
        {
            cout << S[iS] << "\n";
        }
    }
    system("pause");
    return 0;
}
/*
Dimensionar un vector A, B y C, además crear a partir de los anteriores, otro vector S que contendrá
los elementos de los vectores (A, B y C) ordenados en forma consecutiva. Imprimir los vectores en
cuestión
*/
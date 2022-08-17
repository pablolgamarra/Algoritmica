#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X= x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon, dwPos);
    return;
}

int main(){
    int posCaballoUno, posCaballoDos;
    system("cls");
    cout<<"Simulador de Carreras de Caballos.\nEl juego simula una carrera entre dos caballos.\n";
    system("pause");
    system("cls");
    srand((unsigned)time(NULL));
    posCaballoUno = rand()%80+1;
    posCaballoDos = rand()%80+1;
    gotoxy(posCaballoUno, 1);
    cout<<"Caballo Uno";
    gotoxy(posCaballoDos, 3);
    cout<<"Caballo Dos\n";
    if(posCaballoUno < posCaballoDos){
        cout<<"Ha ganado el 'Caballo Uno'\n";
    }else if(posCaballoUno > posCaballoDos){
        cout<<"Ha ganado el 'Caballo Dos'\n";
    }else{
        cout<<"Ha acabado en empate.\n";
    }
    system("pause");
    return 0;
}
/*
Simular la carrera de dos caballos, si cada uno tiene igual posibilidad de ganar (es un ejercicio
de desafío, considerar la función gotoxy, es exclusivo para investigar)
*/
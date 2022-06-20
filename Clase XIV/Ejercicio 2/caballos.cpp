#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
/*Simular la carrera de dos caballos,
si cada uno tiene igual posibilidad de ganar*/
using namespace std;
int main() {
	char op;
	int n, n2, c = 0, c1 = 0, c2 = 0, sw = 0, lim1 = 0, lim2 = 0;
	srand((unsigned)time(NULL));

	cout << "===============!" << endl;
	cout << "1" << endl;
	cout << "2" << endl;
	cout << "===============!" << endl;
	cout << "Iniciar(S/N)?" << endl;
	cin >> op;
	while ((op == 's') && (sw == 0)) {
		Sleep(100);
		system("cls");
		cout << "===============!" << endl;
		c1 = 0;
		c2 = 0;
		n = int(rand() % 2) + 1;
		if (n == 1) {
			lim1++;
		}
		else {
			lim2++;
		}
		while (c1 < lim1) {
			c1++;
			cout << " ";
		}
		cout << "1" << endl;
		while (c2 < lim2) {
			c2++;
			cout << " ";
		}
		cout << "2" << endl;
		if ((lim1 == 15) || (lim2 == 15) && (sw == 0)) {
			sw = 1;
		}
		cout << "===============!" << endl;
	}
	cout << "-------------------" << endl;
	if (lim1 == 15) {
		cout << "Gano el 1" << endl;
	}
	else {
		cout << "Gano el 2" << endl;
	}
	system("pause");

	return 0;
}
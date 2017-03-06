// Zadanie3.cpp 
// Amadeusz Wach

#include "stdafx.h"
#include <iostream>

using namespace std;

int Potega(int x, int p) {
	if (p == 0) return 1; else return x = x*Potega(x, p - 1);
}

int Silnia(int x) {
	if (x == 0) return 1;
	return x*Silnia(x - 1);
}

int main()
{
	bool isExit = false;
	int choice;
	system("cls");

	cout << "1. Oblicz potege" << endl;
	cout << "2. Oblicz silnie" << endl;
	cout << "3. Koniec programu" << endl;

	while (!isExit) {
		cout << "Twoj wybor: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				int x, p;
				cout << "Podaj podstawe potegi: ";
				cin >> x;
				cout << "Podaj wykladnik: ";
				cin >> p;
				cout << "Wynik: " << Potega(x, p) << endl;
				break;
			}
			case 2: {
				int x;
				cout << "Podaj liczbe: ";
				cin >> x;
				if (x < 0) cout << "Silnie mozna obliczyc tylko z nieujemnej liczby" << endl;
					else cout << "Wynik: " << Silnia(x) << endl;
				break;
			}
			case 3: {
				isExit = true;
				break;
			}
		
			default: {
				cout << "Nie znaleziono opcji, sprobuj ponownie!" << endl;
			}
		}
	}

	cin.ignore();
	return 0;
}


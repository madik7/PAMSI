// Zadanie4.cpp
// Amadeusz Wach

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool jestPal(string testStr) {
	if (testStr.size() == 1 || testStr.size() == 0) return true;
	if (testStr.front() == testStr.back())
		return jestPal(testStr.substr(1, testStr.size() - 2));
	else return false;
}

int main()
{
	bool isExit = false;
	int choice;
	system("cls");

	cout << "1. Sprawdzanie czy slowo jest palindromem" << endl;
	cout << "2. Koniec programu" << endl;
	string word;
	while (!isExit) {
		cout << "Twoj wybor: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				
				cout << "Podaj slowo: ";
				cin >> word;
				if (jestPal(word)) cout << "Slowo jest palindromem" << endl; else cout << "Slowo nie jest palindromem" << endl;
				break;
			}
			case 2: {
				isExit = true;
				break;
			}

			default: {
				cout << "Nie znaleziono opcji, sprobuj ponownie!" << endl;
			}
		}
	}

	return 0;
}


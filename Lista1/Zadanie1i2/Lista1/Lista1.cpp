// Lista1.cpp
// Amadeusz Wach
// Zadanie 1 i 2


#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

void fillArray(int ** array, int x, unsigned int rows, unsigned int columns) {
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			array[i][j] = rand() % (x + 1);
		}
	}
}

void displayArray(int ** array, unsigned int rows, unsigned int columns) {
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

int maxOfArray(int ** array, unsigned int rows, unsigned int columns) {
	int max = 0;
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			if (max < array[i][j]) max = array[i][j];
		}
	}
	return max;
}

void writeFromArray(fstream& file, int ** array, unsigned int rows, unsigned int columns, bool binary = false) {
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			if (binary) file.write((const char *)& array[i][j], sizeof array[i][j]);  else file << array[i][j] << " ";
		}
		if (!binary) file << endl;
	}
}

void readToArray(fstream& file, int ** array, unsigned int rows, unsigned int columns, bool binary = false) {
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			if (binary) file.read((char *)& array[i][j], sizeof array[i][j]);  else file >> array[i][j];
		}
	}
}

int main()
{
	srand((unsigned int)time(0));

	unsigned int rows;
	unsigned int columns;

	bool isExit = false;

	int x;
	int choice;

	string fileName;
	fstream file;

	int ** array;

	cout << "Podaj ilosc wierszy: ";
	cin >> rows;

	cout << "Podaj ilosc kolumn: ";
	cin >> columns;

	array = new int *[rows];

	for (unsigned int i = 0; i < rows; i++) {
		array[i] = new int[columns];
	}

	system("cls");

	cout << "1. Wylosuj wartosci do tablicy" << endl;
	cout << "2. Wyswietl zawartosc tablicy" << endl;
	cout << "3. Znajdz najwieksza wartosc w tablicy" << endl;
	cout << "4. Zapisz tablice do pliku tekstowego" << endl;
	cout << "5. Wczytaj tablice z pliku tekstowego" << endl;
	cout << "6. Zapisz tablice do pliku binarnego" << endl;
	cout << "7. Wczytaj tablice do pliku binarnego" << endl;
	cout << "8. Zakoncz program" << endl;

	while (!isExit) {
		cout << "Twoj wybor: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				cout << "Podaj x" << endl;
				cin >> x;
				fillArray(array, x, rows, columns);
				break;
			}
			case 2: {
				displayArray(array, rows, columns);
				break;
			}
			case 3: {
				cout << "Maksymalna wartosc: " << maxOfArray(array, rows, columns) << endl;
				break;
			}
			case 4: {
				cout << "Podaj nazwe pliku: ";
				cin >> fileName;
				file.open(fileName, ios::out);
				if (file.good() == true)
					writeFromArray(file, array, rows, columns);
				else cout << "Blad odczytu pliku!";
				file.close();
				break;
			}
			case 5: {
				cout << "Podaj nazwe pliku: ";
				cin >> fileName;
				file.open(fileName, ios::in);
				if (file.good() == true)
					readToArray(file, array, rows, columns);
				else cout << "Blad odczytu pliku!";
				file.close();
				break;
			}
			case 6: {
				cout << "Podaj nazwe pliku: ";
				cin >> fileName;
				file.open(fileName, ios::out | ios::binary);
				if (file.good() == true)
					writeFromArray(file, array, rows, columns, true);
				else cout << "Blad odczytu pliku!";
				file.close();
				break;
			}
			case 7: {
				cout << "Podaj nazwe pliku: ";
				cin >> fileName;
				file.open(fileName, ios::in | ios::binary);
				if (file.good() == true)
					readToArray(file, array, rows, columns, true);
				else cout << "Blad odczytu pliku!";
				file.close();
				break;
			}

			case 8: {
				isExit = true;
				break;
			}
			default: {
				cout << "Nie znaleziono opcji, sprobuj ponownie!" << endl;
			}
		}
	}

	for (unsigned int i = 0; i < rows; i++) {
		delete array[i];
	}

	delete[] array;
	return 0;
}

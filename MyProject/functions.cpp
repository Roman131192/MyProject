#include <iostream>
#include <Windows.h>
#include "function.h"
using namespace std;

void Screensaver()
{
	cout << "\t              x\n\t   _|_|_       x   x\n\t   _|_|_        x x  _|_|_\n\t    | |          x   _|_|_\n\t";
	cout << "        _|_|_   x x   | |\n\t000000  _|_|_  x   x\n\t0    0   | |        x\n\t";
	cout << "0    0       _|_|_\n\t0    0       _|_|_\n\t000000        | |\n";
	Sleep(3000);
	system("cls");
	cout << "| | |\t\t\t\t| | |\n\\ \\/\t\t\t\t\\ \\/\n/\\ \\\t\tВІТАЮ\t\t/\\ \\\n| | |\t\t\t\t| | |\n\\ \\/\t\t\t\t\\ \\/\n/\\ \\\t\t\t\t/\\ \\\n";
	Sleep(2000);
	system("cls");
	cout << "| | |\t\t\t\t| | |\n\\ \\/\t\t\t\t\\ \\/\n/\\ \\\t\tТИ\t\t/\\ \\\n| | |\t\t\t\t| | |\n\\ \\/\t\t\t\t\\ \\/\n/\\ \\\t\t\t\t/\\ \\\n";
	Sleep(2000);
	system("cls");
	cout << "| | |\t\t\t\t| | |\n\\ \\/\t\t\t\t\\ \\/\n/\\ \\\t\tВ ГРІ\t\t/\\ \\\n| | |\t\t\t\t| | |\n\\ \\/\t\t\t\t\\ \\/\n/\\ \\\t\t\t\t/\\ \\\n";
	Sleep(2000);
	system("cls");

	cout << "\n\n";
}

void ShowCells(char cells[], int size)
{
	system("cls");

	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << cells[0] << "  |  " << cells[1] << "  |  " << cells[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << cells[3] << "  |  " << cells[4] << "  |  " << cells[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << cells[6] << "  |  " << cells[7] << "  |  " << cells[8] << endl;
	cout << "     |     |     " << endl << endl;

}

void Register(char name1[], char name2[], char* userSymbol1, char* userSymbol2)
{
	system("cls");
	cout << "Введіть ім'я першого гравця\n";
	cin.getline(name1, 20);
	cout << "Введіть ім'я другого гравця\n";
	cin.getline(name2, 20);
	size_t symbol;
	bool menu;
	do
	{
		system("cls");
		cout << "Гравець " << name1 << ", виберіть чим бажаєте грати\nХ - натисніть 1\nО - натисніть 2\n";
		cin >> symbol;
		menu = false;
		if (symbol == 1)
		{
			*userSymbol1 = 'X';
			*userSymbol2 = 'O';
		}
		else if (symbol == 2)
		{
			*userSymbol1 = 'O';
			*userSymbol2 = 'X';
		}
		else
		{
			cout << "Ввід неправильний, спробуйте ще раз\n";
			menu = true;
		}
	} while (menu == true);
}

int GameOver(char cells[], int size)
{
	int rows = 0;
	for (size_t i = 0; i < 3; i++)
	{
		if (cells[rows] == cells[rows + 1] && cells[rows + 1] == cells[rows + 2])
			return -1;
		rows += 3;//горизонталь
	}
	int cols = 0;
	for (size_t i = 0; i < 3; i++)
	{
		if (cells[cols] == cells[cols + 3] && cells[cols + 3] == cells[cols + 6])
			return -1;//вертикаль
	}

	if (cells[0] == cells[4] && cells[4] == cells[8] || cells[2] == cells[4] && cells[4] == cells[6])
		return -1;//діагональ

	int draw = 0;//нічия
	for (int i = 0; i < size; i++)
	{
		if (cells[i] == 'X' || cells[i] == 'O')
			draw++;
	}
	if (draw == size)
		return 0;
	return 1;
}
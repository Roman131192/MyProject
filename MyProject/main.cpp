#include <iostream>
#include <ctime>
#include <Windows.h>
#include "function.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(nullptr));

	const int SIZE = 9;
	char cells[SIZE] = { '1','2','3','4','5','6','7','8','9' };
	size_t menu;
	bool exit = true;
	//Screensaver();
	int gameOver = 1;
	size_t choice;
	size_t player = 1;
	do
	{
		system("cls");
		cout << "\t\t\tMЕНЮ\nГрати з другом\t\t\tнатисніть 1\nГрати з комп'ютером\t\tнатисніть 2\nВихід\t\t\t\tнатисніть 3\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			char name1[20], name2[20];
			char userSymbol1, userSymbol2;
			cin.ignore();
			Register(name1, name2, &userSymbol1, &userSymbol2);
			/*do*/
			//{
				ShowCells(cells, SIZE);
				do
				{
					if (player % 2 != 0)
					{
						cout << "Гравець " << name1 << " зробіть свій вибір ";
						cin >> choice;
						cells[choice - 1] = userSymbol1;
					}
					else
					{
						cout << "Гравець " << name2 << " зробіть свій вибір ";
						cin >> choice;
						cells[choice - 1] = userSymbol2;
					}
					system("cls");
					ShowCells(cells, SIZE);
					gameOver = GameOver(cells, SIZE);
					if (gameOver == 0)
					{
						cout << "Нажаль у вашому противостоянні не виявилось переможця\n";
						Sleep(3000);
					}
					else if (gameOver == -1)
					{
						if (player % 2 != 0)
						{
							cout << "Переміг гравець - " << name1 << ". ВІТАЮ!!!\n";
							Sleep(3000);
						}
						else
						{
							cout << "Переміг гравець - " << name2 << ". ВІТАЮ!!!\n";
							Sleep(3000);
						}
					}
					player++;
				} while (gameOver == 1);
			//	cout << "Бажаєте зіграти ще раз\tнатисніть любу клавішу і ENTER\n";
			//	cout << "Вихід в головне меню\tнатисніть 0\n"; /////////доробить
			//	cin >> choice;
			//	if (choice == 2)
			//		break;
			//	for (size_t i = 0; i < SIZE; i++)
			//	{
			//		cells[i] = i + 1;
			//	}
			//} while (true);
			break;
		case 2:
			size_t level;
			cout << "Виберіть рівень складності\nЛегкий\t\tНатисніть 1\nСередній\tНатисніть 2\nВажкий\t\tНатисніть 3\n\nНазад\t\tНатисніть 4\n";
			cin >> level;
			switch (level)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				cout << "Ви ввели невірний символ\n";
			}

			break;
		case 3:
			exit = false;
			break;
		default:
			cout << "Ви ввели не вірний символ, спробуйте ще раз\n";
		}
	} while (exit == true);

	system("pause");
	return 0;
}
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
		cout << "\t\t\tM���\n����� � ������\t\t\t�������� 1\n����� � ����'������\t\t�������� 2\n�����\t\t\t\t�������� 3\n";
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
						cout << "������� " << name1 << " ������ ��� ���� ";
						cin >> choice;
						cells[choice - 1] = userSymbol1;
					}
					else
					{
						cout << "������� " << name2 << " ������ ��� ���� ";
						cin >> choice;
						cells[choice - 1] = userSymbol2;
					}
					system("cls");
					ShowCells(cells, SIZE);
					gameOver = GameOver(cells, SIZE);
					if (gameOver == 0)
					{
						cout << "������ � ������ ������������� �� ��������� ���������\n";
						Sleep(3000);
					}
					else if (gameOver == -1)
					{
						if (player % 2 != 0)
						{
							cout << "������ ������� - " << name1 << ". ²���!!!\n";
							Sleep(3000);
						}
						else
						{
							cout << "������ ������� - " << name2 << ". ²���!!!\n";
							Sleep(3000);
						}
					}
					player++;
				} while (gameOver == 1);
			//	cout << "������ ������ �� ���\t�������� ���� ������ � ENTER\n";
			//	cout << "����� � ������� ����\t�������� 0\n"; /////////��������
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
			cout << "������� ����� ���������\n������\t\t�������� 1\n�������\t�������� 2\n������\t\t�������� 3\n\n�����\t\t�������� 4\n";
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
				cout << "�� ����� ������� ������\n";
			}

			break;
		case 3:
			exit = false;
			break;
		default:
			cout << "�� ����� �� ����� ������, ��������� �� ���\n";
		}
	} while (exit == true);

	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

void print_colored_text(std::string *strs, int str_num)
{
	if (str_num < 1 || str_num > 3)
		return;
	for (int i = 0; i < str_num - 1; i++)
		std::cout << strs[i] << '\n';
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	std::cout << strs[str_num - 1] << '\n'; 
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = str_num; i < 3; i++)
		std::cout << strs[i] << '\n';
}

int main()
{
	setlocale(0, "rus");

	std::ifstream in;
	in.open("input.dat");

	std::string strs[3];

	std::getline(in, strs[0], '\n');
	std::getline(in, strs[1], '\n');
	std::getline(in, strs[2], '\n');

	std::cout << strs[0] << '\n';
	std::cout << strs[1] << '\n';
	std::cout << strs[2] << '\n';

	std::cout << "\n\nНажмите любую клавишу (Esc - для выхода): ";
	int current_condition = 3;
	while (true)
	{
		if(_kbhit())
			if (_getch() == 27)
				break;
			else
			{
				system("cls");
				if (current_condition == 3)
					current_condition = 2;
				else
					if (current_condition == 2)
						current_condition = 1;
					else
						if (current_condition == 1)
							current_condition = 3;
				print_colored_text(strs, current_condition);
				std::cout << "\n\nНажмите любую клавишу (Esc - для выхода): ";
			}

	}

	std::cout << "\n\n";
	return 0; 
}
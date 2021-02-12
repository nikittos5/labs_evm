#include <iostream>
#include <windows.h>
#include <conio.h>

#define MAX_CHARS 70

void print_colored_text(char** strs, int str_num)
{
	if (str_num < 1 || str_num > 3)
		return;
	for (int i = 0; i < str_num - 1; i++)
		std::cout << strs[i];
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	std::cout << strs[str_num - 1];
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = str_num; i < 3; i++)
		std::cout << strs[i];
}

int main()
{
	setlocale(0, "rus");

	FILE* in;
	fopen_s(&in, "input.dat", "r");

	char** strs = new char*[3];
	strs[0] = new char[MAX_CHARS];
	strs[1] = new char[MAX_CHARS];
	strs[2] = new char[MAX_CHARS];

	fgets(strs[0], MAX_CHARS, in);
	fgets(strs[1], MAX_CHARS, in);
	fgets(strs[2], MAX_CHARS, in);

	std::cout << strs[0];
	std::cout << strs[1];
	std::cout << strs[2];

	std::cout << "\n\nНажмите любую клавишу (Esc - для выхода): ";
	int current_condition = 3;
	while (true)
	{
		if (_kbhit())
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

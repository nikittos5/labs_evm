#include <iostream>
#include "11.h"

int main()
{
	setlocale(0, "rus");

	scan_read_write();

	int scan_num;
	std::cout << "Введите номер сканера: ";
	std::cin >> scan_num;

	if (!scan_read(scan_num))
		std::cout << "\nЧтение успешно";
	else
		std::cout << "\nЧтение неудачно";

	std::cout << "\n\n";
	return 0;
}
#include <iostream>
#include <string>
#include <fstream>

struct scan_info {
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

void scan_read_write()
{
	std::ofstream out;

	int scan_count;
	std::cout << "Введите количество сканеров: ";
	std::cin >> scan_count;

	scan_info* scans = new scan_info[scan_count];

	for (int i = 0; i < scan_count; i++)
	{
		std::cout << "\nВведите данные о сканере";
		std::cout << "\nНаименование модели: ";
		std::cin >> scans[i].model;
		std::cout << "Цена: ";
		std::cin >> scans[i].price;
		std::cout << "Горизонтальный размер области сканирования: ";
		std::cin >> scans[i].x_size;
		std::cout << "Вертикальный размер области сканирования: ";
		std::cin >> scans[i].y_size;
		std::cout << "Оптическое разрешение: ";
		std::cin >> scans[i].optr;
		std::cout << "Число градаций серого: ";
		std::cin >> scans[i].grey;
		std::cout << '\n';
	}

	try
	{
		out.open("output.bin", std::ios_base::binary);
	}
	catch (const std::exception&)
	{
		std::cout << "\n\nОшибка при открытии файла записи\n\n";
		return;
	}
	out.write((char*)&scan_count, sizeof(scan_count));
	for (int i = 0; i < scan_count; i++)
	{
		out.write(scans[i].model, sizeof(scans[i].model));
		out.write((char*)&scans[i].price, sizeof(scans[i].price));
		out.write((char*)&scans[i].x_size, sizeof(scans[i].x_size));
		out.write((char*)&scans[i].y_size, sizeof(scans[i].y_size));
		out.write((char*)&scans[i].optr, sizeof(scans[i].optr));
		out.write((char*)&scans[i].grey, sizeof(scans[i].grey));
	}
	out.close();
}

int scan_read(int scan_num)
{
	std::ifstream in;
	try
	{
		in.open("output.bin", std::ios_base::binary);
	}
	catch (const std::exception&)
	{
		return -1;
	}

	int scan_count;
	char buffer[100];
	scan_info scan;

	in.read(buffer, sizeof(scan_count));
	scan_count = *(int*)buffer;
	
	if (scan_num > scan_count || scan_num < 1)
		return -1;

	in.seekg((long long) sizeof(scan_count) + ((long long) scan_num - (long long) 1) * (long long) 53);

	in.read(buffer, sizeof(scan.model));
	strcpy_s(scan.model, buffer);
	in.read(buffer, sizeof(scan.price));
	scan.price = *(int*)buffer;
	in.read(buffer, sizeof(scan.x_size));
	scan.x_size = *(double*)buffer;
	in.read(buffer, sizeof(scan.y_size));
	scan.y_size = *(double*)buffer;
	in.read(buffer, sizeof(scan.optr));
	scan.optr = *(int*)buffer;
	in.read(buffer, sizeof(scan.grey));
	scan.grey = *(int*)buffer;

	in.close();



	return 0;
}

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
		std::cout << "\nЧтение неуспешно";

	std::cout << "\n\n";
	return 0;
}

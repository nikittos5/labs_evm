#include <iostream>
#include <string>

#define STRUCT_SIZE 53
#define ll (long long) 

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
	FILE* out;

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

	fopen_s(&out, "output.bin", "wb");
	fwrite(&scan_count, sizeof(scan_count), 1, out);
	for (int i = 0; i < scan_count; i++)
	{
		fwrite(scans[i].model, sizeof(sizeof(scans[i].model[0])), 1, out);
		fwrite(&scans[i].price, sizeof(scans[i].price), 1, out);
		fwrite(&scans[i].x_size, sizeof(scans[i].x_size), 1, out);
		fwrite(&scans[i].y_size, sizeof(scans[i].y_size), 1, out);
		fwrite(&scans[i].optr, sizeof(scans[i].optr), 1, out);
		fwrite(&scans[i].grey, sizeof(scans[i].grey), 1, out);
	}
	fclose(out);
}

int scan_read(int scan_num)
{
	FILE* in = nullptr;
	fopen_s(&in, "output.bin", "rb");

	int scan_count;
	scan_info scan;

	fread(&scan_count, sizeof(scan_count), 1, in);

	if (scan_num > scan_count || scan_num < 1)
		return -1;

	fseek(in, sizeof(scan_count) + (ll scan_num - ll 1) * 53, SEEK_SET);

	fread(scan.model, sizeof(scan.model[0]), sizeof(scan.model), in);
	fread(&scan.price, sizeof(scan.price), 1, in);
	fread(&scan.x_size, sizeof(scan.x_size), 1, in);
	fread(&scan.y_size, sizeof(scan.y_size), 1, in);
	fread(&scan.optr, sizeof(scan.optr), 1, in);
	fread(&scan.grey, sizeof(scan.grey), 1, in);

	fclose(in);

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
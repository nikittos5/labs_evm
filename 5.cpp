#include <iostream>
#include <string>
#include <algorithm>

struct AEROFLOT
{
	std::string destination_point;
	int flight_num;
	std::string plane_type;
};

bool compare(AEROFLOT a, AEROFLOT b)
{
	return a.flight_num < b.flight_num;
}

int main()
{
	setlocale(0, "rus");

	const int n = 7;
	AEROFLOT flight_list[n];
	
	for (int i = 0; i < n; i++)
	{
		std::cout << "Введите название пункта назначения, номер рейса и тип самолета";
		std::cout << "\nПункт назначения: ";
		std::cin >> flight_list[i].destination_point;
		std::cout << "Номер рейса: ";
		std::cin >> flight_list[i].flight_num;
		std::cout << "Тип самолета: ";
		std::cin >> flight_list[i].plane_type;
		std::cout << '\n';
	}

	std::sort(std::begin(flight_list), std::end(flight_list), compare);

	std::string destination_point;
	std::cout << "Введите название пункта назначения: ";
	std::cin >> destination_point;

	bool flights_exist = false;
	std::cout << "\n\nРейсы, летящие в " << destination_point << ": ";
	for (int i = 0; i < n; i++)
	{
		if (flight_list[i].destination_point == destination_point)
		{
			flights_exist = true;
			std::cout << "\nНомер рейса: " << flight_list[i].flight_num << ". Тип самолета: " << flight_list[i].plane_type << ".";
		}
	}
	if (!flights_exist)
		std::cout << "не найдены. ";


	std::cout << "\n\n";
	return 0;
}

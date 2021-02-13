#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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

	const int n = 2;
	std::vector<AEROFLOT> flight_list(n);

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

	std::sort(flight_list.begin(), flight_list.end(), [](AEROFLOT a, AEROFLOT b) {return a.flight_num > b.flight_num; });

	std::string destination_point;
	std::cout << "Введите название пункта назначения: ";
	std::cin >> destination_point;

	std::cout << "\n\nРейсы, летящие в " << destination_point << ": ";
	
	auto result = std::find_if(flight_list.begin(), flight_list.end(), 
		[&destination_point](const AEROFLOT flight) {return flight.destination_point == destination_point; });

	if (result == flight_list.end())
		std::cout << "не найдены. ";
	else
		while (result != flight_list.end())
		{
			std::cout << "\nНомер рейса: " << (*result).flight_num << ". Тип самолета: " << (*result).plane_type << ".";
			result++;
		}

	std::cout << "\n\n";
	return 0;
}

#include <iostream>
#include <time.h>

int main()
{
	const int n = 10;
	const double max_rand = 2.0, min_rand = -2.0;
	double arr[n], sum = 0;
	int first_neg = -1, second_neg = -1;

	srand(time(NULL));
	setlocale(0, "rus");

	std::cout << "Массив: ";
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)(rand()) / (double)RAND_MAX * (max_rand - min_rand) + min_rand;
		std::cout << arr[i] << ' ';
	}
	for (int i = 0; i < n; i++)
	{
		sum += i % 2 == 1 ? arr[i] : 0;
	}
	std::cout << "\n\nСумма элементов с нечетными номерами: " << sum;;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			first_neg = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			second_neg = i;
			break;
		}
	}
	for (int i = first_neg+1; i < second_neg; i++)
	{
		sum += arr[i];
	}
	std::cout << "\n\nСумма элементов между первым и последним отрицательным элементами: " << sum;

	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(arr[i]) <= 1)
		{
			s++;
			continue;
		}
		arr[i - s] = arr[i];
	}
	for (int i = n - 1; i > n - 1 - s; i--)
	{
		arr[i] = 0;
	}

	std::cout << "\n\nСжатый массив: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
	
	std::cout << "\n\n";
	return 0; 
}

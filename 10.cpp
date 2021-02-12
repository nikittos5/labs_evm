#include <iostream>
#include <time.h>
#include <typeinfo>

template <typename T>
void sum_of_odds(T* arr, int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += i % 2 == 1 ? arr[i] : 0;
	std::cout << "\nСумма элементов (" << typeid(T).name() << ") с нечетными номерами: " << sum;
	return;
}

template <typename T>
void sum_betw_negs(T* arr, int n)
{
	T sum = 0;
	int first_neg = -1, second_neg = -1;
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
	for (int i = first_neg + 1; i < second_neg; i++)
	{
		sum += arr[i];
	}
	std::cout << "\nСумма элементов (" << typeid(T).name() << ") между первым и последним отрицательным элементами: " << sum;
}

template <typename T>
void compres_arr(T* arr, int n)
{
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

	std::cout << "\nСжатый массив (" << typeid(T).name() << "): ";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

int main()
{
	const int n = 10;
	const double max_rand = 5.0, min_rand = -5.0;
	int arr1[n];
	float arr2[n];
	double arr3[n];

	srand(time(NULL));
	setlocale(0, "rus");

	std::cout << "Массив (int): ";
	for (int i = 0; i < n; i++)
	{
		arr1[i] = rand() % ((int)max_rand - (int)min_rand + 1) + (int)min_rand;
		std::cout << arr1[i] << ' ';
	}

	std::cout << "\nМассив (float): ";
	for (int i = 0; i < n; i++)
	{
		arr2[i] = (float)(rand()) / (float)RAND_MAX * ((float)max_rand - (float)min_rand) + (float)min_rand;
		std::cout << arr2[i] << ' ';
	}

	std::cout << "\nМассив (double): ";
	for (int i = 0; i < n; i++)
	{
		arr3[i] = (double)(rand()) / (double)RAND_MAX * (max_rand - min_rand) + min_rand;
		std::cout << arr3[i] << ' ';
	}

	std::cout << "\n\n";

	sum_of_odds<int>(arr1, n);
	sum_of_odds<float>(arr2, n);
	sum_of_odds<double>(arr3, n);

	std::cout << "\n\n";

	sum_betw_negs<int>(arr1, n);
	sum_betw_negs<float>(arr2, n);
	sum_betw_negs<double>(arr3, n);

	std::cout << "\n\n";

	compres_arr<int>(arr1, n);
	compres_arr<float>(arr2, n);
	compres_arr<double>(arr3, n);

	std::cout << "\n\n";
	return 0; 
}

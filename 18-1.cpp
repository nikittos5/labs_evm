#include <iostream>
#include <time.h>
#include <valarray>

int main()
{
	const int n = 10;
	const double max_rand = 2.0, min_rand = -2.0;
	double sum = 0;
	std::valarray<double> arr(n);
	int first_neg = -1, second_neg = -1;

	srand(time(NULL));
	setlocale(0, "rus");

	std::cout << "Массив: ";
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)(rand()) / (double)RAND_MAX * (max_rand - min_rand) + min_rand;
		std::cout << arr[i] << ' ';
	}
	sum = ((std::valarray<double>) arr[*(new std::slice(1, n / 2, 2))]).sum();
	std::cout << "\n\nСумма элементов с нечетными номерами: " << sum;;
	sum = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] < 0)
		{
			first_neg = i;
			break;
		}
	for (int i = n - 1; i >= 0; i--)
		if (arr[i] < 0)
		{
			second_neg = i;
			break;
	}
	sum = ((std::valarray<double>) arr[*(new std::slice(first_neg + 1, second_neg - first_neg - 1, 1))]).sum();
	std::cout << "\n\nСумма элементов между первым и последним отрицательным элементами: " << sum;
	std::valarray<double> arr2 = arr[abs(arr) > 1];
	std::cout << "\n\nСжатый массив: ";
	for (int i = 0; i < n; i++)
	{
		if (i < arr2.size())
		{
			std::cout << arr2[i] << ' ';
			arr[i] = arr2[i];
		}
		else
		{
			std::cout << "0 ";
			arr[i] = 0;
		}
	}
	std::cout << "\n\n";
	return 0;
}

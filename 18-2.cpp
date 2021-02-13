#include <iostream>
#include <time.h>
#include <valarray>
#include <algorithm>

#define slice new std::slice
#define valarray std::valarray<int>

int main()
{
	const int n = 5;
	const int max_rand = 50, min_rand = -10;
	valarray arr(n*n);

	srand(time(NULL));
	setlocale(0, "rus");

	std::cout << "Матрица: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i*n +j] = rand() % (max_rand - min_rand + 1) + min_rand;
			std::cout << arr[i*n + j] << "  ";
		}
		std::cout << '\n';
	}
	long long mul;
	for (int i = 0; i < n; i++)
	{
		mul = 1;
		valarray a = ((valarray)arr[*(slice(i * n, n, 1))]);
		if (((valarray)a[a<0]).size() == 0)
		{
			for (int j = 0; j < n; j++)
				mul *= arr[i*n + j];
			std::cout << "\nПроизведение элементов в строке " << i << ": " << mul;
		}
		else
			std::cout << "\nВ строке " << i << " есть отрицательные элементы";
	}
	int temp_diag_sum, max_diag_sum = 0;
	max_diag_sum = valarray(arr[*slice(0, n, n + 1)]).sum();
	for (int i = n - 1; i > 0; i--)
	{
		max_diag_sum = std::max(std::max(valarray(arr[*slice(i, n - i, n + 1)]).sum(),
			valarray(arr[*slice(i * n, n - i, n + 1)]).sum()), max_diag_sum);
	}

	std::cout << "\n\nМаксимальная сумма на диагонали, параллельной главной равна: " << max_diag_sum;
	std::cout << "\n\n";
	return 0;
}

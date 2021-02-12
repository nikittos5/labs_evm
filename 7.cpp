#include <iostream>
#include <time.h>

void pos_muls(int** arr, int n)
{
	long long mul;
	bool neg;
	for (int i = 0; i < n; i++)
	{
		neg = false;
		mul = 1;
		for (int j = 0; j < n; j++)
			if (arr[i][j] < 0)
			{
				neg = true;
				break;
			}
		if (!neg)
		{
			for (int j = 0; j < n; j++)
				mul *= arr[i][j];
			std::cout << "\nПроизведение элементов в строке " << i << ": " << mul;
		}
		else
			std::cout << "\nВ строке " << i << " есть отрицательные элементы";
	}
	return;
}

void max_diag_sum(int** arr, int n)
{
	int temp_diag_sum, max_diag_sum = 0;
	for (int i = 0; i < n; i++)
		max_diag_sum += arr[i][i];
	for (int i = n - 1; i > 0; i--)
	{
		temp_diag_sum = 0;
		for (int j = 0, k = i; j < n - i; j++, k++)
			temp_diag_sum += arr[j][k];
		if (temp_diag_sum > max_diag_sum)
			max_diag_sum = temp_diag_sum;
	}
	for (int i = n - 1; i > 0; i--)
	{
		temp_diag_sum = 0;
		for (int j = 0, k = i; j < n - i; j++, k++)
			temp_diag_sum += arr[k][j];
		if (temp_diag_sum > max_diag_sum)
			max_diag_sum = temp_diag_sum;
	}

	std::cout << "\n\nМаксимальная сумма на диагонали, параллельной главной равна: " << max_diag_sum;
}

int main()
{
	const int n = 10;
	const int max_rand = 50, min_rand = -10;
	int** arr = new int* [n];

	srand(time(NULL));
	setlocale(0, "rus");

	std::cout << "Матрица: \n";
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % (max_rand - min_rand + 1) + min_rand;
			std::cout << arr[i][j] << "  ";
		}
		std::cout << '\n';
	}

	pos_muls(arr, n);

	max_diag_sum(arr, n);

	std::cout << "\n\n";
	return 0; 
}

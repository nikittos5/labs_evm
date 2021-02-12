#include <iostream>

#define EPSILON 1e-9

int compare(double a, double b)
{
	if (abs(a - b) <= EPSILON)
		return 0;
	else
		if (a - b > EPSILON)
			return 1;
		else
			return -1;
}

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool is_square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double a = dist(x1, y1, x2, y2), b = dist(x1, y1, x3, y3), c = dist(x1, y1, x4, y4), d = dist(x2, y2, x4, y4), e = dist(x3, y3, x4, y4), f = dist(x2, y2, x3, y3);
	if (!compare(a, b) && compare(a, c) == -1 && !compare(a * sqrt(2), c) && !compare(d, e) && !compare(a, d) && !compare(b, e))
		return true;
	else
		if (compare(a, b) == 1 && !compare(a, b * sqrt(2)) && !compare(b, c) && !compare(d, f) && !compare(b, f) && !compare(c, d))
		{
			return true;
		}
		else
			if (compare(a, b) == -1 && !compare(sqrt(2)*a, b) && !compare(a, c) && !compare(f, e) && !compare(a, f) && !compare(c, e))
				return true;
			else
				return false;
}

bool in_square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x, double y)
{
	double a = dist(x1, y1, x2, y2), b = dist(x1, y1, x3, y3), c = dist(x1, y1, x4, y4), d = dist(x2, y2, x4, y4), e = dist(x3, y3, x4, y4), f = dist(x2, y2, x3, y3);
	if (!compare(a, b) &&
		(((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1) >= 0 &&
			(x - x2) * (y4 - y2) - (y - y2) * (x4 - x2) >= 0 &&
			(x - x4) * (y3 - y4) - (y - y4) * (x3 - x4) >= 0 &&
			(x - x3) * (y1 - y3) - (y - y3) * (x1 - x3) >= 0) ||
			((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1) <= 0 &&
				(x - x2) * (y4 - y2) - (y - y2) * (x4 - x2) <= 0 &&
				(x - x4) * (y3 - y4) - (y - y4) * (x3 - x4) <= 0 &&
				(x - x3) * (y1 - y3) - (y - y3) * (x1 - x3) <= 0)))
		return true;
	else
		if (compare(a, b) == 1 &&
			(((x - x1) * (y3 - y1) - (y - y1) * (x3 - x1) >= 0 &&
				(x - x3) * (y2 - y3) - (y - y3) * (x2 - x3) >= 0 &&
				(x - x2) * (y4 - y2) - (y - y2) * (x4 - x2) >= 0 &&
				(x - x4) * (y1 - y4) - (y - y4) * (x1 - x4) >= 0) ||
				((x - x1) * (y3 - y1) - (y - y1) * (x3 - x1) <= 0 &&
					(x - x3) * (y2 - y3) - (y - y3) * (x2 - x3) <= 0 &&
					(x - x2) * (y4 - y2) - (y - y2) * (x4 - x2) <= 0 &&
					(x - x4) * (y1 - y4) - (y - y4) * (x1 - x4) <= 0))) 
			return true;
		else
			if (compare(a, b) == -1 &&
				(((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1) >= 0 &&
					(x - x2) * (y3 - y2) - (y - y2) * (x3 - x2) >= 0 &&
					(x - x3) * (y4 - y3) - (y - y3) * (x4 - x3) >= 0 &&
					(x - x4) * (y1 - y4) - (y - y4) * (x1 - x4) >= 0) ||
					((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1) <= 0 &&
						(x - x2) * (y3 - y2) - (y - y2) * (x3 - x2) <= 0 &&
						(x - x3) * (y4 - y3) - (y - y3) * (x4 - x3) <= 0 &&
						(x - x4) * (y1 - y4) - (y - y4) * (x1 - x4) <= 0)))
				return true;
			else
				return false;
}

double square_area(double a, double b)
{
	return std::min(a * a, b * b);
}

int main()
{
	const int n = 4, m = 1;
	double first_set[n][2], second_set[n][2];
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double min_area = -1;
	setlocale(0, "rus");
	std::cout << "Введите " << n << " точек первого множества: \n";
	for (int i = 0; i < n; i++)
		std::cin >> first_set[i][0] >> first_set[i][1];

	std::cout << "\n\nВведите " << m << " точек второго множества: \n";
	for (int i = 0; i < m; i++)
		std::cin >> second_set[i][0] >> second_set[i][1];

	bool inside_square;
	for(int i = 0; i < n - 3; i++)
		for(int j = i + 1; j < n - 2; j++)
			for(int k = j + 1; j < n - 1; j++)
				for (int h = k + 1; h < n; h++)
				{
					inside_square = true;
					if (is_square(first_set[i][0], first_set[i][1], first_set[j][0], first_set[j][1],
						first_set[k][0], first_set[k][1], first_set[h][0], first_set[h][1]))
					{
						for(int l = 0; l < m; l++)
							if (!in_square(first_set[i][0], first_set[i][1], first_set[j][0], first_set[j][1],
								first_set[k][0], first_set[k][1], first_set[h][0], first_set[h][1], second_set[l][0], second_set[l][1]))
							{
								inside_square = false;
								break;
							}
						if (inside_square)
						{
							double area = square_area(dist(first_set[i][0], first_set[i][1], first_set[j][0], first_set[j][1]), 
								dist(first_set[i][0], first_set[i][1], first_set[k][0], first_set[k][1]));
							if (area < min_area || min_area < 0)
							{
								min_area = area;
								x1 = first_set[i][0]; y1 = first_set[i][1];
								x2 = first_set[j][0]; y2 = first_set[j][1];
								x3 = first_set[k][0]; y3 = first_set[k][1]; 
								x4 = first_set[h][0]; y4 = first_set[h][1];
							}
						}
					}
				}

	if (min_area < 0)
		std::cout << "\n\nНевозможно выбрать необходимый квадрат";
	else
	{
		std::cout << "\n\nНеобходимый квадрат с площадью " << min_area << " построен на точках: \n";
		std::cout << "(" << x1 << ";" << y1 << ") " << "(" << x2 << ";"
			<< y2 << ") " << "(" << x3 << ";" << y3 << ") " << "(" << x4 << ";" << y4 << ")";
	}

	std::cout << "\n\n";
	return 0; 
}

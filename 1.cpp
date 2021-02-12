#include <iostream>
#include <string>

#define CHARS_FOR_NUM 18
#define TIMES_OF_EMPTY_LINE 2
#define EPSILON 1e-12

void F(double a, double b, double c, double x_beg, double x_end, double dx, bool p)
{
	std::cout << "\n\n\n";
	int first_chars = (CHARS_FOR_NUM - 1) / 2;
	for (int sp = 0; sp < first_chars; sp++)
		std::cout << " ";
	std::cout << "X";
	int second_chars = CHARS_FOR_NUM - first_chars - 1;
	for (int sp = 0; sp < second_chars; sp++)
		std::cout << " ";
	std::cout << "|";
	first_chars = (CHARS_FOR_NUM - 6) / 2;
	for (int sp = 0; sp <= first_chars; sp++)
		std::cout << " ";
	std::cout << "RESULT";
	second_chars = CHARS_FOR_NUM - first_chars - 6;
	for (int sp = 0; sp <= second_chars; sp++)
		std::cout << " ";
	std::cout << "\n";
	for(int t = 0; t < TIMES_OF_EMPTY_LINE; t++)
	{
		for (int sp = 0; sp < CHARS_FOR_NUM; sp++)
			std::cout << " ";
		std::cout << "|";
		for (int sp = 0; sp < CHARS_FOR_NUM; sp++)
			std::cout << " ";
		std::cout << "\n"; 
	}
	for (double x = x_beg; x <= x_end; x += dx)
	{
		double res_double = 0;
		int res_int = 0;
		bool div_by_zero = false;

		if (p)
		{
			if (c < 0 && (x > EPSILON || x < -EPSILON))
				res_double = -a * x - c;
			else
				if (c > 0 && (x < EPSILON && x > -EPSILON))
					res_double = (x - a) / (-c);
				else
				{
					if (abs(c-a) < EPSILON)
						div_by_zero = true;
					else
						res_double = b * x / (c - a);
				}
		}
		else
		{
			if (c < 0 && (x > EPSILON || x < -EPSILON))
				res_int = (int)(-a * x - c);
			else
				if (c > 0 && (x < EPSILON && x > -EPSILON))
					res_int = (int) ((x - a) / (-c));
				else
				{
					if (abs(c - a) < EPSILON)
						div_by_zero = true;
					else
						res_double = (int)(b * x / (c - a));
				}
		}
		if (x < EPSILON && x > -EPSILON)
			x = (double) 0;
 		std::string x_str = std::to_string(x);
		int x_str_len = x_str.length();
		for (int sp = 0; sp < CHARS_FOR_NUM - x_str_len; sp++)
			std::cout << " ";
		std::cout << x_str << "|";

		std::string res_str;
		if (div_by_zero)
			res_str = "ERR: DIV. BY ZERO";
		else
			if (p)
				res_str = std::to_string(res_double);
			else
				res_str = std::to_string(res_int);
		int res_str_len = res_str.length();
		for (int sp = 0; sp < CHARS_FOR_NUM - res_str_len; sp++)
			std::cout << " ";
		std::cout << res_str << '\n';
	}
}

int main()
{
	double a, b, c, x_beg, x_end, dx;

	setlocale(0, "rus");
	std::cout << "Введите числа a, b, c, Xнач, Xкон, dX\n";
	std::cin >> a >> b >> c >> x_beg >> x_end >> dx;
	F(a, b, c, x_beg, x_end, dx, (int(a) | int(b) | int(c)));

	return 0;
}

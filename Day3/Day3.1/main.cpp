#include <cmath>





int main()
{
	int input = 289326;
	input -= 1;
	int cycle = floor((sqrt(input) + 1) / 2);
	int k = input - 4 * cycle * (cycle - 1);
	int x = 0, y = 0;
	if (k <= 2 * cycle)
	{
		x = cycle;
		y = k - cycle;
	}
	else if (k <= 4 * cycle)
	{
		x = 3 * cycle - k;
		y = cycle;
	}
	else if (k <= 6 * cycle)
	{
		x = -cycle;
		y = 5 * cycle - k;
	}
	else
	{
		x = k - 7 * cycle;
		y = -cycle;
	}

	return (abs(x) + abs(y));
}
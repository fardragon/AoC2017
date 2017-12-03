#include "Spiral.h"
#include <iostream>

#define SIZE 4

int main()
{
	int input = 289326;


	Spiral spiral(SIZE);
	while (true)
	{
		int current = spiral.FillNext();
		if (current == 0) break;
		if (current > input)
		{
			return current;
		}
	}
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>



int main()
{
	std::ifstream file("input.txt");
	std::string row;
	int sum = 0;
	while (getline(file, row))
	{
		std::istringstream stream(row);
		std::string key;
		std::unordered_set<std::string> set;
		bool correct = true;
		while ((stream >> key) && correct)
		{
			auto result = set.insert(key);
			if (!result.second) correct = false;

		}
		if (correct) sum += 1;
	}
	return sum;
}
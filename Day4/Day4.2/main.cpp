#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

bool IsAnagram(std::string a, std::string b);

int main()
{
	std::ifstream file("input.txt");
	std::string row;
	int sum = 0;
	while (getline(file, row))
	{
		std::istringstream stream(row);
		std::string key;
		std::vector<std::string> strVector;

		bool correct = true;
		while ((stream >> key) && correct)
		{
			for (const auto &str : strVector)
			{
				if (IsAnagram(key, str))
				{
					correct = false;
					break;
				}
			}
			if (correct) strVector.push_back(key);

		}
		if (correct) sum += 1;
	}
	return sum;
}

bool IsAnagram(std::string a, std::string b)
{
	if (a.length() != b.length()) return false;
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	return a == b;
}

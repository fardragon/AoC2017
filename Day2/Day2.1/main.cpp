#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>



int main()
{
	std::ifstream file("input.txt");
	std::string row;
	int sum = 0;
	while (getline(file, row))
	{
		std::istringstream stream(row);
		std::string number;
		std::vector<int> numVec;
		while (stream >> number)
		{
			numVec.push_back(stoi(number));
		}
		std::sort(numVec.begin(), numVec.end());
		sum += numVec.back() - numVec.front();
	}
	return sum;
}
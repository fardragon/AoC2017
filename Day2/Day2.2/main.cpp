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
		for (auto i = 0; i < numVec.size(); ++i)
		{
			for (auto j = 0; j < numVec.size(); ++j)
			{
				if (i == j) continue;
				if ((numVec.at(j) % numVec.at(i)) == 0) sum += numVec.at(j) / numVec.at(i);
			}
		}



	}
	return sum;
}
#include <fstream>
#include <string>
#include <vector>



int main()
{
	std::ifstream file("input.txt");
	std::string line;
	std::vector<int> numVec;

	while (getline(file, line))
	{
		numVec.push_back(stoi(line));
	}
	int moves = 0;
	int index = 0;

	while (true)
	{
		++moves;
		index += numVec.at(index)++;
		if ((index < 0) || (index >= numVec.size()))
		{
			break;
		}
	}

	return moves;
}
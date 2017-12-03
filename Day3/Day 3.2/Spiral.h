#ifndef Spiral_h__
#define Spiral_h__
#include <vector>
#include <algorithm>

struct Vec2i
{
	int x;
	int y;
};

enum class Direction { N, E, S, W };

class Spiral
{
public:
	Spiral() = delete;
	Spiral(int size);
	int FillNext();

private:
	Vec2i GetPos(int n);
	Vec2i GetRelativePos(int n);
	int GetAdjacentSum(Vec2i pos);
	int GetValue(int x, int y);

private:
	std::vector<std::vector<int>> m_spiral;
	int m_size, m_max;
	int m_pos;
	Direction m_dir;


};





#endif // Spiral_h__

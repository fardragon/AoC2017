#include "Spiral.h"

Spiral::Spiral(int size) : m_pos(1), m_max((2 * size + 1)*(2 * size + 1)), m_size(size)
{
	m_spiral.resize(2*size +1);
	for (auto &row : m_spiral)
	{
		row.resize(2 * size + 1);
		std::fill(row.begin(), row.end(), 0);
	}
}

int Spiral::FillNext()
{
	if (m_pos > m_max) return 0;
	auto current = this->GetPos(m_pos);
	if (m_pos == 1)
	{
		m_spiral.at(current.x).at(current.y) = 1;
		++m_pos;
		return 1;
	}
	int sum = GetAdjacentSum(current);
	m_spiral.at(current.x).at(current.y) = sum;
	++m_pos;
	return sum;
}


Vec2i Spiral::GetPos(int n)
{
	auto relPos = this->GetRelativePos(n);
	return { relPos.x + m_size, relPos.y + m_size };
}

Vec2i Spiral::GetRelativePos(int n)
{
	n -= 1;
	int cycle = floor((sqrt(n) + 1) / 2);
	int k = n - 4 * cycle * (cycle - 1);
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
	return { x, y };
}

int Spiral::GetAdjacentSum(Vec2i pos)
{
	int sum = 0;
	sum += GetValue(pos.x - 1, pos.y - 1);
	sum += GetValue(pos.x, pos.y - 1);
	sum += GetValue(pos.x + 1, pos.y - 1);
	sum += GetValue(pos.x + 1, pos.y);
	sum += GetValue(pos.x + 1, pos.y + 1);
	sum += GetValue(pos.x, pos.y + 1);
	sum += GetValue(pos.x - 1, pos.y + 1);
	sum += GetValue(pos.x - 1, pos.y);
	return sum;
}

int Spiral::GetValue(int x, int y)
{
	try
	{
		return m_spiral.at(x).at(y);
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

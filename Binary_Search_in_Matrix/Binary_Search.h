#pragma once
#include <sstream>
const int martixSize = 12;

class BinarySearch
{
public:
	size_t cnt = 1;
public:
	void findTarget(int martix[martixSize][martixSize], int &y, int &x, int yTarget, int xTarget);
	std::string printMatrix(const int matrix[martixSize][martixSize]) const;
};

#include "Binary_Search.h"

void BinarySearch::findTarget(int martix[martixSize][martixSize], int &y, int &x, int yTarget, int xTarget)
{
	martix[y][x] = -1;
	martix[yTarget][xTarget] = 1;
	while (y != yTarget || x != xTarget)
	{
		y = y + (martixSize - y) / 2;
		//x = x + (martixSize - x) / 2;
		if (y < yTarget && x < xTarget)
		{
			y = (martixSize + y) / 2;
			x = (martixSize + x) / 2;
			martix[y][x] = cnt;
		}
		else if (y > yTarget && x < xTarget)
		{
			y /= 2;
			x = (martixSize + x) / 2;
			martix[y][x] = cnt;
		}
		else if (y > yTarget && x == xTarget) //up
		{
			//y = ((martixSize - y) / 2) + 1;
			y--;
			martix[y][x] = cnt;
		}
		else if (y < yTarget && x == xTarget) //down
		{
			//y = (martixSize + y) / 2;
			y++;
			martix[y][x] = cnt;
		}
		else if (y < yTarget && x > xTarget)
		{
			y = (martixSize + y) / 2;
			x /= 2;
			martix[y][x] = cnt;
		}
		else if (y == yTarget && x > xTarget)
		{
			x /= 2;
			martix[y][x] = cnt;
		}
		else if (y > yTarget && x > xTarget)
		{
			y /= 2;
			x /= 2;
			martix[y][x] = cnt;
		}
		else if (y == yTarget && x < xTarget)
		{
			x = (martixSize + x) / 2;
			martix[y][x] = cnt;
		}
		cnt++;
	}
}

std::string BinarySearch::printMatrix(const int matrix[martixSize][martixSize]) const
{
	std::ostringstream info;

	for (size_t i = 0; i < martixSize; i++)
	{
		for (size_t a = 0; a < martixSize; a++)
		{
			info << matrix[i][a] << " ";
		}
		info << "\n";
	}

	return info.str();
}

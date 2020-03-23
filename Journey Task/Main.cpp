#include <iostream>
#include <sstream>
#include "FlightsGenerator.h"
#include <vector>

const int arrSize = 6;
const int howManyTickets = 4;

int arr[arrSize] = { 1, 2, 3, 4, 5, 6};
int result[arrSize][arrSize];

int howMany = arrSize - 2;

bool lastIsVisit = false;

void clearCurrent(int level)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		result[level][i] = 0;
	}
}

void printArray(int someArr[], int start, int end)
{
	for (size_t i = arrSize - 1; i > 0; i--)
	{
		bool temp = false;
		for (size_t a = 0; a < arrSize; a++)
		{
			if (result[i][a] != 0)
			{
				temp = true;
				std::cout << result[i][a] << " ";
			}
		}
		if (temp)
		{
			std::cout << "\n";
		}
	}
	for (size_t i = start; i < end; i++)
	{
		std::cout << someArr[i] << " ";
	}
	std::cout << "\n";
	std::cout << "-------------\n";
}

void gen(int someArr[6], int startPos, int endPos, int increase, int level)
{
	if (level == 1 && lastIsVisit == false)
	{
		printArray(someArr, startPos, endPos);
		lastIsVisit = true;
		return;
	}
	if (startPos >= endPos)
	{
		return;
	}
	if (level == 1 && lastIsVisit == true)
	{
		return;
	}

	lastIsVisit = false;
	int newCnt = 0;
	if (startPos > -1)
	{
		int getNext = startPos;
		size_t cnt = 0;
		clearCurrent(level);
		while (cnt < increase)
		{
			result[level][getNext] = arr[getNext];
			getNext++;
			cnt++;
			newCnt++;
		}
		startPos = getNext - 1;
	}
	int limit = howMany;
	//if (level == 3)
	//{
		limit = howMany - newCnt + 1;
	//}

	for (size_t inc = 1; inc <= limit; inc++)
	{
		gen(someArr, startPos + 1, endPos, inc, level - 1);
	}

}


int main()
{
	int numberOfFlights = 0;
	

	gen(arr, -1, 6, howMany, howManyTickets);

	return 0;
}

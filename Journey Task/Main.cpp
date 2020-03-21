#include <iostream>
#include <sstream>
#include "FlightsGenerator.h"
#include <vector>

int arr[5] = { 1, 2, 3, 4, 5 };

bool visited[5][5] = {};

void printArray(int someArr[], int start, int end)
{
	for (size_t i = start; i < end; i++)
	{
		std::cout << someArr[i] << " ";
	}
	std::cout << "\n";
}

void gen(int someArr[5], int startPos, int endPos, int increase, int level)
{
	if (startPos >= endPos || visited[level][increase] == true || startPos < 0 || level > 3 || (startPos >= 3 && level == 3))
	{
		return;
	}

	if (level == 1 || startPos == endPos - 1)
	{
		printArray(someArr, startPos, endPos);
		return;
	}

	int getNext = startPos;
	size_t cnt = 0;
	while (cnt < increase)
	{
		visited[level][increase] = true; // visited[getNext][increase] = true;
		std::cout << arr[getNext] << " ";
		getNext++;
		cnt++;
	}
	std::cout << "\n";
	startPos = getNext - 1;
	for (size_t inc = 1; inc <= 3; inc++)
	{	
		gen(someArr, startPos + 1, endPos, inc, level - 1);
		if (level < 3)
		{
			level++;
		}	
		startPos--;	
		visited[level][inc] = false;
	}

}


int main()
{
	int numberOfFlights = 0;

	//for (size_t i = 1; i <= 3; i++)
	//{
		gen(arr, 0, 5, 1, 3);
	//}

	return 0;
}

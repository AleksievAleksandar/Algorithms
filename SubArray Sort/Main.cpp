#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

bool outOfOrder(const std::vector<int>& arr, size_t index)
{
	// if index is the first element we must compair it with the second one
	if (index == 0)
	{
		return arr[1] < arr[index];
	}

	// if index is the last component we must compair it with previus one
	if (index == arr.size() - 1)
	{
		return arr[index] < arr[index - 1];
	}

	return (arr[index] < arr[index - 1] || arr[index + 1] < arr[index]);
}

std::pair<int, int> findIndOfSubArrForSort(const std::vector<int>& arr)
{
	int smallestElement = INT32_MAX;
	int largestElement = INT32_MIN;

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (outOfOrder(arr, i))
		{
			smallestElement = std::min(smallestElement, arr[i]);
			largestElement = std::max(largestElement, arr[i]);
		}
	}

	// the array is already sorted
	if (smallestElement == INT32_MAX)
	{
		return std::make_pair(-1, -1);
	}

	size_t leftInd = 0;
	size_t rightInd = arr.size() - 1;

	// find the index where must be placed the smallestElemenr 
	while (leftInd < arr.size() && arr[leftInd] <= smallestElement)
	{
		leftInd++;
	}

	// find the index where must be placed the largestElement 
	while (rightInd >= 0 && arr[rightInd] >= largestElement)
	{
		rightInd--;
	}

	return std::make_pair(leftInd, rightInd);
}

int main()
{
	std::vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
	std::pair<int, int> result = findIndOfSubArrForSort(arr);

	std::cout << result.first << " and " << result.second << std::endl;

	return 0;
}

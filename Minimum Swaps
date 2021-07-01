#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

size_t findNumOfSwapsNeededForSortArr(const std::vector<int>& arr)
{
	const size_t n = arr.size();

	// take current indexes of elements
	std::pair<int, int>* elementsAndTheyInd = new std::pair<int, int>[n];

	for (size_t i = 0; i < n; i++)
	{
		elementsAndTheyInd[i].first = arr[i];
		elementsAndTheyInd[i].second = i;
	}

	// sort elements to prepare them for calculation of newInd
	std::sort(elementsAndTheyInd, elementsAndTheyInd + n);

	size_t swaps = 0;
	std::vector<bool> visited(n, false);

	// find the newInd of the every element
	for (size_t i = 0; i < n; i++)
	{
		size_t loops = 0;

		if (!visited[i])
		{
			size_t newInd = i;

			while (!visited[newInd])
			{
				size_t currentInd = elementsAndTheyInd[newInd].second;
				visited[newInd] = true;
				newInd = currentInd;
				loops++;
			}
			swaps += (loops - 1);
		}
	}

	delete[] elementsAndTheyInd;

	return swaps;
}

int main()
{
	std::vector<int> arr = {2, 4, 5, 1, 3};

	std::cout << findNumOfSwapsNeededForSortArr(arr);

	return 0;
}

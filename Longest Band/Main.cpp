#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>

int findLongestBand(const std::vector<int>& arr)
{
	std::unordered_set<int> present;
	for (size_t i = 0; i < arr.size(); i++)
	{
		present.insert(arr[i]);
	}

	size_t cnt = 1;

	for (size_t i = 0; i < arr.size(); i++)
	{
		int prevElem = arr[i] - 1;

		// find that this element has no parent
		if (present.find(prevElem) == present.end())
		{
			int nextElem = arr[i] + 1;
			size_t currentCnt = 1;

			// find every child of arr[i] parrent and update the cnt
			while (present.find(nextElem) != present.end())
			{
				nextElem++;
				currentCnt++;
			}

			if (currentCnt > cnt)
			{
				cnt = currentCnt;
			}
		}
	}
	return cnt;
}

int main()
{
	std::vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
	
	std::cout << findLongestBand(arr);

	return 0;
}

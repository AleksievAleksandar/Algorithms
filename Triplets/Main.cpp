#include <iostream>
#include <vector>

std::vector<std::vector<int> > findTriplets(const std::vector<int>& data, const int targetSum)
{
	size_t n = data.size();
	std::vector<std::vector<int> > result;

	for (size_t i = 0; i < n - 3; i++)
	{
		int left = i + 1; // points to left element
		int right = n - 1; // points to right element

		while (left < right) // two pointer approach
		{
			int currentSum = data[i];
			currentSum += data[left];
			currentSum += data[right];

			if (currentSum == targetSum)
			{
				result.push_back({data[i], data[left], data[right]});
				left++;
				right--;
			}
			else if (currentSum < targetSum)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return result;
}


int main()
{
	std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int sum = 18;

	auto result = findTriplets(data, sum);

	return 0;
}

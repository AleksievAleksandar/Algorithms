#include <iostream>
#include <vector>
#include <cstdlib>

int maxSubarraySum(const std::vector<int>& arr) 
{
	bool foundOnePositeveElements = (arr[0] < 0 ? false : true);

    int tempSum = arr[0];
	int maxSum = tempSum;

	size_t leftIndex = 0;

	for (size_t i = 1; i < arr.size(); i++)
	{
		// looking for a positive number
		if (arr[i] > 0)
		{
			foundOnePositeveElements = true;
		}

		tempSum += arr[i];

		// check if tempSum is greater without first index
		// and if(true) -> update tempSum and move leftIndex forward
		if (tempSum > tempSum + arr[leftIndex])
		{
			tempSum -= arr[leftIndex];
			leftIndex++;
		}

		if (tempSum < arr[i])
		{
			tempSum = arr[i];
		}

		if (maxSum < tempSum)
		{
			maxSum = tempSum;
		}
	}

	if (!foundOnePositeveElements)
	{
		return 0;
	}

	return maxSum;
}

int main()
{
    //std::vector<int> arr = {-1, 2, 3, 4, -2, 6, -8, 3};
	std::vector<int> arr = { 4, 1, 1};

	std::cout << maxSubarraySum(arr);

	return 0;
}

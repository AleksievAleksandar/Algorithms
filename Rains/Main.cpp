#include <iostream>
#include <vector>
#include <cstdlib>

int findMaxTrapedWater(const std::vector<int>& pool)
{
	int poolSize = pool.size();

	// the pool is too small to trap a water
	if (pool.size() < 2)
	{
		return 0;
	}

	// left and right vectors - to collect a finded max element, 
	// moving from left to right and from right to left
	std::vector<int> left(poolSize, 0);
	std::vector<int> right(poolSize, 0);

	left[0] = pool[0];
	right[poolSize - 1] = pool[poolSize - 1];

	for (size_t i = 1; i < poolSize; i++)
	{
		left[i] = std::max(left[i - 1], pool[i]);
		right[poolSize - i - 1] = std::max(right[poolSize - i], pool[poolSize - i - 1]);
	}

	// calculate traped water
	int trapedWater = 0;
	for (size_t i = 0; i < poolSize; i++)
	{
		trapedWater += (std::min(left[i], right[i]) - pool[i]);
	}

	return trapedWater;
}

int main()
{
	std::vector<int> pool = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	std::cout << findMaxTrapedWater(pool);

	return 0;
}

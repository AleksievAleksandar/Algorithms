#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>

std::pair<int, int> minDifference(std::vector<int>& a, std::vector<int>& b)
{
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	size_t indArrA = 0;
	size_t indArrB = 0;

	// find first element greater then b[0]
	while (a[indArrA] < b[0])
	{
		indArrA++;
	}

	// find last element from b Arr smaler then a[indArr] 
	while (b[indArrB] < a[indArrA])
	{
		indArrB++;
	}

	return std::make_pair(a[indArrA], b[indArrB]);
}

std::pair<int, int> minDifferenceUpdate(const std::vector<int>& a, const std::vector<int>& b)
{
	std::set<int> firstOrderedElementofArr;
	std::set<int> secondOrderedElementofArr;

	for (size_t i = 0; i < a.size(); i++)
	{
		firstOrderedElementofArr.insert(a[i]);
		secondOrderedElementofArr.insert(b[i]);
	}

	// find first element greater then b[0]
	auto numOne = firstOrderedElementofArr.upper_bound(*(secondOrderedElementofArr.upper_bound(0)));

	// find last element from b Arr smaler then a[indArr] 
	auto numTwo = secondOrderedElementofArr.lower_bound(*numOne);

	return std::make_pair((*numOne), (*numTwo));
}

int main()
{
	std::vector<int> a = {23, 5, 10, 17, 30};
	std::vector<int> b = {26, 134, 135, 14, 19};

	std::pair<int, int> result = minDifference(a, b);

	std::cout << result.first << " " << result.second;

	return 0;
}

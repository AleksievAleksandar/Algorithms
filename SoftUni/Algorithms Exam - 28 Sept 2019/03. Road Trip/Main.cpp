#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> getUserInput()
{
	std::string tempString;
	std::getline(std::cin, tempString);

	std::istringstream a(tempString);

	std::vector<int> tempVect;
	std::string currentValue;
	while (a >> currentValue)
	{
		tempVect.push_back(std::stoi(currentValue));
	}

	return tempVect;
}


int getMaxItemsCap(const std::vector<int> &values, const std::vector<int> &space, int index, 
					int &spaceResult, int &findedCurrCap, int & maxFindedCap, const int &maxCap)
{
	if (maxFindedCap < findedCurrCap)
	{
		maxFindedCap = findedCurrCap;
	}

	if (index == values.size())
	{
		return 0;
	}

	for (size_t i = index; i < space.size(); i++)
	{
		if (spaceResult + space[i] <= maxCap)
		{
			spaceResult += space[i];
			findedCurrCap += values[i];

			getMaxItemsCap(values, space, i + 1, spaceResult, findedCurrCap, maxFindedCap, maxCap);

			spaceResult -= space[i];
			findedCurrCap -= values[i];
		}
	}

	return maxFindedCap;
}

int main()
{
	std::ostream::sync_with_stdio(false);
	std::istream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> values;
	std::vector<int> amountSpace;
	int maxCapacity = 0;

	values = getUserInput();
	amountSpace = getUserInput();
	std::cin >> maxCapacity;

	int currentResult = 0;
	int findedCurrCap = 0;
	int maxFindedCap = 0;

	int result = getMaxItemsCap(values, amountSpace, 0, currentResult, findedCurrCap, maxFindedCap, maxCapacity);

	std::cout << "Maximum value: " << result << "\n";

	return 0;
}

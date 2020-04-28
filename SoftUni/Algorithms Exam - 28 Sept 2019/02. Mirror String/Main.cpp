#include <iostream>
#include <vector>

std::vector<std::string> fromLeftToRightComb;
char charsLeft[50];

std::string mirror(std::string fromString)
{
	std::string mirror;

	for (int i = fromString.size() - 1; i >= 0; i--)
	{
		mirror += fromString[i];
	}
	return mirror;
}

void findCombInString(std::string &stringInput, int index, int start, int cnt)
{
	if (index >= cnt)
	{
		std::string temp = charsLeft;
		if (temp == mirror(temp))
		{
			fromLeftToRightComb.push_back(temp);
		}	
	}
	else
	{
		for (size_t i = start; i < stringInput.size(); i++)
		{
			charsLeft[index] = stringInput[i];
			findCombInString(stringInput, index + 1, i + 1, cnt);
		}
	}
}

int main()
{
	//std::cin.sync_with_stdio(false);
	//std::cout.sync_with_stdio(false);

	std::ostream::sync_with_stdio(false);
	std::istream::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string userInput;
	std::cin >> userInput;
	int cnt = 2;

	while (cnt <= userInput.size())
	{
		findCombInString(userInput, 0, 0, cnt);
		cnt++;
	}
	
	if (!fromLeftToRightComb.empty())
	{
		std::cout << fromLeftToRightComb[fromLeftToRightComb.size() - 1];
	}
	return 0;
}

#include <iostream>
#include <string>

bool checkSubSet(const std::string& sOne, const std::string& sTwo)
{
	// two pointer approach
	int indFirstStr = sOne.size() - 1;
	int indSecondStr = sTwo.size() - 1;

	while (indFirstStr >= 0 && indSecondStr >= 0)
	{
		if (sOne[indFirstStr] == sTwo[indSecondStr])
		{
			indFirstStr--;
			indSecondStr--;
		}
		else
		{
			indFirstStr--;
		}
	}

	if (indFirstStr == -1 && indSecondStr > 0)
	{
		return false;
	}

	return true;
}

int main()
{
	std::string sOne = "codingminutes";
	std::string sTwo = "cines";

	if (checkSubSet(sOne, sTwo))
	{
		std::cout << "True";
	}
	else
	{
		std::cout << "False";
	}

	return 0;
}

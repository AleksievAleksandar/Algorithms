#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> resultGirls(3);
std::vector<std::string> resultBoys(2);
std::vector<std::vector<std::string>> allCombGirls;
std::vector<std::vector<std::string>> allCombBoys;

void printVec(std::vector<std::string>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
}

std::vector<std::string> getUserInput()
{
	std::stringstream ss;
	std::string allNames;

	std::getline(std::cin, allNames);
	ss << allNames;

	std::vector<std::string> people;
	std::string currentName;
	while (ss >> currentName)
	{
		std::string temp;
		for (size_t i = 0; i < currentName.size(); i++)
		{
			if (currentName[i] != ',')
			{
				temp += currentName[i];
			}
		}
		people.push_back(temp);
	}

	return people;
}

void genBoys(std::vector<std::string>& boys, int currentIndex, int howMany)
{

	if (currentIndex > 1)
	{
		//printVec(resultBoys);
		allCombBoys.push_back(resultBoys);
		return;
	}

	for (size_t i = howMany; i < boys.size(); i++)
	{
		resultBoys[currentIndex] = boys[i];
		genBoys(boys, currentIndex + 1, i + 1);
	}
}

void genGirls(std::vector<std::string> &girls, int currentIndex, int howMany)
{

	if (currentIndex > 2)
	{
		//printVec(resultGirls);
		allCombGirls.push_back(resultGirls);
		return;
	}

	for (size_t i = howMany; i < girls.size(); i++)
	{			
		resultGirls[currentIndex] = girls[i];
		genGirls(girls, currentIndex + 1, i + 1);
	}	
}

std::string showResult(std::vector<std::vector<std::string>>& girls, std::vector<std::vector<std::string>>& boys)
{
	std::ostringstream infoStream;
	size_t cnt = 0;
	for (auto i : girls)
	{
		while (cnt < boys.size())
		{
			for (auto a : i)
			{
				infoStream << a << ", ";
			}
			
			for (size_t j = 0; j < 2; j++)
			{
				if (j < 1)
				{
					infoStream << boys[cnt][j] << ", ";
				}
				else
				{
					infoStream << boys[cnt][j];
				}
				
			}

			infoStream << "\n";
			cnt++;
		}
		cnt = 0;
	}
	return infoStream.str();
}

int main()
{
	std::vector<std::string> girls;
	std::vector<std::string> boys;

	girls = getUserInput();
	boys = getUserInput();

	genGirls(girls, 0, 0);
	genBoys(boys, 0, 0);

	std::cout << showResult(allCombGirls, allCombBoys);

	return 0;
}

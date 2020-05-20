#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> getUserInput()
{
	std::vector<std::string> names;

	std::string line;
	std::getline(std::cin, line);

	std::istringstream iss(line);
	std::string currentName;

	while (iss >> currentName)
	{
		if (currentName[currentName.size() - 1] == ',')
		{
			std::string reworkedName(currentName.begin(), currentName.end() - 1);
			names.push_back(reworkedName);
		}
		else
		{
			names.push_back(currentName);
		}
	}

	return names;
}

std::vector<std::string> getSits(std::vector<std::string>& people)
{
	std::vector<std::string> reservedSits(people.size());

	std::string userInput;
	std::getline(std::cin, userInput);

	while (userInput != "generate")
	{
		std::istringstream iss(userInput);

		int index;
		std::string data;
		std::string currentName;

		while (iss >> data)
		{
			if (data != "-" && !std::isdigit(data[0]))
			{
				currentName = data;
			}
			else
			{
				if (std::isdigit(data[0]))
				{
					index = std::stoi(data);
					index--;
					reservedSits[index] = currentName;
				}
			}
		}
		std::getline(std::cin, userInput);
	}

	return reservedSits;
}

std::vector<std::string> takeTheRest(const std::vector<std::string>& people, const std::vector<std::string>& reservedSits)
{
	std::vector<std::string> restPeople;
	bool findPerson = false;
	for (size_t i = 0; i < people.size(); i++)
	{
		for (size_t a = 0; a < reservedSits.size(); a++)
		{
			if (people[i] == reservedSits[a])
			{
				findPerson = true;
			}
		}
		if (!findPerson)
		{
			restPeople.push_back(people[i]);
		}
		findPerson = false;
	}
	return restPeople;
}

void printPeople(const std::vector<std::string> &people)
{
	for (size_t i = 0; i < people.size(); i++)
	{
		std::cout << people[i] << " ";
	}
	std::cout << "\n";
}

std::vector<std::string> combine(const std::vector<std::string> &reserved, const std::vector<std::string> &theRest)
{
	std::vector<std::string> combination(reserved.size());
	int cnt = 0;
	for (size_t i = 0; i < reserved.size(); i++)
	{
		if (reserved[i] == "")
		{
			combination[i] = theRest[cnt++];
		}
		else
		{
			combination[i] = reserved[i];
		}
	}

	return combination;
}

void generateCombinations(std::vector<std::string>& toMerge, const std::vector<std::string>& reserved, const std::vector<std::string>& peopleToChoose, int index, bool visited[])
{
	if (index == peopleToChoose.size())
	{
		printPeople(combine(reserved, toMerge));
		return;
	}

	for (size_t i = 0; i < peopleToChoose.size(); i++)
	{
		if (visited[i] != true)
		{
			toMerge[index] = peopleToChoose[i];
			visited[i] = true;
			generateCombinations(toMerge, reserved, peopleToChoose, index + 1, visited);
			toMerge[index] = "";
			visited[i] = false;
		}
	}
}

int main()
{
	std::vector<std::string> people;
	people = getUserInput(); //get all available people
		
	std::vector<std::string> reservedSits;
	reservedSits = getSits(people);

	std::vector<std::string> peopleToChoose;
	peopleToChoose = takeTheRest(people, reservedSits); //take all people different of the reserved

	bool* visited = new bool[peopleToChoose.size()];
	for (size_t i = 0; i < peopleToChoose.size(); i++)
	{
		visited[i] = false;
	}

	std::vector<std::string> merger(peopleToChoose.size());
	generateCombinations(merger, reservedSits, peopleToChoose, 0, visited);

	delete[] visited;

	return 0;
}

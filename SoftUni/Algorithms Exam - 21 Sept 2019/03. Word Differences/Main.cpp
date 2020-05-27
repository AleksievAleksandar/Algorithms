#include <iostream>
#include <sstream>
#include "WordDifferences.h"

std::string getUserInput()
{
	std::string str;
	std::getline(std::cin, str);
	return str;
}

int main()
{
	std::string firstString;
	std::string secondString;

	firstString = getUserInput();
	secondString = getUserInput();

	WordDifferences* levenshteinDistance = new WordDifferences();
	std::cout <<"Deletions and Insertions: " << levenshteinDistance->findMinChanges(firstString, secondString) << "\n";

	return 0;
}

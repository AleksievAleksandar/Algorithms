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

	WordDifferences* wordDiff = new WordDifferences();
	wordDiff->findMinChanges(firstString, secondString);

	return 0;
}

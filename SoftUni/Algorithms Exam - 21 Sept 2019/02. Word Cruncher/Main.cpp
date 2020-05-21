#include <iostream>
#include <sstream>
#include "Words.h"


int main()
{
	std::string userInputOfWords;
	std::string target;

	std::getline(std::cin, userInputOfWords);
	std::getline(std::cin, target);

	Words* words = new Words();
	words->generateWordsCombinations(userInputOfWords, target);

	return 0;
}

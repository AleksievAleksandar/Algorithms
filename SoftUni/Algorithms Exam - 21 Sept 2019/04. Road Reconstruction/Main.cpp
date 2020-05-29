#include <iostream>
#include <sstream>
#include "ImportantStreetsFinder.h"

std::string getUserInput()
{
	std::string str;
	std::getline(std::cin, str);

	return str;
}

int main()
{
	std::string nodes;
	std::string vertices;

	nodes = getUserInput();
	vertices = getUserInput();

	ImportantStreetsFinder* streets = new ImportantStreetsFinder();
	streets->createGraph(nodes, vertices);
	std::cout << streets->findImportantStreets();

	return 0;;
}

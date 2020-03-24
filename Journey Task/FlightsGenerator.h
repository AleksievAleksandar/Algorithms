#pragma once
#include <iostream>
#include <sstream>

class FlightGenerator
{
private:
	size_t arrSize;
	size_t numberOfTickets;
	int destinations[11];
	int result[11][11];
	bool lastIsVisit;
	int howManyTicketsWork;
	int howManyWorkIterations;
	std::ostringstream info;

private:
	void genTickets(const int someArr[], int startPos, int endPos, int increase, int level);
	void printArr(const int someArr[], const int& start, const int& end);
	void clearCurrentLevel(const int& level);

public:
	FlightGenerator(const int arrWithDestinations[], const size_t& arrSize, const size_t& numberOfTickets);
	std::string returnFlightPossibilities();
};

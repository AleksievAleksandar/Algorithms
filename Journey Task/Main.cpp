#include <iostream>
#include <sstream>
#include "FlightsGenerator.h"

const int arrSize = 10;

int arr[arrSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main()
{	
	size_t arraySize = 5;
	size_t howManyTicketsYouWant = 3;

	FlightGenerator* flightGen = new FlightGenerator(arr, arraySize, howManyTicketsYouWant);
	std::cout << flightGen->returnFlightPossibilities();
	
	delete flightGen;
	return 0;
}

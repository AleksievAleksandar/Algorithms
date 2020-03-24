#include "FlightsGenerator.h"

void FlightGenerator::genTickets(const int someArr[], int startPos, int endPos, int increase, int level)
{
	if (level == 1 && this->lastIsVisit == false)
	{
		this->createStringFromDestinations(someArr, startPos, endPos);
		this->lastIsVisit = true;
		return;
	}
	if (startPos >= endPos)
	{
		return;
	}
	if (level == 1 && lastIsVisit == true)
	{
		return;
	}

	this->lastIsVisit = false;
	int newCnt = 0;
	if (startPos > -1)
	{
		int getNext = startPos;
		size_t cnt = 0;
		this->clearCurrentLevel(level);
		while (cnt < increase)
		{
			if (getNext == this->arrSize - 1) //if we take the last destination, before we get to bottom
			{
				return;
			}
			this->result[level][getNext] = someArr[getNext];
			getNext++;
			cnt++;
			newCnt++;
		}
		startPos = getNext - 1;
	}
	int limit = this->howManyWorkIterations;
	if (level == this->numberOfTickets) //based of current level we calculate iterations for next levels
	{
		limit = this->howManyWorkIterations - newCnt + 1;
	}

	for (size_t inc = 1; inc <= limit; inc++)
	{
		genTickets(someArr, startPos + 1, endPos, inc, level - 1);
	}
}

void FlightGenerator::createStringFromDestinations(const int someArr[], const int& start, const int& end)
{
	for (size_t i = this->arrSize; i > 0; i--)
	{
		bool temp = false;
		for (size_t a = 0; a < this->arrSize; a++)
		{
			if (this->result[i][a] != 0)
			{
				temp = true;
				this->info << this->result[i][a] << " ";
			}
		}
		if (temp)
		{
			this->info << "\n";
		}
	}
	for (size_t i = start; i < end; i++)
	{
		this->info << someArr[i] << " ";
	}
	this->info << "\n";
	this->info << "----------------\n";
}

void FlightGenerator::clearCurrentLevel(const int& level)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		result[level][i] = 0;
	}
}

std::string FlightGenerator::returnFlightPossibilities()
{
	if (this->numberOfTickets > this->arrSize)
	{
		this->info << "The number of tickets is greater than destinations!\n";
		return info.str();
	}
	this->howManyTicketsWork = this->numberOfTickets + 1;
	//this->howManyWork = this->arrSize - 2; // tazi 2-ka se buta pri promyana na biletite!!!
	this->howManyWorkIterations = this->arrSize - (this->numberOfTickets - 1);

	this->genTickets(this->destinations, -1, this->arrSize, this->howManyWorkIterations, this->howManyTicketsWork);

	return this->info.str();
}

FlightGenerator::FlightGenerator(const int arrWithDestinations[], const size_t& arrSize, const size_t& numberOfTickets) :
	arrSize(arrSize), numberOfTickets(numberOfTickets), lastIsVisit(false), howManyTicketsWork(0), howManyWorkIterations(0)
{
	for (size_t i = 0; i < 11; i++)
	{
		this->destinations[i] = 0;
	}
	for (size_t i = 0; i < this->arrSize; i++) //copy destinations
	{
		this->destinations[i] = arrWithDestinations[i];
	}
	for (size_t i = 0; i < 11; i++)
	{
		for (size_t a = 0; a < 11; a++)
		{
			this->result[i][a] = 0;
		}
	}
}

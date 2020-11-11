#include "Kruskal.h"
#include <sstream>

std::string Kruskal::getResult(const int someGraph[GraphSize][GraphSize])
{
	neighbours->getNeighbours(someGraph);
	
	setRoots();

	setMST();

	return printMST();
}

Kruskal::~Kruskal()
{
	delete this->neighbours;
	delete this->MST;
}

void Kruskal::setRoots()
{
	for (size_t i = 0; i < GraphSize; i++)
	{
		roots[i] = i;
	}
}

void Kruskal::updateRoots()
{
	for (size_t i = 0; i < GraphSize; i++)
	{
		if (roots[i] == rootForUpdate)
		{
			roots[i] = rootForUpdSec;
		}
	}
}

void Kruskal::setMST()
{
	int cnt = 0; 

	for (size_t i = 0; i < neighbours->getNumberOfNodes(); i++)
	{
		if (roots[neighbours->vertexOne[i]] != roots[neighbours->vertexTwo[i]])
		{
			MST->vertexOne[cnt] = neighbours->vertexOne[i];
			MST->vertexTwo[cnt] = neighbours->vertexTwo[i];
			MST->node[cnt] = neighbours->node[i];
			cnt++;

			rootForUpdate = roots[neighbours->vertexTwo[i]];
			rootForUpdSec = roots[neighbours->vertexOne[i]];
			updateRoots();
		}
	}
}

std::string Kruskal::printMST()
{
	std::ostringstream info;
	info << "The MST is: " << std::endl;
	
	for (size_t i = 0; i < neighbours->getNumberOfNodes(); i++)
	{
		if (MST->node[i] != 0)
		{
			info << MST->vertexOne[i] << " : " << MST->vertexTwo[i] << " -> " << MST->node[i] << std::endl;
		}
	}

	return info.str();
}

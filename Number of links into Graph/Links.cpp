#include "Links.h"
#include <sstream>
#include <iostream>

std::string LinksOfConnections::findLinks(const std::vector<std::vector<int>>& someGraph, int startVertex)
{
	visited = new bool[someGraph.size()];
	setField(someGraph);
	
	for (size_t i = 1; i < someGraph.size(); i++)
	{
		if (visited[i] != true)
		{
			links++;
			DFS(someGraph, i);
			getVertex << std::endl;
		}
	}

	return printResult();
}

LinksOfConnections::LinksOfConnections()
{
	delete[] visited;
}

void LinksOfConnections::setField(const std::vector<std::vector<int>>& someGraph)
{
	links = 0;
	for (size_t i = 0; i < someGraph.size(); i++)
	{
		visited[i] = false;
	}
}

void LinksOfConnections::DFS(const std::vector<std::vector<int>>& someGraph, int startVertex)
{
	visited[startVertex] = true;
	
	getVertex << startVertex << " ";

	for (size_t i = 1; i < someGraph.size(); i++)
	{
		if (someGraph[startVertex][i] == 1 && visited[i] != true)
		{
			DFS(someGraph, i);
		}
	}
	//getVertex << std::endl;
}

std::string LinksOfConnections::printResult()
{
	std::ostringstream info;

	info << "The number of links into the graph are: " << links << std::endl;

	return info.str() + getVertex.str();
}


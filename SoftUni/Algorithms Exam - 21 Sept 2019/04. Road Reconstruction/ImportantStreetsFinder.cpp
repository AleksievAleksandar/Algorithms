#include "ImportantStreetsFinder.h"
#include <iostream>

std::string ImportantStreetsFinder::findImportantStreets()
{
	this->visited.resize(this->numberNodes, false);
	this->result << "Important streets:\n";

	for (auto i : this->connections)
	{
		this->removePath(i.first, i.second);
		this->DFS(0);

		if (this->visitedNodesCounter() < this->numberNodes)
		{
			this->result << i.first << " - " << i.second << "\n";
		}

		this->setVisitedNodesToFalse();
		this->restorePath(i.first, i.second);
	}

	return this->result.str();
}

void ImportantStreetsFinder::createGraph(const std::string& nodes, const std::string& vertices)
{
	this->numberNodes = std::stoi(nodes);
	this->numberVertices = std::stoi(vertices);

	this->graph.resize(this->numberNodes, std::vector<int>(this->numberNodes, Graph_Settings::NO_CONNECTION));
	this->connections.resize(this->numberVertices);

	int vertexCnt = 0;
	while (vertexCnt != this->numberVertices)
	{
		
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);

		std::string separatedWord;
		std::vector<int> nodesVec;
		while (iss >> separatedWord)
		{
			if (std::isdigit(separatedWord[0]))
			{
				nodesVec.push_back(std::stoi(separatedWord));
			}
		}

		this->graph[nodesVec[0]][nodesVec[1]] = Graph_Settings::CONNECTION;
		this->graph[nodesVec[1]][nodesVec[0]] = Graph_Settings::CONNECTION;

		this->connections[vertexCnt].first = nodesVec[0];
		this->connections[vertexCnt].second = nodesVec[1];

		vertexCnt++;
	}

}

void ImportantStreetsFinder::DFS(int node)
{
	this->visited[node] = true;

	for (size_t i = 0; i < this->numberNodes; i++)
	{
		if (this->graph[node][i] == 1 && this->visited[i] != true)
		{
			this->DFS(i);
		}
	}
}

void ImportantStreetsFinder::removePath(int firstNode, int secondNode)
{
	this->graph[firstNode][secondNode] = Graph_Settings::NO_CONNECTION;
	this->graph[secondNode][firstNode] = Graph_Settings::NO_CONNECTION;
}

void ImportantStreetsFinder::restorePath(int firtsNode, int secondNode)
{
	this->graph[firtsNode][secondNode] = Graph_Settings::CONNECTION;
	this->graph[secondNode][firtsNode] = Graph_Settings::CONNECTION;
}

int ImportantStreetsFinder::visitedNodesCounter()
{
	int cntNodes = 0;
	for (size_t i = 0; i < this->numberNodes; i++)
	{
		if (this->visited[i])
		{
			cntNodes++;
		}
	}
	return cntNodes;
}

void ImportantStreetsFinder::setVisitedNodesToFalse()
{
	for (size_t i = 0; i < this->numberNodes; i++)
	{
		this->visited[i] = false;
	}
}

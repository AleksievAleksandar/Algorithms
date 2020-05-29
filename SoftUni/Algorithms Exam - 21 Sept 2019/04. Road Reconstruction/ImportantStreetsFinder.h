#pragma once

#include <sstream>
#include <vector>

enum Graph_Settings
{
	NO_CONNECTION = 0,
	CONNECTION = 1
};

class ImportantStreetsFinder
{
public:
	ImportantStreetsFinder() = default;
	std::string findImportantStreets();
	void createGraph(const std::string& nodes, const std::string& vertices);
private:
	int numberNodes;
	int numberVertices;
	std::vector<std::vector<int>> graph;
	std::vector<std::pair<int, int>> connections;
	std::vector<bool> visited;
	std::ostringstream result;
private:
	void DFS(int node);
	void removePath(int firstNode, int secondNode);
	void restorePath(int firtsNode, int secondNode);
	int visitedNodesCounter();
	void setVisitedNodesToFalse();
};
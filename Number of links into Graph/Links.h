#pragma once
#include <vector>
#include <sstream>

class LinksOfConnections
{
public:
	std::string findLinks(const std::vector<std::vector<int> >& someGraph, int startVertex);
	LinksOfConnections();

private:
	size_t links;
	bool *visited;
	void setField(const std::vector<std::vector<int> > & someGraph);
	void DFS(const std::vector<std::vector<int> > & someGraph, int startVertex);
	std::string printResult();
	std::ostringstream getVertex;
};
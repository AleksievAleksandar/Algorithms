#pragma once
#include "EdgeList.h"
#include <string>

const size_t gr = 10;

class Prim
{
	EdgeList *edges = new EdgeList();
public:
	std::string getMST(const int someGraph[gr][gr], int vertex);
	~Prim();
private:
	int graphCopy[gr][gr];
	int mst[gr][gr];
	void copyGraph(const int someGraph[gr][gr]);
	bool visited[gr];
	bool visitedLoop[gr];
	int parentLoop[gr];
	std::string printResult();
};

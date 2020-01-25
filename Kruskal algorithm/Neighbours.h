#pragma once

const size_t GraphSize = 10;

class Neighbours
{
public:
	void getNeighbours(const int graph[GraphSize][GraphSize]);
	int vertexOne[GraphSize * 2];
	int vertexTwo[GraphSize * 2];
	int node[GraphSize * 2];
	size_t getNumberOfNodes() const;

private:
	size_t cnt;
	void sort();
	bool visited[GraphSize][GraphSize];
};

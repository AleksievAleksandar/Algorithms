#include "Prim.h"
#include <sstream>

std::string Prim::getMST(const int someGraph[gr][gr], int vertex)
{
	copyGraph(someGraph);
	size_t queueCnt = 0;
	size_t vertexCnt = 0;
	visited[vertex] = true;

	do
	{
		for (size_t i = 1; i < gr; i++)
		{
			if (graphCopy[vertex][i] != 0)
			{
				edges->queue[queueCnt] = graphCopy[vertex][i];
				edges->vertex[queueCnt] = i;
				edges->parent[queueCnt] = vertex;
				queueCnt++;

				graphCopy[vertex][i] = 0;
				graphCopy[i][vertex] = 0;
			}
		}
		edges->sortQueue();

		if (visited[edges->vertex[vertexCnt]] != true)
		{	
				mst[edges->parent[vertexCnt]][edges->vertex[vertexCnt]] = edges->queue[vertexCnt];
				visited[edges->vertex[vertexCnt]] = true;
		}
		vertex = edges->vertex[vertexCnt++];
	} while (edges->queue[vertexCnt] != 0);

	return printResult();
}

void Prim::copyGraph(const int someGraph[gr][gr])
{
	for (size_t i = 0; i < gr; i++)
	{
		for (size_t a = 0; a < gr; a++)
		{
			graphCopy[i][a] = someGraph[i][a];
		}
	}
}


std::string Prim::printResult()
{
	std::ostringstream info;
	info << "The MST is:" << std::endl;

	for (size_t i = 1; i < gr; i++)
	{
		for (size_t a = 1; a < gr; a++)
		{
			if (mst[i][a] != 0)
			{
				info << i << " " << a << " -> " << mst[i][a] << std::endl;
			}
		}
	}

	return info.str();
}

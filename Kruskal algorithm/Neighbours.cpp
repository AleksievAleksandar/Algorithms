#include "Neighbours.h"

void Neighbours::getNeighbours(const int graph[GraphSize][GraphSize])
{
	cnt = 0;
	for (size_t i = 1; i < GraphSize; i++)
	{
		for (size_t a = 1; a < GraphSize; a++)
		{
			if (graph[i][a] != 0 && visited[i][a] != true)
			{
				vertexOne[cnt] = i;
				vertexTwo[cnt] = a;
				node[cnt] = graph[i][a];
				cnt++;

				visited[a][i] = true;
			}
		}
	}
	sort();
}

size_t Neighbours::getNumberOfNodes() const
{
	return cnt;
}

void Neighbours::sort()
{
	int temp = 0;

	for (size_t i = 0; i < cnt; i++)
	{
		for (size_t a = 0; a < cnt - 1; a++)
		{
			if (node[a] > node[a + 1])
			{
				temp = node[a];
				node[a] = node[a + 1];
				node[a + 1] = temp;

				temp = vertexOne[a];
				vertexOne[a] = vertexOne[a + 1];
				vertexOne[a + 1] = temp;

				temp = vertexTwo[a];
				vertexTwo[a] = vertexTwo[a + 1];
				vertexTwo[a + 1] = temp;
			}
		}
	}
}

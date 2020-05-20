#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::vector<int>> createGraph(const int nodes, const int vertices)
{
	std::vector<std::vector<int>> graph(nodes, std::vector<int>(nodes, 0));;
	int cnt = 0;
	while (cnt != vertices)
	{
		std::istringstream ss;
		std::string line;
		std::getline(std::cin, line);
		ss.str(line);

		std::vector<int> values;
		std::string number;
		while (ss >> number)
		{
			if (std::isdigit(number[0]))
			{
				values.push_back(std::stoi(number));
			}
		}

		graph[values[0]][values[1]] = values[2];
		graph[values[1]][values[0]] = values[2];
		cnt++;
	}
	return graph;
}

void findBestHamiltonPath(std::vector<std::vector<int>> someGraph, const int nodes, int startNode, bool visited[], int level, int& bestResult, int& currentResult)
{

	if (bestResult > currentResult && level == nodes)
	{
		bestResult = currentResult;
		return;
	}
	
	for (size_t i = 0; i < nodes; i++)
	{
		if (someGraph[startNode][i] != 0 && visited[i] == false)
		{
			visited[i] = true;
			currentResult += someGraph[startNode][i];

			findBestHamiltonPath(someGraph, nodes, i, visited, level + 1, bestResult, currentResult);

			currentResult -= someGraph[startNode][i];
			visited[i] = false;
		}
	}
}

int hamiltonLoops(std::vector<std::vector<int>> someGraph, const int nodes)
{
	bool *visited = new bool[nodes];

	int bestResult = 100000;
	for (size_t i = 0; i < nodes; i++)
	{
		for (size_t i = 0; i < nodes; i++)
		{
			visited[i] = false;
		}
		int level = 1;
		int currentResult = 0;
		visited[i] = true;
		findBestHamiltonPath(someGraph, nodes, i, visited, level, bestResult, currentResult);
	}

	delete[] visited;
	return bestResult;
}



int main()
{
	int nodes = 0;
	int vertices = 0;
	std::cin >> nodes >> vertices;
	std::cin.ignore();

	std::vector<std::vector<int>> graph;
	graph = createGraph(nodes, vertices);

	int result = hamiltonLoops(graph, nodes);
	std::cout << "Total cost: " << result << "\n";
	return 0;
}

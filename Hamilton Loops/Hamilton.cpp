#include "Hamilton.h"
#include <sstream>

Hamilton::Hamilton() :
	curr_sum(0),
	min_sum(1000)
{
	set_fileds();
}

std::string Hamilton::get_hamilton_loop(const int some_graph[7][7], int vertex, int level)
{
	cycle[1] = vertex;

	hamilton(some_graph, vertex, level);

	return print_solution();
}

void Hamilton::hamilton(const int some_graph[7][7], int vertex, int level)
{
	if (vertex == 1 && level > 1)
	{
		if (level == 7)
		{
			min_sum = curr_sum;
			for (size_t i = 1; i < 7; i++)
			{
				min_cycle[i] = cycle[i];
			}
		}
		return;
	}

	if (visited[vertex] == true)
	{
		return;
	}

	visited[vertex] = true;

	for (size_t i = 1; i < 7; i++)
	{
		if (some_graph[vertex][i] != 0 && vertex != i)
		{
			cycle[level] = i;
			curr_sum += some_graph[vertex][i];

			if (curr_sum < min_sum)
			{
				hamilton(some_graph, i, level + 1);
			}
			curr_sum -= some_graph[vertex][i];
		}
	}
	visited[vertex] = false;
}

std::string Hamilton::print_solution()
{
	std::ostringstream info;
	info << "The Hamilton path is:" << std::endl;
	info << 1 << " ";
	for (size_t i = 1; i < 7; i++)
	{
		info << min_cycle[i] << " ";
	}
	info << "with min sum: " << min_sum;

	return info.str();
}

void Hamilton::set_fileds()
{
	for (size_t i = 0; i < 7; i++)
	{
		visited[i] = false;
		min_cycle[i] = 0;
		cycle[i] = 0;
	}
}

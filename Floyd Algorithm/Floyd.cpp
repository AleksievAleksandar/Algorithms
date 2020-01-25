#include "Floyd.h"
#include <iostream>

void Floyd::find_shortest_path(int const some_graph[11][11])
{
	copy_graph(some_graph);
	set_max_values();

	for (size_t k = 1; k < 11; k++)
	{
		for (size_t i = 1; i < 11; i++)
		{
			for (size_t j = 1; j < 11; j++)
			{
				if (dublicated_graph[i][j] > dublicated_graph[i][k] + dublicated_graph[k][j])
				{
					dublicated_graph[i][j] = dublicated_graph[i][k] + dublicated_graph[k][j];
				}
			}
		}
	}

	for (size_t i = 1; i < 11; i++)
	{
		dublicated_graph[i][i] = 1000;
	}

	print_solution();
}

void Floyd::copy_graph(int const some_graph[][11])
{
	for (size_t i = 0; i < 11; i++)
	{
		for (size_t a = 0; a < 11; a++)
		{
			dublicated_graph[i][a] = some_graph[i][a];
		}
	}
}

void Floyd::set_max_values()
{
	for (size_t i = 0; i < 11; i++)
	{
		for (size_t a = 0; a < 11; a++)
		{
			if (dublicated_graph[i][a] == 0)
			{
				dublicated_graph[i][a] = 1000;
			}
		}
	}
}

void Floyd::print_solution()
{
	for (size_t i = 1; i < 11; i++)
	{
		for (size_t a = 1; a < 11; a++)
		{
			//printf("%3d ", (dublicated_graph[i][a] == 1000) ? 0 : dublicated_graph[i][a]); //ternary operator does not work correctly with cout!!!
			//std::cout << " ";
			std::cout << ((dublicated_graph[i][a] == 1000) ? 0 : dublicated_graph[i][a]) << " ";
		}
		std::cout << std::endl;
	}
	/*for (size_t i = 1; i < 11; i++)
	{
		for (size_t a = 1; a < 11; a++)
		{
			if (dublicated_graph[i][a] == 1000)
			{
				std::cout << 0 << " ";
			}
			else
			{
				std::cout << dublicated_graph[i][a] << " ";
			}
		}
		std::cout << std::endl;
	}*/
}

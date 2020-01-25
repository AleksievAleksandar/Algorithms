#include "DFS_find_all_paths_between_two_vertices.h"
#include <iostream>

void DFS_between_two_vertices::find_all_paths(int const some_grapg[][15], int const start_vertex, int const end_vertex)
{
	if (!get_start_vertex)
	{
		dublicate_start_vertex = start_vertex;
		get_start_vertex = true;
	}

	if (start_vertex == end_vertex)
	{
		print_solution();
		return;
	}

	visited[start_vertex] = true;

	for (size_t i = 1; i < 15; i++)
	{
		if (some_grapg[start_vertex][i] == 1 && visited[i] != true)
		{
			//visited[start_vertex] = true;
			queue[cnt_queue++] = i;
			find_all_paths(some_grapg, i, end_vertex);
			visited[i] = false;
			queue[cnt_queue--] = 0;
		}
	}
}

DFS_between_two_vertices::DFS_between_two_vertices() :
	cnt_queue(0),
	get_start_vertex(false)
{
	for (size_t i = 0; i < 15; i++)
	{
		visited[i] = false;
		queue[i] = 0;
	}
}

void DFS_between_two_vertices::print_solution()
{
	int temp = 1;
	size_t cnt = 0;
	size_t cnt_stop = 1;

	std::cout << dublicate_start_vertex << " ";
	while (temp != 0)
	{
		temp = queue[cnt_stop++];
		std::cout << queue[cnt++] << " ";
	}
	std::cout << std::endl;
}

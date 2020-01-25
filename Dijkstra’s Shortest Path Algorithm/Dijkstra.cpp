#include "Dijkstra.h"
#include <iostream>

void Dijkstra::find_shortest_path(int const some_graph[6][6], int start_vertex, int end_vertex)
{
	set_fields(start_vertex);
	
	while (check_visited_vertices(visited))
	{
		for (size_t i = 0; i < 6; i++)
		{
			if (some_graph[start_vertex][i] != 0 && visited[i] != true)
			{
				queue[cnt_queue++] = i;
				if (best_distance[i] > best_distance[start_vertex] + some_graph[start_vertex][i])
				{
					parent[i] = start_vertex;
					best_distance[i] = best_distance[start_vertex] + some_graph[start_vertex][i];
				}
			}
		}
		visited[start_vertex] = true;

		start_vertex = get_next_vertex_for_iteration(start_vertex);
		if (to_break == start_vertex)
		{
			break;
		}
		to_break = start_vertex;
	
	}

	std::cout << "The shortest path between " << get_start_vertex << " and " << end_vertex << " is:" << std::endl;
	print_solution(get_start_vertex, end_vertex);
	if (best_distance[end_vertex] != 1000)
	{
		std::cout << end_vertex << " with value: " << best_distance[end_vertex] << std::endl;
	}
}

void Dijkstra::set_fields(int start_vertex)
{
	for (size_t i = 0; i < 20; i++)
	{
		queue[i] = 0;
	}
	for (size_t i = 0; i < 6; i++)
	{
		parent[i] = 0;
		visited[i] = false;
		best_distance[i] = 1000;
	}
	get_start_vertex = start_vertex;
	visited[0] = true;
	cnt_queue++;
	queue[cnt_queue++] = start_vertex;
	best_distance[start_vertex] = 0;
	to_break = 0;
}

bool Dijkstra::check_visited_vertices(bool visited_array[])
{
	bool check = false;
	for (size_t i = 0; i < 6; i++)
	{
		if (visited_array[i] == false)
		{
			check = true;
		}
	}
	return check;
}

int Dijkstra::get_next_vertex_for_iteration(int start_vertex)
{
	for (size_t i = 0; i < 6; i++)
	{
		if (visited[i] != true && best_distance[i] < get_smalest_edge)
		{
			get_smalest_edge = best_distance[i];
			get_next_vertex = i;
		}
	}
	get_smalest_edge = 1000;
	return start_vertex = get_next_vertex;
}

void Dijkstra::print_solution(int start_vertex, int end_vertex)
{
	if (parent[end_vertex] == 0 && visited[end_vertex] != true)
	{
		std::cout << "There is no path between those two vertices." << std::endl;
	}
	else
	{
		if (parent[end_vertex] == 0)
		{
			return;
		}
		print_solution(start_vertex, parent[end_vertex]);
		std::cout << parent[end_vertex] << " -> ";
	}
}

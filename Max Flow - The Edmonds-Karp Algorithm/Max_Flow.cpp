#include "Max_Flow.h"
#include <sstream>

Max_Flow::BFS::BFS()
{
	set_fields();
}

int Max_Flow::BFS::find_critical_edge(const int some_graph[7][7], size_t size, int start_vertex, int end_vertex)
{
	int cnt_one = 0;
	int cnt_two = 0;
	copy_graph(some_graph, size);

	stack[counter++] = start_vertex;

	while (cnt_one == cnt_two)
	{
		set_fields();
		for (size_t i = start_vertex; i < size; i++)
		{
			if (stack[counter - 1] == end_vertex)
			{
				find_end_vertex = true;
				break;
			}
			for (size_t a = 1; a < size; a++)
			{
				if (dublicated_graph[i][a] != 0 && visited[a] != true)
				{
					stack[counter++] = a;
					visited[a] = true;
					parent[a] = i;
				}
			}
			if (stack[index_cout] != 0)
			{
				i = stack[index_cout++] - 1;
			}
			else
			{
				break;
			}
		}
		int first_vertex_for_delete = 0;
		int second_vertex_for_delete = 0;
		int max_flow = 1000;
		int while_cnt = stack[--counter];
		while (parent[while_cnt] != 0)
		{
			if (max_flow >= dublicated_graph[parent[while_cnt]][while_cnt])
			{
				max_flow = dublicated_graph[parent[while_cnt]][while_cnt];
				//dublicated_graph[parent[while_cnt]][while_cnt] = 0;
				//first_vertex_for_delete = parent[while_cnt];
				//second_vertex_for_delete = while_cnt;
			}
			if (dublicated_graph[parent[while_cnt]][while_cnt] != 1000)
			{
				first_vertex_for_delete = parent[while_cnt];
				second_vertex_for_delete = while_cnt;
			}
			while_cnt = parent[while_cnt];
		}
		dublicated_graph[first_vertex_for_delete][second_vertex_for_delete] = 0;
		if (max_flow < 1000) // && find_end_vertex == true
		{
			max_flow_of_graph += max_flow;
			cnt_one++;
		}
		cnt_two++;
	}

	return max_flow_of_graph;
}

void Max_Flow::BFS::copy_graph(const int some_graph[7][7], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t a = 0; a < size; a++)
		{
			dublicated_graph[i][a] = some_graph[i][a];
		}
	}
}

void Max_Flow::BFS::set_fields()
{
	for (size_t i = 0; i < 7; i++)
	{
		visited[i] = false;
		stack[i] = 0;
		parent[i] = 0;
	}
	counter = 1;
	index_cout = 1;
	find_end_vertex = false;
}

std::string Max_Flow::get_max_flow(const int some_graph[7][7], size_t size, int start_vertex, int end_vertex)
{
	BFS *find = new BFS();

	std::ostringstream info;
	info << "The max flow of the graph is: ";
	info << find->find_critical_edge(some_graph, size, start_vertex, end_vertex) << std::endl;

	return info.str();
}

#pragma once

class Floyd
{
public:
	void find_shortest_path(int const some_graph[][11]);

private:
	int dublicated_graph[11][11];
	void copy_graph(int const some_graph[][11]);
	void set_max_values();
	void print_solution();
};

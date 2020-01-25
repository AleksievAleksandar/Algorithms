#pragma once

class DFS_between_two_vertices
{
public:
	void find_all_paths(int const some_grapg[][15], int const start_vertex, int const end_vertex);
	DFS_between_two_vertices();

private:
	bool visited[15];
	int queue[15];
	size_t cnt_queue;
	void print_solution();
	int dublicate_start_vertex;
	bool get_start_vertex;
};

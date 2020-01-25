#pragma once

class Dijkstra
{
public:
	void find_shortest_path(int const some_graph[6][6], int start_vertex, int end_vertex);


private:
	bool visited[6];
	int parent[6];
	int best_distance[6];
	int queue[20];
	size_t cnt_queue = 0;
	int get_next_vertex = 0;
	int get_smalest_edge = 1000;
	int get_start_vertex = 0;
	void set_fields(int start_vertex);
	bool check_visited_vertices(bool visited_array[]);
	int get_next_vertex_for_iteration(int start_vertex);
	void print_solution(int start_vertex, int end_vertex);
	int to_break = 0;
};

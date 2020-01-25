#pragma once
#include <string>

class Hamilton
{
public:
	Hamilton();
	std::string get_hamilton_loop(const int some_graph[7][7], int vertex, int level);

private:
	void hamilton(const int some_graph[7][7], int vertex, int level);
	std::string print_solution();
	bool visited[7];
	int min_cycle[7];
	int cycle[7];
	int curr_sum;
	int min_sum;
	void set_fileds();
};

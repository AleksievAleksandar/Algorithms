#pragma once
#include <string>

class Max_Flow
{
public:
	std::string get_max_flow(const int some_graph[7][7], size_t size, int start_vertex, int end_vertex);

private:
	class BFS
	{
	public:
		BFS();
		int find_critical_edge(const int some_graph[7][7], size_t size, int start_vertex, int end_vertex);

	private:
		void copy_graph(const int some_graph[7][7], size_t size);
		int dublicated_graph[7][7];
		int stack[7];
		int counter = 0;
		int index_cout = 1;
		bool visited[7];
		int parent[7];
		void set_fields();
		int max_flow_of_graph = 0;
		bool find_end_vertex = false;
	};

	
};

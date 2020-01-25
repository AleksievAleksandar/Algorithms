#include <iostream>
#include "Max_Flow.h"

#define option 1

#if option == 12
const int graph[10][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
							              { 0, 0, 1000, 1000, 0, 0, 0, 0, 0, 0 }, 
							              { 0, 0, 0, 0, 5, 7, 0, 0, 0, 0 }, 
						              	{ 0, 0, 0, 0, 7, 0, 0, 0, 0, 0 }, 
						              	{ 0, 0, 0, 0, 0, 0, 19, 0, 0, 0 }, 
						              	{ 0, 0, 0, 0, 0, 0, 5, 10, 0, 0 }, 
						              	{ 0, 0, 0, 0, 0, 0, 0, 0, 27, 0 }, 
							              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 12 }, 
							              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 15 }, 
							              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };

const size_t size_of_graph = 10;
#else
const int graph[7][7] =   { { 0, 0, 0, 0, 0, 0, 0 },
							              { 0, 0, 5, 5, 10, 0, 0 }, 
							              { 0, 0, 0, 4, 0, 0, 5 }, 
							              { 0, 0, 0, 0, 0, 7, 0 }, 
							              { 0, 0, 0, 0, 0, 0, 7 }, 
							              { 0, 0, 0, 0, 0, 0, 8 }, 
							              { 0, 0, 0, 0, 0, 0, 0 }, };
const size_t size_of_graph = 7;
#endif

int main()
{
	Max_Flow *result = new Max_Flow();
	std::cout << result->get_max_flow(graph, size_of_graph, 1, 6);

	getchar();
	return 0;
}

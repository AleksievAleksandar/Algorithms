#include <iostream>
#include "Hamilton.h"

const int graph[7][7] =   { { 0, 0, 0, 0, 0, 0, 0 },
						              	{ 0, 0, 5, 0, 0, 7, 7 }, 
							              { 0, 5, 0, 5, 0, 0, 0 }, 
							              { 0, 0, 5, 0, 6, 5, 0 }, 
						              	{ 0, 0, 0, 6, 0, 3, 3 }, 
						              	{ 0, 7, 0, 5, 3, 0, 5 }, 
							              { 0, 7, 0, 0, 3, 5, 0 }, };

int main()
{
	Hamilton *find = new Hamilton();
	std::cout << find->get_hamilton_loop(graph, 1, 1);

	getchar();
	return 0;
}

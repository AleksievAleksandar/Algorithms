#include <iostream>
#include <vector>
#include "Links.h"

const std::vector<std::vector<int> > graph =  { { 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 1, 1, 0, 0, 0 }, 
						{ 0, 1, 0, 1, 0, 0, 0 }, 
						{ 0, 1, 1, 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 1, 1 }, 
						{ 0, 0, 0, 0, 1, 0, 1 }, 
						{ 0, 0, 0, 0, 1, 1, 0 }, };

int main()
{
	LinksOfConnections* conn = new LinksOfConnections();
	std::cout << conn->findLinks(graph,1);
	
	delete conn;
	return 0;
}

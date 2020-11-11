#pragma once
#include "Neighbours.h"
#include <string>

class Kruskal
{
	Neighbours* neighbours = new Neighbours();
	Neighbours* MST = new Neighbours();
public:
	~Kruskal();
public:
	std::string getResult(const int someGraph[GraphSize][GraphSize]);

private:
	int roots[GraphSize];
	void setRoots();
	void updateRoots();
	int rootForUpdate;
	int rootForUpdSec;
	void setMST();
	std::string printMST();
};

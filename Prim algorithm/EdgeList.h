#pragma once

class EdgeList
{
public:
	int queue[20];
	int vertex[20];
	int parent[20];
	void sortQueue();

private:
	void setFields();
	size_t cnt = 0;
};

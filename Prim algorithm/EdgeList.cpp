#include "EdgeList.h"

void EdgeList::sortQueue()
{
	int temp = 0;
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t a = cnt; a < 19; a++)
		{
			if (queue[a] > queue[a + 1] && queue[a] != 0 && queue[a + 1] != 0)
			{
				temp = queue[a];
				queue[a] = queue[a + 1];
				queue[a + 1] = temp;

				temp = vertex[a];
				vertex[a] = vertex[a + 1];
				vertex[a + 1] = temp;

				temp = parent[a];
				parent[a] = parent[a + 1];
				parent[a + 1] = temp;
			}
		}
	}
	cnt++;
}

void EdgeList::setFields()
{
	for (size_t i = 0; i < 20; i++)
	{
		queue[i] = 0;
	}
}

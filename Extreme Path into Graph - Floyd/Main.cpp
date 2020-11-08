#include<iostream>

#define MAX_VALUE 10000

int const arguments = 5;

int graph[arguments][arguments] = { {0, 0, 0, 0, 0},
                                    {0, 0, 0, 6, 2}, 
                                    {0, 0, 0, 0, 0}, 
                                    {0, 0, 1, 0, 0}, 
                                    {0, 0, 0, 2, 0}, };

/*int graph[arguments][arguments] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	                              {0, 0, 23, 0, 0, 0, 0, 0, 8, 0, 0},
				      {0, 23, 0, 0, 3, 0, 0, 34, 0, 0, 0},
				      {0, 0, 0, 0, 6, 0, 0, 0, 25, 0, 7},
				      {0, 0, 3, 6, 0, 0, 0, 0, 0, 0, 0},
				      {0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0},
				      {0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0},
				      {0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0},
				      {0, 8, 0, 25, 0, 0, 0, 0, 0, 0, 30},
				      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				      {0, 0, 0, 7, 0, 0, 0, 0, 30, 0, 0} };*/

class Floyd
{
public:
	void findMinPathBetweenEveryVertex()
	{
		for (int i = 1; i < arguments; i++)
		{
			for (int a = 1; a < arguments; a++)
			{
				if (graph[i][a] == 0)
				{
					graph[i][a] = MAX_VALUE;
				}
			}
		}

		for (int k = 1; k < arguments; k++)
		{
			for (int i = 1; i < arguments; i++)
			{
				for (int j = 1; j < arguments; j++)
				{
					if (graph[i][j] > (graph[i][k] + graph[k][j]))
					{
						graph[i][j] = (graph[i][k] + graph[k][j]);
					}
				}
			}
		}
		for (int i = 1; i < arguments; i++)
		{
			graph[i][i] = 0;
		}
		printMinPaths();
	}

	void printMinPaths()
	{
		for (int i = 0; i < arguments; i++)
		{
			for (int a = 0; a < arguments; a++)
			{
				std::cout << (MAX_VALUE == graph[i][a] ? 0 : graph[i][a]);
				std::cout << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Floyd *a = new Floyd;
	a->findMinPathBetweenEveryVertex();

	delete a;
	return 0;
}

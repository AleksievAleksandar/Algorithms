#include <iostream>
#include "Queens.h"

const size_t boardSize = 8;

char board[boardSize][boardSize] ={ { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
									                  { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
									                  { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
								                  	{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
									                  { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
									                  { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
									                  { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', },
									                  { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', } };

int main()
{
	Queens *a = new Queens();
	std::cout << a->findQueens(board);

	getchar();
	return 0;
}

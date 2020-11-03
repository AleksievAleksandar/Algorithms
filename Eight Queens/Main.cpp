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
	Queens *board = new Queens();
	std::cout << board->findQueens(board);

	delete board;
	return 0;
}

#include "Queens.h"
#include <sstream>

std::string Queens::findQueens(char board[sizeBoard][sizeBoard])
{
	setFields();
	placeQueen(board, 0);

	allResults << "Total result: " << counter;

	return allResults.str();
}

void Queens::placeQueen(char board[sizeBoard][sizeBoard], int horizont)
{
	if (numberOfQueens == sizeBoard)
	{
		printBoard();
		counter++;
	}

	if (horizont < 0 || horizont >= sizeBoard)
	{
		return;
	}

	for (size_t i = 0; i < sizeBoard; i++)
	{
		if (isOccupied[horizont][i] == 0)
		{
			chessBoard[horizont][i] = 'X';
			numberOfQueens++;
			setOccupied(horizont, i);

			placeQueen(chessBoard, horizont + 1);

			chessBoard[horizont][i] = 'o';
			numberOfQueens--;
			deOccupied(horizont, i);
		}
	}
}

void Queens::setOccupied(int field, int diagonal)
{
	//horizontal
	for (size_t i = 0; i < sizeBoard; i++)
	{
		isOccupied[field][i] += 1;
	}

	//vertical
	for (size_t i = 0; i < sizeBoard; i++)
	{
		if (field != i)
		{
			isOccupied[i][diagonal] += 1;
		}
	}


	//diagonal -> down(right)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		if (field + i < sizeBoard && diagonal + i < sizeBoard)
		{
			isOccupied[field + i][diagonal + i] += 1;
		}
	}

	//dialgonal -> up(left)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		int a = field - i;
		int b = diagonal - i;
		if (a >= 0 && b >= 0)
		{
			isOccupied[field - i][diagonal - i] += 1;
		}
	}

	//diagonal -> down(left)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		int b = diagonal - i;
		if (field + i < sizeBoard && b >= 0)
		{
			isOccupied[field + i][diagonal - i] += 1;
		}
	}

	//diagonal -> up(right)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		int a = field - i;
		if (a >= 0 && diagonal + i < sizeBoard)
		{
			isOccupied[field - i][diagonal + i] += 1;
		}
	}
}

void Queens::deOccupied(int field, int diagonal)
{
	//horizontal
	for (size_t i = 0; i < sizeBoard; i++)
	{
		isOccupied[field][i] -= 1;
	}

	//vertical
	for (size_t i = 0; i < sizeBoard; i++)
	{
		if (field != i)
		{
			isOccupied[i][diagonal] -= 1;
		}
	}


	//diagonal -> down(right)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		if (field + i < sizeBoard && diagonal + i < sizeBoard)
		{
			isOccupied[field + i][diagonal + i] -= 1;
		}
	}

	//dialgonal -> up(left)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		int a = field - i;
		int b = diagonal - i;
		if (a >= 0 && b >= 0)
		{
			isOccupied[field - i][diagonal - i] -= 1;
		}
	}

	//diagonal -> down(left)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		int b = diagonal - i;
		if (field + i < sizeBoard && b >= 0)
		{
			isOccupied[field + i][diagonal - i] -= 1;
		}
	}

	//diagonal -> up(right)
	for (size_t i = 1; i < sizeBoard; i++)
	{
		int a = field - i;
		if (a >= 0 && diagonal + i < sizeBoard)
		{
			isOccupied[field - i][diagonal + i] -= 1;
		}
	}
}

void Queens::setFields()
{
	for (size_t i = 0; i < sizeBoard; i++)
	{
		for (size_t a = 0; a < sizeBoard; a++)
		{
			isOccupied[i][a] = 0;
			chessBoard[i][a] = 'o';
		}
	}
}

std::string Queens::printBoard()
{
	for (size_t i = 0; i < sizeBoard; i++)
	{
		for (size_t a = 0; a < sizeBoard; a++)
		{
			allResults << chessBoard[i][a] << " ";
		}
		allResults << std::endl;
	}
	allResults << std::endl;

	return allResults.str();
}

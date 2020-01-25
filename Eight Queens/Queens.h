#pragma once
#include <string>
#include <sstream>

const size_t sizeBoard = 8;

class Queens
{
public:
	std::string findQueens(char board[sizeBoard][sizeBoard]);

private:
	size_t numberOfQueens = 0;
	int isOccupied[sizeBoard][sizeBoard];
	char chessBoard[sizeBoard][sizeBoard];
	size_t counter = 0;

private:
	void placeQueen(char board[sizeBoard][sizeBoard], int horizont);
	void setOccupied(int field, int diagonal);
	void deOccupied(int field, int diagonal);
	void setFields();
	std::string printBoard();
	std::ostringstream allResults;
};

#include "WordDifferences.h"

int WordDifferences::findMinChanges(const std::string &first, const std::string &second)
{
	this->stringToModify = first;
	this->stringTarget = second;

	return this->generateDiffs(this->stringToModify, this->stringTarget);
}


int WordDifferences::generateDiffs(const std::string &stringToModify, const std::string &stringTarget)
{
	std::vector<std::vector<int>> levenshteinDistanceMatrix(stringToModify.size() + 1, std::vector<int>(stringToModify.size() + 1, 0));
	this->setRowsAndCols(levenshteinDistanceMatrix);

	return this->calculateDistance(levenshteinDistanceMatrix);
}


int WordDifferences::min(const int &a, const int &b)
{
	return (a < b) ? a : b;
}


void WordDifferences::setRowsAndCols(std::vector<std::vector<int>> &matrix)
{
	for (size_t i = 0; i < this->stringToModify.size() + 1; i++)
	{
		matrix[0][i] = i;
		matrix[i][0] = i;
	}
}


int WordDifferences::calculateDistance(std::vector<std::vector<int>>& matrix)
{
	for (size_t row = 1; row < this->stringToModify.size() + 1; row++)
	{
		for (size_t col = 1; col < this->stringToModify.size() + 1; col++)
		{
			if (this->stringTarget[row - 1] != this->stringToModify[col - 1])
			{
				matrix[row][col] = this->min(matrix[row - 1][col], matrix[row][col - 1]) + 1;
			}
			else
			{
				matrix[row][col] = matrix[row - 1][col - 1];
			}		
		}
	}
	return matrix[this->stringToModify.size()][this->stringToModify.size()];
}

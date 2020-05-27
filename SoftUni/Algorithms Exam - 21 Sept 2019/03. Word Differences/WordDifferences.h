#pragma once

#include <sstream>
#include <vector>

class WordDifferences
{
public:
	WordDifferences() = default;
	int findMinChanges(const std::string &first, const std::string &second);

private:
	std::string stringToModify;
	std::string stringTarget;

private:
	int generateDiffs(const std::string &stringToModify, const std::string &stringTarget);
	int min(const int &a, const int &b);
	void setRowsAndCols(std::vector<std::vector<int>> &matrix);
	int calculateDistance(std::vector<std::vector<int>>& matrix);
};

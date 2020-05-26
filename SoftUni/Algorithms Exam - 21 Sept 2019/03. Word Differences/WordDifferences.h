#pragma once

#include <sstream>
#include <vector>

class WordDifferences
{
public:
	WordDifferences() = default;
	void findMinChanges(const std::string &first, const std::string &second);

private:
	std::vector<char> charVector;
	std::vector<char> charVectorTarget;
	std::string firstWordCopy;
	int minChanges = 10000;
	int currentChanges = 0;
private:
	void getCharsFromString(const std::string &strOne, const std::string& strTwo);
	void generateDiffs(std::vector<char> str, int index);
	void deletion(int index);
	void insertion(int index, char symbol);
};
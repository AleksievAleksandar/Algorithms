#pragma once

#include <vector>
#include <sstream>

class Words
{
public:
	Words() = default;
	std::string generateWordsCombinations(std::string stringWords, std::string stringTarget);

private:
	std::ostringstream solutions;
	std::vector<std::string> words;
	std::string targetString;
	std::vector<std::string> generatedCombinations;
	std::vector<bool> visited; // this option must be implemented if we want not to use one and the same characters

private:
	void getAllWords(std::string stringWords);
	void getTargetString(std::string stringWord);
	void generate(std::vector<std::string> words, int index, int startInddex);
	void setFields();
	void print();
	bool findWord(std::string currentWord, int startIndex);
};

#pragma once

#include <vector>
#include <sstream>

class Words
{
public:
	Words() = default;
	void generateWordsCombinations(std::string stringWords, std::string stringTarget);

private:
	std::vector<std::string> words;
	std::string target;
	std::vector<std::string> combinations;
	std::vector<bool> visited;
	std::string finded;

private:
	void getAllWords(std::string stringWords);
	void getTargetString(std::string stringWord);
	void gen(std::vector<std::string> words, int index);
	void setFields();
	void print();
};
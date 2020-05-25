#include "Words.h"

std::string Words::generateWordsCombinations(std::string stringWords, std::string stringTarget)
{
	this->getAllWords(stringWords);
	this->getTargetString(stringTarget);

	this->generatedCombinations.resize(words.size());
	this->visited.resize(words.size());
	this->setFields();

	this->generate(this->words, 0, 0);

	return this->solutions.str();
}

void Words::getAllWords(std::string stringWords)
{
	std::istringstream iss(stringWords);
	std::string currentWord;

	while (iss >> currentWord)
	{
		if (currentWord[currentWord.size() - 1] == ',')
		{
			std::string reworkedWord(currentWord.begin(), currentWord.end() - 1);
			this->words.push_back(reworkedWord);
		}
		else
		{
			this->words.push_back(currentWord);
		}
	}
}

void Words::getTargetString(std::string stringWord)
{
	this->targetString = stringWord;
}


void Words::generate(std::vector<std::string> words, int index, int startIndex)
{
	if (startIndex >= this->targetString.size())
	{
		this->print();
		return;
	}

	for (size_t i = 0; i < words.size(); i++)
	{
		if (findWord(words[i], startIndex))
		{
			this->generatedCombinations[index] = words[i];
			startIndex += words[i].size();

			generate(words, index + 1, startIndex);

			this->generatedCombinations[index] = "";
			startIndex -= words[i].size();
		}
	}
}

void Words::setFields()
{
	for (size_t i = 0; i < this->visited.size(); i++)
	{
		this->visited[i] = false;
	}
}

void Words::print()
{
	for (size_t i = 0; i < this->generatedCombinations.size(); i++)
	{
		this->solutions << generatedCombinations[i] << " ";
	}
	this->solutions << "\n";
}

bool Words::findWord(std::string currentWord, int startIndex)
{
	bool isEqual = true;

	int cnt = 0;
	while (cnt != currentWord.size())
	{
		if (currentWord[cnt] != this->targetString[startIndex])
		{
			isEqual = false;
			break;
		}
		cnt++;
		startIndex++;
	}
	return isEqual;
}

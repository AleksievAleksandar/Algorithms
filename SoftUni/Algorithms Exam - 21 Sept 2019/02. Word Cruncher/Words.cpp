#include "Words.h"
#include <iostream>
#include <set>

void Words::generateWordsCombinations(std::string stringWords, std::string stringTarget)
{
	this->getAllWords(stringWords);
	this->getTargetString(stringTarget);

	//this->combinations.resize(words.size());
	this->visited.resize(words.size());
	this->setFields();

	this->gen(this->words, 0);
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
	this->target = stringWord;
}

void Words::gen(std::vector<std::string> words, int index)
{
	int cnt = 0;

	while (cnt != this->target.size())
	{
		for (size_t i = 0; i < this->words.size(); i++)
		{
			if (this->words[i][0] == this->target[cnt])
			{
				this->combinations.push_back(words[i]);
			}
		}
		cnt++;
	}
	std::set<std::string> uniqe(this->combinations.begin(), this->combinations.end());
	int a = 0;
	/*
	if (index >= words.size())
	{
		this->print();
		return;
	}

	for (size_t i = 0; i < words.size(); i++)
	{
		if (this->visited[i] != true)
		{
			this->visited[i] = true;
			this->combinations[index] = words[i];

			this->gen(words, index + 1);

			this->visited[i] = false;
			this->combinations[index] = "";
		}
	}
	*/
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
	for (size_t i = 0; i < this->combinations.size(); i++)
	{
		std::cout << combinations[i] << " ";
	}
	std::cout << "\n";
}

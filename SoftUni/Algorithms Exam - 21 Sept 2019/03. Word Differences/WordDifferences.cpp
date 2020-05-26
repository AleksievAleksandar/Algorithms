#include "WordDifferences.h"

void WordDifferences::findMinChanges(const std::string &first, const std::string &second)
{
	this->charVector.resize(first.size());
	this->charVectorTarget.resize(first.size());
	this->firstWordCopy = first;
	
	this->getCharsFromString(first, second);

	this->generateDiffs(this->charVector, 0);
}

void WordDifferences::getCharsFromString(const std::string& strOne, const std::string& strTwo)
{
	for (size_t i = 0; i < strOne.size(); i++)
	{
		this->charVector[i] = strOne[i];
		this->charVectorTarget[i] = strTwo[i];
	}
}

void WordDifferences::generateDiffs(std::vector<char> str, int index)
{
	if (this->charVector == this->charVectorTarget)
	{
		if (this->minChanges > this->currentChanges)
		{
			this->minChanges = this->currentChanges;
		}
		return;
	}

	if (index == str.size())
	{
		return;
	}

	for (size_t i = 0; i < this->charVector.size(); i++)
	{
		if (this->charVector[i] != this->charVectorTarget[i])
		{
			this->deletion(i);
			this->generateDiffs(str, index + 1);

			this->insertion(i, this->charVectorTarget[i]);
			this->generateDiffs(str, index + 1);
		}

	}
}

void WordDifferences::deletion(int index)
{
	this->charVector.erase(this->charVector.begin() + index);
}

void WordDifferences::insertion(int index, char symbol)
{
	this->charVector.insert(this->charVector.begin() + index, symbol);
}

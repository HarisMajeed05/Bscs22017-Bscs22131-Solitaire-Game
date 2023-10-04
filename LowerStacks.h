#pragma once
#include "fannedpile.h"

class LowerStacks : public fannedPile
{
public:
	LowerStacks(sf::Vector2i = sf::Vector2i(0, 0), sf::Vector2f = sf::Vector2f(30.0, 15.0));
	~LowerStacks();
	bool canSplit(unsigned int);
	bool canAppend(const pile&);
};

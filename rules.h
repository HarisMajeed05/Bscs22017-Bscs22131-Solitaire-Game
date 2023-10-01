#pragma once
#include "fannedpile.h"

class rules : public fannedPile
{
public:
	rules(sf::Vector2i = sf::Vector2i(0, 0), sf::Vector2f = sf::Vector2f(30.0, 15.0));
	~rules();
	bool canSplit(unsigned int);
	bool canAppend(const pile&);
};

#include "stackpile.h"
#include "squaredPile.h"

class EmptyStacks : public stackPile, public squaredPile
{
public:
	EmptyStacks(sf::Vector2i = sf::Vector2i(0, 0));
	bool canSplit(unsigned int);
	bool canAppend(const pile&);
	~EmptyStacks();
};
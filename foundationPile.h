#include "stackpile.h"
#include "squaredPile.h"

class foundationPile : public stackPile, public squaredPile
{
public:
	foundationPile(sf::Vector2i = sf::Vector2i(0, 0));
	bool canSplit(unsigned int);
	bool canAppend(const pile&);
	~foundationPile();
};
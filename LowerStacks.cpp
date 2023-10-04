#include "LowerStacks.h"


LowerStacks::LowerStacks(sf::Vector2i offset, sf::Vector2f visibility) : pile(offset), fannedPile(offset, fannedPile::Down, visibility) {
}

bool LowerStacks::canSplit(unsigned int cardIndex) {
	return commonSplitTest(cardIndex);
}

bool LowerStacks::canAppend(const pile& p) {
	if (commonAppendTest(p)) {
		if (getSize() == 0) {
			if (p.getCard(0).getRank() == card::King)
				return true;
		}
		else {
			card thisLastCard = getCard(getSize() - 1);
			card pFirstCard = p.getCard(0);
			if (pFirstCard.getDescendent() == thisLastCard.getRank() && thisLastCard.getColor() != pFirstCard.getColor())
				return true;
		}
	}
	return false;
}

LowerStacks::~LowerStacks(void) {
}
#include "card.h"
card::card(cardRank r, cardSuit s) : rank(r), suit(s) {
}
card::cardRank card::getRank() const {
	return rank;
}
card::cardSuit card::getSuit() const {
	return suit;
}
card::cardColor card::getColor() {
	return cardColor(suit == Diamonds || suit == Hearts);
}
card::cardRank card::getDescendent() {
	return cardRank(rank + 1);
}
card::~card() {
}
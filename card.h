#pragma once
class card {
public:
	enum cardSuit { Spades, Hearts, Diamonds, Clubs };
	enum cardRank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, None };
	enum cardColor { Red, Black };
	card(cardRank, cardSuit);
	cardRank getRank() const;
	cardSuit getSuit() const;
	cardColor getColor();
	cardRank getDescendent();
	~card();
protected:
	cardSuit suit;
	cardRank rank;
};
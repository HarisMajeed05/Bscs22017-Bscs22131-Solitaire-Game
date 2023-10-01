#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "card.h"

class pileCard : public card{
public:
	static const unsigned int WIDTH = 120;
	static const unsigned int HEIGHT = 160;
	enum cardOrientation { Face_Up, Face_Down };
	pileCard(cardRank, cardSuit, cardOrientation = Face_Up, sf::Sprite = sf::Sprite());
	pileCard(const pileCard&);
	card getCard() const;
	cardOrientation getOrientation() const;
	void setOffset(const sf::Vector2i&);
	pileCard operator=(const pileCard&);
	void draw(sf::RenderWindow&);
	void flip();
	~pileCard();
private:
	cardOrientation orientation;
	sf::Sprite sprite;
	sf::Texture const* texture;
};

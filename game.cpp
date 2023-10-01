#include "game.h"
sf::Texture game::textures[card::King + 1][card::Clubs + 1];
sf::Texture game::faceDown;
game::game(void) :sPile(nullptr) {
	backgroundTexture = loadTexture("textures//background.png");
	background.setTexture(backgroundTexture);
	sf::Vector2u size = backgroundTexture.getSize();
	background.scale(float(Width) / size.x, float(Height) / size.y);
	deck standardDeck;
	standardDeck.shuffle();
	piles = standardDeck.getPiles();
}
bool game::isWin() {
	for (unsigned int i = 0; i < 4; i++) {
		if (piles[i]->getSize() != 13)
			return false;
	}
	return true;
}
bool game::isLose() {
	return false;
}
string game::getTexturePath(const card& c) {
	char suitString[2];
	char rankString[3];
	_itoa_s(c.getRank(), rankString, 10);
	_itoa_s(c.getSuit(), suitString, 10);
	string filename;
	filename = string(rankString) + "_" + string(suitString);
	return "textures//" + filename + ".png";
}
sf::Texture* game::getTexture(const pileCard& c) {
	if (c.getOrientation() == pileCard::Face_Down)
		return &faceDown;
	else
		return &textures[c.getRank()][c.getSuit()];
}
void game::loadTextures() {
	for (int i = card::Ace; i <= card::King; i++) {
		for (int j = card::Spades; j <= card::Clubs; j++)
			textures[i][j] = loadTexture(getTexturePath(card(card::cardRank(i), card::cardSuit(j))));
		faceDown = loadTexture("textures\\backside.png");
	}
}
void game::onMouseDown(const sf::Vector2i& mousePos) {
	unsigned int i;
	for (i = 0; i < piles.size() && (sPile = piles[i]->splitPile(mousePos)) == nullptr; i++);
	if (i < piles.size()) {
		mouseOffset = mousePos - sPile->getOffset();
	}
}
void game::onMouseUp() {
	if (sPile) {
		sPile->onMouseUp(piles);
		delete sPile;
		sPile = nullptr;
	}
}
void game::onMouseMove(const sf::Vector2i& mousePos) {
	if (sPile) {
		sPile->setPosition(mousePos - mouseOffset);
	}
}
void game::draw(sf::RenderWindow& window) {
	window.draw(background);
	for (unsigned int i = 0; i < piles.size(); i++)
		piles[i]->draw(window);
	if (sPile)
		sPile->draw(window);
}
game::~game(void) {
}
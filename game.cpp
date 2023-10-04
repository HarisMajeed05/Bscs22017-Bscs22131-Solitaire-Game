#include "game.h"
sf::Texture game::textures[card::King + 1][card::Clubs + 1];
sf::Texture game::faceDown;
sf::Font font;

game::game() :sPile(nullptr) {
	backgroundTexture = loadTexture("textures//background.png");
	background.setTexture(backgroundTexture);
	sf::Vector2u size = backgroundTexture.getSize();
	background.scale(float(Width) / size.x, float(Height) / size.y);
	deck standardDeck;
	standardDeck.shuffle();
	piles = standardDeck.getPiles();
	undoButton.setSize(sf::Vector2f(50, 40));
	undoButton.setPosition(Width / 9 - 100, Height / 7 - 60);
	undoButtonText.setFont(font);
	undoButtonText.setString("  U");
	undoButtonText.setCharacterSize(30); 
	undoButtonText.setFillColor(sf::Color::Black);
	undoButtonText.setPosition(Width / 9 - 104, Height / 7 - 60);

	redoButton.setSize(sf::Vector2f(50, 40));
	redoButton.setPosition(Width / 9 - 100, Height / 7 + 10);
	redoButtonText.setFont(font);
	redoButtonText.setString("  R");
	redoButtonText.setCharacterSize(30);
	redoButtonText.setFillColor(sf::Color::Black);
	redoButtonText.setPosition(Width / 9 - 104, Height / 7 + 10);
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

	if (!font.loadFromFile("Pack In.ttf")) {
		throw "font cant be loaded";
		// Handle font loading error
	}
	for (int i = card::Ace; i <= card::King; i++) {
		for (int j = card::Spades; j <= card::Clubs; j++)
			textures[i][j] = loadTexture(getTexturePath(card(card::cardRank(i), card::cardSuit(j))));
		faceDown = loadTexture("textures\\backside.png");
	}
}
void game::onMouseDown(const sf::Vector2i& mousePos,int c) {
	if (undoButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		if (c == 0)
			return;
		else {
			undo();
			isUndoMode = true;
		}
	}
	else {
		unsigned int i;
		for (i = 0; i < piles.size() && (sPile = piles[i]->splitPile(mousePos)) == nullptr; i++);
		if (i < piles.size()) {
			mouseOffset = mousePos - sPile->getOffset();
		}
	}
}

void game::onMouseUp() {
	if (isUndoMode) {
		isUndoMode = false;
	}
	else {
		if (sPile) {
			sPile->onMouseUp(piles);
			delete sPile;
			sPile = nullptr;
		}
	}
}

void game::onMouseMove(const sf::Vector2i& mousePos) {
	if (sPile) {
		sPile->setPosition(mousePos - mouseOffset);
	}
}
void game::undo() {
	
}



void game::draw(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(undoButton);
	window.draw(undoButtonText);
	window.draw(redoButton);
	window.draw(redoButtonText);
	

	for (unsigned int i = 0; i < piles.size(); i++)
		piles[i]->draw(window);
	if (sPile)
		sPile->draw(window);
}

game::~game() {
}
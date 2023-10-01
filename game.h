#pragma once
#include <SFML/Graphics.hpp>
#include "dimensions.h"
#include "images.h"
#include "deck.h"
#include "card.h"
#include "stickyPile.h"
class game {
public:
	game();
	static sf::Texture textures[card::King + 1][card::Clubs + 1];
	static sf::Texture faceDown;
	void draw(sf::RenderWindow&);
	void onMouseDown(const sf::Vector2i&);
	void onMouseUp();
	bool isWin();
	bool isLose();
	static void loadTextures();
	static sf::Texture* getTexture(const pileCard&);
	void onMouseMove(const sf::Vector2i&);
	~game();
private:
	sf::Texture backgroundTexture;
	sf::Sprite background;
	vector<pile*> piles;
	sf::Vector2i mouseOffset;
	stickyPile* sPile;
	void resetPiles();
	static std::string getTexturePath(const card&);
};
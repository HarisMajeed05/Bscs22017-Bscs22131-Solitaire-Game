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
	game(const game& other);
	static sf::Texture textures[card::King + 1][card::Clubs + 1];
	static sf::Texture faceDown;
	void draw(sf::RenderWindow&);
	void onMouseDown(const sf::Vector2i&,int c);
	void onMouseUp();
	bool isWin();
	bool isLose();
	void undo();
	static void loadTextures();
	static sf::Texture* getTexture(const pileCard&);
	void onMouseMove(const sf::Vector2i&);
	bool isUndoButtonPressed(const sf::Vector2i& mousePos);
	~game();
private:
	sf::Texture backgroundTexture;
	sf::Sprite background;
	vector<pile*> piles;
	sf::Vector2i mouseOffset;
	stickyPile* sPile;
	sf::RectangleShape undoButton;
	sf::RectangleShape redoButton;
	sf::Text undoButtonText;
	sf::Text redoButtonText;
	bool isUndoMode = false;
	void resetPiles();
	static std::string getTexturePath(const card&);
};
#include <iostream>
#include<time.h>
#include <SFML/Graphics.hpp>
#include "dimensions.h"
#include "game.h"
using namespace std;
int main() {
	srand(time(0));
	sf::RenderWindow window;
	window.create(sf::VideoMode(Width, Height), "Bscs 22017 && Bscs 22131", sf::Style::Default);
	window.setPosition(sf::Vector2i(50, 50));
	game::loadTextures();
	game s;
	bool win = s.isWin(), lose = s.isLose();
	while (window.isOpen() && !win && !lose) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				s.onMouseDown(sf::Mouse::getPosition(window));
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				s.onMouseUp();
				win = s.isWin();
				lose = s.isLose();
			}
			else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				s.onMouseMove(sf::Mouse::getPosition(window));
		}
		window.clear(sf::Color::White);
		s.draw(window);
		window.display();
	}
	return 0;
}
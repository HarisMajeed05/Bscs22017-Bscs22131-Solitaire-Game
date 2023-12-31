#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "dimensions.h"
#include "game.h"
using namespace std;

int main() {
    srand(time(0));
    sf::RenderWindow window;
    sf::Music music;
    window.create(sf::VideoMode(Width, Height), "Bscs 22017 && Bscs 22131", sf::Style::Default);
    window.setPosition(sf::Vector2i(50, 50));
    game::loadTextures();

    if (!music.openFromFile("music.ogg")) {
        cerr << "Error loading music file" << endl;
        return 1;
    }

    game s;
    music.play();

    bool win = s.isWin(), lose = s.isLose();
    int count = 0;
    bool isUndoPressed = false;

    while (window.isOpen() && !win && !lose) {
        sf::Event event;

        while (window.pollEvent(event)) {
            //game prevState(s);
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                s.onMouseDown(sf::Mouse::getPosition(window), count);
           //     isUndoPressed = s.isUndoButtonPressed(sf::Mouse::getPosition(window));
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                s.onMouseUp();
                //if (!isUndoPressed) {
                    win = s.isWin();
                    lose = s.isLose();
                //}
               // else {
                 //   s = prevState;
               // }
               // isUndoPressed = false;
            }
            else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                s.onMouseMove(sf::Mouse::getPosition(window));
            
        }

        window.clear(sf::Color::White);
        s.draw(window);
        window.display();
        count++;
    }

    music.stop();
    return 0;
}

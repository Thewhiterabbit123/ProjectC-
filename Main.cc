#include "Game.h"
 #include <sstream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

int main () {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "RACE!");
	window.setFramerateLimit(70);
	Game* game = new Game(&window);

    sf::Clock clock;
    clock.restart();

	while (window.isOpen()) {

        sf::Event Event;
        sf::Time elapsed1 = clock.getElapsedTime();

        while (window.pollEvent(Event)) {

            if (Event.type == sf::Event::Closed) {
                window.close();
            }

        }
        //?????????????????????не могу достать машинкку, она дампится. поэтому я ее просто пока создала

        sf::Font font;
        font.loadFromFile("./CyrilicOld.ttf");
        sf::Text text;
        text.setFont(font);
        
        text.setCharacterSize(24);
        text.setColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);

        std::ostringstream playerTime;  
        playerTime << elapsed1.asSeconds();  
        text.setString("Time:" + playerTime.str());
        text.setPosition(165, 200);
        window.draw(text);
        game->getWorld()->Step(1/60.f, 8, 3);
        game->step();
        window.display();
        window.clear(sf::Color::White);
    }

}
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main () {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "RACE!");
	window.setFramerateLimit(70);
	Game* game = new Game(&window);
	while (window.isOpen()) {

        sf::Event Event;

        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                window.close();
            }
        }
    
        game->step();
        window.display();
        window.clear(sf::Color::White);
    }

}
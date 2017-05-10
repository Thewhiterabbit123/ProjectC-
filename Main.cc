#include "Game.h"
#include "Globals.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include "screen_manager.h"

int main () {
	sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "RACE!");
	window.setFramerateLimit(60);
	Game* game = new Game(&window);

	while (window.isOpen()) {

        sf::Event Event;
     

        while (window.pollEvent(Event)) {

            if (Event.type == sf::Event::Closed) {
                window.close();
            }

        }
        game->getWorld()->Step(1/60.f, 8, 3);
        game->step();
        window.display();
        window.clear(sf::Color::White);
    }

}
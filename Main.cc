#include "Game.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main () {
	RenderWindow window(sf::VideoMode(1366, 768), "RACE!");
	window.setFramerateLimit(70);
	Game* game = new Game();
	Draw* draw = new Draw();
	while (window.isOpen()) {

        sf::Event Event;

        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                window.close();
            }
        }
    
        game->Step();
        draw->Step();

    }

}
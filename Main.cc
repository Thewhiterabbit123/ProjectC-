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



            if (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Left) {
                game->Keyboard('A');
                std::cout<<"A";
            }

            if (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Right)  {
                game->Keyboard('D');
                std::cout<<"D";
            }

            if (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Up)  { 
                game->Keyboard('W'); 
                std::cout<<"W";
            }

            if (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Down)  { 
                game->Keyboard('S');
                std::cout<<"s";
            }
        }
        Player* player = game->getPlayer();
        Car* Car = player.getCar();


        game->getWorld()->Step(1/60.f, 8, 3);
        game->step();
        window.display();
        window.clear(sf::Color::White);
    }

}
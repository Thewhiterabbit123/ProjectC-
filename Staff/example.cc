#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("sound.ogg"))
		return -1;

	sf::Sound sound;
	sound.setBuffer(buffer);
	sf::RenderWindow window(sf::VideoMode(1366, 768), "RACE!");
	window.setFramerateLimit(20);
	while (window.isOpen()) {

        sf::Event Event;
		while (window.pollEvent(Event)) {

	        if (Event.type == sf::Event::Closed) {
	            window.close();
	        }

		sound.play();

	    }


    }
}
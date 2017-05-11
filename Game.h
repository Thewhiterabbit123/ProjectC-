#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <Box2D/Box2D.h>
#include <SFML/Audio.hpp>

class MyContactListener: public b2ContactListener {
public:
    void handleContact(b2Contact* contact, bool began);
    void car_vs_groundArea(b2Fixture* carFixture, b2Fixture* groundFixture, bool began);
    void BeginContact (b2Contact* contact) { handleContact(contact, true); }
    void EndContact (b2Contact* contact) { handleContact(contact, false); }
};

class Game {
  	private:
  		b2Body*  m_groundBody;
	  	b2World* m_world;
        Player   player;
        MyContactListener* m_contactListener;


	    sf::RenderWindow* m_window;
	    sf::Texture       m_tBackGround;
	    sf::Sprite        m_sBackGround;
        sf::SoundBuffer   buffer;
        sf::Sound         sound;
     	sf::Music         music;
        sf::Clock         clock;
        sf::Font          font;
      	sf::Text          text;

     	void setWall(float x, float y, float w, float h, bool sensor, int number = -1);
	    void setWalls();
     	void keyPressed();
      	void checkBorders(float x, float y);

      	int  m_controlState;

  	public:
    	Game(sf::RenderWindow* window);
    	void step();
    	b2World* getWorld();
    	Player getPlayer();

};

#endif
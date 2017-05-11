#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <Box2D/Box2D.h>
#include <SFML/Audio.hpp>

class FooDraw : public b2Draw {
    public:
      FooDraw();
      virtual ~FooDraw();
      void setWindow(sf::RenderWindow *window);
      void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
      void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
      void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color){}
      void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color){}
      void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {}
      void DrawTransform(const b2Transform& xf){}
      void DrawAABB(b2AABB* aabb, const b2Color& color){}
      sf::Color B2SFColor(const b2Color &color, int alpha = 255);


    private:
      sf::RenderWindow *window;
};


class Game {
  	private:
  		b2Body*  m_groundBody;
	  	b2World* m_world;
        FooDraw  m_debugDraw;
        Player   player;


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
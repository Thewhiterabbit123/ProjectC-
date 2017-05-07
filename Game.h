#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <Box2D/Box2D.h>

class Game {
  	private:
  		b2Body*  m_groundBody;
	  	b2World* m_world;
    	Player player(m_world);

  	public:
    	Game();
    	~Game();
    	void Step();
    	World  getWorld();
    	Player getPlayer();
};

#endif
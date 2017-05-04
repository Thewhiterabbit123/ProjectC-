#ifndef GAME_H
#define GAME_H

#include "World.h"
#include "Player.h"

class Game {
  private:
  	World world;
    Player player;

  public:
    Game();
    ~Game();
    Step();
};

#endif
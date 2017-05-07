#include "Game.h"

Game::Game() {
	player.setCar(m_world);
}

b2World* Game::getWorld() {
	return m_world;
}

Player Game::getPlayer() {
	return player; 
}

void Game::Step() {
	
}
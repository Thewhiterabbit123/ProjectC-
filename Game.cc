#include "Game.h"

Game::Game() {
	m_world = new b2World(b2Vec2(0,0));
	b2BodyDef bodyDef;
	m_groundBody = m_world->CreateBody( &bodyDef );

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
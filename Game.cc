#include "Game.h"
#include <iostream>

void Game::setWalls() {
	b2BodyDef bodyDef;
	bodyDef.position.Set(0.0f, 0.0f);
	m_groundBody = m_world->CreateBody( &bodyDef );

	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;
  	fixtureDef.shape = &polygonShape;
   	fixtureDef.isSensor = false;


	polygonShape.SetAsBox( 5.0f/RATIO, 150.0f/RATIO, b2Vec2(130.0f/RATIO,400.0f/RATIO), 0 );
	m_groundBody->CreateFixture(&fixtureDef);


}

Game::Game(sf::RenderWindow* window): m_window(window) {
	m_world = new b2World(b2Vec2(0,0));
	player.setCar(m_world);
	
	m_tBackGround.loadFromFile("./Images/background.png");
	m_tBackGround.setSmooth(true);
	m_sBackGround.setTexture(m_tBackGround);
	m_sBackGround.scale(0.5,0.5);
	

	setWalls();
}

b2World* Game::getWorld() {
	return m_world;
}

Player Game::getPlayer() {
	return player; 
}

void Game::step() {
	//m_window->draw(m_sBackGround);
	Car* _m_sCar = player.getCar();
	sf::Sprite m_sCar = _m_sCar->getSprite();
	m_sCar.setPosition(100,100);
	m_window->draw(m_sCar);
	std::vector<Tire*> tires = _m_sCar->getTires();
	for(int i = 0; i < tires.size(); i++) {
		sf::Sprite m_sTire = tires[i]->getSprite();
		m_window->draw(m_sTire);
	}


}
#include "Player.h"

Player::Player() {
	m_car = new Car(Game::world->getb2World);
}

Player::~Player() {
	delete m_car;
}
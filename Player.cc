#include "Player.h"
#include "Game.h"

void Player::setCar(b2World* m_world) {
	m_car = new Car(m_world);
}

Player::~Player() {
	delete m_car;
}
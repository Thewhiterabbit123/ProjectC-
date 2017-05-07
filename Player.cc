#include "Player.h"
#include "Game.h"

Player::Player(b2World* m_world) {
	m_car = new Car(m_world);
}

Player::~Player() {
	delete m_car;
}
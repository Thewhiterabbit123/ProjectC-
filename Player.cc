#include "Player.h"
#include "Game.h"

void Player::setCar(b2World* m_world) {
	m_car = new Car(m_world);
}

Player::~Player() {
	delete m_car;
}

Car* Player::getCar() {
	return m_car;
}


/*Square::Square(b2World* m_world) {
	b2bodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	m_body = m_world->CreateBody(&bodyDef);


*/
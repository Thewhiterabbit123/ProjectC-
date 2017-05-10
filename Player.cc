#include "Player.h"
#include "Game.h"
#include <fstream>

void Player::getScore() {
	std::ifstream file;
	file.open("./results/result.txt");
	if(!file.is_open()) {
		//проверить
	}
	float score = 0;
	while(file >> score) {
		m_score.push_back(score);
	}
	if(!m_score.empty()) {
		m_best_score = *std::max_element(m_score.begin(), m_score.end());
	} else {
		m_best_score = 0;
	}
	file.close();
}

float Player::getBestScore() {
	return m_best_score;
}

void Player::setScore() {

}



void Player::setCar(b2World* m_world) {
	m_car = new Car(m_world);
	getScore();
}

Player::~Player() {
	delete m_car;
}

Car* Player::getCar() {
	return m_car;
}



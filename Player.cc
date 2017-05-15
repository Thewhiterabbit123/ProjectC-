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

int Player::getRound() {
	return round;
}

float Player::getBestScore() {
	return m_best_score;
}

void Player::pushBack(float score) {
	m_score[0] = score;
}

void Player::setScore() {
	std::ofstream file;
	file.open("./results/result.txt");
	if(!file.is_open()) { 
		//проверить
	}
	int sum = 0;
	for (int i = 0; i < ROUND_NUMBER; i++) {
		sum += m_score[i];
	}
	file << sum;
	file.close();
}

void Player::playerUpdate() {
	Car* car = getCar();
	if (car->getRound() == true) {
		this->round++;
	}
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



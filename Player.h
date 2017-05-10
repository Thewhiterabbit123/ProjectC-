#ifndef PLAYER_H
#define PLAYER_H

#include "Car.h"
#include <vector>
#include <Box2D/Box2D.h>


class Player {
	private:
		Car* m_car;
		std::vector<float> m_score;
		float m_best_score;
	public:
		void getScore();
		void setScore();
		void setCar(b2World* m_world);
		float getBestScore();
		Car* getCar();
		~Player();
};

#endif
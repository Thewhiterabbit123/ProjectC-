#ifndef PLAYER_H
#define PLAYER_H

#include "Car.h"
#include <vector>


class Player {
	private:
		Car* m_car;
		std::vector<int> m_score;
	public:
		void setCar(b2World* m_world);
		~Player();
	
};

#endif
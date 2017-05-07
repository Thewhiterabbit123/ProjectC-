#ifndef PLAYER_H
#define PLAYER_H

#include "Car.h"
#include <vector>
#include <Box2D/Box2D.h>


class Player {
	private:
		Car* m_car;
		std::vector<int> m_score;
	public:
		void setCar(b2World* m_world);
		Car* getCar();
		~Player();
	
};

/*class Square {
private:
	b2Body* m_body;
public:
	Square(b2World* m_world);
	void move();

};*/

#endif
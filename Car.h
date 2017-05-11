#ifndef CAR_H
#define CAR_H

#include "Tire.h"
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

class Car {
	private:
		int control_state;
		int checkpoint;
		bool round;

		b2Body* m_body;
        std::vector<Tire*> m_tires;
        b2RevoluteJoint *flJoint, *frJoint;

        sf::Texture m_tCar;
        sf::Sprite  m_sCar;
        
	public:
		Car(b2World* world);
		~Car();
		b2Body* getBody();
		
		void setCheckpoint(int n) {
			checkpoint = n;
		}

		void setRound(bool round) {
			this->round = round;
		}

		int getCheckpoint() {
			return checkpoint;
		}

		int getRound() {
			return round;
		}
		
		void update(int controlState);
		std::vector<Tire*> getTires();
		sf::Sprite getSprite();
	
};

#endif
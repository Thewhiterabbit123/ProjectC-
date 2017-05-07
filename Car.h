#ifndef CAR_H
#define CAR_H

#include "Tire.h"
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Car {
	private:
		b2Body* m_body;
        std::vector<Tire*> m_tires;
        b2RevoluteJoint *flJoint, *frJoint;

        sf::Texture m_tCar;
        sf::Sprite  m_sCar;
	public:
		Car(b2World* world);
		b2Body* getBody();
		
		void update(int controlState);
		std::vector<Tire*> getTires();
		sf::Sprite getSprite();
	
};

#endif
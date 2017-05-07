#ifndef CAR_H
#define CAR_H

#include "Tire.h"
#include <vector>
#include <Box2D/Box2D.h>

class Car {
	private:
		b2Body* m_body;
        std::vector<Tire*> m_tires;
        b2RevoluteJoint *flJoint, *frJoint;
	public:
		Car();
		Car(b2World* world);
		~Car();

		void update(int controlState);
	
};

#endif
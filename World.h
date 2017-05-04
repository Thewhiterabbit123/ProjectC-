#ifndef WORLD_H
#define WORLD_H

class World {
private:
	b2Body* m_groundBody;
  	b2World* m_world;
public:
	World();
	~World();
	b2World* getb2World() {
		return m_world;
	}
}


#endif
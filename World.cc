#include "World.h"

World::World() {
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	m_world = new b2World(gravity);
	b2bodyDef bodyDef;
	m_ground = m_world->CreateBody(&bodyDef);
}

World::~World() {
	m_world->DestroyBody(m_groundBody);
	delete m_world;
	m_world = NULL;
}
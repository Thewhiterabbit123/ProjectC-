#include "Car.h"

Car::Car(b2World* world) {
	//create car body
    b2BodyDef bodyDef;
    bodyDef.position.Set(XPOS/RATIO, YPOS/RATIO);
    bodyDef.type = b2_dynamicBody;
    m_body = world->CreateBody(&bodyDef);
    m_body->SetAngularDamping(3);

    //SFML()
    m_tCar.loadFromFile("./Images/car2.png");
    m_tCar.setSmooth(true);
    m_sCar.setTexture(m_tCar);
    m_sCar.scale(1,1);

    b2PolygonShape polygonShape;
    //polygonShape.Set( vertices, 4);
    polygonShape.SetAsBox(CAR_WIDTH/2/RATIO, CAR_HEIGHT/2/RATIO);
    b2Fixture* fixture = m_body->CreateFixture(&polygonShape, 0.1f);//shape, density

    //prepare common joint parameters
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = m_body;
    jointDef.enableLimit = true;
    jointDef.lowerAngle = 0;
    jointDef.upperAngle = 0;
    jointDef.localAnchorB.SetZero();//center of tire

    float maxForwardSpeed = 250*CAR_WIDTH/RATIO;
    float maxBackwardSpeed = -40*CAR_WIDTH/RATIO;
    float backTireMaxDriveForce = 300*CAR_WIDTH/RATIO;
    float frontTireMaxDriveForce = 400*CAR_WIDTH/RATIO;
    float backTireMaxLateralImpulse = 7.5*CAR_WIDTH/RATIO;
    float frontTireMaxLateralImpulse = 7.5*CAR_WIDTH/RATIO;

    //back left tire
    Tire* tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, backTireMaxDriveForce, backTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    b2Vec2 vec= m_body->GetLocalCenter();
    jointDef.localAnchorA.Set(vec.x - CAR_WIDTH/RATIO, vec.y);
    world->CreateJoint( &jointDef );
    m_tires.push_back(tire);

    //back right tire
    /*tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, backTireMaxDriveForce, backTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    jointDef.localAnchorA.Set( -0.75f/RATIO, 3/RATIO );
    world->CreateJoint( &jointDef );
    m_tires.push_back(tire);

    //front left tire
    tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, frontTireMaxDriveForce, frontTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    jointDef.localAnchorA.Set( -8.5f/RATIO, -3/RATIO );
    flJoint = (b2RevoluteJoint*)world->CreateJoint( &jointDef );
    m_tires.push_back(tire);

    //front right tire
    tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, frontTireMaxDriveForce, frontTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    jointDef.localAnchorA.Set( -8.5f/RATIO, 3/RATIO);
    frJoint = (b2RevoluteJoint*)world->CreateJoint( &jointDef );
    m_tires.push_back(tire);*/
}


sf::Sprite Car::getSprite() {
	return m_sCar;
}

std::vector<Tire*> Car::getTires() {
	return m_tires;
}

b2Body* Car::getBody() {
    return m_body;
}
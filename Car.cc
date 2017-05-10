#include "Car.h"

Car::Car(b2World* world) {
	//create car body
    b2BodyDef bodyDef;
    bodyDef.position.Set(XPOS/RATIO, YPOS/RATIO);
    bodyDef.type = b2_dynamicBody;
    m_body = world->CreateBody(&bodyDef);
    m_body->SetAngularDamping(3);

    //SFML()
    m_tCar.loadFromFile("./Staff/car2.png");
    m_tCar.setSmooth(true);
    m_sCar.setTexture(m_tCar);
    m_sCar.scale(1,1);

    b2PolygonShape polygonShape;
    //polygonShape.Set( vertices, 4);
    polygonShape.SetAsBox(CAR_WIDTH/2/RATIO, CAR_HEIGHT/2/RATIO);//, b2Vec2(0, -CAR_HEIGHT/2/RATIO), 0);
    b2Fixture* fixture = m_body->CreateFixture(&polygonShape, 0.1f);//shape, density

    //prepare common joint parameters
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = m_body;
    jointDef.enableLimit = true;
    jointDef.lowerAngle = 0;
    jointDef.upperAngle = 0;
    jointDef.localAnchorB.SetZero();//center of tire

    float maxForwardSpeed = 5;
    float maxBackwardSpeed = -2.2;
    float backTireMaxDriveForce = 5;
    float frontTireMaxDriveForce = 5;
    float backTireMaxLateralImpulse = 0.2;
    float frontTireMaxLateralImpulse = 0.2;

    //back left tire
    Tire* tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, backTireMaxDriveForce, backTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    b2Vec2 vec= m_body->GetPosition();
    std::cout << vec.x*30 << " " << vec.y*30 << std::endl;
    jointDef.localAnchorA.Set( -CAR_WIDTH/2/RATIO-TIRE_WIDTH/2/RATIO-INTERVAL/RATIO, CAR_HEIGHT/4/RATIO+INTERVAL/RATIO );
    world->CreateJoint( &jointDef );
    m_tires.push_back(tire);

    //back right tire
    tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, backTireMaxDriveForce, backTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    jointDef.localAnchorA.Set( CAR_WIDTH/2/RATIO-TIRE_WIDTH/2/RATIO+(INTERVAL+6)/RATIO, CAR_HEIGHT/4/RATIO+INTERVAL/RATIO );
    world->CreateJoint( &jointDef );
    m_tires.push_back(tire);

    //front left tire
    tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, frontTireMaxDriveForce, frontTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    jointDef.localAnchorA.Set( -CAR_WIDTH/2/RATIO-TIRE_WIDTH/2/RATIO-INTERVAL/RATIO, -CAR_HEIGHT/4/RATIO-INTERVAL/RATIO );
    flJoint = (b2RevoluteJoint*)world->CreateJoint( &jointDef );
    m_tires.push_back(tire);

    //front right tire
    tire = new Tire(world);
    tire->setCharacteristics(maxForwardSpeed, maxBackwardSpeed, frontTireMaxDriveForce, frontTireMaxLateralImpulse);
    jointDef.bodyB = tire->getBody();
    jointDef.localAnchorA.Set( CAR_WIDTH/2/RATIO-TIRE_WIDTH/2/RATIO+(INTERVAL+6)/RATIO, -CAR_HEIGHT/4/RATIO-INTERVAL/RATIO );
    frJoint = (b2RevoluteJoint*)world->CreateJoint( &jointDef );
    m_tires.push_back(tire);
}

Car::~Car() {
    for (int i = 0; i < m_tires.size(); i++)
        delete m_tires[i];
}

void Car::update(int controlState) {
    for (int i = 0; i < m_tires.size(); i++)
        m_tires[i]->updateFriction();
    for (int i = 0; i < m_tires.size(); i++)
        m_tires[i]->updateDrive(controlState);

    //control steering
    float lockAngle = 35 * DEGTORAD;
    float turnSpeedPerSec = 160 * DEGTORAD;//from lock to lock in 0.5 sec
    float turnPerTimeStep = turnSpeedPerSec / 60.0f;
    float desiredAngle = 0;
    switch ( controlState & (LEFT | RIGHT) ) {
        case LEFT:  desiredAngle = lockAngle;  break;
        case RIGHT: desiredAngle = -lockAngle; break;
        default: ;//nothing
    }
    float angleNow = flJoint->GetJointAngle();
    float angleToTurn = desiredAngle - angleNow;
    angleToTurn = b2Clamp( angleToTurn, -turnPerTimeStep, turnPerTimeStep );
    float newAngle = angleNow + angleToTurn;
    flJoint->SetLimits( newAngle, newAngle );
    frJoint->SetLimits( newAngle, newAngle );
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
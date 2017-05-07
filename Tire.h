#ifndef TIRE_H
#define TIRE_H

#include "Globals.h"
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>


class Tire {
    public:

        float m_maxForwardSpeed;
        float m_maxBackwardSpeed;
        float m_maxDriveForce;
        float m_maxLateralImpulse;
        float m_currentTraction;

        Tire(b2World* world);
        ~Tire();

        void setCharacteristics(float maxForwardSpeed, 
                                float maxBackwardSpeed, 
                                float maxDriveForce, 
                                float maxLateralImpulse);

       
        
        void updateDrive(int controlState);
        void updateTurn(int controlState) ;
        void updateFriction();

        b2Vec2 getForwardVelocity();
        b2Vec2 getLateralVelocity();

        sf::Sprite getSprite();
        b2Body* getBody();
    private: 
        b2Body* m_body;
    	sf::Texture m_tTire;
        sf::Sprite  m_sTire;
};

#endif
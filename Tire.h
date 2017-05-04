#ifndef TIRE_H
#define TIRE_H

#include "Globals.h"

enum {
    LEFT     = 0x1,
    RIGHT    = 0x2,
    UP       = 0x4,
    DOWN     = 0x8
};

class Tire {
    public:
        b2Body* m_body;
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

        b2Vec2 getForwardVelocity();
        b2Vec2 getLateralVelocity();
};

#endif
#ifndef GLOBALS_H
#define GLOBALS_H

// 1 meter (box2d) is more or less 64 pixels (sfml)
#define RATIO 30.0f
#define PIXELS_PER_METER RATIO

// 64 pixels (sfml) are more or less 1 meter (box2d)
#define UNRATIO (1.0f/RATIO)
#define METERS_PER_PIXEL UNRATIO

//formula to convert radians to degrees = (radians * (pi/180))
#define RADTODEG 57.295779513082320876f
#define DEGTORAD 0.0174532925199432957f

#define CAR_WIDTH 23
#define CAR_HEIGHT 39

#define TIRE_WIDTH 7
#define TIRE_HEIGHT 20

#define INTERVAL 2

#define XPOS 100
#define YPOS 100


enum {
    LEFT     = 0x1,
    RIGHT    = 0x2,
    UP       = 0x4,
    DOWN     = 0x8
};

enum fixtureUserDataType {
    FUD_CAR_TIRE,
    FUD_GROUND_AREA
};

class FixtureUserData {
        fixtureUserDataType m_type;
    protected:
        FixtureUserData(fixtureUserDataType type) : m_type(type) {}
    public:
        virtual fixtureUserDataType getType() { return m_type; }
        virtual ~FixtureUserData() {}
};

class CarTireFUD : public FixtureUserData {
    public:
        CarTireFUD() : FixtureUserData(FUD_CAR_TIRE) {}
};


class GroundAreaFUD : public FixtureUserData {
    public:
        float frictionModifier;
        bool outOfCourse;
        int number;

        GroundAreaFUD(float fm, bool ooc, int number) : FixtureUserData(FUD_GROUND_AREA), number(number) {
            frictionModifier = fm;
            outOfCourse = ooc;
        }
};

#endif
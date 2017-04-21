#ifndef CAR_HPP
#define CAR_HPP

class Car {
    private:
        float x, y;
        float speed;
        float angle;

    public:
        Car () speed(2), angle(0);
        virtual ~Car ();
        virtual void move();
        void findTarget();
};

class ComputerCar: public Car {
    public:

};
#endif

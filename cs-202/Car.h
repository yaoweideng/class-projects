#ifndef Car_h
#define Car_h
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle{
    public:
        Car();
        Car(float *lla);
        Car(const Car &car);
        virtual ~Car();
        Car &operator=(const Car &other);
        void setThrottle(int throttle);
        int getThrottle();
        void drive(int throttle);
        void Move(const float *lla);
    private:
        int m_throttle;
        void serialize(ostream &os);
};

#endif
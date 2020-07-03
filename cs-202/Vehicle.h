#ifndef Vehicle_h
#define Vehicle_h
#include <iostream>
using namespace std;

class Vehicle {
    public:
        Vehicle();
        Vehicle(float *lla);
        Vehicle(const Vehicle &vhs);
        virtual ~Vehicle();
        Vehicle &operator=(const Vehicle &other);
        void SetLLA(const float *lla);
        float *getLLA();
        virtual void Move(const float *lla) = 0;
        friend ostream &operator<<(ostream &os, const Vehicle &vhc);
    protected:
        float m_lla[3];
    private:
        virtual void serialize(ostream &os) const;
};

#endif
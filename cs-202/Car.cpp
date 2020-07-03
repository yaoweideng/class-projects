#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(){
    m_throttle = 0;
    cout << "Car: Default-ctor" << endl;
}

Car::Car(float *lla):
Vehicle(lla)
{
    m_throttle = 0;
    cout << "Car: Parametrized-ctor" << endl;
}

Car::Car(const Car &car){
    m_lla[0] = car.m_lla[0];
    m_lla[1] = car.m_lla[1];
    m_lla[2] = car.m_lla[2];
    cout << "Car: Copy-ctor" << endl;
}

Car::~Car(){
    cout << "Car: Dtor" << endl;
}

Car &Car::operator=(const Car &other){
    Vehicle::operator=(other);
    if (this != &other){
        m_throttle = other.m_throttle;
        cout << "Car: Assignment" << endl;
    }
    return *this;
}

void Car::setThrottle(int throttle){
    m_throttle = throttle;
}

int Car::getThrottle(){
    return m_throttle;
}

void Car::drive(int throttle){
    m_throttle = throttle;
}

void Car::Move(const float *lla){
    drive(75);
    const float *ptr_lla = lla;
    for (int i = 0; i < 3; i++){
        m_lla[i] = *lla;
        ptr_lla++;
    }
    cout << "Car: DRIVE to destination, with throttle @ 75" << endl;
}
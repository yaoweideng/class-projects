#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(){
    cout << "Vehicle: Default-ctor" << endl;
}

Vehicle::Vehicle(float *lla){
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
    cout << "Vehicle: Parametrized-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle &vhs){
    m_lla[0] = vhs.m_lla[0];
    m_lla[1] = vhs.m_lla[1];
    m_lla[2] = vhs.m_lla[2];
    cout << "Vehicle: Copy-ctor" << endl;
}

Vehicle::~Vehicle(){
    cout << "Vehicle: Dtor" << endl;
}

Vehicle &Vehicle::operator=(const Vehicle &other){
    if (this != &other){
        cout << "Vehicle: Assignment" << endl;
        for (int i = 0; i < 3; i++){
            m_lla[i] = other.m_lla[i];
        }
    }
    return *this;
}

void Vehicle::SetLLA(const float *lla){
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
}

float *Vehicle::getLLA(){
    return m_lla;
}

void Vehicle::serialize(ostream &os) const{
    os << "Vehicle @ [";
    os << m_lla[0] << ", ";
    os << m_lla[1] << ", ";
    os << m_lla[2] << "]";
}

void Move(const float *lla){
}

ostream &operator<<(ostream &os, const Vehicle &vhc){
    vhc.serialize(os);

    return os;
}
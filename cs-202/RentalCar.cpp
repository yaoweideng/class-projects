#include <iostream>
#include "RentalCar.h"

using namespace std;

RentalCar::RentalCar(){
    RentalCar::setYear(0000);
    RentalCar::setMake("X");
    RentalCar::setModel("X");
    RentalCar::setPrice(0.00);
    RentalCar::setAvailable(0);
}

RentalCar::RentalCar(int y, char *mk, char *md, float p, bool a){
    RentalCar::setYear(y);
    RentalCar::setMake(mk);
    RentalCar::setModel(md);
    RentalCar::setPrice(p);
    RentalCar::setAvailable(a);
}

void RentalCar::setYear(int y) {
    m_year = y;
}

void RentalCar::setMake(char *mk) {
    myStringCopy(m_make, mk);
}

void RentalCar::setModel(char *md) {
    myStringCopy(m_model, md);
}

void RentalCar::setPrice(float p) {
    m_price = p;
}

void RentalCar::setAvailable(bool a) {
    m_available = a;
}

const int RentalCar::getYear() const{
    return m_year;
}

const char *RentalCar::getMake() const{
    return m_make;
}

const char *RentalCar::getModel() const{
    return m_model;
}

const float RentalCar::getPrice() const{
    return m_price;
}

const bool RentalCar::getAvailable() const{
    return m_available;
}

void RentalCar::printCar() {
    cout << getYear() << " ";
    cout << getMake() << " ";
    cout << getModel() << ", ";
    cout << "$" << getPrice() << " per day, ";
    cout << "Available: " << boolalpha << getAvailable();
    cout << endl;
}

float RentalCar::carEstimate(int days) {
    float totalCost;
    totalCost = getPrice() * days;
    return totalCost;
}
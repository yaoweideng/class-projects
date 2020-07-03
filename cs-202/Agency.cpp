#include <iostream>
#include <fstream>
#include "Agency.h"

using namespace std;

const int maxnum = 100;

bool checkABC(char a);

Agency::Agency(){
}

char *Agency::getName(){
    return m_name;
}
int Agency::getZipCode(){
    return m_zipcode;
}
void Agency::setName(char *n){
    StringCopy(m_name, n);
}
void Agency::setZipCode(int zc){
    m_zipcode = zc;
}

Car &Agency::operator[](const int index){
    Car *ptr_car = m_inventory;
    for (int i = 0; i < index; i++, ptr_car++){
    }
    return *ptr_car;
}

void Agency::readAllData(ifstream &inputFile){
    Car *ptr_car = m_inventory;
    char tempMake[maxnum];
    char tempModel[maxnum];
    int tempYear;
    float tempBasePrice;
    float tempFinalPrice;
    bool tempAvailable;
    char tempOwner[maxnum];
    Sensor tempSensor[3];
    char tempType[maxnum];
    char temp;
    Sensor *ptr_sensor = ptr_car->getSensor();

    inputFile >> m_name;
    inputFile >> m_zipcode;
    for (int i = 0; i < 5; i++){
        inputFile >> tempYear;
        inputFile >> tempMake;
        inputFile >> tempModel;
        inputFile >> tempBasePrice;
        ptr_car->setYear(tempYear);
        ptr_car->setMake(tempMake);
        ptr_car->setModel(tempModel);
        ptr_car->setBasePrice(tempBasePrice);
        char *tempSensor;
        char sensorname[maxnum];
        Sensor *ptr_sensor = ptr_car->getSensor();

        do {
            inputFile.get(temp);} while (temp != '{');
        for (int j = 0; ; j++){
            inputFile >> sensorname;
            char *ptr_name = sensorname;
            while (checkABC(*ptr_name) == true){
                ptr_name++;
            }
            if (*ptr_name == '}'){
                *ptr_name = '\0';
                ptr_car->setSensorCount(j+1);
                ptr_sensor->setType(sensorname);
                break;
            }
            ptr_sensor->setType(sensorname); 
            ptr_sensor++;
        }
        ptr_car->updatePrice();
        inputFile >> tempAvailable;
        ptr_car->setAvailable(tempAvailable);
        inputFile.get();
        temp = inputFile.get();
        if (temp >= 'A' && temp <= 'z'){
            inputFile >> tempOwner;
            ptr_car->setOwner(tempOwner);
            //cout << tempOwner << endl;
            //cout << ptr_car->getOwner() << endl;
        }
    }
}

void Agency::printAllData(){
    Car *ptr_car = m_inventory;
    cout << getName() << " ";
    cout << getZipCode();
    cout << endl;
    for (int i = 0; i < 5; i++){
        ptr_car->printCar();
        ptr_car++;
    }
    cout << endl;
}

void Agency::printAvailableCars(){
    Car *ptr_car = m_inventory;
    for (int i = 0; i < 5; i++){
        if (ptr_car->getAvailable() == 1){
            ptr_car->printCar();
        }
        ptr_car++;
    }
}

bool checkABC(char a){
    if (a >= 'A' && a <= 'z'){
        return true;
    }
    else return false;
}
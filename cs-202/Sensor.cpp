#include <iostream>
#include "Sensor.h"

using namespace std;

char *StringCopy(char *destination, const char *source);
int StringCompare(const char *str1, const char *str2);
int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

Sensor::Sensor(){
}

Sensor::Sensor(char *t, float extracost, const int gps, const int camera, const int lidar, const int radar){
    StringCopy(m_type, t);
    m_extracost = extracost;
    gps_cnt = gps;
    camera_cnt = camera;
    lidar_cnt = lidar;
    radar_cnt = radar;
}

Sensor::Sensor(Sensor &sensor){
    setType(sensor.getType());
    m_extracost = sensor.getExtraCost();
}

char *Sensor::getType(){
    return m_type;
}
float Sensor::getExtraCost(){
    return m_extracost;
}
int Sensor::getGPS(){
    return gps_cnt;
}
int Sensor::getCamera(){
    return camera_cnt;
}
int Sensor::getLidar(){
    return lidar_cnt;
}
int Sensor::getRadar(){
    return radar_cnt;
}
void Sensor::setType(char *t){
    StringCopy(m_type, t);
}
void Sensor::setExtraCost(float ec){
    m_extracost = ec;
}
void Sensor::getReset (int &gps_cnt, int &camera_cnt, int &lidar_cnt, int &radar_cnt){
    gps_cnt = 0;
    camera_cnt = 0;
    lidar_cnt = 0;
    radar_cnt = 0;
}

bool operator==(Sensor &a, Sensor &b){
    if (StringCompare(a.getType(), b.getType()) == 0){
        if (a.getExtraCost() == b.getExtraCost()){
            if (a.getGPS() == b.getGPS()){
                if (a.getCamera() == b.getCamera()){
                    if (a.getLidar() == b.getLidar()){
                        if (a.getRadar() == b.getRadar()){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

char *StringCopy(char *destination, const char *source){
    while (*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return destination;
}

int StringCompare(const char *str1, const char *str2){
    while (*str1 == *str2){
        if (*str1 == '\0' || *str2 == '\0'){
            break;
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0'){
        return 0;
    }
    if (*str1 < *str2){
        return -1;
    }
    return 1;
}
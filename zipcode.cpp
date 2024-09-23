#include <iostream>

#include "zipcode.h"

using namespace std;

/*
enum class CompareType {
    LessZip,
    LessCityState,
    LessStateCity,
    LessLatLonState,
    LessLonLatState
};
*/
// Complete this method by implementing the comparison logic
bool ZipCode::compare(ZipCode &rhs, ZipCode::CompareType t) {
    return false;  
}

// Do not edit below this line

ZipCode::ZipCode(int zip, string city, string state, int lat, int lon) {
    this->zip = zip;
    this->city = city;
    this->state = state;
    this->lat = lat;
    this->lon = lon;
}

void ZipCode::print() {
    cout << zip << "\t" << city << "\t";
    if (city.length() < 8) cout << "\t";
    cout << state << "\t" << lat << "\t"<< lon;
}

int ZipCode::getZip() {
    return zip;
}

string ZipCode::getCity() {
    return city;
}

string ZipCode::getState() {
    return state;
}

int ZipCode::getLat() {
    return lat;
}

int ZipCode::getLon() {
    return lon;
}

#ifndef ZIPCODE_H
#define ZIPCODE_H

using namespace std;

class ZipCode {
private:
    int zip;
    int lat;
    int lon;
    string city;
    string state;
public:
    enum class CompareType {
        LessZip,
        LessCityState,
        LessStateCity,
        LessLatLonState,
        LessLonLatState
    };
    ZipCode(int zip, string city, string state, int lat, int lon);
    int getZip();
    string getCity();
    string getState();
    int getLat();
    int getLon();
    bool compare(ZipCode &rhs, ZipCode::CompareType t);
    void print();
};

#endif

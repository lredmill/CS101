#include <iostream>

#include "zipcode.h"

using namespace std;

void print(string s, ZipCode codes[], int len) {
    cout << s << endl;
    for (int i = 0; i < len; i++) {
        cout << "\t";
        codes[i].print();
        cout << endl;
    }
    cout << endl;
}

void bubbleSortInPlace(ZipCode codes[], int len, ZipCode::CompareType t) {
    for(int j = 1; j < len; j++) {
        bool madeChange = false;
        for (int i = 0; i < len - j; i++) {
            if (codes[i + 1].compare(codes[i], t)) {
                swap(codes[i], codes[i + 1]);
                madeChange = true;
            }
        }
        if (!madeChange) break;
    }
}

int main() {
    ZipCode codes[25] = {
        ZipCode(10001, "New York", "NY", 41, -74),
        ZipCode(90001, "Los Angeles", "CA", 34, -118),
        ZipCode(77001, "Houston", "TX", 30, -95),
        ZipCode(60601, "Chicago", "IL", 42, -88),
        ZipCode(78201, "San Antonio", "TX", 29, -98),
        ZipCode(94101, "San Francisco", "CA", 38, -122),
        ZipCode(19101, "Philadelphia", "PA", 40, -75),
        ZipCode(85001, "Phoenix", "AZ", 33, -112),
        ZipCode(95101, "San Jose", "CA", 37, -122),
        ZipCode(48201, "Detroit", "MI", 42, -83),
        ZipCode(43201, "Columbus", "OH", 40, -83),
        ZipCode(46201, "Indianapolis", "IN", 40, -86),
        ZipCode(02201, "Boston", "MA", 42, -71),
        ZipCode(75201, "Dallas", "TX", 33, -97),
        ZipCode(64101, "Kansas City", "MO", 39, -95),
        ZipCode(73301, "Austin", "TX", 30, -98),
        ZipCode(80201, "Denver", "CO", 40, -105),
        ZipCode(92101, "San Diego", "CA", 33, -117),
        ZipCode(73101, "Oklahoma City", "OK", 35, -97),
        ZipCode(55401, "Minneapolis", "MN", 45, -93),
        ZipCode(20001, "Washington", "DC", 39, -77),
        ZipCode(30301, "Atlanta", "GA", 34, -84),
        ZipCode(31901, "Columbus", "GA", 32, -85),
        ZipCode(66101, "Kansas City", "KS", 39, -95),
        ZipCode(35401, "Tuscaloosa", "AL", 33, -88)
    };
    int len = 25;

    print("Zip Codes (unsorted)", codes, len);

    // test your compare method here by changing the CompareType
    bubbleSortInPlace(codes, len, ZipCode::CompareType::LessZip);
    print("Zip Codes", codes, len);

    return 0;
}

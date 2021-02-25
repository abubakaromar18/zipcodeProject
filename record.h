#ifndef RECORD_H
#define RECORD_H

#include <string>

struct ZipCode { // This is a temp struct I was using to test my sort method -Duncan
    ZipCode();
    ZipCode(int zip, std::string stateID, int lat, int longi) : zipcode(zip), state(stateID), latitude(lat), longitude(longi){}

    // We can edit this to have the full data or replace it with a different one.
    int zipcode;
    std::string state;
    float latitude;
    float longitude;
};


#endif
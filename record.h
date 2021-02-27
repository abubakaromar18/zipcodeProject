/**
 * @author Duncan M.
 * 
*/

#ifndef RECORD_H
#define RECORD_H

#include <string>


/**
 * @brief ZipCode is a struct for storing the information of a single location
 * 
 * 
*/
struct ZipCode {
    
    /// @brief default constructor for an uninitialized ZipCode
    ZipCode();

    /// @brief constructor for ZipCode that initializes all values
    ZipCode(int zip, std::string place, std::string stateID, std::string countyName, int lat, int longi) : zipcode(zip), placeName(place), state(stateID), county(countyName), latitude(lat), longitude(longi){}

    /// zip code for the location
    int zipcode;
    /// place name (city?) for the location
    std::string placeName;
    /// state id for the location
    std::string state;
    /// county for the location
    std::string county;
    /// latitude for the location
    float latitude;
    /// longitude for the location
    float longitude;
};


#endif
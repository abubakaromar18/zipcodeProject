/**
 * @file record.h
 * @author Duncan M.
 * @brief Contains the ZipCode struct
*/

#pragma once
#include <string>

/**
 * @brief ZipCode is a struct for storing the information of a single location
 * @struct ZipCode 
*/
struct ZipCode {
    
    /// @brief default constructor for an uninitialized ZipCode
    ZipCode(){}

    /// @brief constructor for ZipCode that initializes all values
    /// @pre all parameters are initialized and have proper values stored
    /// @post a ZipCode struct will be initialized with all provided values.
    ZipCode(int zip, std::string place, std::string stateID, std::string countyName, int lat, int longi) : zipcode(zip), placeName(place), state(stateID), county(countyName), latitude(lat), longitude(longi){}

    /// @brief zip code for the location
    int zipcode;

    /// @brief place name (city?) for the location
    std::string placeName;

    /// @brief state id for the location
    std::string state;

    /// @brief county for the location
    std::string county;

    /// @brief latitude for the location
    float latitude;

    /// @brief longitude for the location
    float longitude;
};
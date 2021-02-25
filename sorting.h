#ifndef SORTING_H
/**
 * @file sorting.h
 * @author Duncan M.
 * @brief Contains the Sort class
*/



#define SORTING_H
#include <iostream>
#include <string>
#include "./record.h"


///@brief A class for sorting out the north, south, east, and west most zip codes given.
/** The Sort class will take in the ZipCode's via the push method. It will assign the ZipCode to the appropriate cardinal direction(s) but will reject the ZipCode if the State IDs don't match. 
*/
class Sort {
    /// @brief The state ID of which this sort belongs
    std::string state;
    /// @brief The northernmost zip code
    ZipCode north;
    /// @brief The easternmost zip code
    ZipCode east;
    /// @brief The westernmost zip code
    ZipCode west;
    /// @brief The southernmost zip code
    ZipCode south;

    public:
        /**
         * @brief the default constructor for Sort class
         * @param stateID the state ID that this sort should be assigned to
        */
        Sort(std::string stateID) : state(stateID) {}

        /**
         * @brief sorts the ZipCode into whatever proper values are for location.
         * @pre none
         * @post the given ZipCode is processed. Assigned to any relevant values in the sort buffer
         * @param zip the ZipCode to process
         * If the zip's state ID doesn't match the state ID for this Sort instance, the ZipCode will be rejected.
        */
        void push(ZipCode zip);

        /// @brief Gives the northernmost ZipCode
        /// @return the north variable
        ZipCode getNorth();

        /// @brief Gives the southernmost ZipCode
        /// @return the north variable
        ZipCode getSouth();

        /// @brief Gives the easternmost ZipCode
        /// @return the north variable
        ZipCode getEast();

        /// @brief Gives the westernmost ZipCode
        /// @return the north variable
        ZipCode getWest();

        /// @brief a placeholder function until a proper print function exists.
        void printStateInfo();
};

#endif
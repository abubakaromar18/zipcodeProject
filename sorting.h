#pragma once

/**
 * @file sorting.h
 * @author Duncan M.
 * @brief Contains the Table and TableElement classes
*/

#include <iostream>
#include <string>
#include "record.h"
#include <set>

#ifndef RECORD_DELIMITER
#define RECORD_DELIMITER ","
#endif


/** @brief A class for sorting out the zip codes given.
 * @class TableElement
 The TableElement class will take in ZipCodes via the push method. It will assign the ZipCode to the appropriate cardinal direction(s) but will reject the ZipCode if the State IDs don't match. 
*/
class TableElement {
    /// @brief The state ID of which this sort belongs
    std::string state;

    /// @brief checked to see if a single ZipCode has been pushed
    bool init = false;

    /// @brief The northernmost zip code
    ZipCode north;
    /// @brief The easternmost zip code
    ZipCode east;
    /// @brief The westernmost zip code
    ZipCode west;
    /// @brief The southernmost zip code
    ZipCode south;

    public:
        ///@brief the default constructor for Sort class
        ///@param stateID the state ID that this sort should be assigned to
        /// @pre stateID is an initialized std::string instance
        /// @post TableElement is initialized with provided state id
        TableElement(std::string stateID) : state(stateID) {}

        /// @brief sorts the ZipCode into whatever proper values are for location.
        /// @pre none
        /// @post the given ZipCode is processed. Assigned to any relevant values in the sort buffer
        /// @param zip the ZipCode to process
        /// If the zip's state ID doesn't match the state ID for this Sort instance, the ZipCode will be rejected.
        void push(ZipCode zip);

        /// @brief Gives the northernmost ZipCode
        /// @pre a single ZipCode has been pushed to this TableElement
        /// @return the north variable
        /// If no ZipCodes have been pushed yet, this will return the default ZipCode
        ZipCode getNorth();

        /// @brief Gives the southernmost ZipCode
        /// @pre a single ZipCode has been pushed to this TableElement
        /// @return the north variable
        /// If no ZipCodes have been pushed yet, this will return the default ZipCode
        ZipCode getSouth();

        /// @brief Gives the easternmost ZipCode
        /// @pre a single ZipCode has been pushed to this TableElement
        /// @return the north variable
        /// If no ZipCodes have been pushed yet, this will return the default ZipCode
        ZipCode getEast();

        /// @brief Gives the westernmost ZipCode
        /// @pre a single ZipCode has been pushed to this TableElement
        /// @return the north variable
        /// If no ZipCodes have been pushed yet, this will return the default ZipCode
        ZipCode getWest();

        /// @brief gives the state id string
        /// @return the state id
        std::string getStateID();

        /// @brief overloads < operator to allow for std::set to sort these automatically.
        /// @param other a reference value of the TableElement to be compared to
        /// @return true if this state id is comes before the other's state id aphabetically.
        /// Sorts alphabetically by state id.
        bool operator<(const TableElement &other) const { 
            // From what I understand, this will sort alphabetically.
            return state < other.state; 
        }
        /// @brief Prints out the pertinent info for the Table Element as desired in the specification.
        void printInfo();
};



/**
 * @brief A class for sorting the TableElements
 * @class Table
 * the insert function can take in an existing TableElement or just a ZipCode. The behaviour is different depending on what type is given.
*/
class Table{
    /// @brief The sorted list of TableElements
    std::set<TableElement> elements;

    /// @brief Inserts an existing TableElement
    /// @param element an initialized TableElement with data to be transferred in.
    /// @pre element is an initialized TableElement
    /// @post the Table includes the TableElement element
    void insert(TableElement element);

public:

    /// @brief Inserts an existing ZipCode
    /// @param element an initialized ZipCode with data to be transferred in.
    /// @pre zipcode is an initialized ZipCode
    /// @post zipcode is inserted into the table into the appopriate TableElement
    void insert(ZipCode zipcode);

    /// @brief Gets the starting iterator for the TableElements set.
    /// @pre N/A
    /// @return the begin iterator for the TableElements set
    std::set<TableElement>::iterator begin(){return elements.begin();}

    /// @brief Gets the ending iterator for the TableElements set.
    /// @pre N/A
    /// @return the end iterator for the TableElements set
    std::set<TableElement>::iterator end(){ return elements.end();}

};

class TableUtil {
        static std::string getNextToken(std::string &line, std::string delim); 

    public:
        static std::string c_str_to_stl_str(const char *);
        static ZipCode getRecordFromString(std::string);


};

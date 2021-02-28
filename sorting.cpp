#include "sorting.h"

/**
 * @file sorting.cpp
 * @author Duncan M.
 * @brief Contains the definitions for the Table and TableElement classes
*/


void TableElement::push(ZipCode zip){
    // If the state doesn't match, don't check the zip.
    if (zip.state.compare(state) != 0) return;
    if (init){
        /*
        Since we already know the position of the zip code, we can just check against current "maximums" and assign properly where needed.
        Because of this, the first Zip to be pushed will tend to be assigned to two slots, and latter Zips will be placed in the remaining, if not overriding existing slots.
        In the case where all zip codes are in one single hemisphere (vertical or horizontal), there may be a case where the opposite hemisphere's slot is not assigned.  
        */
        if (zip.latitude > north.latitude) north = zip;
        if (zip.latitude < south.latitude) south = zip;
        if (zip.longitude < east.longitude) east = zip;
        if (zip.longitude > west.longitude) west = zip;
    }else{
        /*
            When we are not initialized, we need to make the first zip code a reference node. All other subsequent pushes can be compared against this single zip code. This prevents the hemisphere problem from before.
        */
        north = south = east = west = zip;
        init = true;
    }
}



ZipCode TableElement::getNorth(){
    return north;
}
ZipCode TableElement::getSouth(){
    return south;
}
ZipCode TableElement::getEast(){
    return east;
}
ZipCode TableElement::getWest(){
    return west;
}

std::string TableElement::getStateID(){
    return state;
}

void Table::insert(TableElement a){
    /*
        Because this is a set and TableElement overrides the < op, 
        when any value is inserted, they are sorted automatically.
    */
    elements.insert(a);
}

void Table::insert(ZipCode a){
    for(std::set<TableElement>::iterator it = elements.begin();it!=elements.end();++it){
        TableElement te = *it;
        if( te.getStateID() == a.state){
            // insert into the element if found
            te.push(a);
            return;
        }
    }
    // No matching element found. Make a new one
    TableElement te(a.state);
    te.push(a);
    insert(te);
}


std::string TableUtil::getNextToken(std::string &line, std::string delim){
    int pos = line.find(delim); // find next delimiter
    std::string token = line.substr(0, pos); // get substring between beginning and delim
    line.erase(0, pos+delim.length()); // erase current field
    return token; // return token.
}

std::string TableUtil::c_str_to_stl_str(const char * c_str){
    std::string value(c_str); // simple conversion by constructor
    return value;
}

ZipCode TableUtil::getRecordFromString(std::string line){
    // get all 6 tokens on line
    std::string zip = getNextToken(line, RECORD_DELIMITER);
    std::string place = getNextToken(line, RECORD_DELIMITER);
    std::string state = getNextToken(line, RECORD_DELIMITER);
    std::string county = getNextToken(line, RECORD_DELIMITER);
    std::string lat = getNextToken(line, RECORD_DELIMITER);
    std::string lon = getNextToken(line, RECORD_DELIMITER);
    // convert numbers value strings to appropriate types
    int i_zip = std::stoi(zip);
    float f_lat = std::stof(lat);
    float f_lon = std::stof(lon);
    // return the struct with values inserted
    return ZipCode(i_zip, place, state, county, f_lat, f_lon);
}

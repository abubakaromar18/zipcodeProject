#include "sorting.h"

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

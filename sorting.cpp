#include "sorting.h"

void TableElement::push(ZipCode zip){
    // If the state doesn't match, don't check the zip.
    if (zip.state.compare(state) != 0) return;
    if (zip.latitude > north.latitude) north = zip;
    if (zip.latitude < south.latitude) south = zip;
    if (zip.longitude < east.longitude) east = zip;
    if (zip.longitude > west.longitude) west = zip;
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

void TableElement::printStateInfo(){ // This is a temp func
    std::cout << state << " : N(" << getNorth().zipcode << "), S("<< getSouth().zipcode <<"), E("<< getEast().zipcode <<"), W(" << getWest().zipcode <<")" << std::endl;
}

void Table::insert(TableElement a){
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

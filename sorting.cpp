#include "sorting.h"

void Sort::push(ZipCode zip){
    // If the state doesn't match, don't check the zip.
    if (zip.state.compare(state) != 0) return;
    if (zip.latitude > north.latitude) north = zip;
    if (zip.latitude < south.latitude) south = zip;
    if (zip.longitude < east.longitude) east = zip;
    if (zip.longitude > west.longitude) west = zip;
}

ZipCode Sort::getNorth(){
    return north;
}
ZipCode Sort::getSouth(){
    return south;
}
ZipCode Sort::getEast(){
    return east;
}
ZipCode Sort::getWest(){
    return west;
}

void Sort::printStateInfo(){
    std::cout << state << " : N(" << getNorth().zipcode << "), S("<< getSouth().zipcode <<"), E("<< getEast().zipcode <<"), W(" << getWest().zipcode <<")" << std::endl;
}


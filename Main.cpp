/**
 * @file Main.cpp
 * @author Abubakar Omar, 
 * @brief Main Program file for zipcode Project
*/

#include "buffer.h"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    
    char* file = "us_postal_codes.csv";

    buffer zipCode;

    zipCode.init(file);

    zipCode.print();


    return 0;

}
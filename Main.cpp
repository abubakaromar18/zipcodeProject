/**
 * @file Main.cpp
 * @author Abubakar Omar, 
 * @brief Main Program file for zipcode Project
*/

#include "buffer.h"
#include "sorting.h"
#include <iostream>
#include <fstream>
#include <string>

#ifndef FILE_LINE_NUM_TO_REACH
// We can just set this to the final line and go from there
#define FILE_LINE_NUM_TO_REACH 15
#endif

int main()
{
    char* inputFile = "us_postal_codes.csv";

    buffer file1;

    file1.init(inputFile);

    // Sorting

    std::cout << "Processing Lines" << std::endl; // debug print
    Table table;
    for(int i = 1; i < file1.arrLength(); i++){
        std::string line = file1.getInfo(i); // debug print
        //std::cout << line;
        ZipCode cur = TableUtil::getRecordFromString(line);
        //std:cout << "\\-" << cur.zipcode; // debug print
        table.insert(cur);
    }
    //std::cout << "\n\n"; // debug print

    // Printing Data
    std::cout << "__" << "State" << "___" << "North" << "___" << "South" << "___" << "East" << "___" << "West" << std::endl;
    for(std::set<TableElement>::iterator i = table.begin(); i != table.end(); i++){
        TableElement te = *i;
        te.printInfo();
    }

    return 0;
}
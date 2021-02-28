/**
 * @file Main.cpp
 * @author Abubakar Omar, 
 * @brief Main Program file for zipcode Project
*/

#include "buffer.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    string line;

    char* inputFile = "us_postal_codes.csv";

    buffer file1;

    file1.init(inputFile);

    line = file1.getInfo(10);

    cout << "This is the string stored in line: \n" << line << "\n";

    //file1.print();


    return 0;

}
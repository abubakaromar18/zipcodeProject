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
    int length;
    string input;

    cout << "Input the file name: ";
    cin >> input;
    char * file = const_cast<char*>(input.c_str());

    buffer zipCode(file, &length);

    return 0;

}
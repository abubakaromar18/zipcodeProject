///@file
#ifndef BUFFER_H
#define BUFFER_H
#include <stdio.h>
#include <string>

class buffer
{
private:
    const int initSize = 100;
    int arrayLength;
    char **arr;
public:
//-----------------------------------------------------------------------------------------------
/// @brief Default Constructor
/// @pre Preconditions: None
/// @post Postconditions: arrayLength is assigned value of initSize,
//                 which equals 100.
//                 A block of 100 char * are allocated.
    buffer();
    
//-----------------------------------------------------------------------------------------------
/// @brief Destructor
/// @pre Preconditions: arr is an array that has been allocated
///                      100 char *.
/// @post Postconditions: arr is deleted and i't memory deallocated.
    ~buffer();
    
//-----------------------------------------------------------------------------------------------
// checkOpen
/// @brief checks if file is open
/// @param A read only file stream called file
/// @pre Preconditions: None
/// @post Postconditions: A bool called flag is returned indicating
//                 if the file did not open.
    bool checkOpen(FILE *file);
    
//-----------------------------------------------------------------------------------------------
// init
/// @brief opens a file 
/// @param A char * which points to the name of a file
/// @pre preconditions: char * contains a pointer to a file name.
/// @post postconditions: a file with that name is opened in read only mode.    
    void init(char *filename);
    
//-----------------------------------------------------------------------------------------------
// strArr
/// @brief reads the file and inputs the contents of the file into the array.
/// @param A file stream called file
/// @pre Preconditions: file contains the read stream of the open file.
/// @post Postconditions: An array is created containing the contents of
//                 the file.
    void strArr(FILE *file);
    
//-----------------------------------------------------------------------------------------------
// getInfo
/// @brief retrieves info from array and store it in a string.
/// @param an int called index
/// @pre Preconditions: index contains an int
/// @post Postconditions: line contains a string converted from arr
    std::string getInfo(int index);
    
//-----------------------------------------------------------------------------------------------
// convertToString
/// @brief convert the char to a string.
/// @param 
/// @pre Preconditions: None
/// @post Postconditions: a string s is returned.
    std::string convertToString(char* a);
    
//-----------------------------------------------------------------------------------------------
// arrLength
/// @brief Finds the length of the array
/// @pre Preconditions: None
/// @post Postconditions: arrayLength is returned with the length of the array.
    int arrLength();
    
//-----------------------------------------------------------------------------------------------
// print
/// @brief Prints out the contents of the array.
/// @pre Preconditions: None
/// @post Postconditions: The contents of arr are printed one to each line.
    void print();
};
#endif //BUFFER_H

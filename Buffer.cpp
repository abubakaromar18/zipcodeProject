///@file
#include "buffer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

//-----------------------------------------------------------------------------------------------
/// @brief Default Constructor
/// @pre Preconditions: None
/// @post Postconditions: arrayLength is assigned value of initSize,
//                        which equals 100.
//                        A block of 100 char * are allocated.

buffer::buffer()
{
    arrayLength = initSize; ///array length = initSize; which equals 100; 
    ///Allocate space for 100 char *
    arr = (char**) malloc(initSize * sizeof(char*));
}

//-----------------------------------------------------------------------------------------------
/// @brief Destructor
/// @pre Preconditions: arr is an array that has been allocated
///                      100 char *.
/// @post Postconditions: arr is deleted and i't memory deallocated.

buffer::~buffer()
{
    ///Deletes every element inside the array
    for(int i= 0; i < arrayLength; i++)
        {
            delete arr[i];
        }
        ///deletes the array after
        delete [] arr;
}

//-----------------------------------------------------------------------------------------------
// init
/// @brief opens a file 
/// @param A char * which points to the name of a file
/// @pre preconditions: char * contains a pointer to a file name.
/// @post postconditions: a file with that name is opened in read only mode.

void buffer::init(char * filename)
{
    ///Opens file in read only mode
   FILE *f = fopen(filename, "r");

    checkOpen(f);
    strArr(f);
}

//-----------------------------------------------------------------------------------------------
// checkOpen
/// @brief checks if file is open
/// @param A read only file stream called file
/// @pre Preconditions: None
/// @post Postconditions: A bool called flag is returned indicating
//                 if the file did not open.

bool buffer::checkOpen(FILE *file)
{
    bool flag = true;
    if(!file)
    {
        cout << "Can not open file \n";
        return flag;
    }

    else
    {
        return flag;
    }
}

//-----------------------------------------------------------------------------------------------
// strArr
/// @brief reads the file and inputs the contents of the file into the array.
/// @param A file stream called file
/// @pre Preconditions: file contains the read stream of the open file.
/// @post Postconditions: An array is created containing the contents of
//                 the file.

void buffer:: strArr(FILE * file)
{ 
    char buf[1000];     ///creates a buffer array with size of 1000 char
    int counter = 0;

    ///while loop that reads every line of the file
    while (fgets(buf, 1000, file))
    {
        ///checks if array is full
        if (counter == arrayLength)
        {
            ///if the array is full then array length is doubled
            ///the old array is reallocated to a new array with double the size
            arrayLength += initSize;
            char ** newArr = (char **) realloc(arr, arrayLength * sizeof(char*));

            ///if the new array did not get reallocated the program exits
            if(!newArr)
            {
                cout << "Can not reallocate \n";
                exit(1);
            }

            ///**Array is given the address of the new array
            arr = newArr;
        }
        ///Replacing the NEW line with NULL line
        buf[strlen(buf) - 1 ] = '\0';

        ///gets length of buffer array
        int slen = strlen(buf);

        ///Allocate exact amount of space for the string + the NULL line character
        ///inside a new pointer array
        char* str = (char *) malloc(slen * sizeof(char));
            
        ///copy string from buffer array to string array
        strcpy(str, buf);

        ///attach string array to the array of arrays
        arr[counter] = str;

        ///increases the counter
        counter++;
    }
}

//-----------------------------------------------------------------------------------------------
// arrLength
/// @brief Finds the length of the array
/// @pre Preconditions: None
/// @post Postconditions: arrayLength is returned with the length of the array.

int buffer::arrLength()
{
    int i=0;
    while(arr[i] != '\0')
    {
        i++;
    }

    cout << arrayLength << "\n";
    cout << i << "\n";
    arrayLength = i;
    return arrayLength;
}

//-----------------------------------------------------------------------------------------------
// print
/// @brief Prints out the contents of the array.
/// @pre Preconditions: None
/// @post Postconditions: The contents of arr are printed one to each line.

void buffer::print()
{
    for(int i = 0; i <= arrayLength; i++)
    {
        cout << arr[i]<< '\n';
    }
}

//-----------------------------------------------------------------------------------------------
// getInfo
/// @brief retrieves info from array and store it in a string.
/// @param an int called index
/// @pre Preconditions: index contains an int
/// @post Postconditions: line contains a string converted from arr

string buffer::getInfo(int index)
{
    string line = convertToString(arr[index]);

    return line;
    
}

//-----------------------------------------------------------------------------------------------
// convertToString
/// @brief convert the char to a string.
/// @param 
/// @pre Preconditions: None
/// @post Postconditions: a string s is returned.

string buffer::convertToString(char *a)
{
    string s = a;

    return s;
}

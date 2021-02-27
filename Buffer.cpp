#include "buffer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

buffer::buffer()
{
    int stepSize = 100;
    //Allocate space for 100 char *
    arr = (char**) malloc(stepSize * sizeof(char*)); 
}
buffer::~buffer()
{
    //Deletes every element inside the array
    for(int i= 0; i < arrayLength; i++)
        {
            delete arr[i];
        }
        //deletes the array after
        delete [] arr;
}
bool buffer:: checkOpen(FILE * file)
{
    if(!file)
        {
            std::cout << "File did not open \n";
            return false;
        }
    return true;
}
void buffer::init(char * filename)

{
    //Opens file in read only mode
    FILE *f = fopen(filename, "r");

    if(checkOpen(f) == false)
    {
        exit(1);
    }

    strLength(f);
}
void buffer:: strLength(FILE * file)
{
    stepSize = 100;
    int arrlen = stepSize;  //array length = stepSize; which equals 100; 

    char buf[1000];     //creates a buffer array with size of 1000 char
    arrayLength = 0;      //creates a counter

    //while loop that reads every line of the file
    while (fgets(buf, 1000, file))
    {
        //checks if array is full
        if (arrayLength == arrlen)
        {
            //if the array is full then array length is doubled
            //the old array is reallocated to a new array with double the size
            arrlen += stepSize;
            char ** newlines = (char **) realloc(arr, 200 * sizeof(char*));

            //if the new array did not get reallocated the program exits
            if(!newlines)
            {
                std::cout << "Can not reallocate \n";
                exit(1);
            }

            //**Array is given the address of the new array
            arr = newlines;
        }
        //Replacing the NEW line with NULL line
        buf[strlen(buf)] = '\0';

        //gets length of buffer array
        int slen = strlen(buf);

        //Allocate exact amount of space for the string + the NULL line character
        //inside a new pointer array
        char* str = (char *) malloc((slen + 1) * sizeof(char));
            
        //copy string from buffer array to string array
        strcpy(str, buf);

        //attach string array to the array of arrays
        arr[arrayLength] = str;

        //increases the counter
        arrayLength++;
    }
    //*length = arrayLength; // set the length of the array char ptr
    //return arr;       returns the array of arrays
}

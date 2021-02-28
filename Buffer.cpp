#include "buffer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

buffer::buffer()
{
    arrayLength = initSize; ///array length = initSize; which equals 100; 
    ///Allocate space for 100 char *
    arr = (char**) malloc(initSize * sizeof(char*));
}
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

void buffer::init(char * filename)
{
    ///Opens file in read only mode
   FILE *f = fopen(filename, "r");

    checkOpen(f);
    strArr(f);
}

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
void buffer::print()
{
    for(int i = 0; i <= arrayLength; i++)
    {
        cout << arr[i]<< '\n';
    }
}
string buffer::getInfo(int index)
{
    string line = convertToString(arr[index]);

    return line;
    
}

string buffer::convertToString(char *a)
{
    string s = a;

    return s;
}
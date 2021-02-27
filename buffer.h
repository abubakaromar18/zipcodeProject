#ifndef BUFFER_H
#define BUFFER_H
#include <stdio.h>

class buffer
{
public:
    int stepSize;
    int arrayLength;
    char **arr;
    buffer();

    ~buffer();

    bool checkOpen(FILE * file);

    void init(char * filename, int * length);

    void strLength(FILE * file, int * length);
};
#endif
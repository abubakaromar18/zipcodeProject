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
    buffer();
    ~buffer();
    
    bool checkOpen(FILE *file);
    void init(char *filename);
    void strArr(FILE *file);
    std::string getInfo(int index);
    std::string convertToString(char* a);
    int arrLength();
    void print();
};
#endif //BUFFER_H
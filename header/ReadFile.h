#include <iostream>
#include <fstream>
#include <cmath>
#include "Read.h"
#include "../exceptions/FailOpen.h"
#include "../exceptions/InvalidInput.h"
#ifndef READ_FILE_H
#define READ_FILE_H


class ReadFile : public Read
{
public:
    ReadFile(std::string path) : Read(path){}
    std::string getStringFromFile(Flag::Value flags = Flag::ONE_LINE,uint32_t numOfLine=1);
};

#endif
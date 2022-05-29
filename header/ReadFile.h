//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_READFILE_H
#define PIZZATIME_READFILE_H
#include "Read.h"
#include "../exceptions/FailOpen.h"
#include "../exceptions/InvalidInput.h"
#include <fstream>

class ReadFile : public Read
{
public:
    ReadFile(std::string path) : Read(path){}
    std::string getStringFromFile(Flag::Value flags = Flag::ONE_LINE,uint32_t numOfLine=1);
};

#endif //PIZZATIME_READFILE_H

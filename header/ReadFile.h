<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
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
=======
>>>>>>> Stashed changes
//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_READFILE_H
#define PIZZATIME_READFILE_H
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
#include "Read.h"
#include "../exceptions/FailOpen.h"
#include "../exceptions/InvalidInput.h"
#include <fstream>

<<<<<<< Updated upstream
class ReadFile : public Read
{
public:
    ReadFile(std::string path) : Read(path){}
    std::string getStringFromFile(Flag::Value flags = Flag::ONE_LINE,uint32_t numOfLine=1);
};

#endif //PIZZATIME_READFILE_H
=======
class ReadFile : public Read {
public:
    ReadFile(std::string path) : Read(path) {}

    std::string getStringFromFile(Flag::Value flags = Flag::ONE_LINE, uint32_t numOfLine = 1);
};

#endif //PIZZATIME_READFILE_H
>>>>>>> Stashed changes
>>>>>>> Stashed changes

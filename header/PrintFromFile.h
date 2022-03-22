#ifndef PRINT_FROM_FILE_H
#define PRINT_FROM_FILE_H

#include "Read.h"
class PrintFromFile
{
public:
    static void printFromFile(Read* objectToPrint,Flag::Value flags=Flag::ONE_LINE, uint32_t numOfLine=1);
};

#endif
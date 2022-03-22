#include "../header/PrintFromFile.h"

void PrintFromFile::printFromFile(Read* objectToPrint,Flag::Value flags, uint32_t numOfLine)
{
    std::cout<<objectToPrint->getStringFromFile(flags,numOfLine)<<std::endl;
}
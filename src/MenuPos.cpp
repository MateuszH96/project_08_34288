#include "../header/MenuPos.h"

MenuPos::MenuPos(std::string inputStringFromFile)
{
    setValuesFromString(inputStringFromFile);
}

void MenuPos::setValuesFromString(std::string inputStringFromFile)
{
    std::vector<std::string> tmp = splitStr(inputStringFromFile);
    id = std::stoi(tmp[0]);
    name = tmp[1];
    smallSize = std::stod(tmp[2]);
    mediumSize = std::stod(tmp[3]);
    largeSize = std::stod(tmp[4]);
}

std::vector<std::string> MenuPos::splitStr(std::string input)
{
    std::vector<std::string> inputSeparate;
    std::string tmp = "";
    
    for (auto &&i : input)
    {
        if (i == ',')
        {
            inputSeparate.push_back(tmp);
            tmp = "";
        }
        else
        {
           tmp += i;
        }
    }
    inputSeparate.push_back(tmp);
    return inputSeparate;
}

uint32_t MenuPos::getId()
{
    return id;
}

std::string MenuPos::getName()
{
    return name;
}

double MenuPos::getSmallSize()
{
    return smallSize;
}
double MenuPos::getMediumSize()
{
    return mediumSize;
}
double MenuPos::getLargeSize()
{
    return largeSize;
}

std::ostream& operator<<(std::ostream& out,const MenuPos toPrint)
{
    out<<toPrint.id<<". "<<toPrint.name<<SEPARATOR <<toPrint.smallSize<<SEPARATOR 
        <<toPrint.mediumSize<<SEPARATOR <<toPrint.largeSize;
    return out;
}
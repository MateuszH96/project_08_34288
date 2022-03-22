#include "../header/Ingredient.h"

Ingredient::Ingredient(std::string inputStringFromFile)
{
    setValuesFromString(inputStringFromFile);
}

void Ingredient::setValuesFromString(std::string inputStringFromFile)
{
    std::vector<std::string> tmp = splitStr(inputStringFromFile);
    id = std::stoi(tmp[0]);
    name = tmp[1];
    smallSize = std::stod(tmp[2]);
    mediumSize = std::stod(tmp[3]);
    largeSize = std::stod(tmp[4]);
}

std::vector<std::string> Ingredient::splitStr(std::string input)
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

uint32_t Ingredient::getId()
{
    return id;
}

std::string Ingredient::getName()
{
    return name;
}

double Ingredient::getSmallSize()
{
    return smallSize;
}
double Ingredient::getMediumSize()
{
    return mediumSize;
}
double Ingredient::getLargeSize()
{
    return largeSize;
}
#ifndef INGREDIENT_H    
#define INGREDIENT_H
#include <iostream>
#include <vector>
class Ingredient
{
private:
    uint32_t id;
    std::string name;
    double smallSize;
    double mediumSize;
    double largeSize;
    std::vector<std::string> splitStr(std::string input);
public:
    Ingredient(std::string inputStringFromFile);
    void setValuesFromString(std::string inputStringFromFile);  
    uint32_t getId();
    std::string getName();
    double getSmallSize();
    double getMediumSize();
    double getLargeSize();
};

#endif
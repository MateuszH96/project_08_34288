#ifndef MENU_POS_H
#define MENU_POS_H
#include <iostream>
#include <vector>
#define SEPARATOR "\t"
class MenuPos
{
private:
    uint32_t id;
    std::string name;
    double smallSize;
    double mediumSize;
    double largeSize;
    std::vector<std::string> splitStr(std::string input);

public:
    MenuPos(std::string inputStringFromFile);
    void setValuesFromString(std::string inputStringFromFile);
    uint32_t getId();
    std::string getName();
    double getSmallSize();
    double getMediumSize();
    double getLargeSize();
    friend std::ostream &operator<<(std::ostream &out, const MenuPos toPrint);
};

#endif
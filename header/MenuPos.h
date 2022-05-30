//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_MENUPOS_H
#define PIZZATIME_MENUPOS_H

#include <iostream>
#include <vector>
#include "ConvertString.h"

#define SEPARATOR "\t"
#define PRICE_SEPARATOR "\n\t\t\t\t"

class MenuPos {
private:
    uint32_t id;
    std::string name;
    double smallSize;
    double mediumSize;
    double largeSize;

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

#endif //PIZZATIME_MENUPOS_H

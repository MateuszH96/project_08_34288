<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
#ifndef MENU_POS_H
#define MENU_POS_H
=======
>>>>>>> Stashed changes
//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_MENUPOS_H
#define PIZZATIME_MENUPOS_H
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
>>>>>>> Stashed changes
#include <iostream>
#include <vector>
#include "ConvertString.h"

#define SEPARATOR "\t"
<<<<<<< Updated upstream
#define PRICE_SEPARATOR "\n\t\t\t\t"
=======
<<<<<<< Updated upstream
>>>>>>> Stashed changes
class MenuPos
{
=======
#define PRICE_SEPARATOR "\n\t\t\t\t"

class MenuPos {
>>>>>>> Stashed changes
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

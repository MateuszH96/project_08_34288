<<<<<<< Updated upstream
//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_ORDERPOS_H
#define PIZZATIME_ORDERPOS_H
=======
<<<<<<< Updated upstream
#ifndef ORDER_POS_H
#define ORDER_POS_H
>>>>>>> Stashed changes
#include <iostream>
#include <vector>
#include "PrintMenu.h"
#include <map>
#include <unistd.h>
#include <iomanip>
#include <cmath>
typedef struct ingredient
{
    std::string name;
    double price;
    ingredient(std::string _name = "", double _price = 0.0) : name(_name), price(_price) {}

} Ingredient;
enum TYPE_POS
{
    PIZZA,
    SET,
    HALF_PIZZA,
    PIZZA_AND_DRINK,
    INGREDIENTS,
    ERROR
};
class OrderPos
{
<<<<<<< Updated upstream
public:
    bool isAdded;
=======
private:
=======
//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_ORDERPOS_H
#define PIZZATIME_ORDERPOS_H

#include <iostream>
#include <vector>
#include "PrintMenu.h"
#include <map>
#include <unistd.h>
#include <iomanip>
#include <cmath>

typedef struct ingredient {
    std::string name;
    double price;

    ingredient(std::string _name = "", double _price = 0.0) : name(_name), price(_price) {}

} Ingredient;
enum TYPE_POS {
    PIZZA,
    SET,
    HALF_PIZZA,
    PIZZA_AND_DRINK,
    INGREDIENTS,
    ERROR
};

class OrderPos {
public:
    bool isAdded;
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    PrintMenu *menu;
    Ingredient tmpIngtrdient;
    std::vector<Ingredient> list;
<<<<<<< Updated upstream
    void pickPos(TYPE_POS typePos);
    void addPos(TYPE_POS typePos);
    double setPrecision(double input, unsigned n);
    void halfPizza(ingredient &toAdd, char size);
    double getPriceBySize(char size, unsigned index);
    void addAdditives(std::string file);
=======
<<<<<<< Updated upstream
    void pickPos();
>>>>>>> Stashed changes

public:
    OrderPos(TYPE_POS typePos);
    void removeIngredient();
    bool getIsAdded();
    std::vector<Ingredient> getList();
    void printList();
    ~OrderPos();
    //friend std::ostream &operator<<(std::ostream &out, const OrderPos &input);
};
<<<<<<< Updated upstream
#endif //PIZZATIME_ORDERPOS_H
=======
#endif
=======

    void pickPos(TYPE_POS typePos);

    void addPos(TYPE_POS typePos);

    double setPrecision(double input, unsigned n);

    void halfPizza(ingredient &toAdd, char size);

    double getPriceBySize(char size, unsigned index);

    void addAdditives(std::string file);

public:
    OrderPos(TYPE_POS typePos);

    bool getIsAdded();

    std::vector<Ingredient> getList();

    ~OrderPos();
};

#endif //PIZZATIME_ORDERPOS_H
>>>>>>> Stashed changes
>>>>>>> Stashed changes

#ifndef ORDER_POS_H
#define ORDER_POS_H
#include <iostream>
#include <vector>
#include "PrintMenu.h"
#include <map>
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
private:
    bool isAdded;
    PrintMenu *menu;
    double price;
    Ingredient tmpIngtrdient;
    std::vector<Ingredient> list;
    void pickPos(TYPE_POS typePos);
    void addPos(TYPE_POS typePos);
    double setPrecision(double input, unsigned n);
    void halfPizza(ingredient &toAdd, char size);

public:
    OrderPos(TYPE_POS typePos);
    void addIngredient();
    void removeIngredient();
    bool getIsAdded();
    ~OrderPos();
    friend std::ostream &operator<<(std::ostream &out, const OrderPos &input);
};
#endif
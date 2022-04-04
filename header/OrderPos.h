#ifndef ORDER_POS_H
#define ORDER_POS_H
#include <iostream>
#include <vector>
#include "PrintMenu.h"
typedef struct ingredient
{
    std::string name;
    double price;
    ingredient(std::string _name, double _price) : name(_name), price(_price) {}
} Ingredient;

typedef struct orderFlag
{
    enum Value
    {
        SET = 0x01,
        NO_SET = 0X02
    };
} OrderFlag;


class OrderPos
{
private:
    PrintMenu *menu;
    double price;
    std::vector<Ingredient> list;
    void pickPos();

public:
    OrderPos(OrderFlag::Value flag = OrderFlag::NO_SET);
    void addIngredient();
    void removeIngredient();
    ~OrderPos();
    friend std::ostream &operator<<(std::ostream &out, const OrderPos &input);
};
#endif
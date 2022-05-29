//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_ORDER_H
#define PIZZATIME_ORDER_H
#include "OrderPos.h"
#include "PrintMenu.h"
class Order
{
private:
    static uint8_t num;
    uint8_t numOfOrder;
    std::vector<std::vector<Ingredient>> list;
    void printOrder();
public:
    Order();
    void printMenu();
    void addOrderPos();
    void deleteOrderPos();
    void modifyOrderPos();
    void generateBill();
    ~Order();
};
#endif //PIZZATIME_ORDER_H

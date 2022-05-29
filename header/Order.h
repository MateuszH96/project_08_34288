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
    void generateOrderBill(std::string filename);
    std::vector<std::string> splitPromo(std::string input);
    double getTotalPrice();
    std::string convertOrderToString();
public:
    Order();
    void printMenu();
    void addOrderPos();
    void deleteOrderPos();
    void checkOrderPos();
    void generateBill();
    ~Order();
};
#endif //PIZZATIME_ORDER_H

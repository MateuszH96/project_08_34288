//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_ORDER_H
#define PIZZATIME_ORDER_H


#include "OrderPos.h"
#include "PrintMenu.h"
#include "ConvertString.h"

class Order {
private:
    std::vector<std::vector<Ingredient>> list;

    void printOrder();

    void generateOrderBill(const std::string &filename);

    static std::vector<std::string> splitPromo(const std::string &input);

    double getTotalPrice();

    std::string convertOrderToString();

public:
    Order();

    static void printMenu();

    void addOrderPos();

    void deleteOrderPos();

    void checkOrderPos();

    void generateBill();

    ~Order();
};

#endif //PIZZATIME_ORDER_H

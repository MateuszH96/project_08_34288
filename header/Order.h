#ifndef ORDER_H
#define ORDER_H
#include "OrderPos.h"
#include "PrintMenu.h"
class Order
{
private:
    static uint8_t num;
    uint8_t numOfOrder;
    std::vector<OrderPos> list;
    void printOrder();
public:
    Order();
    void addOrderPos();
    void deleteOrderPos();
    void modifyOrderPos();
    ~Order();
};
#endif
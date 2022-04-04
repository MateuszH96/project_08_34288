#include "../header/Order.h"

uint8_t Order::num = 0;
Order::Order()
{
    numOfOrder=num;
    num = num < 100 ? num++ : 0;
    addOrderPos();
}
Order::~Order()
{
    list.clear();
}

void Order::addOrderPos()
{
    uint8_t choose;
    std::cout<<"wybierz pozycję:\n"<<
                "1.Dodaj zestaw\n"<<
                "2.Dodaj pizzę\n";
    std::cin>>choose;
    switch (choose)
    {
    case 1:
        list.push_back(OrderPos(OrderFlag::SET));
        break;
    case 2:
        list.push_back(OrderPos());
        break;
    default:
        break;
    }
}

void Order::printOrder()
{
    uint32_t numPos=0;
    for (auto &&i : list)
    {
        std::cout<<numPos<<'.'<<i<<std::endl;
        numPos++;
    }
}

void Order::deleteOrderPos()
{
    printOrder();
}

void Order::modifyOrderPos()
{
    printOrder();
}